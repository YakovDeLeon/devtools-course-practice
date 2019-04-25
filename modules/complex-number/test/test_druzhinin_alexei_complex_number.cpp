// Copyright 2019 Druzhinin Alexei

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Druzhinin_Alexei_ComplexNumberTest, Check_All_Operations_With_Priority) {
    // Arrange
    ComplexNumber z1(1.0, 1.0);
    ComplexNumber z2(2.0, 2.0);
    ComplexNumber z3(4.0, 0.0);
    ComplexNumber z4(-1.0, -1.0);
    ComplexNumber z5(5.0, 5.0);

    // Act
    ComplexNumber z = (z1 * z2 + z3 - z4) / z5;

    // Assert
    EXPECT_EQ(1.0, z.getRe());
    EXPECT_EQ(0.0, z.getIm());
}

TEST(Druzhinin_Alexei_ComplexNumberTest, Pow_Of_Imaginary_Unit) {
    // Arrange
    ComplexNumber z1(0, 1.0);
    bool res;

    // Act
    res = z1 == z1*z1*z1*z1*z1;

    // Assert
    ASSERT_TRUE(res);
}

TEST(Druzhinin_Alexei_ComplexNumberTest, Copy_Of_Complex_Number) {
    // Arrange
    ComplexNumber z1(5.0, 5.0);

    // Act
    ComplexNumber z2(z1);

    // Assert
    EXPECT_EQ(z1, z2);
}

