#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printWords( const vector<string> msg );
int xz();
int q;
string dr;
int main() {
  vector<string> msg{ "Hello", "C++",     "World",
                      "from",  "VS Code", "and the C++ extension!!" };
  printWords( msg );
}
void printWords( const vector<string> msg ) {
  for( const string &NUWEK: msg ) {
    cout << NUWEK << " ";
  }
  cout << endl;
}
int xz() { return 0; }
