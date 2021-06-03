#ifndef TrigraphSequencesInjector_H
#define TrigraphSequencesInjector_H

#include <regex>
#include <stdlib.h>
#include <time.h>

#include "Obfuscator.h"

class TrigraphSequencesInjector : public Obfuscator {
  std::vector<std::string> foundReplacements;
  std::vector<std::size_t> foundPositions;

public:
  TrigraphSequencesInjector( Obfuscator obf ) : Obfuscator( obf ) {}

  std::vector<std::string> findRegexMatches( std::string str, std::regex reg );
  bool findReplacements();
  bool findPositions();
  bool injectTrigraphSequences();

  std::vector<std::string> getFoundReplacements() { return foundReplacements; };
  std::vector<std::size_t> getFoundPositions() { return foundPositions; };
};

#endif