// Copyright 2019 Vdovin Eugene

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Vdovin_Eugene_ComplexNumberTest, Can_Create_Zero_Two_Way) {
    // Arrange
    ComplexNumber cn(0.0, 0.0);
    ComplexNumber cn2;

    // Assert
    EXPECT_EQ(cn, cn2);
}

TEST(Vdovin_Eugene_ComplexNumberTest, Work_Triple_Assignment) {
    // Arrange
    ComplexNumber cn1(3.0, 4.0);
    ComplexNumber cn2(-5.0, 6.3);
    ComplexNumber cn3(-8.0, -9.3);

    // Act
    cn1 = cn2 = cn3;

    // Assert
    EXPECT_EQ(cn3, cn1);
    EXPECT_EQ(cn3, cn2);
}

TEST(Vdovin_Eugene_ComplexNumberTest, Mult_And_Div_Compensation) {
    // Arrange
    ComplexNumber cn1(4.0, 4.0);
    ComplexNumber cn2(5.0, 5.0);
    ComplexNumber cn3;

    // Act
    cn3 = (cn1 * cn2) / cn1;

    // Assert
    EXPECT_EQ(cn2, cn3);
}
