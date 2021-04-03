cmake_minimum_required(VERSION 3.0.0)
project(NonASTObfuscation VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(main main.cc obfuscator.h obfuscator.cc)
add_executable(originalCode testFile.cc)

set_target_properties(main
    PROPERTIES 
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
