#include "IfConditionChanger.h"
#include <regex>

using namespace std;
void IfConditionChanger::rebuildIfStatement() {
  string code;
  regex ifRegex( "if\\(" );
  smatch m;
  while( src.readWord( &code ) ) {
    if( regex_match( code, m, ifRegex ) ) {
      string condition = searchForCondition();
      cout << "!!!!!! " << condition << endl;
      if( condition.rfind( ")" ) != string::npos ) {
        condition.pop_back();
      }
      cout << "!!!!!! " << condition << endl;
    }
  }
}

string IfConditionChanger::searchForCondition() {
  string result( "" );
  string lastWord;
  int numOfOpenings = 0;
  int numOfEndings = 0;
  do {
    src.readWord( &lastWord );
    result += lastWord;
    if( lastWord.find( '(' ) != string::npos ) {
      ++numOfOpenings;
    }
    if( lastWord.find( ')' ) != string::npos ) {
      ++numOfEndings;
    }
  } while( lastWord.find( ")" ) == string::npos ||
           ( numOfEndings - 1 ) != numOfOpenings );
  return result;
}
