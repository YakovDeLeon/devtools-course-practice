// Copyright 2019 Korobeinikov Aleksey
#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/segment_tree_application.h"

class SegmentTreeApplicationTest : public ::testing::Test {
 protected:
    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("Segment_tree");
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
    SegmentTreeApplication app_;
    std::string output_;
};

TEST_F(SegmentTreeApplicationTest, Print_Help_Without_Arguments) {
    // Arrange
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is application for segment tree class");
}

TEST_F(SegmentTreeApplicationTest, Can_Do_Adding) {
    // Arrange
    std::vector<std::string> args = { "1", "5", "1",
         "add1", "3", "34", "get1", "3" };

    Act(args);

    Assert("Index = 3 Value = 34");
}

TEST_F(SegmentTreeApplicationTest, Throw_Error_When_Border_Is_Not_A_Number) {
    // Arrange
    std::vector<std::string> args = { "1", "e", "2" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(SegmentTreeApplicationTest,
    Throw_Error_When_Left_Border_More_Than_Right) {
    // Arrange
    std::vector<std::string> args = { "6", "4", "2" };

    Act(args);

    Assert("Wrong borders.");
}

TEST_F(SegmentTreeApplicationTest,
    Throw_Error_And_Print_Help_When_Count_Of_Arguments_Less_Than_Three) {
    // Arrange
    std::vector<std::string> args = { "6", "4" };

    Act(args);

    Assert("Minimum 3 arguments");
}

TEST_F(SegmentTreeApplicationTest,
    Cant_Use_The_Wrong_Number_Of_Function) {
    // Arrange
    std::vector<std::string> args = { "3", "4", "4" };

    Act(args);

    Assert("Wrong number of function");
}

TEST_F(SegmentTreeApplicationTest,
    Can_Use_Segment_Tree_With_Min_Function) {
    // Arrange
    std::vector<std::string> args = { "1", "7", "2", "add1", "1", "8",
        "set1", "1", "7",
        "set1", "1", "9", "add2", "2", "5", "3", "get2", "1", "2"};

    Act(args);

    Assert("Left border = 1 Right border = 2 Value = 3");
}

TEST_F(SegmentTreeApplicationTest,
    Can_Use_Segment_Tree_With_Max_Function) {
    // Arrange
    std::vector<std::string> args = { "1", "7", "3", "add1", "1", "8",
        "add2", "2", "5", "7", "get2", "1", "2" };

    Act(args);

    Assert("Left border = 1 Right border = 2 Value = 8");
}

TEST_F(SegmentTreeApplicationTest,
    Throw_Error_When_Int_Overflow) {
    // Arrange
    std::vector<std::string> args = { "1", "7", "3", "add1", "1", "",
        "add2", "2", "5", "7234345435636634", "get2", "1", "2" };

    Act(args);

    Assert("Number is out of bounds");
}

TEST_F(SegmentTreeApplicationTest,
    Correct_Setting_After_Adding_On_Segment) {
    // Arrange
    std::vector<std::string> args = { "-5", "0", "1",
        "add2", "-4", "-1", "7", "set1", "-3", "2", "get1", "-3" };

    Act(args);

    Assert("Index = -3 Value = 2");
}

TEST_F(SegmentTreeApplicationTest,
    Correct_Adding_After_Setting_On_Segment) {
    // Arrange
    std::vector<std::string> args = { "-5", "0", "1",
        "set2", "-4", "-1", "7", "add2", "-3", "-2", "2", "get2", "-5", "0" };

    Act(args);

    Assert("Left border = -5 Right border = 0 Value = 32");
}

TEST_F(SegmentTreeApplicationTest,
    Throw_Error_When_Try_Use_Wrong_Operation) {
    // Arrange
    std::vector<std::string> args = { "-5", "0", "1", "adr2", "-4", "-1", "7" };

    Act(args);

    Assert("Unknown operation: adr2");
}

TEST_F(SegmentTreeApplicationTest,
    Throw_Error_When_Try_Use_Adding_On_Segment_With_Incorrect_Borders) {
    // Arrange
    std::vector<std::string> args = { "-5", "0", "1", "add2", "1", "2", "7" };

    Act(args);

    Assert("Incorrect borders");
}

TEST_F(SegmentTreeApplicationTest,
    Throw_Error_When_Try_Use_Adding_With_Incorrect_Borders) {
    // Arrange
    std::vector<std::string> args = { "-5", "0", "1", "add1", "1", "7" };

    Act(args);

    Assert("Out of borders!");
}

TEST_F(SegmentTreeApplicationTest,
    Throw_Error_When_Try_Use_Setting_On_Segment_With_Incorrect_Borders) {
    // Arrange
    std::vector<std::string> args = { "-5", "0", "1", "set2", "-3", "2", "7" };

    Act(args);

    Assert("Incorrect borders");
}

TEST_F(SegmentTreeApplicationTest,
    Throw_Error_When_Try_Use_Setting_With_Incorrect_Borders) {
    // Arrange
    std::vector<std::string> args = { "-5", "0", "1", "set1", "1", "7" };

    Act(args);

    Assert("Out of borders!");
}

TEST_F(SegmentTreeApplicationTest,
    Throw_Error_When_Try_Use_Getting_On_Segment_With_Incorrect_Borders) {
    // Arrange
    std::vector<std::string> args = { "-5", "0", "1", "get2", "-6", "-2" };

    Act(args);

    Assert("Incorrect borders");
}

TEST_F(SegmentTreeApplicationTest,
    Throw_Error_When_Try_Use_Getting_With_Incorrect_Borders) {
    // Arrange
    std::vector<std::string> args = { "-5", "0", "1", "get1", "1" };

    Act(args);

    Assert("Out of borders!");
}
