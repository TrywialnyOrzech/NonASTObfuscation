cmake_minimum_required(VERSION 3.0.0)
project(NonASTObfuscation VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(obfuscator)

add_executable(main main.cc)
add_executable(originalCode testFile.cc)
add_subdirectory(src/obfuscator)
add_subdirectory(src/test)
target_link_libraries(main obfuscator)


set_target_properties(main
    PROPERTIES 
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
