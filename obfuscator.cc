#include "obfuscator.h"

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
#include <regex>

using namespace std;

Obfuscator::Obfuscator(string oFP, string tFP)
{
    this->originalFilePath = oFP;
    this->targetFilePath = tFP;
    
    this->testFile.open("../../" + originalFilePath, fstream::in);
    this->obfuscatedFile.open("../../" + targetFilePath , fstream::out | fstream::trunc);
}

void Obfuscator::clearEnters(string originalFilePath, string targetFilePath)
{
    ifstream testFile("../../" + originalFilePath);
    fstream obfuscatedFile("../../" + targetFilePath);
    string code = "start reading";
    string toReplace = "word";
    if (testFile)
    {
        cout << "--------------------------------------\n"
             << code << endl
             << "--------------------------------------" << endl;
        while (!testFile.eof())
        {
            getline(testFile, code);
            if (code.find(toReplace) != string::npos)
            {
                code.replace(code.find(toReplace), toReplace.length(), "slowo");
            }
            obfuscatedFile << code;
            if (code.find("#include") != string::npos)
                obfuscatedFile << endl;
        }
        cout << "--------------------------------------\n"
             << "Obfuscation completed" << endl
             << "--------------------------------------" << endl;
    }
    else
    {
        cout << "Cannot open file!" << endl;
    }
    testFile.close();
    obfuscatedFile.close();
}

void Obfuscator::changeVariablenames()
{
    string code = "start reading";
    string toReplace = "word";

    map<string, string> variables;
    set<string> keyVariableWords{"int", "float", "string", "short", "long",
                                 "double", "char", "bool"};

    bool catchVariable = false;
    string variableName;
    regex mainFunctionReg("(main())");
    regex anyFun("(.*)(\\(.*\\);)");
    smatch m, n;

    int i = 1;
    while (testFile >> code)
    {
        if (catchVariable)
        {
            if (variables.find(code) == variables.end())
            {
                if (!regex_search(code, m, mainFunctionReg))
                {
                    variableName = code;
                    code = "weirdName8" + to_string(i);
                    variables[variableName] = code;
                    ++i;
                }
            }
            catchVariable = false;
        }
        for (auto it = keyVariableWords.begin(); it != keyVariableWords.end(); ++it)
        {
            // regex variableRegex(*it||*it+"\\s+")
            if (code.compare(*it) == 0 || code.compare(*it + "&") == 0)
                catchVariable = true;
        }
        for (const auto &[original, toChange] : variables)
        {
            if (code.compare(original) == 0)
            {
                code = toChange;
            }
        }
        if (code.compare("#include") == 0)
        {
            string nextLine;
            testFile >> nextLine;
            obfuscatedFile << code << ' ' << nextLine << endl;
        }
        else
            obfuscatedFile << code << ' ';
    }
}

void Obfuscator::changeFunctionNames(){
    string code;
    map<string, string> variables;
    set<string> keyVariableWords{"int", "float", "string", "short", "long",
                                 "double", "char", "bool", "void"};
    bool catchFuncion = false;
    smatch m;
    while(getline(testFile,code)){
        
        obfuscatedFile << "code: " << code << endl;
        for (auto it = keyVariableWords.begin(); it != keyVariableWords.end(); ++it)
        {
            regex variableRegex(*it+"\\s+\\w+\\(*");
            // cout << "- ";
            while (regex_search(code,m,variableRegex))
            {
                for(auto x:m)
                    obfuscatedFile << x << " ";
                code = m.suffix().str();
                obfuscatedFile << "New iteration:" << endl;
            }
                
        }
    }

    
}

void Obfuscator::setOriginalFilePath(string path)
{
    originalFilePath = path;
}
void Obfuscator::setTargetFilePath(string path)
{
    targetFilePath = path;
}

string Obfuscator::getOriginalFilePath()
{
    return originalFilePath;
}
string Obfuscator::getTargetFilePath()
{
    return targetFilePath;
}
