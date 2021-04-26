cmake_minimum_required(VERSION 3.0.0)
project(NonASTObfuscation VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(obfuscator)

add_executable(main main.cc)
add_executable(originalCode testFile.cc)
add_subdirectory(obfuscator)
add_subdirectory(test)
target_link_libraries(main obfuscator)

 
# Link runTests with what we want to test and the GTest and pthread library
#add_executable(runTests test/obfuscationTests.cc obfuscator/obfuscator.cc obfuscator/sourcesController.cc)
#target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

set_target_properties(main
    PROPERTIES 
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
