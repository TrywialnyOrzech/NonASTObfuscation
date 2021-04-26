#include "Obfuscator.h"

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <algorithm>
#include <regex>

using namespace std;



void Obfuscator::clearEnters()
{
    string code = "start reading";
    string toReplace = "word";
    if (sourceFile)
    {
        printState("Obfuscation started");
        while (!sourceFile.eof())
        {
            getline(sourceFile, code);
            if (code.find(toReplace) != string::npos)
            {
                code.replace(code.find(toReplace), toReplace.length(), "slowo");
            }
            targetFile << code;
            if (code.find("#include") != string::npos)
                targetFile << endl;
        }
        cout << "   Obfuscation completed" << endl;
    }
    else
    {
        
        cout << "Cannot open file!" << endl;
    }
    sourceFile.close();
    targetFile.close();
}

void Obfuscator::changeVariablesNames()
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
    regex varNameOnly("(;$)|$");
    smatch m, n;

    int i = 1;
    while (sourceFile >> code)
    {
        if (catchVariable)
        {
            if (variables.find(code) == variables.end())
            {
                if (regex_match(code,m,varNameOnly))
                   for (auto x:m) cout << "srednik" << x << " ";
                if (!regex_search(code, m, mainFunctionReg))
                {
                    variableName = code;
                    code = "regexTest" + to_string(i);
                    variables[variableName] = code;
                    ++i;
                }
            }
            catchVariable = false;
        }
        for (auto it = keyVariableWords.begin(); it != keyVariableWords.end(); ++it)
        {
            const regex varRegex("("+*it+")|("+*it+"&)");
            const regex delimeterReg(";");
            if (regex_match(code,m,varRegex)){
                // for (auto x:m) cout << x << " ";
                catchVariable = true;
                // cout << endl;
                // string nextLine;
                // sourceFile >> nextLine;
                // cout << nextLine << endl;

            }
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
            sourceFile >> nextLine;
            targetFile << code << ' ' << nextLine << endl;
        }
        else
            targetFile << code << ' ';
    }
}

void Obfuscator::changeFunctionNames(){
    string code;
    map<string, string> variables;
    set<string> keyVariableWords{"int", "float", "string", "short", "long",
                                 "double", "char", "bool", "void"};
    bool catchFuncion = false;
    smatch m;
    while(getline(sourceFile,code)){
        
        targetFile << "code: " << code << endl;
        for (auto it = keyVariableWords.begin(); it != keyVariableWords.end(); ++it)
        {
            regex variableRegex(*it+"\\s+\\w+\\(*");
            // cout << "- ";
            while (regex_search(code,m,variableRegex))
            {
                for(auto x:m)
                    targetFile << x << " ";
                code = m.suffix().str();
                targetFile << "New iteration:" << endl;
            }
                
        }
    }
}

void Obfuscator::setOriginalFilePath(string path)
{
    sourceName = path;
}
void Obfuscator::setTargetFilePath(string path)
{
    targetName = path;
}

string Obfuscator::getOriginalFilePath()
{
    return sourceName;
}
string Obfuscator::getTargetFilePath()
{
    return targetName;
}
