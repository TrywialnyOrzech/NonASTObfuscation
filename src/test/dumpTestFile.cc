#include <iostream>
#include <string>
#include <vector>
using namespace std; void b(const vector <string> msg ); int main(){ vector<string> MU{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!!" }; b(MU); } void b(const vector<string> MU) { for( const string &FtPj:MU) { cout << &FtPj<< " "; } cout << endl; } 