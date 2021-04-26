#ifndef SOURCESCONTROLLER_H
#define SOURCESCONTROLLER_H

#include <string>
#include <fstream>
class SourcesController{
    public:
        SourcesController(std::string src = "../testFile.cc", std::string tar = "../obfuscatedFile.cc") : sourceName(src), targetName(tar) {}
        ~SourcesController(){if(sourceFile)sourceFile.close(); if(targetFile)targetFile.close();}
        void loadSourceFile(const std::string &name);
        void loadTargetFile(const std::string &name);
        void init();
        void close(){sourceFile.close(); targetFile.close();}
        void printState(std::string text);
        void setOriginalFilePath(std::string path);

        void setTargetFilePath(std::string path);

        std::string getOriginalFilePath();

        std::string getTargetFilePath();

        std::fstream getSourceFile();

        std::fstream getTargetFile();

        std::string readWord();

        void writeWord(std::string word);

        SourcesController( const SourcesController& src){
            sourceName = src.sourceName;
            targetName = src.targetName;
        }

    protected:
        std::string sourceName;
        std::string targetName;
        std::fstream sourceFile;
        std::fstream targetFile;
};

#endif