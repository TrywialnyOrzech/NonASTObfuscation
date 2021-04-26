#ifndef OBFUSCATOR_H
#define OBFUSCATOR_H

#include <string>
#include <fstream>
#include "SourcesController.h"
class Obfuscator : public SourcesController
{
public:
    Obfuscator(std::string oFP = "../testFile.cc", std::string tFP = "../obfuscatedFile.cc") : SourcesController(oFP,tFP) {}
    void clearEnters();

    void spaceCleaning(std::string line);

    void changeVariablesNames();

    void changeFunctionNames();

    void setOriginalFilePath(std::string path);

    void setTargetFilePath(std::string path);

    std::string getOriginalFilePath();

    std::string getTargetFilePath();

};

#endif