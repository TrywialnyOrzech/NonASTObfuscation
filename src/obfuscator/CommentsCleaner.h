// Author: Lukasz Stojke
#ifndef COMMENTSCLEANER_H
#define COMMENTSCLEANER_H

#include "Obfuscator.h"
class CommentsCleaner : public Obfuscator {
public:
  CommentsCleaner( std::string oFP = "../testFile.cc",
                   std::string tFP = "../obfuscatedFile.cc" )
      : Obfuscator( oFP, tFP ) {}
  CommentsCleaner( Obfuscator &obf ) : Obfuscator( obf ) {}
  ~CommentsCleaner() {}
  void cleanComments();
  void fetchWholeComment();

private:
};

#endif