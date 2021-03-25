#ifndef OBFUSCATOR_H
#define OBFUSCATOR_H

#include <string>
class Obfuscator
{
public:
    Obfuscator(std::string oFP = "testFile.cpp", std::string tFP = "obfuscatedFile.cpp");
    void clearEnters(std::string originalFilePath, std::string targetFilePath);

    void spaceCleaning(std::string line);

    void changeVariablenames();

    void setOriginalFilePath(std::string path);

    void setTargetFilePath(std::string path);

    std::string getOriginalFilePath();

    std::string getTargetFilePath();

private:
    std::string originalFilePath;
    std::string targetFilePath;
};

#endif