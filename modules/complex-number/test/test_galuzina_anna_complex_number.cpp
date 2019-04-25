// Copyright 2019 Galuzina Anna

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Galuzina_Anna_ComplexNumberTest, Can_difference_three_complex) {
  // Arrange & Act
  ComplexNumber z1(1.0, 1.0);
  ComplexNumber z2(2.0, 1.0);
  ComplexNumber z3(3.0, 1.0);
  ComplexNumber dif(-4.0, -1.0);

  // Assert
  EXPECT_EQ(dif, z1 - z2 - z3);
}

TEST(Galuzina_Anna_ComplexNumberTest, Assignment_Returns_The_Value) {
  // Arrange
  ComplexNumber z1(0.0, 0.0);
  ComplexNumber z2(1.0, 1.0);

  // Assert
  EXPECT_EQ(z2, z1 = z2);
}

TEST(Galuzina_Anna_ComplexNumberTest, Copy_Constructor_Works) {
  // Arrange & Act
  ComplexNumber z1(0.0, 0.0);
  ComplexNumber z2(z1);

  // Assert
  EXPECT_EQ(z1, z2);
}

TEST(Galuzina_Anna_ComplexNumberTest,
The_multiplication_operation_is_commutative) {
  // Arrange
  ComplexNumber z1(1.0, 1.0);
  ComplexNumber z2(2.0, 1.0);

  // Assert
  EXPECT_EQ(z1 * z2, z2 * z1);
}

TEST(Galuzina_Anna_ComplexNumberTest, Can_assign_to_itself) {
  // Arrange
  ComplexNumber z(1.0, 1.0);

  // Assert
  EXPECT_NO_THROW(z = z);
}
