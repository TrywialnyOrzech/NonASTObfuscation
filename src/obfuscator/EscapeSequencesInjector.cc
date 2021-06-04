#include "EscapeSequencesInjector.h"

#include <iostream>
#include <sstream>
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
  "\"ABCDEFGHIJKLMNOPRSTUWXYZ\";\nstring numbers = \"0123456789\";\nstring "
  "mixed = \"aZ95Gj asd asd asd\";\n}";

  const regex escSeqReg(
  "(\")((\\w)+[ ]?)+(\")" );          // string can not start with space
  foundStrings = findRegexMatches( code, escSeqReg );
  for( int i = 0; i < foundStrings.size(); ++i ) {
    cout << "ESCAPE SEQUENCES" << endl;
    cout << foundStrings[i] << endl;
  }
  return 0;
}

bool EscapeSequencesInjector::findPositions() {
  // get target file contents to string (to fix)
  string code =
  "#include <iostream>\nusing namespace std;\n\nint main() {\nstring letters = "
  "\"abcdefghijklmnoprstuwxyz\";\nstring capitalLetters = "
  "\"ABCDEFGHIJKLMNOPRSTUWXYZ\";\nstring numbers = \"0123456789\";\nstring "
  "mixed = \"aZ95Gj asd asd asd\";\n}";
  int bypass = 0;
  if( foundStrings.size() == 0 ) {
    cerr << "foundStrings vector is empty. Perhaps findStrings() "
            "should be ran first?"
         << endl;
    return 1;
  }
  for( int i = 0; i < foundStrings.size(); ++i ) {
    string func = foundStrings[i];
    foundPositions.push_back( code.find( func, bypass ) );
    bypass = foundPositions[i];
  }
  return 0;
}

bool EscapeSequencesInjector::injectEscapeSequences() {
  // get target file contents to string (to fix)
  string code =
  "#include <iostream>\nusing namespace std;\n\nint main() {\nstring letters = "
  "\"abcdefghijklmnoprstuwxyz\";\nstring capitalLetters = "
  "\"ABCDEFGHIJKLMNOPRSTUWXYZ\";\nstring numbers = \"0123456789\";\nstring "
  "mixed = \"aZ95Gj asd asd asd\";\n}";

  //   const size_t singleLiteralHexLength = 4;
  //   size_t offsetSum = 0;
  //   for( int i = 0; i < foundStrings.size(); ++i ) {
  //     string currentString = foundStrings[i];
  //     size_t currentOffset =
  //     offsetSum + ( currentString.length() * singleLiteralHexLength -
  //                   singleLiteralHexLength );
  //     for( int j = 0; j < currentString.size(); ++i ) {
  //       char currentChar = currentString[i];
  //       stringstream ss;
  //       ss << hex << (int)currentChar;
  //       string hexCharValue = ss.str();

  //       // replace char in string with \xxx
  //       // dodaj offsetSum
  //     }
  cout << " " << endl;
  return 0;
}

bool EscapeSequencesInjector::convertCharsToHex( string str ) {
  const size_t CHAR_LENGTH = 1;
  const int SINGLE_OFFSET = 4;
  size_t offset = 0;
  for( int i = 0; i < str.length(); ++i ) {
    offset = i * SINGLE_OFFSET;

    char currentChar = str[i + (int)offset];
    stringstream ss;
    ss << hex << (int)currentChar;
    string hexCharValue = ss.str();
    cout << getEscapeSequence( hexCharValue ) << endl;
    // str.replace( i + offset, CHAR_LENGTH, "\\x"  + hexCharValue );
  }
  cout << str << endl;
  return 0;
}

string EscapeSequencesInjector::getEscapeSequence( string hexVal ) {
    // Letters
    if (hexVal == "61"){
        string x = "\x61";
        return x;
    }

    if (hexVal == "62")
        return "\x62";
    if (hexVal == "63")
        return "\x63";
    if (hexVal == "64")
        return "\x64";
    if (hexVal == "65")
        return "\x65";
    if (hexVal == "66")
        return "\x66";
    if (hexVal == "67")
        return "\x67";
    if (hexVal == "68")
        return "\x68";
    if (hexVal == "69")
        return "\x69";
    if (hexVal == "6a")
        return "\x6a";
    if (hexVal == "6b")
        return "\x6b";
    if (hexVal == "6c")
        return "\x6c";
    if (hexVal == "6d")
        return "\x6d";
    if (hexVal == "6e")
        return "\x6e";
    if (hexVal == "6f")
        return "\x6f";
    if (hexVal == "70")
        return "\x70";
    if (hexVal == "71")
        return "\x71";
    if (hexVal == "72")
        return "\x72";
    if (hexVal == "73")
        return "\x73";
    if (hexVal == "74")
        return "\x74";
    if (hexVal == "75")
        return "\x75";
    if (hexVal == "76")
        return "\x76";
    if (hexVal == "77")
        return "\x77";
    if (hexVal == "78")
        return "\x78";
    if (hexVal == "79")
        return "\x79";
    if (hexVal == "7a")
        return "\x7a";
    // Capital letters
    if (hexVal == "41")
        return "\x41";
    if (hexVal == "42")
        return "\x42";
    if (hexVal == "43")
        return "\x43";
    if (hexVal == "44")
        return "\x44";
    if (hexVal == "45")
        return "\x45";
    if (hexVal == "46")
        return "\x46";
    if (hexVal == "47")
        return "\x47";
    if (hexVal == "48")
        return "\x48";
    if (hexVal == "49")
        return "\x49";
    if (hexVal == "4a")
        return "\x4a";
    if (hexVal == "4b")
        return "\x4b";
    if (hexVal == "4c")
        return "\x4c";
    if (hexVal == "4d")
        return "\x4d";
    if (hexVal == "4e")
        return "\x4e";
    if (hexVal == "4f")
        return "\x4f";
    if (hexVal == "50")
        return "\x50";
    if (hexVal == "51")
        return "\x51";
    if (hexVal == "52")
        return "\x52";
    if (hexVal == "53")
        return "\x53";
    if (hexVal == "54")
        return "\x54";
    if (hexVal == "55")
        return "\x55";
    if (hexVal == "56")
        return "\x56";
    if (hexVal == "57")
        return "\x57";
    if (hexVal == "58")
        return "\x58";
    if (hexVal == "59")
        return "\x59";
    if (hexVal == "5a")
        return "\x5a";
    // Numbers
    if (hexVal == "30")
        return "\x30";
    if (hexVal == "31")
        return "\x31";
    if (hexVal == "32")
        return "\x32";
    if (hexVal == "33")
        return "\x33";
    if (hexVal == "34")
        return "\x34";
    if (hexVal == "35")
        return "\x35";
    if (hexVal == "36")
        return "\x36";
    if (hexVal == "37")
        return "\x37";
    if (hexVal == "38")
        return "\x38";
    if (hexVal == "39")
        return "\x39";
    // Space and _
    if (hexVal == "20")
        return "\x20";
    if (hexVal == "5f")
        return "\x5f";
    cerr << "Letter hex representation not found";
    exit(1);
}