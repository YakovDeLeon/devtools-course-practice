// Copyright 2019 Valiullin Damir

#include <gtest/gtest.h>

#include "include/radix.h"

TEST(RadixTest, Can_Create_Radix_Withowt_Parameters) {
    // Arrange
    Radix rdx;

    // Act & Assert
    EXPECT_EQ(1, rdx.GetSize());
}

TEST(RadixTest, Can_Create_Radix_With_Size) {
    // Arrange
    Radix rdx(20);

    // Act & Assert
    EXPECT_EQ(20, rdx.GetSize());
}

TEST(RadixTest, Throw_When_Create_Radix_Zero_Size) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(Radix rdx(0));
}

TEST(RadixTest, Throw_When_Create_Radix_With_Size_Less_Than_Zero) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(Radix rdx(-1));
}

TEST(RadixTest, Throw_When_Create_Radix_With_Array_And_Size_Less_Than_Zero) {
    // Arrange
    int mas[] = { 1, 2, 3 };

    // Act & Assert
    ASSERT_ANY_THROW(Radix rdx(mas, -1));
}

TEST(RadixTest, Throw_When_Create_Radix_With_Array_And_Zero_Size) {
    // Arrange
    int mas[] = { 1, 2, 3 };

    // Act & Assert
    ASSERT_ANY_THROW(Radix rdx(mas, 0));
}

TEST(RadixTest, Can_Calculate_Memory) {
    // Arrange
    int mem = 0;

    int size = 3;
    int mas[] = { 1, 2, 3 };
    Radix rdx(mas, size);

    // Act
    mem += 2 * 256 * 4 + 4;
    mem += size * 4;

    // Assert
    EXPECT_EQ(rdx.HowMuchMem(), mem);
}

TEST(RadixTest, Memory_Will_Change_If_The_Array_Is_Of_A_Different_Size) {
    // Arrange
    int mem = 0;

    int size1 = 3;
    int size2 = 5;
    int mas1[] = { 1, 2, 3 };
    int mas2[] = { 1, 2, 3, 3, 2 };
    Radix rdx(mas1, size1);

    // Act
    rdx.RadixSort(mas2, size2);
    mem += 2 * 256 * 4 + 4;
    mem += size2 * 4;

    // Assert
    EXPECT_EQ(rdx.HowMuchMem(), mem);
}

TEST(RadixTest, Memory_Will_Not_Change_If_The_Array_Is_Of_A_Different_Size) {
    // Arrange
    int mem = 0;

    int size = 3;
    int mas1[] = { 1, 2, 3 };
    int mas2[] = { 3, 2, 1 };
    Radix rdx(mas1, size);

    // Act
    rdx.RadixSort(mas2, size);
    mem += 2 * 256 * 4 + 4;
    mem += size * 4;

    // Assert
    EXPECT_EQ(rdx.HowMuchMem(), mem);
}

TEST(RadixTest, Can_Set_Size) {
    // Arrange
    Radix rdx(3);

    // Act
    rdx.SetSize(5);

    // Assert
    EXPECT_EQ(rdx.GetSize(), 5);
}

TEST(RadixTest, Throw_When_Size_Less_Than_Zero_In_Function_SetSize) {
    // Arrange
    Radix rdx(3);

    // Act & Assert
    ASSERT_ANY_THROW(rdx.SetSize(-1));
}

TEST(RadixTest, Throw_When_Zero_Size_In_Function_SetSize) {
    // Arrange
    Radix rdx(3);

    // Act & Assert
    ASSERT_ANY_THROW(rdx.SetSize(0));
}

TEST(RadixTest, Size_Will_Change_If_Array_Is_Of_A_Different_Size) {
    // Arrange
    int mas[] = { 1, 2, 3, 4, 5 };
    Radix rdx(3);

    // Act
    rdx.RadixSort(mas, 5);

    // Assert
    EXPECT_EQ(rdx.GetSize(), 5);
}

TEST(RadixTest, Correctness_Of_Sorting) {
    // Arrange
    int mas[] = { 0, -5, 2, 4, -1, 1, -3, -4, -2, 3};
    Radix rdx(10);
    bool flag = true;

    // Act
    rdx.RadixSort(mas, 10);

    for (int i = -5; i < 5; ++i) {
        if (mas[i + 5] != i) {
            flag = false;
        }
    }

    // Assert
    EXPECT_EQ(flag, true);
}

TEST(RadixTest, Correctness_Of_Sorting_With_Large_Numbers) {
    // Arrange
    int mas[] = { 2000000000, 1750000000, -1750000000,
        -1500000000, 1250000000, 1500000000,
        -1250000000, -2000000000, 1500000000};

    int sortMas[] = { -2000000000, -1750000000, -1500000000,
        -1250000000, 1250000000, 1500000000,
        1500000000, 1750000000, 2000000000};

    Radix rdx(9);
    bool flag = true;

    // Act
    rdx.RadixSort(mas, 9);

    for (int i = 0; i < 9; ++i) {
        if (mas[i] != sortMas[i]) {
            flag = false;
        }
    }

    // Assert
    EXPECT_EQ(flag, true);
}

TEST(RadixTest, Can_Use_RadixSort_After_Constructor) {
    // Arrange
    int mas1[] = { 0, -5, 2, 4, -1, 1, -3, -4, -2, 3 };
    int mas2[] = { 4, -1, 1, -3, -4, -2, 3, -5, 2, 0 };
    Radix rdx(mas1, 10);
    bool flag = true;

    // Act
    rdx.RadixSort(mas2, 10);

    for (int i = -5; i < 5; ++i) {
        if (mas2[i + 5] != i) {
            flag = false;
        }
    }

    // Assert
    EXPECT_EQ(flag, true);
}

TEST(RadixTest, Throw_When_Zero_Size_In_Function_RadixSort) {
    // Arrange
    int mas[] = { 0, -5, 2, 4, -1, 1, -3, -4, -2, 3 };
    Radix rdx(10);

    // Act & Assert
    ASSERT_ANY_THROW(rdx.RadixSort(mas, 0));
}

TEST(RadixTest, Throw_When_Size_Less_Than_Zero_In_Function_RadixSort) {
    // Arrange
    int mas[] = { 0, -5, 2, 4, -1, 1, -3, -4, -2, 3 };
    Radix rdx(10);

    // Act & Assert
    ASSERT_ANY_THROW(rdx.RadixSort(mas, -1));
}

TEST(RadixTest, Can_Use_RadixSort_With_Array_Size_One) {
    // Arrange
    int mas[] = { 3 };
    Radix rdx;

    // Act
    rdx.RadixSort(mas, 1);

    // Assert
    EXPECT_EQ(*mas, 3);
}
