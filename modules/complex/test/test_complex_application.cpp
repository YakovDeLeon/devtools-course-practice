// Copyright 2019 Kruglov Yegor

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/complex_application.h"

using ::testing::internal::RE;

class ComplexApplicationTest : public ::testing::Test {
 private:
    ComplexApplication app_;
    std::string output_;

 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); i++) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }
};

TEST_F(ComplexApplicationTest, Print_Help_Without_Arguments) {
    // Arrange
    std::vector<std::string> args = {};

    // Act
    Act(args);

    // Assert
    Assert("This is a complex number calculator application\\..*");
}

TEST_F(ComplexApplicationTest, Check_Arguments) {
    // Arrange
    std::vector<std::string> args = { "1.0", "2.0" };

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Should be 5 arguments\\..*");
}

TEST_F(ComplexApplicationTest, Can_Find_Wrong_Argument_Format) {
    // Arrange
    std::vector<std::string> args = { "1.0", "2.0", "+", "qwerty", "4.0" };

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Wrong number format!");
}

TEST_F(ComplexApplicationTest, Can_Find_Wrong_Operation_Format) {
    // Arrange
    std::vector<std::string> args = { "1.0", "2.0", "qwerty", "4.0", "5.0" };

    // Act
    Act(args);

    // Assert
    Assert("ERROR: Wrong operation format!");
}

TEST_F(ComplexApplicationTest, Can_Add_Numbers) {
    // Arrange
    std::vector<std::string> args = { "1.0", "2.0", "+", "3.0", "4.0" };

    // Act
    Act(args);

    // Assert
    Assert("Real = 4 Imaginary = 6");
}

TEST_F(ComplexApplicationTest, Can_Substruct_Numbers) {
    // Arrange
    std::vector<std::string> args = { "3.0", "4.0", "-", "1.0", "2.0" };

    // Act
    Act(args);

    // Assert
    Assert("Real = 2 Imaginary = 2");
}

TEST_F(ComplexApplicationTest, Can_Multiply_Numbers) {
    // Arrange
    std::vector<std::string> args = { "3.0", "4.0", "*", "1.0", "2.0" };

    // Act
    Act(args);

    // Assert
    Assert("Real = -5 Imaginary = 10");
}

TEST_F(ComplexApplicationTest, Can_Divide_Numbers) {
    // Arrange
    std::vector<std::string> args = { "-5.0", "10.0", "/", "1.0", "2.0" };

    // Act
    Act(args);

    // Assert
    Assert("Real = 3 Imaginary = 4");
}

TEST_F(ComplexApplicationTest, Can_Not_Divide_By_Zero) {
    // Arrange
    std::vector<std::string> args = { "1.0", "2.0", "/", "0", "0" };

    // Act
    Act(args);

    // Assert
    Assert("Division by zero!");
}
