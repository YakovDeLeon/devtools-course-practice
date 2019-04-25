// Copyright 2019 Sitkin Dmitry

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Sitkin_Dmitry_ComplexNumberTest, Division_Equals_Number_Is_One) {
    // Arrange
    ComplexNumber z(5.0, 3.0);

    // Act
    ComplexNumber division = z/z;

    // Assert
    double expected_re = 1.0;
    double expected_im = 0.0;
    EXPECT_EQ(expected_re, division.getRe());
    EXPECT_EQ(expected_im, division.getIm());
}

TEST(Sitkin_Dmitry_ComplexNumberTest, Multiplication_Conjugate_Complex) {
    // Arrange
    ComplexNumber z1(5.0, 3.0);
    ComplexNumber z2(5.0, -3.0);

    // Act
    ComplexNumber z3 = z1 * z2;

    // Assert
    ComplexNumber expected(34.0, 0.0);
    EXPECT_EQ(expected.getRe(), z3.getRe());
    EXPECT_EQ(expected.getIm(), z3.getIm());
}

TEST(Sitkin_Dmitry_ComplexNumberTest, Multiplication_By_Imiginary_One) {
    // Arrange
    ComplexNumber z1(5.0, 3.0);
    ComplexNumber z2(0.0, 1.0);

    // Act
    ComplexNumber z3 = z1 * z2;

    // Assert
    ComplexNumber expected(-3.0, 5.0);
    EXPECT_EQ(expected.getRe(), z3.getRe());
    EXPECT_EQ(expected.getIm(), z3.getIm());
}

TEST(Sitkin_Dmitry_ComplexNumberTest, Division_By_One) {
    // Arrange
    ComplexNumber z1(5.0, 3.0);
    ComplexNumber z2(1.0, 0.0);

    // Act
    ComplexNumber z3 = z1 / z2;

    // Assert
    ComplexNumber expected(5.0, 3.0);
    EXPECT_EQ(expected.getRe(), z3.getRe());
    EXPECT_EQ(expected.getIm(), z3.getIm());
}
