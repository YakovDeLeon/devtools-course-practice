// Copyright 2019 Evdokimov Artem

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Evdokimov_Artem_ComplexNumberTest, Copy_Has_Its_Own_Memory) {
    // Arrange
    double re = 1.1;
    double im = 1.1;

    // Act
    ComplexNumber a(re , im);
    ComplexNumber b(a);

    // Assert
    EXPECT_NE(&a , &b);
}

TEST(Evdokimov_Artem_ComplexNumberTest, Can_Assign) {
    // Arrange
    double re = 1.1;
    double im = 1.1;

    // Act
    ComplexNumber a(re , im);
    ComplexNumber b(1.1 , 1.1);

    // Assert
    EXPECT_EQ(a , b);
}
TEST(Evdokimov_Artem_ComplexNumberTest, Self_Assign) {
    // Arrange
    double re = 1.1;
    double im = 1.1;

    // Act
    ComplexNumber a(re , im);

    // Assert
    EXPECT_EQ(a , a);
}

TEST(Evdokimov_Artem_ComplexNumberTest, Can_Create_Object_Without_Arguments) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber a(re , im);
    ComplexNumber b;

    // Assert
    EXPECT_EQ(a , b);
}

TEST(Evdokimov_Artem_ComplexNumberTest, Can_Multiply_By_Zero) {
    // Arrange
    double re = 1.1;
    double im = 1.1;

    // Act
    ComplexNumber a(re , im);
    ComplexNumber b(0.0 , 0.0);

    // Assert
    EXPECT_EQ(b , a * b);
}
