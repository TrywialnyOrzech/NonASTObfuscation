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
  sourceStream.str( string() );
  sourceStream << targetStream.str();
  targetStream.str( string() );
  loadTargetFile( targetName );
  cout << "=========\n\n" << originalStream.str();
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
  string temp;
  if( ifTarget ) {
    do {
      if( !getline( targetStream, temp ) )
        return false;

      *word += temp;
    } while( temp != "\n" );
    return true;
  } else {
    do {
      if( !getline( sourceStream, temp ) )
        return false;
      *word += temp;
    } while( temp.find( "\n" ) != string::npos );
    return true;
  }
  return false;
}

void SourcesController::writeWord( string word ) { targetStream << word; }

void SourcesController::loadStringStream() {
  string line;
  while( getline( sourceFile, line ) ) {
    originalStream << line << "\n";
  }
  sourceStream << originalStream.str();
}

string SourcesController::readWholeFile( bool ifTarget = false ) {
  if( !ifTarget ) {
    return sourceStream.str();
  } else {
    return targetStream.str();
  }
}

string SourcesController::getOriginalStream() { return originalStream.str(); }