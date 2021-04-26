#include "FilesCompiler.h"
#include <iostream>
using namespace std;

bool FilesCompiler::fileCompilation(string filename){
    string systemCall("g++ " + filename);
    if(system(systemCall.c_str())!=0)
        return false;
    else
        return true;
}

bool FilesCompiler::initialCompilation(){
    src->printState("Compiling source file...");
    if(!fileCompilation(src->getOriginalFilePath())){

        cerr << "Compilation of source file failed! Provide valid file. Exitting.." << endl;
        return false;
    }
    else{
        cout << "   Compilation successful" << endl << endl; 
        return true;
    }
        
}