#include "src/obfuscator/FilesCompiler.h"
#include "src/obfuscator/NamesChanger.h"
#include "src/obfuscator/Obfuscator.h"
#include "src/obfuscator/QualityChecker.h"
#include "src/obfuscator/SourcesController.h"
#include <iostream>
#include <string>

using namespace std;

int main( int argc, char **argv ) {
  SourcesController *sources = new SourcesController();
  if( argc > 1 ) {
    string sourceName = argv[1];
    sources->setOriginalFilePath( argv[1] );
    cout << sources->getOriginalFilePath();
    if( argc > 2 ) {
      string targetName = argv[2];
      sources->setTargetFilePath( argv[2] );
    }
  }
  Obfuscator *obfuscator = new Obfuscator( sources );
  NamesChanger namesChanger( *obfuscator );
  FilesCompiler filesCompiler( *obfuscator );
  obfuscator = &filesCompiler;
  if( obfuscator->initialCompilation() ) {
    obfuscator = &namesChanger;
    obfuscator->init();
    obfuscator->changeVariablesNames();
  }
  QualityChecker qualityChecker( *obfuscator );
  obfuscator = &qualityChecker;
  obfuscator->reload();
  obfuscator->loadFileContent();
  string x = "elo elo wiadomosc na start";
  string y = "ouhasdoihaasoijasfoihsdfiohsdoihgsoihgsiohsdghoidgsoigds";
  const char *source = x.c_str();
  const char *target = y.c_str();
  obfuscator->rateCodeLength(source, target);
  return 0;
}
