// Copyright 2019 Timakin Nikita

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/sorter.h"

using ::testing::internal::RE;

class SorterTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

    void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

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
    Sorter app_;
    std::string output_;
};

TEST_F(SorterTest, Returns_Empty_Without_Arguments) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("");
}

TEST_F(SorterTest, Returns_Empty_With_Help_Flag) {
    std::vector<std::string> args = {"help"};

    Act(args);

    Assert("");
}

TEST_F(SorterTest, Returns_Empty_With_Invalid_Arguments) {
    std::vector<std::string> args = {"a", "2", "!"};

    Act(args);

    Assert("");
}

TEST_F(SorterTest, Can_Sort_Int) {
    std::vector<std::string> args = {"2", "1", "3"};

    Act(args);

    Assert("3 2 1");
}

TEST_F(SorterTest, Can_Sort_Float) {
    std::vector<std::string> args = {"2.10", "1.0", "3.95"};

    Act(args);

    Assert("3.95 2.1 1");
}
