#include "QualityChecker.h"

#include <iostream>

using namespace std;

void QualityChecker::loadFileContent() {
  string code, fileContent;
  while( src.readLine( &code ) ) {
    fileContent += code;
  }
  cout << "TERA MOJE" << endl;
  cout << fileContent << endl;
}