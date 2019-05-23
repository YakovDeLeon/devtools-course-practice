// Copyright 2019 Shkerin Igor

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/radix_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class RadixAppTest : public ::testing::Test {
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
    RadixApp app_;
    string output_;
};

TEST_F(RadixAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a radix application\\..*");
}

TEST_F(RadixAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1", "2", "3" };

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(RadixAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "seven", "RadixSort" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(RadixAppTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "10000", "RS" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(RadixAppTest, Can_Calculate_How_Much_Mem_Is_Used) {
    vector<string> args = { "100000", "HowMuchMem" };

    Act(args);

    Assert("The amount of occupied memory = 402052");
}

TEST_F(RadixAppTest, Can_Radix_Sort) {
    vector<string> args = { "1000000", "RadixSort" };

    Act(args);

    Assert("Array size 1000000 sorted by RadixSort.");
}
