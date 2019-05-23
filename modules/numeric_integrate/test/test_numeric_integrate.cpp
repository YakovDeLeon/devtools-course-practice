// Copyright 2019 Yakovlev Pavel

#include <gtest/gtest.h>

#include <cstdlib>
#include <iostream>

#include "include/numeric_integrate.h"

TEST(IntegrateTest, Can_use_set_and_get) {
    // Arrange
    NumericIntegrate c(0.0, 1.0);

    // Act
    c.Set_a(0.5);
    c.Set_b(5.0);

    // Assert
    EXPECT_EQ(0.5, c.Get_a());
    EXPECT_EQ(5.0, c.Get_b());
}

TEST(IntegrateTest, Can_use_default_constr) {
    // Arrange
    NumericIntegrate c;

    // Assert
    EXPECT_EQ(0.0, c.Get_a());
    EXPECT_EQ(1.0, c.Get_b());
}

TEST(IntegrateTest, Can_set_section) {
    // Arrange
    NumericIntegrate c(0.0, 1.0);

    // Act
    c.SetSection(4.5, 5.0);

    // Assert
    EXPECT_EQ(4.5, c.Get_a());
    EXPECT_EQ(5.0, c.Get_b());
}

TEST(IntegrateTest, Use_integrate_rectangle_method_a_b_EQ) {
    // Arrange
    NumericIntegrate c(6.7, 6.7);

    // Act
    double res = c.RectangleMethod(8);

    // Assert
    EXPECT_EQ(0.0, res);
}

TEST(IntegrateTest, Use_integrate_trapezium_method_a_b_EQ) {
    // Arrange
    NumericIntegrate c(6.7, 6.7);

    // Act
    double res = c.TrapeziumMethod(8);

    // Assert
    EXPECT_EQ(0.0, res);
}

TEST(IntegrateTest, Use_integrate_rectangle_method_a_and_minus_a) {
    // Arrange
    NumericIntegrate c(-2.0, 2.0);

    // Act
    double res = c.RectangleMethod(8);

    // Assert
    EXPECT_NEAR(0.0, res, 0.000001);
}

TEST(IntegrateTest, Use_integrate_trapezium_method_a_and_minus_a) {
    // Arrange
    NumericIntegrate c(-2.0, 2.0);

    // Act
    double res = c.TrapeziumMethod(8);

    // Assert
    EXPECT_NEAR(0.0, res, 0.000001);
}

TEST(IntegrateTest, Use_integrate_rectangle_method_a_b) {
    // Arrange
    NumericIntegrate c(0.0, 1.0);

    // Act
    double res = c.RectangleMethod(100000);

    // Assert
    EXPECT_NEAR(2.0/3.0, res, 0.000001);
}

TEST(IntegrateTest, Use_integrate_trapezium_method_a_b) {
    // Arrange
    NumericIntegrate c(0.0, 1.0);

    // Act
    double res = c.TrapeziumMethod(100000);

    // Assert
    EXPECT_NEAR(2.0/3.0, res, 0.000001);
}

TEST(IntegrateTest, Use_integrate_method_a_b_and_minus_a_b) {
    // Arrange
    NumericIntegrate c1(6.0, 8.0);
    NumericIntegrate c2(-8.0, -6.0);

    // Act
    double res_rect = c1.RectangleMethod() + c2.RectangleMethod();
    double res_trap = c1.TrapeziumMethod() + c2.TrapeziumMethod();

    // Assert
    EXPECT_NEAR(0.0, res_rect, 0.000001);
    EXPECT_NEAR(0.0, res_trap, 0.000001);
}

TEST(IntegrateTest, Can_set_incorrect_section) {
    // Arrange
    NumericIntegrate c;

    // Act
    c.SetSection(6.0, 5.0);

    // Assert
    EXPECT_EQ(5.0, c.Get_a());
    EXPECT_EQ(6.0, c.Get_b());
}

TEST(IntegrateTest, Can_set_a_larger_b) {
    // Arrange
    NumericIntegrate c1(0.0, 1.0);
    NumericIntegrate c2(0.0, 1.0);

    // Act
    c1.Set_a(6.0);
    c2.Set_b(-6.0);

    // Assert
    EXPECT_EQ(1.0, c1.Get_a());
    EXPECT_EQ(6.0, c1.Get_b());
    EXPECT_EQ(-6.0, c2.Get_a());
    EXPECT_EQ(0.0, c2.Get_b());
}
