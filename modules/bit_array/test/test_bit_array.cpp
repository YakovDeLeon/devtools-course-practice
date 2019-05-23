// Copyright 2019 Soluyanov Alexsey

#include <gtest/gtest.h>
#include <string>


#include "include/bit_array.h"

TEST(BitArrayTest, Default_Constructor_Test) {
    // Arrange
    BitArray bit;

    // Act

    // Assert
    EXPECT_GT(bit.size(), 0);
}

TEST(BitArrayTest, Int_Constructor_Test) {
    // Arrange
    int bit_count = 255;

    // Act
    BitArray bit(bit_count);

    // Assert
    EXPECT_EQ(bit.size(), 255);
}

TEST(BitArrayTest, Cant_Create_Negative_Size_Array) {
    // Arrange
    int bit_count = -256;

    // Act

    // Assert
    EXPECT_ANY_THROW(BitArray bit(bit_count));
}

TEST(BitArrayTest, Can_Print) {
    // Arrange
    int bit_count = 8;
    BitArray bit(bit_count);
    std::string to_exp = "";

    // Act
    to_exp = bit.print_string();

    // Assert
    EXPECT_EQ(to_exp, "00000000");
}

TEST(BitArrayTest, Can_Set_Value_True) {
    // Arrange
    int bit_count = 8;
    BitArray bit(bit_count);
    std::string to_exp = "";

    // Act
    bit.SetBit(0, true);
    bit.SetBit(2, true);
    to_exp = bit.print_string();

    // Assert
    EXPECT_EQ(to_exp, "10100000");
}

TEST(BitArrayTest, Can_Set_Value_False) {
    // Arrange
    int bit_count = 8;
    BitArray bit(bit_count);
    std::string to_exp = "";

    // Act
    bit.SetBit(0, true);
    bit.SetBit(2, true);
    bit.SetBit(0, false);
    to_exp = bit.print_string();

    // Assert
    EXPECT_EQ(to_exp, "00100000");
}

TEST(BitArrayTest, Assgn_Operator_Test) {
    // Arrange
    int bit_count1 = 8;
    int bit_count2 = 16;
    BitArray bit_1(bit_count1);
    BitArray bit_2(bit_count2);

    // Act
    bit_2 = bit_1;

    // Assert
    EXPECT_EQ(bit_2.size(), bit_1.size());
}

TEST(BitArrayTest, Cant_Set_Bit_OOR) {
    // OOR - out of range
    // Arrange
    int bit_count = 8;
    BitArray bit(bit_count);

    // Act

    // Assert
    EXPECT_ANY_THROW(bit.SetBit(8, true));
}

TEST(BitArrayTest, Cant_Get_Bit_OOR) {
    // OOR - out of range
    // Arrange
    int bit_count = 8;
    BitArray bit(bit_count);

    // Act

    // Assert
    EXPECT_ANY_THROW(bit.GetBit(8));
}

TEST(BitArrayTest, Can_Get_Value_True) {
    // OOR - out of range
    // Arrange
    int bit_count = 8;
    BitArray bit(bit_count);

    // Act
    bit.SetBit(0, true);

    // Assert
    EXPECT_EQ(bit.GetBit(0), true);
}

TEST(BitArrayTest, Can_Get_Value_False) {
    // OOR - out of range
    // Arrange
    int bit_count = 8;
    BitArray bit(bit_count);

    // Act
    bit.SetBit(0, false);

    // Assert
    EXPECT_EQ(bit.GetBit(0), false);
}

TEST(BitArrayTest, Assign_Operator_Test) {
    // OOR - out of range
    // Arrange
    int bit_count_1 = 8;
    int bit_count_2 = 16;
    BitArray bit_1(bit_count_1);
    BitArray bit_2(bit_count_2);

    // Act
    bit_1 = bit_2;

    // Assert
    EXPECT_EQ(bit_1.print_string(), bit_2.print_string());
}

TEST(BitArrayTest, Copy_Constructor_Test) {
    // OOR - out of range
    // Arrange
    int bit_count = 8;
    BitArray bit_1(bit_count);

    // Act
    bit_1.SetBit(0, true);
    BitArray bit_2(bit_1);

    // Assert
    EXPECT_EQ(bit_1.print_string(), bit_2.print_string());
}
