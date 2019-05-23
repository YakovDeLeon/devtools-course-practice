// Copyright 2019 Utkin Konstantin

#include <gtest/gtest.h>

#include "include/quadratic_equation.h"

TEST(QuadraticEquation, Cant_Create_Equation_With_Zero_Coefs) {
    // Arrange & Act & Assert
    EXPECT_ANY_THROW(QuadraticEquation(0.0, 0.0, 1000.0));
}

TEST(QuadraticEquation, Can_Create_Equation_With_Positive_Coefs) {
    // Arrange & Act & Assert
    EXPECT_NO_THROW(QuadraticEquation(10035.0, 11020.0, 7800.0));
}

TEST(QuadraticEquation, Can_Create_Equation_With_Negative_Coefs) {
    // Arrange & Act & Assert
    EXPECT_NO_THROW(QuadraticEquation(-8230.0, -2095.0, -45.0));
}

TEST(QuadraticEquation, Dont_Exist_Real_Solutions_With_Negative_D) {
    // Arrange
    QuadraticEquation qe(20.0, 1.0, 3.0);

    // Act & Assert
    EXPECT_ANY_THROW(qe.GetX1());
    EXPECT_ANY_THROW(qe.GetX2());
}

TEST(QuadraticEquation, Exist_Real_Solutions_With_Positive_D) {
    // Arrange
    QuadraticEquation qe(1.0, -70.0, 600.0);

    // Act & Assert
    EXPECT_DOUBLE_EQ(qe.GetX1(), 60.0);
    EXPECT_DOUBLE_EQ(qe.GetX2(), 10.0);
}

TEST(QuadraticEquation, Exist_One_Real_Solution_With_Zero_Coef_A) {
    // Arrange
    QuadraticEquation qe(0.0, -150.0, 3000.0);

    // Act & Assert
    EXPECT_DOUBLE_EQ(qe.GetX1(), 20.0);
    EXPECT_DOUBLE_EQ(qe.GetX2(), 20.0);
}

TEST(QuadraticEquation, Can_Print) {
    // Arrange
    QuadraticEquation qe(-42.0, 42.0, 42.0);
    std::stringstream ss;

    // Act & Assert
    EXPECT_NO_THROW(ss << qe);
    EXPECT_EQ("-42*x^2 + 42*x + 42 = 0\n", ss.str());
}
