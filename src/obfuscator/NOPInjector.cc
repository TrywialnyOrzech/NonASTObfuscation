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

  return 0;
}

void NOPInjector::findRegexMatches( string str, regex reg ) {
  string results;
  sregex_iterator currentMatch( str.begin(), str.end(), reg );
  sregex_iterator lastMatch;
  while( currentMatch != lastMatch ) {
    smatch match = *currentMatch;
    results.append( match.str() + "\n" );
    ++currentMatch;
  }
  foundFunctions = results;
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
