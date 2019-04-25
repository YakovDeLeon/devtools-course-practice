// Copyright 2019 Kondrina Tatyana

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kondrina_Tatyana_ComplexNumber, Can_GetRe_And_GetIm) {
    // Arrange
    ComplexNumber z(2.0, 3.0);

    // Assert
    EXPECT_EQ(2.0, z.getRe());
    EXPECT_EQ(3.0, z.getIm());
}

TEST(Kondrina_Tatyana_ComplexNumber, Can_Assign_Some_Numbers) {
    // Arrange
    ComplexNumber z1(3.0, 4.0);
    ComplexNumber z2(2.0, 3.0);
    ComplexNumber z3(4.0, 5.0);

    // Act
    z1 = z2 = z3;

    // Assert
    EXPECT_TRUE(z1 == z3);
}

TEST(Kondrina_Tatyana_ComplexNumber, Check_Correct_Sequence_Of_Actions) {
    // Arrange
    ComplexNumber z1(3.0, 4.0);
    ComplexNumber z2(4.0, 6.0);
    ComplexNumber z3(2.0, 3.0);

    // Act
    ComplexNumber res = z1 + z2 / z3;
    ComplexNumber res1 = z2 / z3;
    res1 = res1 + z1;

    // Assert
    EXPECT_EQ(res, res1);
}

TEST(Kondrina_Tatyana_ComplexNumber, Can_Multi_Some_Numbers) {
    // Arrange
    ComplexNumber z(2.0, 3.0);
    ComplexNumber z1(3.0, 4.0);
    ComplexNumber z2(5.0, 7.0);

    // Assert
    ComplexNumber expected_z(-149.0, 43.0);
    EXPECT_EQ(expected_z, z*z1*z2);
}
