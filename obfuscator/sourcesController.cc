#include "sourcesController.h"
#include <iostream>
using namespace std;

void SourcesController::init(){
    printState("Opening source file...");
    loadSourceFile(sourceName);
    loadTargetFile(targetName);
    printState("Compiling source file...");
    if(!fileCompilation(sourceName))
        cerr << "Compilation of source file failed! Provide valid file" << endl;
    else
        cout << "   Compilation successful" << endl; 
}

void SourcesController::loadSourceFile(const string &name){
    sourceFile.open(name, fstream::in);
    if(!sourceFile)
        cerr << "Cannot open source file in this path!, path: "
                << name << endl; 
    else
        cout <<"    Loading file successful" << endl;
}
void SourcesController::loadTargetFile(const string &name){
    targetFile.open(name, fstream::in | fstream::out | fstream::trunc);
    if(!sourceFile){
        cerr << "Cannot open/create target file in this path!, path: "
                << name << endl; 
    }
}
bool SourcesController::fileCompilation(string filename){
    string systemCall("g++ " + filename);
    if(system(systemCall.c_str())!=0)
        return false;
    else
        return true;
}

void SourcesController::printState(string text){

    cout << "--------------------------------------\n"
        << text << endl
        << "--------------------------------------" << endl;
}