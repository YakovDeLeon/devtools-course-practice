// Copyright 2019 Tolstikov Maksim

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Tolstikov_Maksim_ComplexNumberTest, Can_Sum_With_Negative_Complex_Number) {
    // Arrange
    ComplexNumber z1(4.0, 3.0);
    ComplexNumber z2(7.0, 1.0);
    ComplexNumber z(-7.0, -1.0);
    // Act
    ComplexNumber z3 = z1 - z2;
    ComplexNumber z4 = z1 + z;
    // Assert
    EXPECT_EQ(z3.getRe(), z4.getRe());
    EXPECT_EQ(z3.getIm(), z4.getIm());
}

TEST(Tolstikov_Maksim_ComplexNumberTest, Can_Complex_Number_Divide_By_Imagine) {
    // Arrange
    ComplexNumber z(5.0, 3.0);
    ComplexNumber z1(0.0, 2.0);
    // Act
    ComplexNumber z2 = z / z1;
    // Assert
    EXPECT_EQ(1.5, z2.getRe());
    EXPECT_EQ(-2.5, z2.getIm());
}

TEST(Tolstikov_Maksim_ComplexNumberTest, Can_Exponentiation) {
    // Arrange
    ComplexNumber z(4.0, 3.0);
    ComplexNumber z1;
    // Act
    z1 = z * z;
    // Assert
    EXPECT_EQ(7.0, z1.getRe());
    EXPECT_EQ(24.0, z1.getIm());
}

TEST(Tolstikov_Maksim_ComplexNumberTest, Divide_With_Equal_Values) {
    // Arrange
    ComplexNumber z(4.0, 3.0);
    // Act
    ComplexNumber z1 = z / z;
    // Assert
    EXPECT_EQ(1.0, z1.getRe());
    EXPECT_EQ(0.0, z1.getIm());
}

TEST(Tolstikov_Maksim_ComplexNumberTest, Can_Complex_Number_Divide_By_Real) {
    // Arrange
    ComplexNumber z1(2.0, 0.0);
    ComplexNumber z2(26.0, 14.0);
    // Act
    ComplexNumber z3 = z2 / z1;
    // Assert
    EXPECT_FLOAT_EQ(13.0, z3.getRe());
    EXPECT_EQ(7.0, z3.getIm());
}
