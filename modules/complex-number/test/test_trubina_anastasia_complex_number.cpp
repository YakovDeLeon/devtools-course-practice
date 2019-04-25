// Copyright 2019 Trubina Anastasia

#include <gtest/gtest.h>

#include <cfloat>

#include "include/complex_number.h"

TEST(Trubina_Anastasia_ComplexNumberTest, Property_Of_The_Imaginary_Unit) {
    // Arrange
    ComplexNumber i(0, 1.0);
    ComplexNumber n(-1.0, 0);
    bool res;

    // Act
    res = n == i * i;

    // Assert
    ASSERT_TRUE(res);
}

TEST(Trubina_Anastasia_ComplexNumberTest, Is_Additive_Inverse_Complex_Number) {
    // Arrange
    ComplexNumber dir(1.0, 1.0);
    ComplexNumber inv(-1.0, -1.0);
    ComplexNumber res(0, 0);

    // Act&Assert
    ASSERT_TRUE(res == dir + inv);
}

TEST(Trubina_Anastasia_ComplexNumberTest, Correctness_Of_Operation_Set) {
    // Arrange
    ComplexNumber res;

    // Act
    res.setRe(2.3);
    res.setIm(4.7);

    // Assert
    EXPECT_FLOAT_EQ(2.3, res.getRe());
    EXPECT_FLOAT_EQ(4.7, res.getIm());
}

TEST(Trubina_Anastasia_ComplexNumberTest, Is_Reciprocal_Complex_Number) {
    // Arrange
    ComplexNumber dir(3.0, 4.0);

    // Act
    ComplexNumber rec(dir.getRe() / (dir.getRe() * dir.getRe() +
        dir.getIm() * dir.getIm()), dir.getIm() / (dir.getRe() *
        dir.getRe() + dir.getIm() * dir.getIm()));

    // Assert
    EXPECT_FLOAT_EQ(0.12, rec.getRe());
    EXPECT_FLOAT_EQ(0.16, rec.getIm());
}

TEST(Trubina_Anastasia_ComplexNumberTest, Infinity_Not_Reciprocal_Null) {
    // Arrange
    ComplexNumber dir(0, 0);

    // Act
    ComplexNumber rec(dir.getRe() / (dir.getRe() * dir.getRe() +
        dir.getIm() * dir.getIm()), dir.getIm() / (dir.getRe() *
        dir.getRe() + dir.getIm() * dir.getIm()));

    // Assert
    EXPECT_NE(DBL_MAX, rec.getRe());
    EXPECT_NE(DBL_MAX, rec.getIm());
}
