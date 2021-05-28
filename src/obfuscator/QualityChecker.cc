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