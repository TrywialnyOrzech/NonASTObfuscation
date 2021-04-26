#include "SourcesController.h"
#include <iostream>
#include <fstream>
using namespace std;

void SourcesController::init(){
    printState("Opening source file...");
    loadSourceFile(sourceName);
    loadTargetFile(targetName);
}

void SourcesController::loadSourceFile(const string &name){
    sourceFile.open(name, fstream::in);
    if(!sourceFile)
        cerr << "Cannot open source file in this path!, path: "
                << name << endl; 
    else
        cout <<"    Loading file successful" << endl << endl;
}
void SourcesController::loadTargetFile(const string &name){
    targetFile.open(name, fstream::in | fstream::out | fstream::trunc);
    if(!sourceFile){
        cerr << "Cannot open/create target file in this path!, path: "
                << name << endl; 
    }
}

void SourcesController::printState(string text){

    cout << "--------------------------------------\n"
        << text << endl
        << "--------------------------------------" << endl;
}

void SourcesController::setOriginalFilePath( string path ) { sourceName = path; }
void SourcesController::setTargetFilePath( string path ) { targetName = path; }

string SourcesController::getOriginalFilePath() { return sourceName; }
string SourcesController::getTargetFilePath() { return targetName; }

string SourcesController::readWord() {
    string result;
    if(sourceFile >> result)
        return result;
    else{
        return "";
    }
}

void SourcesController::writeWord(string word){
    targetFile << word;
}