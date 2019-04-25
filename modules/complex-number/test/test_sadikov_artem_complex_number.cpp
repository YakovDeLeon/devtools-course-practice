// Copyright 2019 Sadikov Artem

#include <gtest/gtest.h>

#include <cmath>

#include "include/complex_number.h"

TEST(Sadikov_Artem_ComplexNumberTest, Return_Zero_If_Multiplied_By_Zero) {
    // Arrange
    double re = 13.0;
    double im = 12.0;
    ComplexNumber z(re, im);
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber zr;

    // Act
    zr = z * z1;

    // Assert
    EXPECT_EQ(z1, zr);
}

TEST(Sadikov_Artem_ComplexNumberTest, Can_Create_Without_Args) {
    // Arrange & Act
    ComplexNumber z(0.0, 0.0);
    ComplexNumber zr;

    // Assert
    EXPECT_EQ(z, zr);
}

TEST(Sadikov_Artem_ComplexNumberTest, Can_Copy_Complex_Without_Args) {
    // Arrange
    ComplexNumber z;

    // Act
    ComplexNumber z1(z);

    // Assert
    EXPECT_EQ(z1.getRe(), 0.0);
    EXPECT_EQ(z1.getIm(), 0.0);
}

TEST(Sadikov_Artem_ComplexNumberTest, Copyed_Number_Is_Equal_To_Original) {
    // Arrange
    ComplexNumber z(12.0, 12.0);

    // Act
    ComplexNumber z1(z);

    // Assert
    EXPECT_EQ(z1, z);
}

TEST(Sadikov_Artem_ComplexNumberTest, Can_Assign_Complex) {
    // Arrange & Act
    ComplexNumber z(12.0, 12.0);
    ComplexNumber z1;

    // Assert
    ASSERT_NO_THROW(z1 = z);
}
