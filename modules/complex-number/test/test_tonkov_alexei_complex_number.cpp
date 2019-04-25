// Copyright 2019 Tonkov Alexei

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Tonkov_Alexei_ComplexNumberTest, Creation_Without_Args) {
    // Arrange & Act
    ComplexNumber a(0.0, 0.0);
    ComplexNumber b;

    // Assert
    EXPECT_EQ(a, b);
}

TEST(Tonkov_Alexei_ComplexNumberTest, Equality) {
    // Arrange
    ComplexNumber a(1.0, 2.0);
    ComplexNumber b(1.0, 2.0);
    bool result;

    // Act
    result = a == b;

    // Assert
    ASSERT_TRUE(result);
}

TEST(Tonkov_Alexei_ComplexNumberTest, Non_Equality) {
    // Arrange
    ComplexNumber a(1.0, 2.0);
    ComplexNumber b(1.0, 2.0);
    bool result;

    // Act
    result = a != b;

    // Assert
    ASSERT_FALSE(result);
}

TEST(Tonkov_Alexei_ComplexNumberTest, Only_Re_Creation) {
    // Arrange
    double re = 1.0;
    double im = 0.0;

    // Act
    ComplexNumber a(re, im);

    // Assert
    EXPECT_EQ(re, a.getRe());
    EXPECT_EQ(im, a.getIm());
}

TEST(Tonkov_Alexei_ComplexNumberTest, Only_Im_Creation) {
    // Arrange
    double re = 0.0;
    double im = 1.0;

    // Act
    ComplexNumber b(re, im);

    // Assert
    EXPECT_EQ(re, b.getRe());
    EXPECT_EQ(im, b.getIm());
}
