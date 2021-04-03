#include <iostream>
#include <string>
#include <regex>
#include "obfuscator.h"

using namespace std;

int main()
{
    Obfuscator obfuscator("testFile.cc","obfuscatedFile.cc");
    // obfuscator.changeVariablenames();
    obfuscator.changeFunctionNames();
    return 0;
}
