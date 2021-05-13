#include <iostream>
#include <string>
#include <vector>
using namespace std;
void printWords( const vector<string> msg );
int YgZ();
int YgZHykXYFy();
string Yg;
int main() {
  vector<string> msg{ "Hello", "C++",     "World",
                      "from",  "VS Code", "and the C++ extension!!" };
  printWords( msg );
}
void printWords( const vector<string> msg ) {
  for( const string &Yg: msg ) {
    cout << &Yg << " ";
  }
  cout << endl;
}
int YgZHykXYFy() { return 0; }