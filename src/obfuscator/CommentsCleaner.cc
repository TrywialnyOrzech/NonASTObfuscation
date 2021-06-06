#include "CommentsCleaner.h"
#include <regex>

using namespace std;
void CommentsCleaner::cleanComments() {
  string code;
  regex comment( "^//" );
  smatch m;
  while( src.readWord( &code ) ) {
    if( regex_match( code, m, comment ) ) {
      src.readLine( &code, READSOURCE );
      cout << code;
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
}          //