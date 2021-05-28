#include "NOPInjector.h"

#include <fstream>
#include <iostream>

using namespace std;

int NOPInjector::readFile() {
  ifstream originalFile;
  ifstream obfuscatedFile;
  originalFile.open( "../testFile.cc" );
  obfuscatedFile.open( "../obfuscatedFile.cc" );
  if( !originalFile || !obfuscatedFile ) {
    cerr << "Unable to open file" << endl;
    exit( 1 );
  }
  string x, y, originalFileContent, obfuscatedFileContent;
  while( originalFile >> x ) {
    originalFileContent += x;
  }
  while( obfuscatedFile >> y ) {
    obfuscatedFileContent += y;
  }
  cout << "---------------------------------------" << endl;
  cout << obfuscatedFileContent << endl;

  // cout << "-------------------------------" << endl;
  // string code, fileContent;
  // while( src.readLine( &code ) )
  //   fileContent += code;
  // cout << fileContent << endl;
  return 0;
}