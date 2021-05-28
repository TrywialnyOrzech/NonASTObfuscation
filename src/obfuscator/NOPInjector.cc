#include "NOPInjector.h"

#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool injectForLoops( const char *fileContent ) {
  string fileContentStr( fileContent );
  cout << "INJECT FOR LOOPS" << endl;
  cout << fileContentStr << endl;
  return 0;
}

int NOPInjector::getRandomValues( bool choice ) {
  if( choice )
    return randomX;
  else
    return randomY;
}