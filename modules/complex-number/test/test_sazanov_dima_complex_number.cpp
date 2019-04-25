// Copyright 2019 Sazanov Dima

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Sazanov_Dima_ComplexNumberTest, Comolex_Number_Can_Create_If_Empty) {
    // Arrange
    double n1 = 0.0;
    double n2 = 0.0;
    ComplexNumber cnn(n1 , n2);
    ComplexNumber cnr;

    // Assert
    EXPECT_EQ(cnn , cnr);
}

TEST(Sazanov_Dima_ComplexNumberTest, Complex_Number_Can_Copy) {
    // Arrange
    double n1 = 13.0;
    double n2 = 13.0;
    ComplexNumber cn(n1 , n2);

    // Act
    ComplexNumber cn1(cn);

    // Assert
    EXPECT_EQ(cn1 , cn);
}

TEST(Sazanov_Dima_ComplexNumberTest, Comolex_Number_Can_Create_A_Negative) {
    // Arrange
    double n1 = -10.0;
    double n2 = -11.0;

    // Act
    ComplexNumber z(n1 , n2);

    // Assert
    EXPECT_EQ(n1 , z.getRe());
    EXPECT_EQ(n2 , z.getIm());
}

TEST(Sazanov_Dima_ComplexNumberTest, Complex_Number_Can_Mp_By_Zero) {
    // Arrange
    double n1 = 13.0;
    double n2 = 37.0;
    double n0 = 0.0;
    ComplexNumber cn1(n1 , n2);
    ComplexNumber cn0(n0 , n0);
    ComplexNumber cnr;

    // Act
    cnr = cn1 * cn0;

    // Assert
    EXPECT_EQ(cnr , cn0);
}

TEST(Sazanov_Dima_ComplexNumberTest, Complex_Number_Can_Copy_If_Empty) {
    // Arrange
    ComplexNumber cn0;

    // Act
    ComplexNumber cn1(cn0);

    // Assert
    EXPECT_EQ(cn1.getRe() , 0.0);
    EXPECT_EQ(cn1.getIm() , 0.0);
}
