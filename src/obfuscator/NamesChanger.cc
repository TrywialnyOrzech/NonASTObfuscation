#include "NamesChanger.h"

#include <algorithm>
#include <ctime>
#include <fstream>
#include <iostream>
#include <regex>
#include <set>

using namespace std;

void NamesChanger::changeVariablesNames() {
  srand( (unsigned)time( NULL ) );
  string code;
  set<string> keyVariableWords{ "int",  "float",       "string", "short",
                                "long", "double",      "char",   "bool",
                                "void", "vector<\\w+>" };

  bool catchVariable = false;
  smatch m;
  enum Endings { none, semicolon, colon, brace };
  while( src.readWord( &code ) ) {
    for( auto it = keyVariableWords.begin(); it != keyVariableWords.end();
         ++it ) {
      const regex varRegex( "(" + *it + ")|(" + *it + "&)" );

      if( !ifDuplicate( &code ) ) {
        if( regex_match( code, m, varRegex ) ) {
          int ending = Endings::none;
          catchVariable = true;
          string nextLine = "";
          src.readWord( &nextLine );
          if( !ifDuplicate( &nextLine ) ) {
            if( nextLine.find( "main()" ) == string::npos ) {
              string newName = genRandomName( rand() % 10 + 1 );
              if( nextLine.find( "()" ) != string::npos )
                newName += "()";
              else if( nextLine.find( "(" ) != string::npos )
                newName += "(";
              if( nextLine.find( "&" ) != string::npos ) {
                newName.insert( 0, "&" );
                nextLine.erase( nextLine.begin() );
              }
              clearAndTagEnding( Endings::semicolon, ';', &nextLine, &ending );
              clearAndTagEnding( Endings::colon, ':', &nextLine, &ending );
              clearAndTagEnding( Endings::brace, '{', &nextLine, &ending );
              variables[nextLine] = newName;
              nextLine = newName;
              switch( ending ) {
              case Endings::none:
                break;
              case Endings::semicolon:
                nextLine.push_back( ';' );
                break;
              case Endings::colon:
                nextLine.push_back( ':' );
                break;
              case Endings::brace:
                nextLine.push_back( '{' );
                break;

              default:
                break;
              }
            }
          }
          src.writeWord( code );
          src.writeWord( " " );
          src.writeWord( nextLine );
        }
      } else {
        src.writeWord( code );
        src.readWord( &code );
      }
    }
    if( code.compare( "#include" ) == 0 ) {
      string nextLine( "" );
      src.readWord( &nextLine );
      src.writeWord( code );
      src.writeWord( " " );
      src.writeWord( nextLine );
      src.writeWord( "\n" );
    } else if( !catchVariable ) {
      src.writeWord( code );
      src.writeWord( " " );
    } else
      catchVariable = false;
  }
}
bool NamesChanger::ifDuplicate( string *name ) {
  int addSemicolon = 0;
  clearAndTagEnding( 1, ';', name, &addSemicolon );
  for( auto i = variables.begin(); i != variables.end(); ++i ) {
    if( name->compare( i->first ) == 0 ) {
      *name = i->second;
      if( addSemicolon == 1 )
        name->push_back( ';' );
      return true;
    }
  }
  if( addSemicolon == 1 )
    name->push_back( ';' );
  return false;
}

string NamesChanger::genRandomName( const int length ) {
  string result;
  static const char lettersBank[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                    "abcdefghijklmnopqrstuvwxyz";

  result.reserve( length );
  for( int i = 0; i < length; ++i )
    result += lettersBank[rand() % ( sizeof( lettersBank ) - 1 )];
  return result;
}

void NamesChanger::clearAndTagEnding( int type, char character, string *word,
                                      int *result ) {
  if( word->find( character ) != string::npos ) {
    word->erase( word->end() - 1 );
    *result = type;
  }
}
void NamesChanger::changeFunctionNames() {}
