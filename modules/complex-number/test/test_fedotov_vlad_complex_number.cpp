// Copyright 2019 Fedotov Vlad

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Fedotov_Vlad_ComplexNumberTest, Can_Create_With_No_Arguments) {
    // Act & Assert
    ASSERT_NO_THROW(ComplexNumber{});
}

TEST(Fedotov_Vlad_ComplexNumberTest, Can_Create_With_No_Arguments_Correctly) {
    // Act & Assert
    ComplexNumber z;
    EXPECT_EQ(0.0, z.getRe());
    EXPECT_EQ(0.0, z.getIm());
}

/*
TEST(Fedotov_Vlad_ComplexNumberTest, DISABLED_Can_Increment) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    ASSERT_NO_THROW(z++);
}

TEST(Fedotov_Vlad_ComplexNumberTest, DISABLED_Can_Increment_Correctly) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);
    z++;

    // Assert
    EXPECT_EQ(1.0, z.getRe());
    EXPECT_EQ(1.0, z.getIm());
}

TEST(Fedotov_Vlad_ComplexNumberTest, DISABLED_Can_Decrement) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    ASSERT_NO_THROW(z--);
}

TEST(Fedotov_Vlad_ComplexNumberTest, DISABLED_Can_Decrement_Correctly) {
    // Arrange
    double re = 0.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);
    z++;

    // Assert
    EXPECT_EQ(-1.0, z.getRe());
    EXPECT_EQ(-1.0, z.getIm());
}
*/

TEST(Fedotov_Vlad_ComplexNumberTest, Is_Precision_Enough) {
    // Arrange
    double re = 0.000000001;
    double im = 0.000000001;
    double re2 = 0.0;
    double im2 = 0.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_NE(z, z2);
}
