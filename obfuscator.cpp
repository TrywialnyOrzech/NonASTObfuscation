#include "obfuscator.h"

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
#include <boost/regex.hpp>

using namespace std;

Obfuscator::Obfuscator(string oFP, string tFP)
{
    this->originalFilePath = oFP;
    this->targetFilePath = tFP;
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

void Obfuscator::spaceCleaning(string line)
{
    set<string> keyWords{"int", "float", "string", "short", "long", "unsigned",
                         "double", "char", "bool", "using", "namespace"};
    set<size_t> savedSpaces;
    for (auto it = keyWords.begin(); it != keyWords.end(); ++it)
    {
        if (line.find(*it) != string::npos)
            savedSpaces.insert(line.find(*it) + (*it).length());
        cout << *it << " ";
    }
    int pos = 0;
    do
    {
        size_t place = line.find(' ', pos);
        pos = place + 1;
        cout << pos << endl;
        if (savedSpaces.find(place) == savedSpaces.end())
            line.erase(line.begin() + place);
        // for_each(begin(savedSpaces), end(savedSpaces), [](size_t x){return x-1;});
        // cout << place+' ';
        // transform(begin(savedSpaces),end(savedSpaces),begin(savedSpaces),[](size_t
        // x){if(x>0)return x-1; else return x;});

    } while (line.find(' ', pos) != string::npos);
}
void Obfuscator::changeVariablenames()
{
    ifstream testFile("../../" + originalFilePath);
    fstream obfuscatedFile("../../" + targetFilePath);
    string code = "start reading";
    string toReplace = "word";

    map<string, string> variables;
    set<string> keyVariableWords{"int", "float", "string", "short", "long",
                         "double", "char", "bool"};

    bool catchVariable = false;
    string variableName;
    int i = 1;
    while (testFile >> code)
    {

        if (catchVariable)
        {
            if (variables.find(code) == variables.end())
            {
                if (code.compare("main()") != 0)
                {
                    variableName = code;
                    code = "weirdName" + to_string(i);
                    variables[variableName] = code;
                    ++i;
                }
            }
            catchVariable = false;
        }
        for (auto it = keyVariableWords.begin(); it != keyVariableWords.end(); ++it)
        {
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