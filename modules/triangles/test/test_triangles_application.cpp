// Copyright 2019 Valiullin Damir

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/triangles_application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class TrianglesAppTest : public ::testing::Test {
 protected:
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
    TrianglesApp app_;
    string output_;
};

TEST_F(TrianglesAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a triangles application\\..*");
}

TEST_F(TrianglesAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1", "2" };

    Act(args);

    Assert("ERROR: Should be 7 arguments\\..*");
}

TEST_F(TrianglesAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "1", "pi", "2", "4", "5", "6", "angles" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(TrianglesAppTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "0", "0", "1", "0", "1", "1", "angels" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(TrianglesAppTest, Can_Detect_Wrong_Triangle) {
    vector<string> args = { "0", "0", "1", "1", "2", "2", "points" };

    Act(args);

    Assert("Such a triangle does not exist.");
}

TEST_F(TrianglesAppTest, Can_Get_Points) {
    vector<string> args = { "-0.5", "0.0", "1.0", "0.0", "1.0", "1.0",
        "points" };

    Act(args);

    Assert("A\\(-0.5\\, 0\\) B\\(1\\, 0\\) C\\(1\\, 1\\)");
}

TEST_F(TrianglesAppTest, Can_Get_Angles) {
    vector<string> args = { "0.0", "0.0", "1.0", "0.0", "1.0", "1.0",
        "angles" };

    Act(args);

    Assert("Angle A = 45 Angle B = 90 Angle C = 45");
}

TEST_F(TrianglesAppTest, Can_Get_Sides) {
    vector<string> args = { "0.0", "0.0", "1.0", "0.0", "1.0", "1.0",
        "sides" };

    Act(args);

    Assert("AB = 1 AC = 1.41421 BC = 1");
}

TEST_F(TrianglesAppTest, Can_Get_Perimeter) {
    vector<string> args = { "0.0", "0.0", "1.0", "0.0", "1.0", "1.0",
        "perimeter" };

    Act(args);

    Assert("Perimeter = 3.41421");
}

TEST_F(TrianglesAppTest, Can_Get_Square) {
    vector<string> args = { "0.0", "0.0", "1.0", "0.0", "1.0", "1.0",
        "square" };

    Act(args);

    Assert("Square = 0.5");
}
