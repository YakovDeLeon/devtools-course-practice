// Copyright 2019 Sitkin Dmitry

#include <gtest/gtest.h>

#include "include/deposit_calculator.h"

TEST(Sitkin_Dmitry_Deposit_Calculator, Can_Set_Initial_Amount) {
    // Arrange
    DepositCalculator dc;

    // Act
    dc.SetInitialAmount(1000000);

    // Assert
    EXPECT_EQ(1000000, dc.GetInitialAmount());
}

TEST(Sitkin_Dmitry_Deposit_Calculator, Can_Set_Term) {
    // Arrange
    DepositCalculator dc;

    // Act
    dc.SetTerm(24);

    // Assert
    EXPECT_EQ(24, dc.GetTerm());
}

TEST(Sitkin_Dmitry_Deposit_Calculator, Can_Set_Annual_Interest) {
    // Arrange
    DepositCalculator dc;

    // Act
    dc.SetAnnualInterest(12);

    // Assert
    EXPECT_EQ(12, dc.GetAnnualInterest());
}

TEST(Sitkin_Dmitry_Deposit_Calculator, Can_Set_Capitalization) {
    // Arrange
    DepositCalculator dc;

    // Act
    dc.SetCapitalization(2);

    // Assert
    EXPECT_EQ(2, dc.GetCapitalization());
}

TEST(Sitkin_Dmitry_Deposit_Calculator, Can_Calculate_With_No_Capitalization) {
    // Arrange
    DepositCalculator dc;
    dc.SetInitialAmount(100000);
    dc.SetTerm(12);
    dc.SetAnnualInterest(10);
    dc.SetCapitalization(0);

    // Act
    double result = dc.Calculate();

    // Assert
    EXPECT_EQ(110000, static_cast<int>(result));
}

TEST(Sitkin_Dmitry_Deposit_Calculator,
    Can_Calculate_With_Daily_Capitalization) {
    // Arrange
    DepositCalculator dc;
    dc.SetInitialAmount(100000);
    dc.SetTerm(12);
    dc.SetAnnualInterest(10);
    dc.SetCapitalization(1);

    // Act
    double result = dc.Calculate();

    // Assert
    EXPECT_EQ(110364, static_cast<int>(result));
}

TEST(Sitkin_Dmitry_Deposit_Calculator,
    Can_Calculate_With_Weekly_Capitalization) {
    // Arrange
    DepositCalculator dc;
    dc.SetInitialAmount(100000);
    dc.SetTerm(12);
    dc.SetAnnualInterest(10);
    dc.SetCapitalization(2);

    // Act
    double result = dc.Calculate();

    // Assert
    EXPECT_EQ(110264, static_cast<int>(result));
}

TEST(Sitkin_Dmitry_Deposit_Calculator,
    Can_Calculate_With_Monthly_Capitalization) {
    // Arrange
    DepositCalculator dc;
    dc.SetInitialAmount(100000);
    dc.SetTerm(12);
    dc.SetAnnualInterest(10);
    dc.SetCapitalization(3);

    // Act
    double result = dc.Calculate();

    // Assert
    EXPECT_EQ(110471, static_cast<int>(result));
}

TEST(Sitkin_Dmitry_Deposit_Calculator,
    Can_Calculate_With_Yearly_Capitalization) {
    // Arrange
    DepositCalculator dc;
    dc.SetInitialAmount(100000);
    dc.SetTerm(24);
    dc.SetAnnualInterest(10);
    dc.SetCapitalization(4);

    // Act
    double result = dc.Calculate();

    // Assert
    EXPECT_EQ(121000, static_cast<int>(result));
}

TEST(Sitkin_Dmitry_Deposit_Calculator,
    Cant_Calculate_With_Unknown_Capitalization) {
    // Arrange
    DepositCalculator dc;
    dc.SetInitialAmount(100000);
    dc.SetTerm(24);
    dc.SetAnnualInterest(10);
    dc.SetCapitalization(5);

    // Assert
    EXPECT_ANY_THROW(dc.Calculate());
}
