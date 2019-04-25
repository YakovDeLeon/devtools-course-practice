// Copyright 2019 Yakovlev Pavel

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Yakovlev_Pavel_ComplexNumberTest, div_number_by_imaginary_unit) {
    // Arrange
    ComplexNumber z1(3.0, 2.0);
    ComplexNumber z2(0.0, 1.0);
    // Act
    ComplexNumber res = z1 / z2;
    ComplexNumber simple(2.0, -3.0);
    // Assert
    EXPECT_EQ(simple, res);
}

TEST(Yakovlev_Pavel_ComplexNumberTest, test_mult_conjugate_numbers) {
    // Arrange
    ComplexNumber z1(3.0, 2.0);
    ComplexNumber _z1(3.0, -2.0);
    // Act
    ComplexNumber res = z1 * _z1;
    ComplexNumber simple(13.0, 0.0);
    // Assert
    EXPECT_EQ(simple, res);
}

TEST(Yakovlev_Pavel_ComplexNumberTest, test_div_conjugate_numbers) {
    // Arrange
    ComplexNumber z1(3.0, 2.0);
    ComplexNumber _z1(3.0, -2.0);
    // Act
    ComplexNumber res = z1 / _z1;
    ComplexNumber simple(5.0 / 13.0, 12.0 / 13.0);
    // Assert
    EXPECT_EQ(simple, res);
}

TEST(Yakovlev_Pavel_ComplexNumberTest, test_complex_expression) {
    // Arrange
    ComplexNumber z1(3.0, 2.0);
    ComplexNumber z2(-3.0, 1.0);
    ComplexNumber z3(2.0, 1.0);
    // Act
    ComplexNumber res = (z1 + z2) * z3;
    ComplexNumber simple(-3.0, 6.0);
    // Assert
    EXPECT_EQ(simple, res);
}

TEST(Yakovlev_Pavel_ComplexNumberTest, test_complex_assignment) {
    // Arrange
    ComplexNumber z1(3.0, 2.0);
    ComplexNumber z2(0.0, 0.0);
    ComplexNumber z3(0.0, 0.0);
    // Act
    z3 = z2 = z1;
    // Assert
    EXPECT_EQ(true, z1 == z2);
    EXPECT_EQ(true, z1 == z3);
}
