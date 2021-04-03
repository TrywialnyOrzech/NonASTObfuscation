#ifndef OBFUSCATOR_H
#define OBFUSCATOR_H

#include <string>
#include <fstream>
class Obfuscator
{
public:
    Obfuscator(std::string oFP = "testFile.cc", std::string tFP = "obfuscatedFile.cc");
    void clearEnters(std::string originalFilePath, std::string targetFilePath);

    void spaceCleaning(std::string line);

    void changeVariablenames();

    void changeFunctionNames();

    void setOriginalFilePath(std::string path);

    void setTargetFilePath(std::string path);

    std::string getOriginalFilePath();

    std::string getTargetFilePath();

private:
    std::string originalFilePath;
    std::string targetFilePath;

    std::ifstream testFile;
    std::fstream obfuscatedFile;
};

#endif