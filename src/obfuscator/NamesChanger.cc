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
  string code = "start reading";
  string toReplace = "word";

  set<string> keyVariableWords{ "int",  "float",       "string", "short",
                                "long", "double",      "char",   "bool",
                                "void", "vector<\\w+>" };

  bool catchVariable = false;
  string variableName;
  regex mainFunctionReg( "(main())" );
  regex anyFun( "(.*)(\\(.*\\);)" );
  regex varNameOnly( "(;$)|$" );
  smatch m, n;
  enum Endings { none, semicolon, colon, brace };
  int i = 1;
  while( src.readWord( &code ) ) {
    for( auto it = keyVariableWords.begin(); it != keyVariableWords.end();
         ++it ) {
      const regex varRegex( "(" + *it + ")|(" + *it + "&)" );

      if( !ifDuplicate( &code ) ) {
        if( regex_match( code, m, varRegex ) ) {
          catchVariable = true;
          int ending = Endings::none;
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
      string nextLine = "";
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
  for( auto i = variables.begin(); i != variables.end(); ++i ) {
    if( name->compare( i->first ) == 0 ) {
      *name = i->second;
      return true;
    }
  }
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
//   string code;
//   map<string, string> variables;
//   set<string> keyVariableWords{ "int",    "float", "string", "short",
//   "long",
//                                 "double", "char",  "bool",   "void" };
//   bool catchFuncion = false;
//   smatch m;
//   while( getline( src->getSourceFile(), code ) ) {

//     src->getTargetFile() << "code: " << code << endl;
//     for( auto it = keyVariableWords.begin(); it != keyVariableWords.end();
//          ++it ) {
//       regex variableRegex( *it + "\\s+\\w+\\(*" );
//       // cout << "- ";
//       while( regex_search( code, m, variableRegex ) ) {
//         for( auto x: m )
//           src->getTargetFile() << x << " ";
//         code = m.suffix().str();
//         src->getTargetFile() << "New iteration:" << endl;
//       }
//     }
//   }
// }
