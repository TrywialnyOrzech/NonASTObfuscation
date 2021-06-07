// Author: Lukasz Stojke
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
  Obfuscator( const Obfuscator &obf ) { src = obf.src; }
  Obfuscator( SourcesController *source ) { src = *source; }
  ~Obfuscator() {}
  virtual void changeVariablesNames() {}
  virtual void changeFunctionNames() {}
  virtual void runNOPInjector(){}
  virtual void runTrigraphSequencesInjector(){}
  virtual int rateCodeLength(){ return -1; }
  virtual void fileCompilation() {}
  virtual bool initialCompilation() { return false; }
  virtual void init();
  virtual void loadFileContent(){};
  virtual int rateCodeLength( char const *, char const * ) { return false; };
  virtual void rebuildIfStatement() {}
  virtual void cleanComments() {}
  virtual bool saveIncludes( std::string &code );
  void reload();
  void close();
  std::string getOutput() { return src.getOutput(); }

protected:
  SourcesController src;
  const bool READSOURCE = false;
  const bool READTARGET = true;
};

#endif