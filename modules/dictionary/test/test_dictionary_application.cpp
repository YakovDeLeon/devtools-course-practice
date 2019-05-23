// Copyright 2019 Yakovlev Denis

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/dictionary_application.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class DictionaryApplicationTest : public ::testing::Test {
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
    DicitonaryApplication app_;
    string output_;
};

TEST_F(DictionaryApplicationTest , Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a dictionary application.*");
}

TEST_F(DictionaryApplicationTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"abc", "2"};

    Act(args);

    Assert("ERROR: Should be at least 3 arguments.*");
}

TEST_F(DictionaryApplicationTest, Can_Detect_Invalid_Operation) {
    vector<string> args = {"abc", "2", "2", "4", "+"};

    Act(args);

    Assert("Invalid operation!.*");
}

TEST_F(DictionaryApplicationTest, Can_Detect_Invalid_Key) {
    vector<string> args = {"avc", "invalid key", "-smin"};

    Act(args);

    Assert("Invalid key!.*");
}

TEST_F(DictionaryApplicationTest,
    Can_Detect_Invalid_Search_Item) {
    vector<string> args = {"2.0", "3.5", "-s"};

    Act(args);

    Assert("Invalid search element!.*");
}

TEST_F(DictionaryApplicationTest, Can_Find_Min_Item) {
    vector<string> args =
    {"a", "7", "b", "-14", "c", "124", "-smin"};

    Act(args);

    Assert("a 7");
}

TEST_F(DictionaryApplicationTest, Can_Find_Max_Item) {
    vector<string> args =
    {"a", "7", "b", "-14", "c", "124", "-smax" };

    Act(args);

    Assert("c 124");
}

TEST_F(DictionaryApplicationTest, Can_Find_Item) {
    vector<string> args =
    {"a", "7", "b", "-14", "c", "124", "-s", "b"};

    Act(args);

    Assert("b -14");
}
