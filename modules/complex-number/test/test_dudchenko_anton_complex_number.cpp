// Copyright 2019 Dudchenko Anton

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Dudchenko_Anton_ComplexNumberTest, Can_Equate_Some_Complexnumber) {
    // Arrange
    ComplexNumber num1(3.0, 14.0);
    ComplexNumber num2(15.92, 65.35);
    ComplexNumber num3(89.79, 32.38);
    // Act
    num1 = num2 = num3;
    // Assert
    EXPECT_TRUE(num3 == num1);
}

TEST(Dudchenko_Anton_ComplexNumberTest, Can_Execute_Multiple_Operations) {
    // Arrange
    ComplexNumber num1(3.0, 14.0);
    ComplexNumber num2(15.0, 92.0);
    ComplexNumber num3(65.0, 35.0);
    // Act
    ComplexNumber result = num2 + num1 * num3;
    // Assert
    ComplexNumber expectedResult(-280.0, 1107.0);
    EXPECT_EQ(expectedResult, result);
}


TEST(Dudchenko_Anton_ComplexNumberTest, Construct_Numbers_Without_Arguments) {
    // Act
    ComplexNumber num1;
    // Assert
    EXPECT_NO_THROW(num1.getRe());
    EXPECT_NO_THROW(num1.getIm());
}
