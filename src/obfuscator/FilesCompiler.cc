#include "FilesCompiler.h"
#include <iostream>
using namespace std;

bool FilesCompiler::fileCompilation( string filename ) {
#ifdef _WIN32
  string systemCall( "gcc " + filename );

#else
  string systemCall( "g++ " + filename );
#endif
  if( system( systemCall.c_str() ) != 0 )
    return false;
  else
    return true;
}
bool FilesCompiler::fileFormatting( string filename ) {
  string systemCall( "clang-format -i " + filename );
  if( system( systemCall.c_str() ) != 0 )
    return false;
  else
    return true;
}

bool FilesCompiler::initialCompilation() {
  src.printState( "Compiling source file..." );
  if( !fileCompilation( src.getOriginalFilePath() ) ) {

    cerr << "Compilation of source file failed! Provide valid file. Exitting.."
         << endl;
    return false;
  } else {
    cout << "   Compilation successful" << endl << endl;
    src.printState( "Formatting source file..." );
    if( !fileFormatting( src.getOriginalFilePath() ) ) {
      cerr << "Formattin of source file failed! Exitting.." << endl;
      return false;
    } else {
      cout << "   Formatting successful" << endl << endl;
    }
    return true;
  }
}