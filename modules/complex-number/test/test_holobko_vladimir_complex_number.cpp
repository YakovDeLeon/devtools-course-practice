// Copyright 2019 Holobko Vladimir

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Holobko_Vladimir_ComplexNumberTest, Can_CC_CV) {
    // Arrange
    double re = 77.7;
    double im = 55.5;

    // Act
    ComplexNumber a(re, im);
    ComplexNumber c(a);

    // Assert
    EXPECT_EQ(a.getRe(), c.getRe());
    EXPECT_EQ(a.getIm(), c.getIm());
}

TEST(Holobko_Vladimir_ComplexNumberTest, Can_Check_Equality) {
    // Act
    ComplexNumber x(5.0, 5.0);
    ComplexNumber y(5.0, 5.0);

    // Assert
    EXPECT_EQ(true, x == y);
}
TEST(Holobko_Vladimir_ComplexNumberTest, Can_Assign_To_Itself_Complex_Numbers) {
    // Act
    ComplexNumber a(5.0, 7.7);

    // Assert
    ASSERT_NO_THROW(a = a);
}

TEST(Holobko_Vladimir_ComplexNumberTest,
    Can_Difference_Four_Complex_Numbers) {
    // Act
    ComplexNumber a(10., 10.);
    ComplexNumber b(1., 1.);
    ComplexNumber expect(7., 7.);
    ComplexNumber c = a - b - b - b;

    // Assert
    EXPECT_EQ(expect.getRe(), c.getRe());
    EXPECT_EQ(expect.getIm(), c.getIm());
}
