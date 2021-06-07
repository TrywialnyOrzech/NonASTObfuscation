#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printWords( const vector<string> msg );
int returnVar();
char printCharacter( char c );
int globalVar;
string globalVarString;

int main() {
  // vector<string> msg{ "Hello", "C++",     "World",
  //                     "from",  "VS Code", "and the C++ extension!!" };
  string msg = "Hello C++ World from VS Code";
  // printWords( msg );
  if( msg != " " ) {
    globalVar = 1;
    cout << printCharacter( 'A' );
  } else {
    globalVar = returnVar();
    globalVarString = msg;
  }
  if( ( globalVar == 1 ) && ( globalVar != returnVar() ) ) {
    cout << "XD";
  }
  /********
   * It is sample comment to check quality of comments cleaning
   ********/
}

void printWords( const vector<string> msg ) {
  for( const string &word: msg ) {
    cout << word << " ";
  }
  cout << returnVar() << endl;
}
int returnVar() { return 0; }
char printCharacter( char c ) { return c + 1; }