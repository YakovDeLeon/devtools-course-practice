// Copyright 2019 Emshanov Andrey

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Emshanov_Andrey_ComplexNumberTest, Can_Difference_Six_Complex_Numbers) {
    // Act
    ComplexNumber a(20., 20.);
    ComplexNumber b(3., 3.);
    ComplexNumber expect(5., 5.);
    ComplexNumber c = a - b - b - b - b - b;

     // Assert
    EXPECT_EQ(expect.getRe(), c.getRe());
    EXPECT_EQ(expect.getIm(), c.getIm());
}

TEST(Emshanov_Andrey_ComplexNumberTest, Can_Add_Complex_Four) {
    // Arrange
    ComplexNumber a1(2.0, 9.0);
    ComplexNumber a2(3.0, 11.0);
    ComplexNumber a3(4.0, 14.0);
    ComplexNumber a4(5.0, 14.0);

    // Act
    ComplexNumber a = a1 + a2 + a3 + a4;

    // Assert
    ComplexNumber expected_a(14.0, 48.0);
    EXPECT_EQ(expected_a, a);
}

TEST(Emshanov_Andrey_ComplexNumberTest,
    Multiplication_By_Imaginary_One_Works_Incorrectly) {
    // Arrange
    double d1 = 7.1;
    double d2 = 54.3;
    ComplexNumber a(d1, d2);
    ComplexNumber b(-d2, d1);
    ComplexNumber c(1.8, 1.3);

    // Act
    ComplexNumber e = b * c;

     // Assert
    EXPECT_TRUE(b != e);
}

TEST(Emshanov_Andrey_ComplexNumberTest, Can_Create_Negative_Real) {
    // Arrange
    double re = -3.98;
    double im = 1.0;

    // Act
    ComplexNumber a(re, im);

    // Assert
    EXPECT_EQ(re, a.getRe());
    EXPECT_EQ(im, a.getIm());
}
