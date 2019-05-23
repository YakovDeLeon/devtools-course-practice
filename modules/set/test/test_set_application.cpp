// Copyright 2019 Trykin Alexander

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/set_application.h"

using ::testing::internal::RE;

class SetApplicationTest : public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("appname");
        for (auto &arg : args_) {
            options.push_back(arg.c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    SetApplication app_;
    std::string output_;
};

TEST_F(SetApplicationTest, Can_Show_Help) {
    // Arrange
    std::vector<std::string> args = {"help"};

    // Act
    Act(args);

    // Assert
    Assert("This is a set application.");
}

TEST_F(SetApplicationTest, Can_Detect_Invalid_Operation) {
    // Arrange
    std::vector<std::string> args = {"1", "2", "3", "o", "4", "5"};

    // Act
    Act(args);

    // Assert
    Assert("Missed operation!");
}

TEST_F(SetApplicationTest, Can_Detect_Invalid_Arguments) {
    // Arrange
    std::vector<std::string> args = {"1", "!", "9", "i", "4", "5"};

    // Act
    Act(args);

    // Assert
    Assert("Input error!");
}

TEST_F(SetApplicationTest, Can_Union_Sets) {
    // Arrange
    std::vector<std::string> args = {"1", "2", "3", "u", "4", "5"};

    // Act
    Act(args);

    // Assert
    Assert("1 2 3 4 5");
}

TEST_F(SetApplicationTest, Can_Intersection_Sets) {
    // Arrange
    std::vector<std::string> args = {"1", "2", "3", "i", "1", "3"};

    // Act
    Act(args);

    // Assert
    Assert("1 3");
}

TEST_F(SetApplicationTest, Can_Difference_Sets) {
    // Arrange
    std::vector<std::string> args = {"1", "2", "3", "d", "2", "3"};

    // Act
    Act(args);

    // Assert
    Assert("1");
}

TEST_F(SetApplicationTest, Can_Symmetric_Difference_Sets) {
    // Arrange
    std::vector<std::string> args = {"1", "2", "3", "sd", "1", "3"};

    // Act
    Act(args);

    // Assert
    Assert("2");
}
