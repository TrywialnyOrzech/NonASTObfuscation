#ifndef NOPInjector_H
#define NOPInjector_H

#include "Obfuscator.h"

class NOPInjector : public Obfuscator {
public:
  int readFile();
};

#endif