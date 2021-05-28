#include <iostream>
#include <string>
#include <vector>
using namespace std; void gj(const vector <string> msg ); int main(){ vector<string> wxOZRVEx{"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!!" }; gj(wxOZRVEx); } void gj(const vector<string> wxOZRVEx) { for( const string &a:wxOZRVEx) { cout << &a<< " "; } cout << endl; } 