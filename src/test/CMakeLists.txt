# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

include_directories(obfuscator)
add_executable(runTests obfuscationTests.cc)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread obfuscator)
set_target_properties(runTests
    PROPERTIES 
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)