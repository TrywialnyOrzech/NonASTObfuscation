# Locate GTest

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


