// Copyright 2019 Obolenskiy Arseniy
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/tree_application.h"

class TreeApplicationTest : public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("tree");
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
    TreeApplication app_;
    std::string output_;
};

TEST_F(TreeApplicationTest, Do_Print_Help_Without_Arguments) {
    // Arrange
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is application for tree class");
}

TEST_F(TreeApplicationTest, Adds_And_Searches_The_Same_Number) {
    // Arrange
    std::vector<std::string> args = {"add", "1", "search", "1"};

    Act(args);

    Assert("\\(1 is found, count: 1\\)");
}

TEST_F(TreeApplicationTest, Adds_Deletes_And_Searches_The_Same_Number) {
    // Arrange
    std::vector<std::string> args = {"add", "1", "del", "1", "search", "1"};

    Act(args);

    Assert("\\(1 is not found\\)");
}

TEST_F(TreeApplicationTest, Can_Search_Twice_The_Same_Number) {
    // Arrange
    std::vector<std::string> args = {"add", "1", "search", "1",
                           "del", "1", "search", "1"};

    Act(args);

    Assert("\\(1 is found, count: 1\\) \\(1 is not found\\)");
}

TEST_F(TreeApplicationTest, Throws_An_Error_If_Argument_Is_Not_Numeric) {
    // Arrange
    std::vector<std::string> args = {"add", "a"};

    Act(args);

    Assert("a is not the number");
}

TEST_F(TreeApplicationTest, Throws_An_Error_If_Int_Overflows) {
    // Arrange
    std::vector<std::string> args = {"add", "20000000000"};

    Act(args);

    Assert("Number is out of bounds");
}

TEST_F(TreeApplicationTest, Can_Clear_Tree) {
    // Arrange
    std::vector<std::string> args = {"add", "2", "search", "2", "clear",
                                     "search", "2"};

    Act(args);

    Assert("\\(2 is found, count: 1\\) \\(2 is not found\\)");
}

TEST_F(TreeApplicationTest, Handles_Unknown_Operation) {
    // Arrange
    std::vector<std::string> args = {"addd", "2", "search", "2",
                                     "clear", "search", "2"};

    Act(args);

    Assert("Unknown operation: addd");
}

TEST_F(TreeApplicationTest, Handles_Deleting_Element_With_Zero_Count) {
    // Arrange
    std::vector<std::string> args = {"del", "2", "search", "2"};

    Act(args);

    Assert("\\(2 is not found\\)");
}
