#ifndef FilesCompiler_H
#define FilesCompiler_H

#include "Obfuscator.h"
#include <fstream>
#include <string>
class FilesCompiler : public Obfuscator {
public:
  FilesCompiler(std::string oFP = "../testFile.cc",
                std::string tFP = "../obfuscatedFile.cc")
      : Obfuscator(oFP, tFP) {}
  ~FilesCompiler() {}
  static bool fileCompilation(std::string filename);
  bool initialCompilation();
};

#endif