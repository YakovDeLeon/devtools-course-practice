// Copyright 2019 Gribanov Mihail

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Gribanov_Mihail_ComplexNumberTest, Can_Assign_To_Himself) {
    // Arrange
    ComplexNumber c(-123.456, 78.999);
    // Act & Assert
    EXPECT_NO_THROW(c = c);
}

TEST(Gribanov_Mihail_ComplexNumberTest, Can_Assign_Several_Times) {
    // Arrange
    ComplexNumber c1(1.234, 56.78);
    ComplexNumber c2(1.0, 1.0);
    ComplexNumber c3(2.0, 2.0);
    // Act
    c1 = c2 = c3;
    // Assert
    EXPECT_TRUE(c3 == c1);
}

TEST(Gribanov_Mihail_ComplexNumberTest, Can_Sum_Several_Times) {
    // Arrange
    ComplexNumber c1(100.0, 100.0);
    ComplexNumber c2(-100.0, -200.0);
    ComplexNumber c3(50.0, 20.0);
    ComplexNumber c4(-50.0, 80.0);
    ComplexNumber exp_c(0.0, 0.0);

    // Act
    ComplexNumber res_c = c1 + c2 + c3 + c4;
    // Assert
    EXPECT_EQ(exp_c.getRe(), res_c.getRe());
    EXPECT_EQ(exp_c.getIm(), res_c.getIm());
}

TEST(Gribanov_Mihail_ComplexNumberTest, Can_Multiply_Several_Times) {
    // Arrange
    ComplexNumber c1(1.0, 1.0);
    ComplexNumber c2(5.0, -10.0);
    ComplexNumber c3(10.0, -1.0);
    ComplexNumber c4(-2.0, 2.0);
    ComplexNumber exp_c(-160.0, 420.0);
    // Act
    ComplexNumber res_c = c3 * c1 * c2 * c4;
    // Assert
    EXPECT_EQ(exp_c.getRe(), res_c.getRe());
    EXPECT_EQ(exp_c.getIm(), res_c.getIm());
}

TEST(Gribanov_Mihail_ComplexNumberTest, Order_Of_Operations_Is_Correct) {
    // Arrange
    ComplexNumber c1(10.0, 5.0);
    ComplexNumber c2(3.0, 1.0);
    ComplexNumber c3(4.0, 4.0);
    ComplexNumber c4(2.0, 2.0);
    ComplexNumber exp_c(27, 25);
    // Act
    ComplexNumber res_c = c1 * c2 + c3 / c4;
    // Assert
    EXPECT_EQ(exp_c.getRe(), res_c.getRe());
    EXPECT_EQ(exp_c.getIm(), res_c.getIm());
}
