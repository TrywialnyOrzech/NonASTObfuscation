#include "CommentsCleaner.h"
#include <regex>

using namespace std;
void CommentsCleaner::cleanComments() {
  string code;
  regex comment( "^//+" );
  regex bigComment( "^/\\*+" );
  smatch m;
  while( src.readWord( &code ) ) {
    if( regex_match( code, m, comment ) ) {
      src.readLine( &code, READSOURCE );
    } else if( regex_match( code, m, bigComment ) ) {
      fetchWholeComment();
    } else {
      if( code.compare( "#include" ) == 0 ) {
        string nextLine( "" );
        src.readWord( &nextLine );
        src.writeWord( code );
        src.writeWord( " " );
        src.writeWord( nextLine );
        src.writeWord( "\n" );
      } else {
        src.writeWord( code );
        src.writeWord( " " );
      }
    }
  }
}

void CommentsCleaner::fetchWholeComment() {
  string result( "" );
  string lastWord;
  regex endOfComment( "(.*)(\\*/$)" );
  smatch m;
  do {
    src.readWord( &lastWord );
    result += lastWord;
  } while( !regex_match( lastWord, m, endOfComment ) );
}