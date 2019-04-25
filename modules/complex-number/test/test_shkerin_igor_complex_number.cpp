// Copyright 2019 Shkerin Igor

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Shkerin_Igor_ComplexNumberTest, Can_Create_Negative_Complex) {
    // Arrange
    double re = -3.0;
    double im = -7.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Shkerin_Igor_ComplexNumberTest, Correct_Setter_And_Getter) {
    // Arrange
    double re1 = 1.0;
    double im1 = 2.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2;
    z2.setRe(z1.getRe());
    z2.setIm(z1.getIm());

    // Assert
    EXPECT_EQ(z1, z2);
}

TEST(Shkerin_Igor_ComplexNumberTest, Can_Multiplication_Complex_By_Zero) {
    // Arrange
    ComplexNumber z1(27.0, 11.0);
    ComplexNumber zero(0.0, 0.0);

    // Act
    ComplexNumber z3 = z1 * zero;
    ComplexNumber expected_z3(0.0, 0.0);

    // Assert
    EXPECT_EQ(z3, expected_z3);
}

TEST(Shkerin_Igor_ComplexNumberTest, Multiplication_By_One_Give_The_Same) {
    // Arrange
    ComplexNumber z1(27.0, 11.0);
    ComplexNumber z2(1.0, 0.0);

    // Act & Assert
    EXPECT_EQ(z1*z2, z1);
}

TEST(Shkerin_Igor_ComplexNumberTest, Different_Equal_Initialize_Is_Equal) {
    // Arrange
    double re = 1.0;
    double im = 2.0;

    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(1.0, 2.0);

    // Assert
    EXPECT_EQ(z1, z2);
}
