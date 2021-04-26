#ifndef NamesChanger_H
#define NamesChanger_H

#include <string>
#include <fstream>
#include "Obfuscator.h"
class NamesChanger : public Obfuscator
{
public:
    NamesChanger(std::string oFP = "../testFile.cc", std::string tFP = "../obfuscatedFile.cc") : Obfuscator(oFP,tFP) {}
    void clearEnters();

    virtual void changeVariablesNames();

    void changeFunctionNames();
    // SourcesController* src;

};

#endif