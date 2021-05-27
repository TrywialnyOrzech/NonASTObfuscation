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
  while( ( code = src.readWord() ).compare( "" ) != 0 ) {
    for( auto it = keyVariableWords.begin(); it != keyVariableWords.end();
         ++it ) {
      const regex varRegex( "(" + *it + ")|(" + *it + "&)" );

      if( !ifDuplicate( &code ) ) {
        if( regex_match( code, m, varRegex ) ) {
          catchVariable = true;
          Endings ending = none;
          string nextLine = src.readWord();
          if( !ifDuplicate( &nextLine ) ) {
            if( nextLine.find( "main()" ) == string::npos ) {
              string newName = gen_random_name( rand() % 10 + 1 );
              if( nextLine.find( "()" ) != string::npos )
                newName += "()";
              else if( nextLine.find( "(" ) != string::npos )
                newName += "(";
              if( nextLine.find( ";" ) != string::npos ) {
                ending = semicolon;
                nextLine.erase( nextLine.end() - 1 );
              }
              if( nextLine.find( ":" ) != string::npos ) {
                ending = colon;
                nextLine.erase( nextLine.end() - 1 );
              }
              if( nextLine.find( "{" ) != string::npos ) {
                ending = brace;
                nextLine.erase( nextLine.end() - 1 );
              }

              if( nextLine.find( "&" ) != string::npos ) {
                newName.insert( 0, "&" );
                nextLine.erase( nextLine.begin() );
              }
              variables[nextLine] = newName;
              nextLine = newName;
              switch( ending ) {
              case none:
                break;
              case semicolon:
                nextLine.push_back( ';' );
                break;
              case colon:
                nextLine.push_back( ':' );
                break;
              case brace:
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
        code = src.readWord();
      }
    }
    if( code.compare( "#include" ) == 0 ) {
      string nextLine = src.readWord();
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
  cout << "Variables:\n\n";
  for( auto i = variables.begin(); i != variables.end(); ++i ) {
    cout << endl << i->first << ' ' << i->second << endl;
  }
}
bool NamesChanger::ifDuplicate( string *name ) {
  for( auto i = variables.begin(); i != variables.end(); ++i ) {
    if( name->compare( i->first ) == 0 ) {
      cout << *name << ": przed zmiana" << endl;
      *name = i->second;
      cout << *name << ": po zmiana" << endl;
      return true;
    }
  }
  return false;
}

string NamesChanger::gen_random_name( const int length ) {
  string result;
  static const char lettersBank[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                    "abcdefghijklmnopqrstuvwxyz";

  result.reserve( length );
  for( int i = 0; i < length; ++i )
    result += lettersBank[rand() % ( sizeof( lettersBank ) - 1 )];
  return result;
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
