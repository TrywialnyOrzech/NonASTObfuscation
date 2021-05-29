#include "NOPInjector.h"

#include <iostream>
#include <string>

using namespace std;

bool NOPInjector::findFuncDefinitions() {
  // get target file contents to string (to fix)
  string code =
  "#include <iostream>\n\n int main() {\nint xsowy = 12;\nfloat "
  "ygrekowy = 3.33;\ny=2.4;\nx = 4;\n"
  "return 0;\n}\n\nvoid sayHello() {\nstd::cout << \"Hello\" << "
  "std::endl;\n}\nfloat compute(int x) {\nfloat z = 2.53*x;\nreturn z;\n}";
  const regex functionsReg(
  "(bool||char||double||float||int||long||short||void)[ "
  "][a-zA-Z]+(\\(((\\w)+[ ]+(\\w)+(,)*[ ]*)*\\))+[ ](\\{)+" );
  foundFunctions = findRegexMatches( code, functionsReg );
  if( foundFunctions.empty() ) {
    cout << "Pusty strinol " << endl;
    return 1;
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
  // get target file contents to string (to fix)
  string code =
  "#include <iostream>\n\n int main() {\nint xsowy = 12;\nfloat "
  "ygrekowy = 3.33;\ny=2.4;\nx = 4;\n"
  "return 0;\n}\n\nvoid sayHello() {\nstd::cout << \"Hello\" << "
  "std::endl;\n}\nfloat compute(int x) {\nfloat z = 2.53*x;\nreturn z;\n}";
  vector<size_t> positions;
  int bypass = 0;
  if( choice ) {
    if( foundFunctions.size() == 0 ) {
      cerr << "foundFunctions vector is empty. Perhaps findFuncDefinitions() "
              "should be run first?"
           << endl;
      exit( 1 );
    }
    for( int i = 0; i < foundFunctions.size(); ++i ) {
      string func = foundFunctions[i];
      positions.push_back( code.find( func, bypass ) );
      bypass = positions[i];
    }
    funcPositions = positions;
  } else {
    cerr << "to be implemented" << endl;
  }
  return 0;
}

bool NOPInjector::injectForLoops( const char *fileContent ) {
  string fileContentStr( fileContent );
  cout << "INJECT FOR LOOPS" << endl;
  cout << fileContentStr << endl;
  return 0;
}

int NOPInjector::getRandomValues( bool choice ) {
  if( choice )
    return randomX;
  else
    return randomY;
}
