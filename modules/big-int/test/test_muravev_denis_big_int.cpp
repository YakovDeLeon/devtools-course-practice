// Copyright 2019 Muravev Denis

#include <gtest/gtest.h>
#include "include/big_int.h"

TEST(Big_Int_Test, Can_Create_Empty_Number) {
    // Arrange & Act
    BigInt a;

    // Assert
    EXPECT_EQ(0, a.BigIntToInt());
}

TEST(Big_Int_Test, Can_Create_Positive_Number) {
    // Arrange & Act
    BigInt a(9223372036854775807);

    // Assert
    EXPECT_EQ(9223372036854775807, a.BigIntToInt());
}

TEST(Big_Int_Test, Can_Create_Negative_Number) {
    // Arrange & Act
    BigInt a(-1000000000);

    // Assert
    EXPECT_EQ(-1000000000, a.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_Copy_Constructor) {
    // Arrange
    BigInt a(1000000000);

    // Act
    BigInt b(a);

    // Assert
    EXPECT_EQ(1000000000, b.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_String_Constructor) {
    // Arrange & Act
    BigInt a("-9223372036854775807");

    // Assert
    EXPECT_EQ(-9223372036854775807, a.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_Assignment_Operator) {
    // Arrange
    BigInt a(999999999);
    BigInt b(-9223372036854775807);

    // Act
    b = a;

    // Assert
    EXPECT_EQ(999999999, b.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_Number_Assignment_Operator_For_Positive_Number) {
    // Arrange
    BigInt a;

    // Act
    a = 1000000000;

    // Assert
    EXPECT_EQ(1000000000, a.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_Number_Assignment_Operator_For_Negative_Number) {
    // Arrange
    BigInt a;

    // Act
    a = -9223372036854775807;

    // Assert
    EXPECT_EQ(-9223372036854775807, a.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_Container_Operator) {
    // Arrange
    BigInt a(1337000000000);

    // Act
    int res = a[1];

    // Assert
    EXPECT_EQ(1337, res);
}

TEST(Big_Int_Test, Can_Get_Size) {
    // Arrange & Act
    BigInt a(1000000000);

    // Assert
    EXPECT_EQ(2, a.getSize());
}

TEST(Big_Int_Test, Can_Get_Sign) {
    // Arrange & Act
    BigInt a(451);
    BigInt b(-322);

    // Assert
    EXPECT_EQ(1, a.getSign());
    EXPECT_EQ(-1, b.getSign());
}

TEST(Big_Int_Test, Can_Call_Convert_Big_Int_To_String) {
    // Arrange & Act
    BigInt a(-9223372036854775807);

    // Assert
    EXPECT_EQ("-9223372036854775807", a.BigIntToString());
}

TEST(Big_Int_Test, Can_Call_Convert_Big_Int_Zero_To_String) {
    // Arrange & Act
    BigInt a(0);

    // Assert
    EXPECT_EQ("0", a.BigIntToString());
}

TEST(Big_Int_Test, Can_Call_Convert_Big_Int_To_Int) {
    // Arrange & Act
    BigInt a(9223372036854775807);

    // Assert
    EXPECT_EQ(9223372036854775807, a.BigIntToInt());
}

// Operator Sum
TEST(Big_Int_Test, Can_Call_Operator_Sum_For_Left_Positive_And_Right_Positive) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = 999999999;
    b = 1;
    res = a + b;

    // Assert
    EXPECT_EQ(1000000000, res.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_Operator_Sum_For_Left_Negative_And_Right_Positive) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = -1000000000;
    b = 1;
    res = a + b;

    // Assert
    EXPECT_EQ(-999999999, res.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_Operator_Sum_For_Left_Positive_And_Right_Negative) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = 1;
    b = -1;
    res = a + b;

    // Assert
    EXPECT_EQ(0, res.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_Operator_Sum_For_Left_Negative_And_Right_Negative) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = -2009;
    b = -10;
    res = a + b;

    // Assert
    EXPECT_EQ(-2019, res.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_Operator_Sum_For_Left_Less_Right) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = 1;
    b = -1000000000;
    res = a + b;

    // Assert
    EXPECT_EQ(-999999999, res.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_Operator_Sum_For_Left_More_Right) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = 8999999999999999999;
    b = 1;
    res = a + b;

    // Assert
    EXPECT_EQ(9000000000000000000, res.BigIntToInt());
}

// Operator Subtraction
TEST(Big_Int_Test,
    Can_Call_Operator_Subtraction_For_Left_Positive_And_Right_Positive) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = 1000000000;
    b = 1;
    res = a - b;

    // Assert
    EXPECT_EQ(999999999, res.BigIntToInt());
}

TEST(Big_Int_Test,
    Can_Call_Operator_Subtraction_For_Left_Negative_And_Right_Positive) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = -999999999;
    b = 1;
    res = a - b;

    // Assert
    EXPECT_EQ(-1000000000, res.BigIntToInt());
}

TEST(Big_Int_Test,
    Can_Call_Operator_Subtraction_For_Left_Positive_And_Right_Negative) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = 1;
    b = -999999999;
    res = a - b;

    // Assert
    EXPECT_EQ(1000000000, res.BigIntToInt());
}

TEST(Big_Int_Test,
    Can_Call_Operator_Subtraction_For_Left_Negative_And_Right_Negative) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = -2009;
    b = -10;
    res = a - b;

    // Assert
    EXPECT_EQ(-1999, res.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_Operator_Subtraction_For_Left_More_Right) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = 9000000000000000000;
    b = 1;
    res = a - b;

    // Assert
    EXPECT_EQ(8999999999999999999, res.BigIntToInt());
}

// Operator Multiplication
TEST(Big_Int_Test, Can_Call_Operator_Multiplication_At_Zero) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = 102030201;
    b = 0;
    res = a * b;

    // Assert
    EXPECT_EQ(0, res.BigIntToInt());
}

TEST(Big_Int_Test,
    Can_Call_Operator_Multiplication_Positive_And_Right_Positive) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = 102030201;
    b = 101010101;
    res = a * b;

    // Assert
    EXPECT_EQ(10306080908060301, res.BigIntToInt());
}

TEST(Big_Int_Test,
    Can_Call_Operator_Multiplication_For_Left_Negative_And_Right_Positive) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = -102030201;
    b = 101010101;
    res = a * b;

    // Assert
    EXPECT_EQ(-10306080908060301, res.BigIntToInt());
}

TEST(Big_Int_Test,
    Can_Call_Operator_Multiplication_For_Left_Positive_And_Right_Negative) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = 102030201;
    b = -101010101;
    res = a * b;

    // Assert
    EXPECT_EQ(-10306080908060301, res.BigIntToInt());
}

TEST(Big_Int_Test,
    Can_Call_Operator_Multiplication_For_Left_Negative_And_Right_Negative) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = -102030201;
    b = -101010101;
    res = a * b;

    // Assert
    EXPECT_EQ(10306080908060301, res.BigIntToInt());
}

// Operator Division
TEST(Big_Int_Test, Can_Call_Operator_Division_For_Divide_By_Zero) {
    // Arrange & Act
    BigInt a(321);
    BigInt b(0);

    // Assert
    EXPECT_ANY_THROW(a / b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_Division_For_Left_Negative_And_Right_Positive) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = -9223372036854775807;
    b = 36854775807;
    res = a / b;

    // Assert
    EXPECT_EQ(-250262600, res.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_Operator_Division_For_Equal_Numbers) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = 321;
    b = 321;
    res = a / b;

    // Assert
    EXPECT_EQ(1, res.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_Operator_Division_For_Left_Less_Right) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = 123;
    b = 321;
    res = a / b;

    // Assert
    EXPECT_EQ(0, res.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_Operator_Division_For_Left_More_Right) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = 321;
    b = 123;
    res = a / b;

    // Assert
    EXPECT_EQ(2, res.BigIntToInt());
}

// Operator Remainder
TEST(Big_Int_Test, Can_Call_Operator_Remainder_For_Equal_Numbers) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = 321;
    b = 321;
    res = a % b;

    // Assert
    EXPECT_EQ(0, res.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_Operator_Remainder_For_Left_Less_Right) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = 123;
    b = 321;
    res = a % b;

    // Assert
    EXPECT_EQ(123, res.BigIntToInt());
}

TEST(Big_Int_Test, Can_Call_Operator_Remainder_For_Left_More_Right) {
    // Arrange
    BigInt a;
    BigInt b;
    BigInt res;

    // Act
    a = 321;
    b = 123;
    res = a % b;

    // Assert
    EXPECT_EQ(75, res.BigIntToInt());
}

// Operator Less
TEST(Big_Int_Test, Can_Call_Operator_Less_For_Equal_Numbers) {
    // Arrange & Act
    BigInt a(0);
    BigInt b(0);

    // Assert
    EXPECT_EQ(0, a < b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_Less_For_Left_Negative_And_Right_Positive) {
    // Arrange & Act
    BigInt a(-1);
    BigInt b(1);

    // Assert
    EXPECT_EQ(1, a < b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_Less_For_Left_Positive_And_Right_Negative) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(-1);

    // Assert
    EXPECT_EQ(0, a < b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_Less_For_Left_Negative_And_Right_Negative) {
    // Arrange & Act
    BigInt a(-2);
    BigInt b(-1);

    // Assert
    EXPECT_EQ(1, a < b);
}

TEST(Big_Int_Test, Can_Call_Operator_Less_For_Left_Less_Right) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(2);

    // Assert
    EXPECT_EQ(1, a < b);
}

TEST(Big_Int_Test, Can_Call_Operator_Less_For_Left_More_Right) {
    // Arrange & Act
    BigInt a(2);
    BigInt b(1);

    // Assert
    EXPECT_EQ(0, a < b);
}

TEST(Big_Int_Test, Can_Call_Operator_Less_For_Left_Size_Less_Right_Size) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(1000000001);

    // Assert
    EXPECT_EQ(1, a < b);
}

TEST(Big_Int_Test, Can_Call_Operator_Less_For_Left_Size_More_Right_Size) {
    // Arrange & Act
    BigInt a(1000000001);
    BigInt b(1);

    // Assert
    EXPECT_EQ(0, a < b);
}

// Operator More
TEST(Big_Int_Test, Can_Call_Operator_More_For_Equal_Numbers) {
    // Arrange & Act
    BigInt a(0);
    BigInt b(0);

    // Assert
    EXPECT_EQ(0, a > b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_More_For_Left_Negative_And_Right_Positive) {
    // Arrange & Act
    BigInt a(-1);
    BigInt b(1);

    // Assert
    EXPECT_EQ(0, a > b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_More_For_Left_Positive_And_Right_Negative) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(-1);

    // Assert
    EXPECT_EQ(1, a > b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_More_For_Left_Negative_And_Right_Negative) {
    // Arrange & Act
    BigInt a(-2);
    BigInt b(-1);

    // Assert
    EXPECT_EQ(0, a > b);
}

TEST(Big_Int_Test, Can_Call_Operator_More_For_Left_Less_Right) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(2);

    // Assert
    EXPECT_EQ(0, a > b);
}

TEST(Big_Int_Test, Can_Call_Operator_More_For_Left_More_Right) {
    // Arrange & Act
    BigInt a(2);
    BigInt b(1);

    // Assert
    EXPECT_EQ(1, a > b);
}

TEST(Big_Int_Test, Can_Call_Operator_More_For_Left_Size_Less_Right_Size) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(1000000001);

    // Assert
    EXPECT_EQ(0, a > b);
}

TEST(Big_Int_Test, Can_Call_Operator_More_For_Left_Size_More_Right_Size) {
    // Arrange & Act
    BigInt a(1000000001);
    BigInt b(1);

    // Assert
    EXPECT_EQ(1, a > b);
}

// Operator Less Or Equal
TEST(Big_Int_Test, Can_Call_Operator_Less_Or_Equal_For_Equal_Numbers) {
    // Arrange & Act
    BigInt a(0);
    BigInt b(0);

    // Assert
    EXPECT_EQ(1, a <= b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_Less_Or_Equal_For_Left_Negative_And_Right_Positive) {
    // Arrange & Act
    BigInt a(-1);
    BigInt b(1);

    // Assert
    EXPECT_EQ(1, a <= b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_Less_Or_Equal_For_Left_Positive_And_Right_Negative) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(-1);

    // Assert
    EXPECT_EQ(0, a <= b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_Less_Or_Equal_For_Left_Negative_And_Right_Negative) {
    // Arrange & Act
    BigInt a(-2);
    BigInt b(-1);

    // Assert
    EXPECT_EQ(1, a <= b);
}

TEST(Big_Int_Test, Can_Call_Operator_Less_Or_Equal_For_Left_Less_Right) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(2);

    // Assert
    EXPECT_EQ(1, a <= b);
}

TEST(Big_Int_Test, Can_Call_Operator_Less_Or_Equal_For_Left_More_Right) {
    // Arrange & Act
    BigInt a(2);
    BigInt b(1);

    // Assert
    EXPECT_EQ(0, a <= b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_Less_Or_Equal_For_Left_Size_Less_Right_Size) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(1000000001);

    // Assert
    EXPECT_EQ(1, a <= b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_Less_Or_Equal_For_Left_Size_More_Right_Size) {
    // Arrange & Act
    BigInt a(1000000001);
    BigInt b(1);

    // Assert
    EXPECT_EQ(0, a <= b);
}

// Operator More Or Equal
TEST(Big_Int_Test, Can_Call_Operator_More_Or_Equal_For_Equal_Numbers) {
    // Arrange & Act
    BigInt a(0);
    BigInt b(0);

    // Assert
    EXPECT_EQ(1, a >= b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_More_Or_Equal_For_Left_Negative_And_Right_Positive) {
    // Arrange & Act
    BigInt a(-1);
    BigInt b(1);

    // Assert
    EXPECT_EQ(0, a >= b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_More_Or_Equal_For_Left_Positive_And_Right_Negative) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(-1);

    // Assert
    EXPECT_EQ(1, a >= b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_More_Or_Equal_For_Left_Negative_And_Right_Negative) {
    // Arrange & Act
    BigInt a(-2);
    BigInt b(-1);

    // Assert
    EXPECT_EQ(0, a >= b);
}

TEST(Big_Int_Test, Can_Call_Operator_More_Or_Equal_For_Left_Less_Right) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(2);

    // Assert
    EXPECT_EQ(0, a >= b);
}

TEST(Big_Int_Test, Can_Call_Operator_More_Or_Equal_For_Left_More_Right) {
    // Arrange & Act
    BigInt a(2);
    BigInt b(1);

    // Assert
    EXPECT_EQ(1, a >= b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_More_Or_Equal_For_Left_Size_Less_Right_Size) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(1000000001);

    // Assert
    EXPECT_EQ(0, a >= b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_More_Or_Equal_For_Left_Size_More_Right_Size) {
    // Arrange & Act
    BigInt a(1000000001);
    BigInt b(1);

    // Assert
    EXPECT_EQ(1, a >= b);
}

// Operator Equal
TEST(Big_Int_Test, Can_Call_Operator_Equal_For_Equal_Numbers) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(1);

    // Assert
    EXPECT_EQ(1, a == b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_Equal_For_Left_Negative_And_Right_Positive) {
    // Arrange & Act
    BigInt a(-1);
    BigInt b(1);

    // Assert
    EXPECT_EQ(0, a == b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_Equal_For_Left_Positive_And_Right_Negative) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(-1);

    // Assert
    EXPECT_EQ(0, a == b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_Equal_For_Left_Negative_And_Right_Negative) {
    // Arrange & Act
    BigInt a(-2);
    BigInt b(-1);

    // Assert
    EXPECT_EQ(0, a == b);
}

TEST(Big_Int_Test, Can_Call_Operator_Equal_For_Left_Less_Right) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(2);

    // Assert
    EXPECT_EQ(0, a == b);
}

TEST(Big_Int_Test, Can_Call_Operator_Equal_For_Left_More_Right) {
    // Arrange & Act
    BigInt a(2);
    BigInt b(1);

    // Assert
    EXPECT_EQ(0, a == b);
}

TEST(Big_Int_Test, Can_Call_Operator_Equal_For_Left_Size_Less_Right_Size) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(1000000001);

    // Assert
    EXPECT_EQ(0, a == b);
}

TEST(Big_Int_Test, Can_Call_Operator_Equal_For_Left_Size_More_Right_Size) {
    // Arrange & Act
    BigInt a(1000000001);
    BigInt b(1);

    // Assert
    EXPECT_EQ(0, a == b);
}

// Operator Not Equal
TEST(Big_Int_Test, Can_Call_Operator_Not_Equal_For_Equal_Numbers) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(1);

    // Assert
    EXPECT_EQ(0, a != b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_Not_Equal_For_Left_Negative_And_Right_Positive) {
    // Arrange & Act
    BigInt a(-1);
    BigInt b(1);

    // Assert
    EXPECT_EQ(1, a != b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_Not_Equal_For_Left_Positive_And_Right_Negative) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(-1);

    // Assert
    EXPECT_EQ(1, a != b);
}

TEST(Big_Int_Test,
    Can_Call_Operator_Not_Equal_For_Left_Negative_And_Right_Negative) {
    // Arrange & Act
    BigInt a(-2);
    BigInt b(-1);

    // Assert
    EXPECT_EQ(1, a != b);
}

TEST(Big_Int_Test, Can_Call_Operator_Not_Equal_For_Left_Less_Right) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(2);

    // Assert
    EXPECT_EQ(1, a != b);
}

TEST(Big_Int_Test, Can_Call_Operator_Not_Equal_For_Left_More_Right) {
    // Arrange & Act
    BigInt a(2);
    BigInt b(1);

    // Assert
    EXPECT_EQ(1, a != b);
}

TEST(Big_Int_Test, Can_Call_Operator_Not_Equal_For_Left_Size_Less_Right_Size) {
    // Arrange & Act
    BigInt a(1);
    BigInt b(1000000001);

    // Assert
    EXPECT_EQ(1, a != b);
}

TEST(Big_Int_Test, Can_Call_Operator_Not_Equal_For_Left_Size_More_Right_Size) {
    // Arrange & Act
    BigInt a(1000000001);
    BigInt b(1);

    // Assert
    EXPECT_EQ(1, a != b);
}
