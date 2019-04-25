// Copyright 2019 Karasev Anton

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Karasev_Anton_ComplexNumberTest, Sum_Numb_Other_Sign) {
    // Arrange
    ComplexNumber x(2.5, 45.7);
    ComplexNumber y(-2.5, -45.7);

    // Act
    ComplexNumber z = x + y;

    // Assert
    ASSERT_EQ(z.getRe(), 0);
    ASSERT_EQ(z.getIm(), 0);
}

TEST(Karasev_Anton_ComplexNumberTest, Sum_Conj_Numb) {
    // Arrange
    ComplexNumber x(26, 7);
    ComplexNumber y(26, -7);

    // Act
    ComplexNumber z = x + y;

    // Assert
    ASSERT_EQ(z.getRe(), 52);
}

TEST(Karasev_Anton_ComplexNumberTest, Multiple_Conj_Numb) {
    // Arrange
    ComplexNumber x(5, 7);
    ComplexNumber y(5, -7);

    // Act
    ComplexNumber z = x * y;

    // Assert
    ASSERT_EQ(z.getRe(), 74);
}

TEST(Karasev_Anton_ComplexNumberTest, Prop_compar_not_equal) {
    // Arrange
    ComplexNumber x(8.1, 26);
    ComplexNumber y(0.9, 1);
    ComplexNumber z(9, 27);
    bool res = true;

    // Act
    res = z != x + y;

    // Assert
    ASSERT_NE(res, true);
}

TEST(Karasev_Anton_ComplexNumberTest, Correct_Mem_Al_And_Fill) {
    // Arrange
    ComplexNumber *z;

    // Act
    z = new ComplexNumber(22, -10);

    // Assert
    ASSERT_EQ(z->getRe(), 22);
    ASSERT_EQ(z->getIm(), -10);
}
