#ifndef SOURCESCONTROLLER_H
#define SOURCESCONTROLLER_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
class SourcesController {
public:
  SourcesController( std::string src = "../testFile.cc",
                     std::string tar = "../obfuscatedFile.cc" )
      : sourceName( src ), targetName( tar ) {}
  ~SourcesController() {
    if( sourceFile )
      sourceFile.close();
    if( targetFile )
      targetFile.close();
  }
  void loadSourceFile( const std::string &name );
  void loadTargetFile( const std::string &name );
  std::string readWholeFile( bool ifTarget );
  void init();
  void reload();
  void close() {
    targetFile << targetStream.str();
    sourceFile.close();
    targetFile.close();
  }
  void printState( std::string text );
  void setOriginalFilePath( std::string path );

  void setTargetFilePath( std::string path );

  std::string getOriginalFilePath();

  std::string getTargetFilePath();

  bool readWord( std::string *word );

  bool readLine( std::string *word, bool whichFile );

  void writeWord( std::string word );

  void loadStringStream();
  std::string getOutput() { return targetStream.str(); }
  void operator=( const SourcesController &src ) {
    sourceName = src.sourceName;
    targetName = src.targetName;
    sourceStream << src.sourceStream.str();
    targetStream << src.targetStream.str();
  }
  SourcesController( const SourcesController &src ) {
    sourceName = src.sourceName;
    targetName = src.targetName;
    sourceStream << src.sourceStream.str();
    targetStream << src.targetStream.str();
  }

protected:
  std::string sourceName;
  std::string targetName;
  std::fstream sourceFile;
  std::fstream targetFile;
  std::stringstream sourceStream;
  std::stringstream targetStream;
};

#endif