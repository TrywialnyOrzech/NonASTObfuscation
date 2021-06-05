#ifndef IFCONDITIONCHANGER_H
#define IFCONDITIONCHANGER_H

#include "Obfuscator.h"
class IfConditionChanger : public Obfuscator {
public:
  IfConditionChanger( std::string oFP = "../testFile.cc",
                      std::string tFP = "../obfuscatedFile.cc" )
      : Obfuscator( oFP, tFP ) {}
  IfConditionChanger( Obfuscator obf ) : Obfuscator( obf ) {}
  ~IfConditionChanger() {}
  void rebuildIfStatement();

private:
};

#endif