cmake_minimum_required(VERSION 3.0.0)
project(NonASTObfuscation VERSION 0.1.0)

include(CTest)
enable_testing()


set(BOOST_ROOT "C:/Users/lukas/Desktop/Studia/PW/Semestr 6/ZPR/boost_1_75_0")
set(Boost_USE_STATIC_LIBS        ON)  # only find static libs
set(Boost_USE_DEBUG_LIBS         OFF) # ignore debug libs and
set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)


add_executable(main main.cpp obfuscator.h obfuscator.cpp)
add_executable(originalCode testFile.cpp)
add_executable(checkObfuscation obfuscatedFile.cpp)

set_target_properties(main
    PROPERTIES 
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)
find_package(Boost)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
endif()


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
