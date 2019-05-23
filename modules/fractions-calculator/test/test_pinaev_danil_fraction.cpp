// Copyright 2019 Pinaev Danil

#include <gtest/gtest.h>

#include "include/fraction.h"

TEST(Pinaev_Danil_FractionTest, NOD_Test) {
    // Arrange
    int x;
    Fraction a;
    // Act

    x = a.Nod(28, 49);

    // Assert
    EXPECT_EQ(x, 7);
}

TEST(Pinaev_Danil_FractionTest, Compare_Test) {
    // Arrange
    Fraction a(123, -123);
    Fraction b(123, -123);
    // Act
    // Assert
    ASSERT_TRUE(a == b);
}

TEST(Pinaev_Danil_FractionTest, Uncompare_Test) {
    // Arrange
    Fraction a(123, 123);
    Fraction b(123, -123);
    // Act
    // Assert
    ASSERT_TRUE(a != b);
}

TEST(Pinaev_Danil_FractionTest, Copy_Test) {
    // Arrange
    Fraction a;
    Fraction b(123, -123);

    // Act
    a = b;

    // Assert
    EXPECT_EQ(a, b);
}

TEST(Pinaev_Danil_FractionTest, Copy_Constructor_Test) {
    // Arrange
    Fraction a(123, -123);

    // Act
    Fraction b(a);

    // Assert
    EXPECT_EQ(a, b);
}

TEST(Pinaev_Danil_FractionTest, Can_Create_Fraction) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_THROW(Fraction());
}

TEST(Pinaev_Danil_FractionTest, Cant_Create_Zero_Den_Fraction ) {
    // Arrange
    // Act
    // Assert
    ASSERT_ANY_THROW(Fraction(1, 0));
}

TEST(Pinaev_Danil_FractionTest, Cant_Set_Zero_Den) {
     // Arrange
     Fraction a;
     // Act
     // Assert
     ASSERT_ANY_THROW(a.SetDen(0));
}

TEST(Pinaev_Danil_FractionTest, Can_Add_Fractions) {
    // Arrange
    Fraction a(3, 8);
    Fraction b(5, 2);
    Fraction res(23, 8);
    Fraction x;

    // Act
    x = a + b;

    // Assert
    EXPECT_EQ(x, res);
}

TEST(Pinaev_Danil_FractionTest, Can_Subtract_Fractions) {
    // Arrange
    Fraction a(3, 8);
    Fraction b(5, 2);
    Fraction res(-17, 8);
    Fraction x;

    // Act
    x = a - b;

    // Assert
    EXPECT_EQ(x, res);
}

TEST(Pinaev_Danil_FractionTest, Can_Multiply_Fractions) {
    // Arrange
    Fraction a(3, 8);
    Fraction b(5, 2);
    Fraction res(15, 16);
    Fraction x;

    // Act
    x = a * b;

    // Assert
    EXPECT_EQ(x, res);
}

TEST(Pinaev_Danil_FractionTest, Can_Divide_Fractions) {
    // Arrange
    Fraction a(3, 8);
    Fraction b(5, 2);
    Fraction res(3, 20);
    Fraction x;

    // Act
    x = a / b;

    // Assert
    EXPECT_EQ(x, res);
}
