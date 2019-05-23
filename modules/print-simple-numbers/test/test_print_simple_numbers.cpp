// Copyright 2019 by Zolotareva Olesya

#include <gtest/gtest.h>

#include "include/print-simple-numbers.h"

TEST(SimpleNumbersTest, The_Right_Border_Mistake) {
    // arrange
    SimpleNumbers check_eng;
    int a = 6;
    int b = -7;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_Left_Border_Mistake) {
    // arrange
    SimpleNumbers check_eng;
    int a = -10;
    int b = 7;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_negative_border_Mistake) {
    // arrange
    SimpleNumbers check_eng;
    int a = -5;
    int b = -13;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_check_big_array) {
    // arrange
    SimpleNumbers check_eng;
    int a = 6;
    int b = 20;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(5, res);
}

TEST(SimpleNumbersTest, The_Nullleft_Border_Mistake) {
    // arrange
    SimpleNumbers check_eng;
    int a = 0;
    int b = 4;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_Null_border_Mistake) {
    // arrange
    SimpleNumbers check_eng;
    int a = 0;
    int b = 0;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_Nullright_Border_Mistake) {
    // arrange
    SimpleNumbers check_eng;
    int a = 3;
    int b = 0;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_Big_Left_Border_Mistake) {
    // arrange
    SimpleNumbers check_eng;
    int a = 6;
    int b = 2;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_Null_Interval) {
    // arrange
    SimpleNumbers check_eng;
    int a = 5;
    int b = 5;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_first_Interval) {
    // arrange
    SimpleNumbers check_eng;
    int a = 0;
    int b = 1;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_Null_Numbers) {
    // arrange
    SimpleNumbers check_eng;
    int a = 9;
    int b = 10;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(0, res);
}

TEST(SimpleNumbersTest, One_Simple_Numbers) {
    // arrange
    SimpleNumbers check_eng;
    int a = 12;
    int b = 16;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(1, res);
}

TEST(SimpleNumbersTest, Few_Simple_Numbers) {
    // arrange
    SimpleNumbers check_eng;
    int a = 9;
    int b = 15;
    int res;
    // act
    res = check_eng.SizeOfArray(a, b);
    // assert
    EXPECT_EQ(2, res);
}

TEST(SimpleNumbersTest, The_Negative_Number) {
    // arrange
    SimpleNumbers check_eng;
    int n = -5;
    int res;
    // act
    res = check_eng.Check(n);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_Complex_Number) {
    // arrange
    SimpleNumbers check_eng;
    int n = 6;
    int res;
    // act
    res = check_eng.Check(n);
    // assert
    EXPECT_EQ(0, res);
}

TEST(SimpleNumbersTest, The_null_Number) {
    // arrange
    SimpleNumbers check_eng;
    int n = 0;
    int res;
    // act
    res = check_eng.Check(n);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_first_Number) {
    // arrange
    SimpleNumbers check_eng;
    int n = 1;
    int res;
    // act
    res = check_eng.Check(n);
    // assert
    EXPECT_EQ(-1, res);
}

TEST(SimpleNumbersTest, The_Simple_Number) {
    // arrange
    SimpleNumbers check_eng;
    int n = 7;
    int res;
    // act
    res = check_eng.Check(n);
    // assert
    EXPECT_EQ(7, res);
}

TEST(SimpleNumbersTest, the_check_size_array) {
// arrange
SimpleNumbers check_eng1;
SimpleNumbers check_eng2;

int a = 4;
int b1 = 7;
int b2 = 9;

int res1;
int res2;
// act
res1 = check_eng1.SizeOfArray(a, b1);
res2 = check_eng2.SizeOfArray(a, b2);

// assert
EXPECT_EQ(res1, res2);
}

TEST(SimpleNumbersTest, the_check_null_size) {
// arrange
SimpleNumbers check_eng1;
SimpleNumbers check_eng2;

int a = 14;
int b1 = 15;
int b2 = 16;

int res1;
int res2;
// act
res1 = check_eng1.SizeOfArray(a, b1);
res2 = check_eng2.SizeOfArray(a, b2);

// assert
EXPECT_EQ(res1, res2);
}
