// Copyright 2019 Kutovoi Vadim

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/bond_calculator_app.h"

using ::testing::internal::RE;

class CalculatorTest : public ::testing::Test {
 protected:
      void Act(std::vector<std::string> args_) {
         std::vector<const char*> options;

          options.push_back("appname");
         for (size_t i = 0; i < args_.size(); ++i) {
             options.push_back(args_[i].c_str());
         }

          const char** argv = &options.front();
         int argc = static_cast<int>(args_.size()) + 1;

          output_ = app_(argc, argv);
         std::cout << std::endl << output_ << std::endl;
     }

      void Assert(std::string expected) {
         EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
     }

 private:
     BondCalculatorApp app_;
     std::string output_;
};

TEST_F(CalculatorTest, Returns_Empty_If_No_Args) {
    std::vector<std::string> args = {};

     Act(args);

     Assert("");
}

TEST_F(CalculatorTest, Returns_Empty_If_Not_Four_Args) {
    std::vector<std::string> args = { "100", "90" };

     Act(args);

     Assert("");
}

TEST_F(CalculatorTest, Returns_Empty_If_Wrong_Args) {
    std::vector<std::string> args = { "Henlo", "its", "hacker", "doggo",
                                         "!", "!", "!" };

     Act(args);

     Assert("");
}

TEST_F(CalculatorTest, Can_Calculate_Total_Income) {
    std::vector<std::string> args =
            { "100", "90", "2020", "50", "2019", "6", "total" };

     Act(args);

     Assert("Total income :");
}

TEST_F(CalculatorTest, Can_Calculate_Relative_Income) {
    std::vector<std::string> args =
            { "100", "90", "2020", "50", "2019", "6", "relative" };

     Act(args);

     Assert("Relative income :");
}

TEST_F(CalculatorTest, Can_Calculate_Payments) {
    std::vector<std::string> args =
            { "100", "90", "2020", "50", "2019", "6", "payments" };

     Act(args);

     Assert("Payments :");
}

TEST_F(CalculatorTest, Can_Calculate_Yearly_internal_Income) {
    std::vector<std::string> args =
            { "100", "90", "2020", "50", "2019", "6", "yearly" };

     Act(args);

     Assert("Yearly internal income :");
}

TEST_F(CalculatorTest, Can_Calculate_All_Metrics) {
    std::vector<std::string> args =
            { "100", "90", "2020", "50", "2019", "6", "all" };

     Act(args);

     Assert("");
}

TEST_F(CalculatorTest, Cant_Calculate_With_Wrong_Metric) {
    std::vector<std::string> args =
            { "100", "90", "2020", "50", "2019", "6", "wrongmetric" };

     Act(args);

     Assert("Wrong metric");
}
