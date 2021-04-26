#include <iostream>
#include <vector>
#include <string>
using namespace std; void printWords(const vector<string> msg); int regexTest1; string regexTest2; int main() { vector<string> msg{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!!"}; printWords(msg); } void printWords(const vector<string> msg) { for (const string& regexTest3 : msg) { cout << regexTest3 << " "; } cout << endl; } 