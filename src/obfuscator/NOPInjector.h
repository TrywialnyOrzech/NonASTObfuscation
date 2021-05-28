#ifndef NOPInjector_H
#define NOPInjector_H

#include <stdlib.h>
#include <time.h>

#include "Obfuscator.h"

class NOPInjector : public Obfuscator {
  int randomX, randomY;

public:
  NOPInjector( Obfuscator obf ) : Obfuscator( obf ) {
    srand( time( NULL ) );
    randomX = rand() % 10 + 1;
    randomY = rand() % 50 + 1;
  }
  bool findFuncDefinitions();          // returns array with string positions
  int getRandomValues( bool );
  bool injectForLoops( const char * );
  bool findKeywords();
  bool injectZeros();
  bool injectOR();
};

#endif