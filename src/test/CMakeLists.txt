# Locate GTest
<<<<<<< HEAD

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/master.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(lib)
add_executable(tests obfuscationTests.cc)
target_link_libraries(tests gtest_main obfuscator)
add_test(NAME obfuscation_tests COMMAND tests)

=======
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
>>>>>>> CMakeLists with gtest download added.
