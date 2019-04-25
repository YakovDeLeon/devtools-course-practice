// Copyright 2019 Utsho Momen

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Utsho_Momen_ComplexNumberTest, Init_Imaginary_To_Zero) {
    // Arrange & Act
    ComplexNumber z;

    // Assert
    EXPECT_FLOAT_EQ(0, z.getIm());
}

TEST(Utsho_Momen_ComplexNumberTest, Multiply_Complex) {
    // Arrange
    ComplexNumber z1(45.65, 13.35);
    ComplexNumber z2(0.0, 34.75);

    // Act & Assert
    EXPECT_NO_THROW(z1 * z2);
}

TEST(Utsho_Momen_ComplexNumberTest, Comparison_Between_Two_Variable) {
    // Arrange
    ComplexNumber z1;
    ComplexNumber z2;

    // Assert
    EXPECT_TRUE(z1 == z2);
}

TEST(Utsho_Momen_ComplexNumberTest, Double_Real_Number) {
    // Arrange
    ComplexNumber z(1.0, 2.0);

    // Act
    double real = z.getRe();

    // Assert
    EXPECT_EQ(1.0, real);
}
