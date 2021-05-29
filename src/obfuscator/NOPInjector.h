#ifndef NOPInjector_H
#define NOPInjector_H

#include <regex>
#include <stdlib.h>
#include <time.h>

#include "Obfuscator.h"

class NOPInjector : public Obfuscator {
  int randomX, randomY;
  std::vector<std::string> foundFunctions;

public:
  NOPInjector( Obfuscator obf ) : Obfuscator( obf ) {
    srand( time( NULL ) );
    randomX = rand() % 10 + 1;
    randomY = rand() % 50 + 1;
  }
  std::vector<std::string> findRegexMatches( std::string str, std::regex reg );
  bool findFuncDefinitions();          // returns string with definitions
  bool findPositions();                // return positions of found functions
  bool injectForLoops( const char * );

  bool findKeywords();
  bool injectZeros();
  bool injectOR();

  int getRandomValues( bool );
  std::vector<std::string> getFoundFunctions() { return foundFunctions; };
};

#endif