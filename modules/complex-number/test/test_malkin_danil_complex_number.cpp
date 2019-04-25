// Copyright 2019 Malkin Danil

#include <gtest/gtest.h>
#include "include/complex_number.h"

TEST(Malkin_Danil_ComplexNumberTest, Two_Zero_Numbers_Equals) {
    // Arrange
    ComplexNumber a(0, 0);
    ComplexNumber b(0, 0);

    // Act & Assert
    EXPECT_TRUE(a == b);
}

TEST(Malkin_Danil_ComplexNumberTest, Sum_Two_Opposite_Equals_Zero) {
    // Arrange
    ComplexNumber a(2, -4);
    ComplexNumber b(-2, 4);
    ComplexNumber c(0, 0);

    // Act
    ComplexNumber res = a + b;

    // Assert
    EXPECT_EQ(c, res);
}

TEST(Malkin_Danil_ComplexNumberTest, Substract_Two_Same_Equals_Zero) {
    // Arrange
    ComplexNumber a(2, 4);
    ComplexNumber b(2, 4);
    ComplexNumber c(0, 0);

    // Act
    ComplexNumber res = a - b;

    // Assert
    EXPECT_EQ(c, res);
}
