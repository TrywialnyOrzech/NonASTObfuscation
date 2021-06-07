#include "NOPInjector.h"

#include <iostream>
#include <string>

using namespace std;

void NOPInjector::randomNoGen() {
  srand( time( NULL ) );
  randomX = rand() % 10 + 1;
  randomY = rand() % 50 + 1;
}

bool NOPInjector::findFuncDefinitions() {
  // get target file contents to string (to fix)
  // string code =
  // "#include <iostream>\n\n int main() {\nint xsowy = 12;\nfloat "
  // "ygrekowy = 3.33;\ny=2.4;\nx = 4;\n"
  // "return 0;\n}\n\nvoid sayHello() {\nstd::cout << \"Hello\" << "
  // "std::endl;\n}\nfloat compute(int x) {\nfloat z = 2.53*x;\nreturn z;\n}";
  string code = src.readWholeFile( READSOURCE );
  const regex functionsReg(
  "(bool||char||double||float||int||long||short||void)[ "
  "][a-zA-Z]+(\\(((\\w)+[ ]+(\\w)+(,)*[ ]*)*\\))+[ ](\\{)+" );
  foundFunctions = findRegexMatches( code, functionsReg );
  if( foundFunctions.empty() ) {
    cerr
    << "foundFunctions from NOPInjector class has no values. Unable to proceed."
    << endl;
    return 1;
  }
  return 0;
}

bool NOPInjector::findVarDefinitions() {
  // get target file contents to string (to fix)
  // string code =
  // "#include <iostream>\n\n int main() {\nint xsowy = 12;\nfloat "
  // "ygrekowy = 3.33;\ny=2.4;\nx = 4;\n"
  // "return 0;\n}\n\nvoid sayHello() {\nstd::cout << \"Hello\" << "
  // "std::endl;\n}\nfloat compute(int x) {\nfloat z = 2.53*x;\nreturn z;\n}";
  string code = src.readWholeFile( READSOURCE );
  const regex varReg(
  "(bool||char||double||float||int||long||short||void)[ ][a-zA-Z]+[ ](=)[ "
  "][0-9]+(.)?[0-9]*" );
  foundVars = findRegexMatches( code, varReg );
  if( foundVars.empty() ) {
    cerr << "foundVars from NOPInjector class has no values. Unable to proceed."
         << endl;
    return 1;
  }
  for( int i = 0; i < foundVars.size(); ++i ) {
    cout << foundVars[i] << endl;
  }
  return 0;
}

vector<string> NOPInjector::findRegexMatches( string str, regex reg ) {
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

bool NOPInjector::findPositions( bool choice ) {

  string code = src.readWholeFile( READSOURCE );
  // get target file contents to string (to fix)
  // string code =
  // "#include <iostream>\n\n int main() {\nint xsowy = 12;\nfloat "
  // "ygrekowy = 3.33;\ny=2.4;\nx = 4;\n"
  // "return 0;\n}\n\nvoid sayHello() {\nstd::cout << \"Hello\" << "
  // "std::endl;\n}\nfloat compute(int x) {\nfloat z = 2.53*x;\nreturn z;\n}";
  vector<size_t> positions;
  int bypass = 0;
  if( choice ) {
    if( foundFunctions.size() == 0 ) {
      cerr << "foundFunctions vector is empty. Perhaps findFuncDefinitions() "
              "should be ran first?"
           << endl;
      return 1;
    }
    for( int i = 0; i < foundFunctions.size(); ++i ) {
      string func = foundFunctions[i];
      positions.push_back( code.find( func, bypass ) );
      bypass = positions[i];
    }
    funcPositions = positions;
  } else {
    if( foundVars.size() == 0 ) {
      cerr << "foundVars vector is empty. Perhaps findFuncDefinitions should "
              "be ran first?"
           << endl;
      return 1;
    }
    for( int i = 0; i < foundVars.size(); ++i ) {
      string var = foundVars[i];
      positions.push_back( code.find( var, bypass ) );
      bypass = positions[i];
    }
    varPositions = positions;
    for( int i = 0; i < positions.size(); ++i ) {
      cout << "DUPSKOOOO" << endl;
      cout << positions[i] << endl;
    }
  }
  return 0;
}

bool NOPInjector::injectForLoops() {
  // get target file contents to string (to fix)
  // string code =
  // "#include <iostream>\n\n int main() {\nint xsowy = 12;\nfloat "
  // "ygrekowy = 3.33;\ny=2.4;\nx = 4;\n"
  // "return 0;\n}\n\nvoid sayHello() {\nstd::cout << \"Hello\" << "
  // "std::endl;\n}\nfloat compute(int x) {\nfloat z = 2.53*x;\nreturn z;\n}";
  string code = src.readWholeFile( READSOURCE );

  size_t offset =
  0;          // offset for increased functions positions while adding for loops
  for( int i = 0; i < funcPositions.size(); ++i ) {
    randomNoGen();

    string iValue = to_string( randomX );
    string limit = to_string( randomX * randomY );
    string forLoopStr =
    "\nfor( int i = " + iValue + "; i < " + limit +
    "; ++i) {\n}\n";          // forLoopStr length is constant for each object
    if( i > 0 )
      offset = ( size_t )( forLoopStr.length() * i );
    code.replace( funcPositions[i] + offset, foundFunctions[i].length(),
                  foundFunctions[i] + forLoopStr );
  }
  return 0;
}

bool NOPInjector::injectZeros() {
  if( varPositions.size() == 0 ) {
    cerr << "varPositions variable is empty. Perhaps findPositions(0) should "
            "be ran first?"
         << endl;
    exit( 1 );
  }
  // get target file contents to string (to fix)
  // string code =
  // "#include <iostream>\n\n int main() {\nint xsowy = 12;\nfloat "
  // "ygrekowy = 3.33;\ny=2.4;\nx = 4;\n"
  // "return 0;\n}\n\nvoid sayHello() {\nstd::cout << \"Hello\" << "
  // "std::endl;\n}\nfloat compute(int x) {\nfloat z = 2.53;\nreturn z;\n}";
  string code = src.readWholeFile( READSOURCE );
  string zero = " + 0";
  size_t offset = 0;
  for( int i = 0; i < varPositions.size(); ++i ) {
    if( i > 0 )
      offset = ( size_t )( zero.length() * i );
    string currentVar = foundVars[i];
    char lastChar = currentVar.back();
    string lastCharStr( 1, lastChar );
    if( lastCharStr == ";" ) {
      currentVar.pop_back();
      code.replace( varPositions[i] + offset, foundVars[i].length() - 1,
                    currentVar + zero );
    } else {
      code.replace( varPositions[i] + offset, foundVars[i].length(),
                    foundVars[i] + zero );
    }
  }
  return 0;
}

int NOPInjector::getRandomValues( bool choice ) {
  if( choice )
    return randomX;
  else
    return randomY;
}
