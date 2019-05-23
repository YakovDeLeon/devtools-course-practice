// Copyright 2019 Iamshchikov Ivan

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/regexpr_application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class RegExprApplicationTest : public ::testing::Test {
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
    RegExprApplication app_;
    string output_;
};

TEST_F(RegExprApplicationTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a regular expression application\\..*");
}

TEST_F(RegExprApplicationTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"expression"};

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(RegExprApplicationTest, Can_Match) {
    vector<string> args = {
        "+7\\([0-9][0-9][0-9]\\)[0-9][0-9][0-9]-[0-9][0-9]-[0-9][0-9]",
        "This is a search line: +7(999)120-32-28"};

    Act(args);

    Assert("Position of start = 23 Position of end = 39");
}

TEST_F(RegExprApplicationTest, Can_Detect_No_Occurrence) {
    vector<string> args = {"abcde", "abc"};

    Act(args);

    Assert("Search string doesn't contain a line according to pattern: abcde");
}
