#ifndef NamesChanger_H
#define NamesChanger_H

#include "Obfuscator.h"
#include <fstream>
#include <map>
#include <string>
class NamesChanger : public Obfuscator {
public:
  NamesChanger( std::string oFP = "../testFile.cc",
                std::string tFP = "../obfuscatedFile.cc" )
      : Obfuscator( oFP, tFP ) {}
  ~NamesChanger() {}
  void clearEnters();
  virtual void changeVariablesNames();
  void changeFunctionNames();
  bool ifDuplicate( std::string *name );

private:
  std::map<std::string, std::string> variables;
  std::string gen_random_name( const int );
};

#endif