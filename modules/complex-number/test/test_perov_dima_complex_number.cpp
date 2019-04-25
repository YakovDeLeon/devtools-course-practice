// Copyright 2019 Perov Dima

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Perov_Dima_ComplexNumberTest, Can_Combination_Operations) {
    // Arrange
    double re1 = 1.0;
    double im1 = 1.0;
    double re2 = 1.0;
    double im2 = -1.0;
    double re3 = -1.0;
    double im3 = 1.0;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);
    ComplexNumber res(0, 0);

    // Act
    res = z3+z1*z2;

    // Assert
    double expectedRe = 1;
    double expectedIm = 1;
    EXPECT_EQ(expectedRe, res.getRe());
    EXPECT_EQ(expectedIm, res.getIm());
}

TEST(Perov_Dima_ComplexNumberTest, Check_Multiplication_Division_Priority) {
    // Arrange
    double re1 = 1.0;
    double im1 = 1.0;
    double re2 = 0.0;
    double im2 = 1.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber res(0, 0);
    ComplexNumber expectedRes(0, 0);

    // Act
    res = z1/z2*z2;
    expectedRes = (z1/z2)*z2;

    // Assert
    EXPECT_EQ(expectedRes, res);
}

TEST(Perov_Dima_ComplexNumberTest, Check_Comparison_Priority) {
    // Arrange
    double re1 = 1.0;
    double im1 = 1.0;
    double re2 = 1.0;
    double im2 = -1.0;
    double re3 = 0.0;
    double im3 = 2.0;
    bool res;
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3(re3, im3);

    // Act
    res = z1 == z2+z3;

    // Assert
    bool expectedRes = true;
    EXPECT_EQ(expectedRes, res);
}

TEST(Perov_Dima_ComplexNumberTest, Can_Degree) {
    // Arrange
    double re1 = 0.0;
    double im1 = 1.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber res(re1, im1);

    // Act
    for (int i = 0; i < 10; i++)
    res = res*z1;

    // Assert
    ComplexNumber expectedRes(0, -1);
    EXPECT_EQ(expectedRes, res);
}

TEST(Perov_Dima_ComplexNumberTest, Check_Set_Get) {
    // Arrange
    double re1 = 0.0;
    double im1 = 1.0;

    ComplexNumber z1(re1, im1);

    // Act
    ComplexNumber res(0, 0);
    res.setRe(z1.getRe());
    res.setIm(z1.getIm());

    // Assert
    EXPECT_EQ(res, z1);
}
