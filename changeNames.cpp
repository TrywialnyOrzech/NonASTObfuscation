#include <iostream>
#include <vector>
#include <string>
using namespace std; int main() { vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!!"}; for (const string& weirdName1 : msg) { cout << weirdName1 << " "; } cout << endl; } 