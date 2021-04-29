# Locate GTest
Include(FetchContent)
	FetchContent_Declare(
	GTest
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG origin/devel)
	
	FetchContent_GetProperties(GTest)
	if(NOT gtest_POPULATED)
	FetchContent_Populate(GTest)
	add_subdirectory("${gtest_SOURCE_DIR}" "${gtest_BINARY_DIR}")
	endif()

include_durectories(lib)
add_executable(tests dumpTestFile.cc obfuscationTests.cc testFile.cc)
target_link_llibraries(tests GTest)
