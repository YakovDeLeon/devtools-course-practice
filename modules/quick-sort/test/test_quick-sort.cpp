// Copyright 2019 Yury Gaydaychuk

#include <gtest/gtest.h>

#include "include/quick-sort.h"

// Checking of simple increasing list
TEST(Gaydaychuk_Yury_ComplexNumberTest, Increasing_Checking) {
    // Arrange
    QuickSort qs;
    int arr[3] = {1, 2, 3};

    // Act
    bool res = qs.CheckIncreasing(arr, 3);

    // Assert
    EXPECT_TRUE(res);
}

// Checking of unsorted list
TEST(Gaydaychuk_Yury_ComplexNumberTest, Unsorted_Checking) {
    // Arrange
    QuickSort qs;
    int arr[3] = {1, 3, 2};

    // Act
    bool res = qs.CheckIncreasing(arr, 3);

    // Assert
    EXPECT_TRUE(!res);
}

// Sort function passes checking
TEST(Gaydaychuk_Yury_ComplexNumberTest, Sort_Passes_Checking) {
    // Arrange
    QuickSort qs;
    int arr[3] = {3, 2, 1};

    // Act
    qs.MySort(arr, 3);
    bool res = qs.CheckIncreasing(arr, 3);

    // Assert
    EXPECT_TRUE(res);
}

// First element checking
TEST(Gaydaychuk_Yury_ComplexNumberTest, First_Element_Checking) {
    // Arrange
    QuickSort qs;
    int arr[3] = {3, 2, 1};

    // Act
    qs.MySort(arr, 3);
    int must_be_one = arr[0];

    // Assert
    EXPECT_EQ(1, must_be_one);
}


