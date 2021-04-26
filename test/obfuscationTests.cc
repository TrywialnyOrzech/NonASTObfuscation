#include <gtest/gtest.h>
#include "../obfuscator/Obfuscator.h"
#include "../obfuscator/SourcesController.h"

using ::testing::Test;

class obfuscationTests : public Test{
    protected: 
        void SetUp() override {
            obf = new Obfuscator("../../test/testFile.cc","../../test/dumpTestFile.cc");
            obf->init(); 
            }
        Obfuscator* obf;
};

TEST_F(obfuscationTests, compile_source_file){
    ASSERT_TRUE(obf->fileCompilation(obf->getOriginalFilePath()));
}

// Very last test (deletes Obfuscator)
TEST_F(obfuscationTests, compile_target_file){
    obf->changeVariablesNames();
    std::string path = obf->getTargetFilePath();
    delete obf;
    ASSERT_TRUE(SourcesController::fileCompilation(path));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}