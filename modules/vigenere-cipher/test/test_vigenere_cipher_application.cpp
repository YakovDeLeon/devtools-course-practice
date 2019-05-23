// Copyright 2019 Konnov Sergey

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/vigenere_cipher_application.h"

class VigenereCipherApplicationTest :
    public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;
        options.push_back("VigenereCipher");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(::testing::internal::RE::PartialMatch(output_,
            ::testing::internal::RE(expected)));
    }

 private:
    VigenereCipherApplication app_;
    std::string output_;
};

TEST_F(VigenereCipherApplicationTest, Print_Help_Without_Arguments) {
    // Arrange
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is application for Vigenere Cipher Class");
}

TEST_F(VigenereCipherApplicationTest, Can_Encrypt_String) {
    // Arrange
    std::vector<std::string> args =
        { "encrypt", "abcdef", "coolkey" };

    Act(args);

    Assert("cpqooj");
}

TEST_F(VigenereCipherApplicationTest, Can_Decrypt_String) {
    // Arrange
    std::vector<std::string> args =
        { "decrypt", "abcdef", "coolkey" };

    Act(args);

    Assert("ynosub");
}

TEST_F(VigenereCipherApplicationTest,
    Throws_If_Operation_Is_Unknown) {
    // Arrange
    std::vector<std::string> args = { "crypt" };

    Act(args);

    Assert("Unknown operation: crypt");
}

TEST_F(VigenereCipherApplicationTest,
    Throws_If_There_Are_Too_Few_Arguments) {
    // Arrange
    std::vector<std::string> args = { "encrypt" };

    Act(args);

    Assert("Too few arguments!");
}

TEST_F(VigenereCipherApplicationTest,
    Throws_If_There_Are_Too_Many_Arguments) {
    // Arrange
    std::vector<std::string> args =
        { "encrypt" , "hi", "there", "fg!"};

    Act(args);

    Assert("Too many arguments!");
}
