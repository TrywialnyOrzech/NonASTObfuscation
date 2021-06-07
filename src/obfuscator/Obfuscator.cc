#include "Obfuscator.h"

void Obfuscator::init() { src.init(); }

void Obfuscator::close() { src.close(); }

void Obfuscator::reload() { src.reload(); }

bool Obfuscator::saveIncludes( std::string &code ) {
  if( code.compare( "#include" ) == 0 ) {
    std::string nextLine( "" );
    src.readWord( &nextLine );
    src.writeWord( code );
    src.writeWord( " " );
    src.writeWord( nextLine );
    src.writeWord( "\n" );
    return true;
  }
  return false;
}
