#include "QualityChecker.h"

#include <iostream>

using namespace std;

void QualityChecker::loadFileContent() {
  const bool SOURCE = false;
  const bool TARGET = true;
  string code, fileContent;
  while( src.readLine( &code, TARGET ) ) {
    fileContent += code;
  }
  cout << "TERA MOJE" << endl;
  cout << fileContent << endl;
}

int QualityChecker::rateCodeLength( char const *source, char const *target ) {
  string sourceStr( source );
  string targetStr( target );
  int result = (int)targetStr.length() * 100 / sourceStr.length();
  cout << "Obfuscated code is " << result << " % length of original code."
       << endl;
  return result;
}