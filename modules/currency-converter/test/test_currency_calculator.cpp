// Copyright 2017 Korniakov Kirill

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/currency_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class CurrencyCalculatorTest : public ::testing::Test {
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
    CurrencyCalculator app_;
    string output_;
};

TEST_F(CurrencyCalculatorTest, Can_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a currency calculator application\\..*");
}

TEST_F(CurrencyCalculatorTest, Can_Check_Number_Of_Arguments) {
    vector<string> args = {"5.5"};

    Act(args);

    Assert("ERROR: Should be 2 arguments\\..*");
}

TEST_F(CurrencyCalculatorTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"two", "RubleToDollar"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(CurrencyCalculatorTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = {"1", "garbage"};

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(CurrencyCalculatorTest, Can_Ruble_To_Euro) {
    vector<string> args = {"72.29", "RubleToEuro"};

    Act(args);

    Assert("Euro: 1");
}

TEST_F(CurrencyCalculatorTest, Can_Ruble_To_Dollar) {
    vector<string> args = {"64.82", "RubleToDollar"};

    Act(args);

    Assert("Dollar: 1");
}

TEST_F(CurrencyCalculatorTest, Can_Ruble_To_Shekel) {
    vector<string> args = {"17.9", "RubleToShekel"};

    Act(args);

    Assert("Shekel: 1");
}

TEST_F(CurrencyCalculatorTest, Can_Ruble_To_Grivna) {
    vector<string> args = {"2.45", "RubleToGrivna"};

    Act(args);

    Assert("Grivna: 1");
}

TEST_F(CurrencyCalculatorTest, Can_Ruble_To_Dirham) {
    vector<string> args = {"17.65", "RubleToDirham"};

    Act(args);

    Assert("Dirham: 1");
}

TEST_F(CurrencyCalculatorTest, Can_Euro_To_Dirham) {
    vector<string> args = {"100.0", "EuroToDirham"};

    Act(args);

    Assert("Dirham: 409");
}

TEST_F(CurrencyCalculatorTest, Can_Euro_To_Grivna) {
    vector<string> args = {"100.0", "EuroToGrivna"};

    Act(args);

    Assert("Grivna: 2953");
}

TEST_F(CurrencyCalculatorTest, Can_Euro_To_Shekel) {
    vector<string> args = {"100.0", "EuroToShekel"};

    Act(args);

    Assert("Shekel: 403");
}

TEST_F(CurrencyCalculatorTest, Can_Euro_To_Rubles) {
    vector<string> args = {"1.0", "EuroToRubles"};

    Act(args);

    Assert("Rubles: 72.24");
}

TEST_F(CurrencyCalculatorTest, Can_Euro_To_Dollar) {
    vector<string> args = {"100.0", "EuroToDollar"};

    Act(args);

    Assert("Dollar: 111");
}

TEST_F(CurrencyCalculatorTest, Can_Dollar_To_Euro) {
    vector<string> args = {"100.0", "DollarToEuro"};

    Act(args);

    Assert("Euro: 89");
}

TEST_F(CurrencyCalculatorTest, Can_Dollar_To_Rubles) {
    vector<string> args = {"100.0", "DollarToRubles"};

    Act(args);

    Assert("Rubles: 6482");
}

TEST_F(CurrencyCalculatorTest, Can_Dollar_To_Shekel) {
    vector<string> args = {"100.0", "DollarToShekel"};

    Act(args);

    Assert("Shekel: 362");
}

TEST_F(CurrencyCalculatorTest, Can_Dollar_To_Grivna) {
    vector<string> args = {"100.0", "DollarToGrivna"};

    Act(args);

    Assert("Grivna: 2647");
}

TEST_F(CurrencyCalculatorTest, Can_Dollar_To_Dirham) {
    vector<string> args = {"100.0", "DollarToDirham"};

    Act(args);

    Assert("Dirham: 367");
}

TEST_F(CurrencyCalculatorTest, Can_Shekel_To_Grivna) {
    vector<string> args = {"100.0", "ShekelToGrivna"};

    Act(args);

    Assert("Grivna: 731");
}

TEST_F(CurrencyCalculatorTest, Can_Shekel_To_Dirham) {
    vector<string> args = {"1000.0", "ShekelToDirham"};

    Act(args);

    Assert("Dirham: 1010");
}

TEST_F(CurrencyCalculatorTest, Can_Shekel_To_Rubles) {
    vector<string> args = {"100.0", "ShekelToRubles"};

    Act(args);

    Assert("Rubles: 1788");
}

TEST_F(CurrencyCalculatorTest, Can_Shekel_To_Dollar) {
    vector<string> args = {"1000.0", "ShekelToDollar"};

    Act(args);

    Assert("Dollar: 276");
}

TEST_F(CurrencyCalculatorTest, Can_Shekel_To_Euro) {
    vector<string> args = {"1000.0", "ShekelToEuro"};

    Act(args);

    Assert("Euro: 246");
}

TEST_F(CurrencyCalculatorTest, Can_Dirham_To_Grivna) {
    vector<string> args = {"100.0", "DirhamToGrivna"};

    Act(args);

    Assert("Grivna: 720");
}

TEST_F(CurrencyCalculatorTest, Can_Dirham_To_Shekel) {
    vector<string> args = {"100.0", "DirhamToShekel"};

    Act(args);

    Assert("Shekel: 98");
}

TEST_F(CurrencyCalculatorTest, Can_Dirham_To_Euro) {
    vector<string> args = {"1000.0", "DirhamToEuro"};

    Act(args);

    Assert("Euro: 243");
}

TEST_F(CurrencyCalculatorTest, Can_Dirham_To_Rubles) {
    vector<string> args = {"1.0", "DirhamToRubles"};

    Act(args);

    Assert("Rubles: 17.63");
}

TEST_F(CurrencyCalculatorTest, Can_Dirham_To_Dollar) {
    vector<string> args = {"1000.0", "DirhamToDollar"};

    Act(args);

    Assert("Dollar: 273");
}

TEST_F(CurrencyCalculatorTest, Can_Grivna_To_Dollar) {
    vector<string> args = {"100.0", "GrivnaToDollar"};

    Act(args);

    Assert("Dollar: 3.7");
}

TEST_F(CurrencyCalculatorTest, Can_Grivna_To_Euro) {
    vector<string> args = {"100.0", "GrivnaToEuro"};

    Act(args);

    Assert("Euro: 3.3");
}

TEST_F(CurrencyCalculatorTest, Can_Grivna_To_Rubles) {
    vector<string> args = {"1.0", "GrivnaToRubles"};

    Act(args);

    Assert("Rubles: 2.443");
}

TEST_F(CurrencyCalculatorTest, Can_Grivna_To_Dirham) {
    vector<string> args = {"1000.0", "GrivnaToDirham"};

    Act(args);

    Assert("Dirham: 138");
}

TEST_F(CurrencyCalculatorTest, Can_Grivna_To_Shekel) {
    vector<string> args = {"1000.0", "GrivnaToShekel"};

    Act(args);

    Assert("Shekel: 136");
}
