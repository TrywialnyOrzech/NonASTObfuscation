#include <iostream>
#include <string>
#include <regex>
#include "obfuscator/obfuscator.h"

using namespace std;

int main(int argc, char** argv)
{
    Obfuscator obfuscator;
    size_t num_of_args = sizeof(argv)/sizeof(argv[0]);
    if(num_of_args > 1){
        string sourceName = argv[1];
        obfuscator.setOriginalFilePath(argv[1]);
        if(num_of_args > 2){
            string targetName = argv[2];
            obfuscator.setTargetFilePath(argv[2]);
        }
    }
    obfuscator.init();
    // obfuscator.clearEnters();
    obfuscator.changeVariablesNames();
    // obfuscator.changeFunctionNames();
    return 0;
}
