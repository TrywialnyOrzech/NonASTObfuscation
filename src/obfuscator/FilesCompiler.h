// Author: Lukasz Stojke
#ifndef FilesCompiler_H
#define FilesCompiler_H

#include "Obfuscator.h"
#include <string>
class FilesCompiler : public Obfuscator {
public:
  FilesCompiler( std::string oFP = "../testFile.cc",
                 std::string tFP = "../obfuscatedFile.cc" )
      : Obfuscator( oFP, tFP ) {}
  FilesCompiler( Obfuscator obf ) : Obfuscator( obf ) {}
  ~FilesCompiler() {}
  static bool fileCompilation( std::string filename );
  bool initialCompilation();
  static bool fileFormatting( std::string filename );
};

#endif