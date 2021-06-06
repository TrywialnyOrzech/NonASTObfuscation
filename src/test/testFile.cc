#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printWords( const vector<string> msg );

int main() {
  vector<string> msg{ "Hello", "C++",     "World",
                      "from",  "VS Code", "and the C++ extension!!" };

  printWords( msg );
}

void printWords( const vector<string> msg ) {
  for( const string &word: msg ) {
    cout << word << " ";
  }
  cout << endl;
}
