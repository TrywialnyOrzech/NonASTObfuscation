#include "SourcesController.h"
#include <iostream>
using namespace std;

void SourcesController::init() {
  printState( "Opening source file..." );
  loadSourceFile( sourceName );
  loadTargetFile( targetName );
  loadStringStream();
}
void SourcesController::reload() {
  // printState( "Reopening files..." );
  // close();
  // sourceFile.clear();
  // sourceFile.seekg( 0, ios::beg );
  // targetFile.clear();
  // targetFile.seekg( 0, ios::beg );
  // loadSourceFile( sourceName );
  // targetFile.open( targetName, fstream::in | fstream::out );
  sourceStream.str( string() );
  sourceStream << targetStream.str();
  loadTargetFile( targetName );
}

void SourcesController::loadSourceFile( const string &name ) {
  sourceFile.open( name, fstream::in );
  if( !sourceFile )
    cerr << "Cannot open source file in this path!, path: " << name << endl;
  else
    cout << "    Loading file successful" << endl << endl;
}
void SourcesController::loadTargetFile( const string &name ) {
  targetFile.open( name, fstream::in | fstream::out | fstream::trunc );
  if( !targetFile ) {
    cerr << "Cannot open/create target file in this path!, path: " << name
         << endl;
  }
}

void SourcesController::printState( string text ) {

  cout << "--------------------------------------\n"
       << text << endl
       << "--------------------------------------" << endl;
}

void SourcesController::setOriginalFilePath( string path ) {
  sourceName = path;
}
void SourcesController::setTargetFilePath( string path ) { targetName = path; }

string SourcesController::getOriginalFilePath() { return sourceName; }
string SourcesController::getTargetFilePath() { return targetName; }

bool SourcesController::readWord( string *word ) {
  if( sourceStream >> *word )
    return true;
  else {
    return false;
  }
}

bool SourcesController::readLine( string *word, bool ifTarget = false ) {
  if( ifTarget ) {
    if( getline( targetStream, *word ) )
      return true;
  } else {
    if( getline( sourceFile, *word ) )
      return true;
  }
  return false;
}

void SourcesController::writeWord( string word ) { targetStream << word; }

void SourcesController::loadStringStream() {
  string line;
  while( getline( sourceFile, line ) ) {
    sourceStream << line;
  }
}

string SourcesController::readWholeFile( bool ifTarget = false ) {
  if( !ifTarget ) {
    return sourceStream.str();
  } else {
    return targetStream.str();
  }
}