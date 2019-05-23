// Copyright 2019 Soluyanov Alexsey

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/vector-3d-calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class VectorCalculatorTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    VectorCalculator app_;
    string output_;
};

TEST_F(VectorCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a vector-3d calculator application\\..*");
}
TEST_F(VectorCalculatorTest, Is_Cheking_Num_of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Incorrect num of arguments\\..*");
}

TEST_F(VectorCalculatorTest, Can_Detect_Wtong_Num_Format) {
    vector<string> args = {"1", "2", "3", "pi", "5", "6", "+"};

    Act(args);

    Assert("Wrong number format!.*");
}
TEST_F(VectorCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"1", "2", "3", "4", "5", "6", "//"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(VectorCalculatorTest, Can_Add_Vectors) {
    vector<string> args = {"1", "2", "3", "4", "5", "6", "+"};

    Act(args);

    Assert("X = 5 Y = 7 Z = 9");
}

TEST_F(VectorCalculatorTest, Can_Diff_Vectors) {
    vector<string> args = {"1", "2", "3", "2", "4", "6", "-"};

    Act(args);

    Assert("X = -1 Y = -2 Z = -3");
}

TEST_F(VectorCalculatorTest, Can_Mult_Vectors) {
    vector<string> args = {"1", "1", "1", "2", "4", "6", "*"};

    Act(args);

    Assert("Result = 12");
}

TEST_F(VectorCalculatorTest, Can_Mult_Vector_and_Num) {
    vector<string> args = {"1", "2", "3", "2", "*"};

    Act(args);

    Assert("X = 2 Y = 4 Z = 6");
}

TEST_F(VectorCalculatorTest, Can_Div_Vector_and_Num) {
    vector<string> args = {"4", "10", "6", "2", "/"};

    Act(args);

    Assert("X = 2 Y = 5 Z = 3");
}

TEST_F(VectorCalculatorTest, Can_Find_Vectors_Norma) {
    vector<string> args = {"1", "2", "2", "norma"};

    Act(args);

    Assert("Result = 3");
}

TEST_F(VectorCalculatorTest, Can_Normalize_Vectors) {
    vector<string> args = {"3", "0", "4", "normalize"};

    Act(args);

    Assert("X = 0.6 Y = 0 Z = 0.8");
}

TEST_F(VectorCalculatorTest, Can_Cross_Vectors) {
    vector<string> args = {"6", "4", "5", "1", "2", "3", "cross"};

    Act(args);

    Assert("X = 2 Y = -13 Z = 8");
}


TEST_F(VectorCalculatorTest, Exception_Zero_Div) {
    vector<string> args = {"1", "2", "3", "0", "/"};

    Act(args);

    Assert("Can't divide by zero");
}


TEST_F(VectorCalculatorTest, Exception_Cant_Normalize) {
    vector<string> args = {"0", "0", "0", "normalize"};

    Act(args);

    Assert("Can't find norma");
}

