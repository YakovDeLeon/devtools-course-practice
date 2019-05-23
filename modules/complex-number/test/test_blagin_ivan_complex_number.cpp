// Copyright 2019 Blagin Ivan

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Blagin_Ivan_ComplexNumberTest, Can_Pass_Complex_In_lambda) {
    // Arrange
    ComplexNumber a(1.0, 2.0);
    ComplexNumber expRes(3.0, 3.0);
    ComplexNumber actRes;
    auto lambda = [](ComplexNumber& x){
        ComplexNumber b(2.0, 1.0);
        return x + b;
    };

    // Act
    actRes = lambda(a);

    // Assert
    EXPECT_EQ(expRes, actRes);
}

TEST(Blagin_Ivan_ComplexNumberTest, Can_Multiplication_By_Temp_Object) {
    // Arrange
    ComplexNumber a(1.0, 1.0);
    ComplexNumber res;

    // Act
    res = a * ComplexNumber(4.0, 2.0);

    // Assert
    EXPECT_EQ(res, ComplexNumber(2.0, 6.0));
}

TEST(Blagin_Ivan_ComplexNumberTest, Commutative_Property) {
    // Arrange
    ComplexNumber x(14.35, 2352.943);
    ComplexNumber y(14.32, 243552.943);

    // Assert
    EXPECT_EQ(x+y, y+x);
    EXPECT_EQ(x*y, y*x);
}

TEST(Blagin_Ivan_ComplexNumberTest, Associative_Property) {
    // Arrange
    ComplexNumber x(4.0, 3.0);
    ComplexNumber y(5.0, 6.0);
    ComplexNumber z(18.0, 32.0);

    // Assert
    EXPECT_EQ((x + (y + z) == (x + z) + y), true);
    EXPECT_EQ((x*(y*z) == (x*z)*y), true);
}

TEST(Blagin_Ivan_ComplexNumberTest, Distributive_Property) {
    // Arrange
    ComplexNumber x(13.0, 23.0);
    ComplexNumber y(6.0, 12.0);
    ComplexNumber z(4.0, 3.0);

    // Assert
    EXPECT_EQ(x*(y+z) == (x*y)+(x*z), true);
}
