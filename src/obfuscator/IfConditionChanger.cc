#include "IfConditionChanger.h"
#include <regex>

using namespace std;
void IfConditionChanger::rebuildIfStatement() {
  string code;
  regex ifRegex( "if" );
  smatch m;
  while( src.readWord( &code ) ) {
    if( regex_match( code, m, ifRegex ) ) {
    }
  }
}
