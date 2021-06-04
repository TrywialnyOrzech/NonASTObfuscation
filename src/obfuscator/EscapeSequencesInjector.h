#ifndef EscapeSequencesInjector_H
#define EscapeSequencesInjector_H

#include <regex>
#include <stdlib.h>
#include <time.h>

#include "Obfuscator.h"

class EscapeSequencesInjector : public Obfuscator {
  std::vector<std::string> foundStrings;
  std::vector<std::size_t> foundPositions;

public:
  EscapeSequencesInjector( Obfuscator obf ) : Obfuscator( obf ) {}

  std::vector<std::string> findRegexMatches( std::string str, std::regex reg );
  bool findStrings();
  bool findPositions();
  bool injectEscapeSequences();
  bool convertCharsToHex( std::string );
  std::string getEscapeSequence( std::string hexVal );

  std::vector<std::string> getFoundStrings() { return foundStrings; };
  std::vector<std::size_t> getFoundPositions() { return foundPositions; };
};

#endif