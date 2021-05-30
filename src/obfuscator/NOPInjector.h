#ifndef NOPInjector_H
#define NOPInjector_H

#include <regex>
#include <stdlib.h>
#include <time.h>

#include "Obfuscator.h"

class NOPInjector : public Obfuscator {
  int randomX, randomY;
  std::vector<std::string> foundFunctions;
  std::vector<std::size_t> funcPositions;
  std::vector<std::string> foundVars;
  std::vector<std::size_t> varPositions;

public:
  NOPInjector( Obfuscator obf ) : Obfuscator( obf ) {}
  void randomNoGen();
  std::vector<std::string> findRegexMatches( std::string str, std::regex reg );
  bool findFuncDefinitions();          // returns string with definitions
  bool findPositions( bool );          // return positions of found functions
  bool injectForLoops();

  bool findVarDefinitions();
  bool injectZeros();
  bool injectOR();

  int getRandomValues( bool );
  std::vector<std::string> getFoundFunctions() { return foundFunctions; };
  std::vector<std::size_t> getFuncPositions() { return funcPositions; };
  std::vector<std::size_t> getVarPositions() { return varPositions; };

  void clearFoundFunctions() { foundFunctions.clear(); };
  void clearFuncPositions() { funcPositions.clear(); };
};

#endif