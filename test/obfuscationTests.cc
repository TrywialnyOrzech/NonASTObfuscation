#include <gtest/gtest.h>
#include "../obfuscator/obfuscator.h"


TEST(OBFUSCATION_VERIFICATION, compile_source_file){
    //Arrange
    Obfuscator obf("../test/testFile.cc", "../test/dumpTestFile.cc");
    //Act
    obf.init();
    //Assert
    ASSERT_TRUE(obf.fileCompilation(obf.getOriginalFilePath()));
    }

TEST(OBFUSCATION_VERIFICATION, compile_target_file){
    //Arrange
    Obfuscator obf("../test/testFile.cc", "../test/dumpTestFile.cc");
    //Act
    obf.init();
    obf.clearEnters();
    //Assert
    ASSERT_TRUE(obf.fileCompilation(obf.getTargetFilePath()));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}