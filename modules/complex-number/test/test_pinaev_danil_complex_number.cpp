// Copyright 2019 Pinaev Danil

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Pinaev_Danil_ComplexNumberTest, Can_Create_Complex_Numbers) {
    // Assert
    ASSERT_NO_THROW(ComplexNumber a(1.0, 1.0));
}

TEST(Pinaev_Danil_ComplexNumberTest, Have_A_Default_Value) {
    // Arrange
    ComplexNumber a;
    ComplexNumber b;

    // Assert
    ASSERT_EQ(a, b);
}

TEST(Pinaev_Danil_ComplexNumberTest, Defauld_Value_Is_Zero_Value) {
    // Arrange
    ComplexNumber a(0, 0);
    ComplexNumber b;

    // Assert
    ASSERT_EQ(a, b);
}

TEST(Pinaev_Danil_ComplexNumberTest, Can_Create_Arr_Complex_Numbers) {
    // Assert
    ASSERT_NO_THROW(ComplexNumber A[5]);
}

TEST(Pinaev_Danil_ComplexNumberTest, Can_Add_To_Arr) {
    // Arrange
    ComplexNumber a(1, -2);
    ComplexNumber A[5];

    // Assert
    ASSERT_NO_THROW(A[0] = a);
}
