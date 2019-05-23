// Copyright 2019 Daria Koroleva

#include <gtest/gtest.h>
#include <limits>
#include "include/complex_number.h"

TEST(Koroleva_Daria_ComplexNumberTest, Can_Create_Complex_By_CopyConstructor) {
    // Arrange
    ComplexNumber a(1., 143.);
    // Act
    ComplexNumber b(a);
    // Assert
    EXPECT_EQ(a, b);
}

TEST(Koroleva_Daria_ComplexNumberTest, Can_Divide_By_Small_Number) {
    // Arrange
    const double eps = std::numeric_limits<double>::epsilon();
    ComplexNumber a(-32., 143.);
    ComplexNumber b(eps, eps);
    // Act
    // Assert
    ASSERT_NO_THROW(a/b);
}

TEST(Koroleva_Daria_ComplexNumberTest, Cant_Divide_By_Zero) {
    // Arrange
    ComplexNumber a(-32., 24.);
    ComplexNumber b(0., 0.);
    // Act
    // Assert
    ASSERT_ANY_THROW(a / b);
}

TEST(Koroleva_Daria_ComplexNumberTest, Can_Multiply_Three_ComplexNumbers) {
    // Arrange
    ComplexNumber a(-32., 24.);
    ComplexNumber b(0., -12.);
    ComplexNumber c(-12., 12.);
    // Act
    ComplexNumber res = a * b * c;
    // Assert
    EXPECT_EQ(-8064, res.getRe());
    EXPECT_EQ(-1152, res.getIm());
}
