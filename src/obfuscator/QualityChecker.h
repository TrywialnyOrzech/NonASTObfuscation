#ifndef QualityChecker_H
#define QualityChecker_H

#include "Obfuscator.h"

class QualityChecker : public Obfuscator {
public:
  QualityChecker( Obfuscator obf ) : Obfuscator( obf ) {}
  void loadFileContent();
};

#endif