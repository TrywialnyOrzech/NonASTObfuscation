#ifndef FilesCompiler_H
#define FilesCompiler_H

#include <string>
#include <fstream>
#include "Obfuscator.h"
class FilesCompiler : public Obfuscator
{
public:
    FilesCompiler(std::string oFP = "../testFile.cc", std::string tFP = "../obfuscatedFile.cc"): Obfuscator(oFP,tFP){}
    static bool fileCompilation(std::string filename);
    bool initialCompilation();

};

#endif