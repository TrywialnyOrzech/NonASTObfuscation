#include "NamesChanger.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <set>

using namespace std;

// void NamesChanger::clearEnters() {
//   string code = "start reading";
//   string toReplace = "word";
//   if( src->getSourceFile() ) {
//     src->printState( "Obfuscation started" );
//     while( !src->getSourceFile().eof() ) {
//       getline( src->getSourceFile(), code );
//       if( code.find( toReplace ) != string::npos ) {
//         code.replace( code.find( toReplace ), toReplace.length(), "slowo" );
//       }
//       src->getTargetFile() << code;
//       if( code.find( "#include" ) != string::npos )
//         src->getTargetFile() << endl;
//     }
//     cout << "   Obfuscation completed" << endl;
//   } else {

//     cout << "Cannot open file!" << endl;
//   }
// }

void NamesChanger::changeVariablesNames() {
  string code = "start reading";
  string toReplace = "word";

  map<string, string> variables;
  set<string> keyVariableWords{ "int",  "float",  "string", "short",
                                "long", "double", "char",   "bool" };

  bool catchVariable = false;
  string variableName;
  regex mainFunctionReg( "(main())" );
  regex anyFun( "(.*)(\\(.*\\);)" );
  regex varNameOnly( "(;$)|$" );
  smatch m, n;
  int i = 1;
  while( ( code = src->readWord() ).compare("") != 0 ) {
    for( auto it = keyVariableWords.begin(); it != keyVariableWords.end();
         ++it ) {
      const regex varRegex( "(" + *it + ")|(" + *it + "&)" );
      const regex delimeterReg( ";" );
      if( regex_match( code, m, varRegex ) ) {
        catchVariable = true;
        string nextLine = src->readWord();
        src->writeWord(code);
        src->writeWord(" ");
        src->writeWord(nextLine);
      }
    }
    for( const auto &[original, toChange]: variables ) {
      if( code.compare( original ) == 0 ) {
        code = toChange;
      }
    }
    if( code.compare( "#include" ) == 0 ) {
      string nextLine = src->readWord();
      src->writeWord(code);
      src->writeWord(" ");
      src->writeWord(nextLine);
      src->writeWord("\n");
    } else if( !catchVariable ) {
      src->writeWord(code);
      src->writeWord(" ");
    } else
      catchVariable = false;
  }
}

void NamesChanger::changeFunctionNames() {}
//   string code;
//   map<string, string> variables;
//   set<string> keyVariableWords{ "int",    "float", "string", "short", "long",
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
