#ifndef Obfuscator_H
#define Obfuscator_H

#include "SourcesController.h"
#include <string>
class Obfuscator {
public:
  Obfuscator( std::string oFP = "../testFile.cc",
              std::string tFP = "../obfuscatedFile.cc" ) {
    SourcesController source( oFP, tFP );
    src = source;
  }
  Obfuscator( SourcesController *source ) { src = *source; }
  ~Obfuscator() {}
  virtual void changeVariablesNames() {}
  virtual void changeFunctionNames() {}
  virtual void fileCompilation() {}
  virtual bool initialCompilation() { return false; }
  virtual void init();
  void close();

protected:
  SourcesController src;
};

#endif