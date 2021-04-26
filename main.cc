#include "src/obfuscator/FilesCompiler.h"
#include "src/obfuscator/NamesChanger.h"
#include "src/obfuscator/Obfuscator.h"
#include "src/obfuscator/SourcesController.h"
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main( int argc, char **argv ) {
  SourcesController *sources = new SourcesController();
  size_t num_of_args = sizeof( argv ) / sizeof( argv[0] );
  if( num_of_args > 1 ) {
    string sourceName = argv[1];
    sources->setOriginalFilePath( argv[1] );
    if( num_of_args > 2 ) {
      string targetName = argv[2];
      sources->setTargetFilePath( argv[2] );
    }
  }
  Obfuscator *obfuscator = new Obfuscator( sources );
  NamesChanger namesChanger( sources->getOriginalFilePath(),
                             sources->getTargetFilePath() );
  FilesCompiler filesCompiler;
  obfuscator = &filesCompiler;
  if( obfuscator->initialCompilation() ) {
    obfuscator = &namesChanger;
    obfuscator->init();
    obfuscator->changeVariablesNames();
  }
  return 0;
}
