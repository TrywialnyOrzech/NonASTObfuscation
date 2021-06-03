#include "EscapeSequencesInjector.h"

#include <iostream>
#include <string>

using namespace std;

vector<string> EscapeSequencesInjector::findRegexMatches( string str,
                                                          regex reg ) {
  vector<string> results;
  sregex_iterator currentMatch( str.begin(), str.end(), reg );
  sregex_iterator lastMatch;
  while( currentMatch != lastMatch ) {
    smatch match = *currentMatch;
    results.push_back( match.str() );
    ++currentMatch;
  }
  return results;
}

bool EscapeSequencesInjector::findStrings() {
  // get target file contents to string (to fix)
  string code =
  "#include <iostream>\nusing namespace std;\n\nint main() {\nstring letters = "
  "\"abcdefghijklmnoprstuwxyz\";\nstring capitalLetters = "
  "\"ABCDEFGHIJKLMNOPRSTUWXYZ\";\nstring numbers = \"0123456789\";\nstring mixed = \"aZ95Gj asd asd asd\";\n}";

  const regex escSeqReg( "(\")((\\w)+[ ]?)+(\")" );    // string can not start with space
  foundStrings = findRegexMatches( code, escSeqReg );
  for( int i = 0; i < foundStrings.size(); ++i ) {
    cout << "ESCAPE SEQUENCES" << endl;
    cout << foundStrings[i] << endl;
  }
  return 0;
}