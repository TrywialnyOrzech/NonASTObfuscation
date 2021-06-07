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
}

int QualityChecker::rateCodeLength() {
  string sourceStr( src.getOriginalStream() );
  string targetStr = src.readWholeFile(READSOURCE);
  int result = (int)targetStr.length() * 100 / sourceStr.length();
  cout << "Obfuscated code is " << result << " % length of original code."
       << endl;
  return result;
}
