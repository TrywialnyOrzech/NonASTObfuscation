#add_subdirectory(../test)
add_library(obfuscator Obfuscator.cc NOPInjector.cc
             TrigraphSequencesInjector.cc FilesCompiler.cc 
             QualityChecker.cc NamesChanger.cc SourcesController.cc
             IfConditionChanger.cc CommentsCleaner.cc)