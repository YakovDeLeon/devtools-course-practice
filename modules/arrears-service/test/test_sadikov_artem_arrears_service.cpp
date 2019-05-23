// Copyright 2019 Sadikov Artem

#include <gtest/gtest.h>

#include "include/arrears_service.h"

TEST(Sadikov_Artem_ArrearServiceTest, Can_Create_Client_With_Args) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(ArrearService(1, 1, 1, 1));
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Copy_Client) {
    // Arrange
    ArrearService c(1, 1, 1, 1);

    // Act & Assert
    ASSERT_NO_THROW(ArrearService c1(c));
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Calculate_Express_Pay) {
    // Arrange
    ArrearService c(100, 22, 20, 5);

    // Act & Assert
    EXPECT_NEAR(32.92059, c.GetExpress(), 0.0001);
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Calculate_Year_Pay) {
    // Arrange
    ArrearService c(10000, 10, 0, 5);

    // Act
    c.SetYearPay(500);

    // Assert
    EXPECT_NEAR(732.91, c.GetYearPay(), 0.01);
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Calculate_Fond) {
    // Arrange
    ArrearService c(300, 12, 15, 6);

    // Act & Assert
    EXPECT_NEAR(8.11518, c.Fond(), 0.00001);
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Set_Express) {
    // Arrange
    ArrearService c(300, 12, 15, 6);

    // Act
    c.SetDebt(500);
    c.SetExpress();

    // Act & Assert
    EXPECT_NEAR(136.612, c.GetExpress(), 0.001);
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Set_Debt) {
    // Arrange
    ArrearService c(1312, 12, 13, 5);

    // Act
    c.SetDebt(213);

    // Assert
    EXPECT_EQ(213, c.GetDebt());
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Set_Procent) {
    // Arrange
    ArrearService c(123, 123, 123, 123);

    // Act
    c.SetProcent(4);

    // Assert
    EXPECT_EQ(4, c.GetProcent());
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Set_Rate) {
    // Arrange
    ArrearService c(123, 12, 4, 5);

    // Act
    c.SetRate(3);

    // Assert
    EXPECT_EQ(3, c.GetRate());
}

TEST(Sadikov_Artem_ArrearServiceTest, Can_Set_Time) {
    // Arrange
    ArrearService c(123, 12, 1, 4);

    // Act
    c.SetTime(13);

    // Assert
    EXPECT_EQ(13, c.GetTime());
}

TEST(Sadikov_Artem_ArrearServiceTest, Throws_Exception_If_Invalid_Prog) {
    // Arrange
    ArrearService c(123, 123, 1, 3);

    // Act & Assert
    ASSERT_ANY_THROW(c.SetYearPay(0));
}

TEST(Sadikov_Artem_ArrearServiceTest, Throws_Exepction_If_Invalid_Debt) {
    // Arrange
    ArrearService c(123, 123, 13, 13);

    // Act & Arrange
    ASSERT_ANY_THROW(c.SetDebt(0));
}

TEST(Sadikov_Artem_ArrearServiceTest, Throw_Expection_If_Invalid_Procent) {
    // Arrange
    ArrearService c(123, 123, 12, 1);

    // Act & Arrange
    ASSERT_ANY_THROW(c.SetProcent(0));
}

TEST(Sadikov_Artem_ArrearServiceTest, Throw_Exepction_If_Invalid_Time) {
    // Arange
    ArrearService c(123, 123, 1, 2);

    // Act & Arrange
    ASSERT_ANY_THROW(c.SetTime(0));
}

TEST(Sadikov_Artem_ArrearServiceTest, Throw_Exepction_If_Invalid_Proc_Exp) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(ArrearService c(123, 0, 4, 5));
}

TEST(Sadikov_Artem_ArrearServiceTest, Throw_Exepction_If_Invalid_Time_Exp) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(ArrearService c(123, 2, 4, 0));
}
