// Copyright Irina Astafeva 2019

#include <gtest/gtest.h>
#include "src/TSalary.cpp"

TEST(TSalary, can_create_object) {
    // Act & Assert
    ASSERT_NO_THROW(TSalary t(25000, 160, 150, 5, 5));
}  // 1

TEST(TSalary, cant_create_with_negative_salary) {
    // Act & Assert
    ASSERT_ANY_THROW(TSalary t(-25000, 160, 150, 5, 5));
}  // 2

TEST(TSalary, cant_create_with_zero_salary) {
    // Act & Assert
    ASSERT_ANY_THROW(TSalary t(0, 160, 150, 5, 5));
}  // 3

TEST(TSalary, cant_create_with_negative_norm) {
    // Act & Assert
    ASSERT_ANY_THROW(TSalary t(25000, -160, 150, 5, 5));
}  // 4

TEST(TSalary, cant_create_with_zero_norm) {
    // Act & Assert
    ASSERT_ANY_THROW(TSalary t(25000, 0, 150, 5, 5));
}  // 5

TEST(TSalary, cant_create_with_negative_worked_hours) {
    // Act & Assert
    ASSERT_ANY_THROW(TSalary t(25000, 160, -150, 5, 5));
}  // 6

TEST(TSalary, can_create_with_zero_worked_hours) {
    // Act & Assert
    ASSERT_NO_THROW(TSalary t(25000, 160, 0, 5, 5));
}  // 7

TEST(TSalary, cant_create_with_negative_overtime) {
    // Act & Assert
    ASSERT_ANY_THROW(TSalary t(25000, 160, 150, -5, 5));
}  // 8

TEST(TSalary, can_create_with_zero_overtime) {
    // Act & Assert
    ASSERT_NO_THROW(TSalary t(25000, 160, 150, 0, 5));
}  // 9

TEST(TSalary, cant_create_with_negative_vacantion) {
    // Act & Assert
    ASSERT_ANY_THROW(TSalary t(25000, 160, 150, 5, -5));
}  // 10

TEST(TSalary, can_create_with_zero_vacantion) {
    // Act & Assert
    ASSERT_NO_THROW(TSalary t(25000, 160, 150, 5, 0));
}  // 11

TEST(TSalary, can_calculate_payroll) {
    // Arrange
    TSalary t(25000, 160, 150, 5, 5);

    // Act & Assert
    ASSERT_NO_THROW(t.Payroll());
}  // 12

TEST(TSalary, calculate_payroll_right) {
    // Arrange
    TSalary t(25000, 160, 150, 5, 5);

    // Act & Assert
    ASSERT_DOUBLE_EQ(t.Payroll(), 23437.5);
}  // 13

TEST(TSalary, can_calculate_payroll_right_if_it_is_zero) {
    // Arrange
    TSalary t(25000, 160, 0, 0, 0);

    // Act & Assert
    ASSERT_DOUBLE_EQ(t.Payroll(), 0.0);
}  // 14
