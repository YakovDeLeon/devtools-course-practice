// Copyright 2019 Kudrin Matvey

#include <gtest/gtest.h>
#include <vector>
#include "include/bond_calculator.h"

TEST(BondCalculatorTest, CanCalculatePayment) {
    BondCalculator calc;
    std::vector<int> months(2);
    months.at(0) = 0;
    months.at(1) = 6;

    bond paper = {100, 120, months, 2020, 8.5};
    std::vector<payment> payments = calc.CalculatePayments(paper, 0, 2019);

    ASSERT_GT(payments.size(), 0);
}

TEST(BondCalculatorTest, CorrectNumberOfPayments) {
    BondCalculator calc;
    std::vector<int> months(2);
    months.at(0) = 0;
    months.at(1) = 6;

    bond paper = {100, 120, months, 2022, 8.5};
    std::vector<payment> payments = calc.CalculatePayments(paper, 0, 2019);

    EXPECT_EQ(payments.size(), 9);
}

TEST(BondCalculatorTest, TestCorrectCouponValue) {
    BondCalculator calc;
    std::vector<int> months(3);
    months.at(0) = 0;
    months.at(1) = 6;
    months.at(2) = 9;

    bond paper = {100, 120, months, 2022, 9.0};
    std::vector<payment> payments = calc.CalculatePayments(paper, 0, 2019);
    for (size_t i = 0; i < payments.size() - 1; i++) {
        EXPECT_EQ(payments.at(i).value, 3.0);
    }
}

TEST(BondCalculatorTest, TestCorrectPercentage) {
    BondCalculator calc;
    std::vector<int> months(2);
    months.at(0) = 0;
    months.at(1) = 6;

    bond paper = {100, 100, months, 2018, 9.0};

    EXPECT_FLOAT_EQ(calc.CalculateTotalIncome(paper, 0, 2018).value, 109.0);
}

TEST(BondCalculatorTest, TestRelativeIncome) {
    BondCalculator calc;
    std::vector<int> months(2);
    months.at(0) = 1;
    months.at(1) = 10;

    bond paper = {100, 100, months, 2019, 10.0};

    EXPECT_FLOAT_EQ(calc.CalculateRelativeIncome(paper, 0, 2020),  10.0);
}


TEST(BondCalculatorTest, TestInternalIncome) {
    BondCalculator calc;
    std::vector<int> months(2);
    months.at(0) = 0;
    months.at(1) = 6;

    bond paper = {100, 100, months, 2019, 10.0};

    EXPECT_FLOAT_EQ(calc.CalculateYearlyInternalIncome(paper, 2018),
            5.0000029);
}
