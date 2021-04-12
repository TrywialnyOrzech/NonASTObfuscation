#ifndef SOURCESCONTROLLER_H
#define SOURCESCONTROLLER_H

#include <string>
#include <fstream>
class SourcesController{
    public:
        SourcesController(std::string &src, std::string &tar) : sourceName(src), targetName(tar) {}
        ~SourcesController(){sourceFile.close(); targetFile.close();}
        void loadSourceFile(const std::string &name);
        void loadTargetFile(const std::string &name);
        void init();
        bool fileCompilation(std::string filename);
        bool prepareForObfuscation();
        void printState(std::string text);
    
    protected:
        std::string sourceName;
        std::string targetName;
        std::fstream sourceFile;
        std::fstream targetFile;
};

#endif