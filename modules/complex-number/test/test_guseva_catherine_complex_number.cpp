// Copyright 2019 Guseva Catherine

#include <gtest/gtest.h>

#include <cmath>

#include "include/complex_number.h"

TEST(Guseva_Catherine_ComplexNumberTest, Can_Create_Without_Args) {
    // Arrange & Act
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2;

    // Assert
    EXPECT_EQ(z1, z2);
}

TEST(Guseva_Catherine_ComplexNumberTest, Can_Multiply_By_Zero) {
    // Arrange
    ComplexNumber z1(4.0, 6.0);
    ComplexNumber z2(0.0, 0.0);

    // Act
    ComplexNumber z3 = z1 * z2;

    // Assert
    EXPECT_EQ(z2, z3);
}

TEST(Guseva_Catherine_ComplexNumberTest, Can_Assign_Complex) {
    // Arrange
    double re = 55.5;
    double im = 44.4;

    // Act
    ComplexNumber a(re, im);
    ComplexNumber c(2.0, 2.0);

    // Assert
    ASSERT_NO_THROW(c = a);
}

TEST(Guseva_Catherine_ComplexNumberTest, Can_Add_Complex_Twice) {
    // Arrange
    ComplexNumber z1(1.0, 3.0);
    ComplexNumber z2(1.0, 7.0);
    ComplexNumber z3(2.0, 2.0);

    // Act
    ComplexNumber z = z1 + z2 + z3;

    // Assert
    ComplexNumber expected_z(4.0, 12.0);
    EXPECT_EQ(expected_z, z);
}

TEST(Guseva_Catherine_ComplexNumberTest, Can_Subtract_Complex_Twice) {
    // Arrange
    ComplexNumber z1(10.0, 5.0);
    ComplexNumber z2(1.0, 3.0);
    ComplexNumber z3(5.0, 2.0);

    // Act
    ComplexNumber z = z1 - z2 - z3;

    // Assert
    ComplexNumber expected_z(4.0, 0.0);
    EXPECT_EQ(expected_z, z);
}
