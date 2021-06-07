#include "TrigraphSequencesInjector.h"

#include <iostream>
#include <string>

using namespace std;

vector<string> TrigraphSequencesInjector::findRegexMatches( string str,
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

bool TrigraphSequencesInjector::findReplacements() {
  string code = src.readWholeFile( READSOURCE );
  const regex triSeqReg( "(\\[|\\]|\\{|\\}|#|\\^|\\||~)" );
  foundReplacements = findRegexMatches( code, triSeqReg );
  cout << "TRIGRAPH SEQ" << endl;
  for( int i = 0; i < foundReplacements.size(); ++i ) {
    cout << foundReplacements[i] << endl;
  }
  return 0;
}

bool TrigraphSequencesInjector::findPositions() {
  string code = src.readWholeFile( READSOURCE );
  int bypass = 0;
  if( foundReplacements.size() == 0 ) {
    cerr << "foundReplacements vector is empty. Perhaps findReplacements() "
            "should be ran first?"
         << endl;
    return 1;
  }
  for( int i = 0; i < foundReplacements.size(); ++i ) {
    string func = foundReplacements[i];
    foundPositions.push_back( code.find( func, bypass ) );
    bypass = foundPositions[i];
  }
  return 0;
}

bool TrigraphSequencesInjector::injectTrigraphSequences() {
  string code = src.readWholeFile( READSOURCE );
  size_t offset = 0;          // offset for increased functions positions while
                              // adding trigraph sequences
  const int trigraphSequenceLength = 3;
  const int replacementLength = 1;
  for( int i = 0; i < foundPositions.size(); ++i ) {
    offset = ( size_t )( ( trigraphSequenceLength - 1 ) * i );
    string replacementStr = foundReplacements[i];
    char replacement = replacementStr[0];
    switch( replacement ) {
    case '[':
      code.replace( foundPositions[i] + offset, replacementLength, "??(" );
      break;
    case ']':
      code.replace( foundPositions[i] + offset, replacementLength, "??)" );
      break;
    case '{':
      code.replace( foundPositions[i] + offset, replacementLength, "??<" );
      break;
    case '}':
      code.replace( foundPositions[i] + offset, replacementLength, "??>" );
      break;
    case '#':
      code.replace( foundPositions[i] + offset, replacementLength, "??=" );
      break;
    case '^':
      code.replace( foundPositions[i] + offset, replacementLength, "??'" );
      break;
    case '|':
      code.replace( foundPositions[i] + offset, replacementLength, "??!" );
      break;
    case '~':
      code.replace( foundPositions[i] + offset, replacementLength, "??-" );
      break;
    default:
      cerr << "Trigraph sequence replacement not recognized. Check "
              "foundReplacements vector values."
           << endl;
      break;
    }
  }
  src.writeWord( code );
  return 0;
}

void TrigraphSequencesInjector::runTrigraphSequencesInjector() {
  findReplacements();
  src.reload();
  findPositions();
  src.reload();
  injectTrigraphSequences();
}