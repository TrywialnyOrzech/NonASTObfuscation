#include <algorithm>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include "obfuscator.h"

using namespace std;

int main()
{
    Obfuscator obfuscator("testFile.cpp","changeNames.cpp");
    cout << obfuscator.getTargetFilePath() << endl;
    obfuscator.changeVariablenames();
    return 0;
}
