// Copyright 2019 Kruglov Yegor

#include <gtest/gtest.h>

#include <string>

#include "include/string_calculator.h"

TEST(String_Calculator_Test, Can_Set_Infix) {
    // Arrange
    StringCalculator sc;
    std::string str = "2+2";

    // Assert
    ASSERT_NO_THROW(sc.set_infix(str));
}

TEST(String_Calculator_Test, Correct_Set_Infix) {
    // Arrange
    StringCalculator sc;
    std::string str = "2+2";

    // Act
    sc.set_infix(str);
    std::string tmp = sc.get_infix();

    // Assert
    EXPECT_EQ(tmp, str);
}

TEST(String_Calculator_Test, Can_Transform_To_Postfix) {
    // Arrange
    StringCalculator sc;
    std::string str = "2+2";
    std::string tmp = "2 2+";

    // Act
    sc.set_infix(str);
    sc.Calculate();
    str = sc.get_postfix();

    // Assert
    EXPECT_EQ(str, tmp);
}

TEST(String_Calculator_Test, Can_Add_Two_Nums) {
    // Arrange
    StringCalculator sc;
    std::string str = "2+2";

    // Act
    sc.set_infix(str);
    double res = sc.Calculate();

    // Assert
    EXPECT_EQ(res, 4);
}

TEST(String_Calculator_Test, Can_Subtract) {
    // Arrange
    StringCalculator sc;
    std::string str = "4 - 2";

    // Act
    sc.set_infix(str);
    double res = sc.Calculate();

    // Assert
    EXPECT_EQ(res, 2);
}

TEST(String_Calculator_Test, Can_Multiply) {
    // Arrange
    StringCalculator sc;
    std::string str = "2 * 2";

    // Act
    sc.set_infix(str);
    double res = sc.Calculate();

    // Assert
    EXPECT_EQ(res, 4);
}

TEST(String_Calculator_Test, Can_Divide) {
    // Arrange
    StringCalculator sc;
    std::string str = "4 / 2";

    // Act
    sc.set_infix(str);
    double res = sc.Calculate();

    // Assert
    EXPECT_EQ(res, 2);
}

TEST(String_Calculator_Test, Can_Not_Divide_By_Zero) {
    // Arrange
    StringCalculator sc;
    std::string str = "4 / 0";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Rase_To_A_Power) {
    // Arrange
    StringCalculator sc;
    std::string str = "2^2";

    // Act
    sc.set_infix(str);
    double res = sc.Calculate();

    // Assert
    EXPECT_EQ(res, 4);
}

TEST(String_Calculator_Test, Can_Return_Num_Without_Signs) {
    // Arrange
    StringCalculator sc;
    std::string str = "222";

    // Act
    sc.set_infix(str);
    double res = sc.Calculate();

    // Assert
    EXPECT_EQ(res, 222);
}

TEST(String_Calculator_Test, Can_Not_Calculate_Plus_Begin) {
    // Arrange
    StringCalculator sc;
    std::string str = "+22";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Plus_End) {
    // Arrange
    StringCalculator sc;
    std::string str = "2+2+";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Minus_Begin) {
    // Arrange
    StringCalculator sc;
    std::string str = "-2+2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Minus_End) {
    // Arrange
    StringCalculator sc;
    std::string str = "2+2-";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Mult_Begin) {
    // Arrange
    StringCalculator sc;
    std::string str = "*2+2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Mult_End) {
    // Arrange
    StringCalculator sc;
    std::string str = "2+2*";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Divide_Begin) {
    // Arrange
    StringCalculator sc;
    std::string str = "/2+2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Divide_End) {
    // Arrange
    StringCalculator sc;
    std::string str = "2+2/";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Power_Begin) {
    // Arrange
    StringCalculator sc;
    std::string str = "^2+2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Power_End) {
    // Arrange
    StringCalculator sc;
    std::string str = "2+2^";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Two_Pluses) {
    // Arrange
    StringCalculator sc;
    std::string str = "2++2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Pluse_Near_Multyple) {
    // Arrange
    StringCalculator sc;
    std::string str = "2+*2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Pluse_Near_Pow) {
    // Arrange
    StringCalculator sc;
    std::string str = "2+^2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Two_Minuses) {
    // Arrange
    StringCalculator sc;
    std::string str = "2--2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Minus_Near_Multiple) {
    // Arrange
    StringCalculator sc;
    std::string str = "2*-2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Minus_Near_Pow) {
    // Arrange
    StringCalculator sc;
    std::string str = "2^-2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Two_Multiple) {
    // Arrange
    StringCalculator sc;
    std::string str = "2**2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Multiple_Near_Plus) {
    // Arrange
    StringCalculator sc;
    std::string str = "2*+2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Multiple_Near_Pow) {
    // Arrange
    StringCalculator sc;
    std::string str = "2*^2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Two_Divide) {
    // Arrange
    StringCalculator sc;
    std::string str = "2//2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Divide_Near_Plus) {
    // Arrange
    StringCalculator sc;
    std::string str = "2+/2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Divide_Near_Pow) {
    // Arrange
    StringCalculator sc;
    std::string str = "2^/2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Two_Pows) {
    // Arrange
    StringCalculator sc;
    std::string str = "2^^2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Pow_Near_Plus) {
    // Arrange
    StringCalculator sc;
    std::string str = "2^+2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_Pow_Near_Multiple) {
    // Arrange
    StringCalculator sc;
    std::string str = "2^*2";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Correct_Priority) {
    // Arrange
    StringCalculator sc;

    // Act
    int a = sc.get_priority('+');

    // Assert
    EXPECT_EQ(a, 1);
}

TEST(String_Calculator_Test, Exception_In_Priority) {
    // Arrange
    StringCalculator sc;

    // Act
    int a = sc.get_priority('c');

    // Assert
    EXPECT_EQ(a, -1);
}

TEST(String_Calculator_Test, Can_Calculate_Fraction) {
    // Arrange
    StringCalculator sc;
    std::string str = "2.5 + 2.5";

    // Act
    sc.set_infix(str);
    double res = sc.Calculate();

    // Assert
    EXPECT_EQ(res, 5);
}

TEST(String_Calculator_Test, Can_Not_Calculate_Mismatched_Brackets) {
    // Arrange
    StringCalculator sc;
    std::string str = ")2+2(";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Not_Calculate_More_Open_Brackets) {
    // Arrange
    StringCalculator sc;
    std::string str = "((((2+2)";

    // Act
    sc.set_infix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}

TEST(String_Calculator_Test, Can_Calculate_With_Different_Priorities) {
    // Arrange
    StringCalculator sc;
    std::string str = "2 + 2 * 2";

    // Act
    sc.set_infix(str);
    double res = sc.Calculate();

    // Assert
    EXPECT_EQ(res, 6);
}

TEST(String_Calculator_Test, Can_Calculate_Long_Expression_Without_Brackets) {
    // Arrange
    StringCalculator sc;
    std::string str = "2 + 2 ^ 2 + 2 * 2 - 4 / 2";

    // Act
    sc.set_infix(str);
    double res = sc.Calculate();

    // Assert
    EXPECT_EQ(res, 8);
}

TEST(String_Calculator_Test, Can_Calculate_Long_Expression_With_Brackets) {
    // Arrange
    StringCalculator sc;
    std::string str = "(2 + 2) * 2 - 2 ^ 3 / 4";

    // Act
    sc.set_infix(str);
    double res = sc.Calculate();

    // Assert
    EXPECT_EQ(res, 6);
}

TEST(String_Calculator_Test, Can_Calculate_Not_Empty_Stacks) {
    // Arrange
    StringCalculator sc;
    std::string str = "(2 + 2) * 2 - 2 ^ 3 / 4";

    // Act
    sc.set_stacks(4);
    sc.set_infix(str);
    double res = sc.Calculate();

    // Assert
    EXPECT_EQ(res, 6);
}

TEST(String_Calculator_Test, Can_Not_Calculate_With_One_Num) {
    // Arrange
    StringCalculator sc;
    std::string str = "2+";

    // Act
    sc.set_postfix(str);

    // Assert
    ASSERT_ANY_THROW(sc.Calculate());
}
