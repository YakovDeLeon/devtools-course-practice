// Copyright 2019 Karasev Anton

#include <utility>
#include <vector>
#include <string>

#include "gtest/gtest.h"

#include "include/modif_stack.h"


TEST(ModifStack, Can_Creating_Empty_Stack) {
    // Arrange
    std::vector<int> x;

    // Arrange
    ModifStack y(x);

    // Assert
    EXPECT_EQ(y.Size(), 0);
}

TEST(ModifStack, Can_Create_Stack_In_Non_Empty_Vector) {
    // Arrange
    std::vector<int> x = {4, 6, 7};

    // Act
    ModifStack y(x);

    // Assert
    std::vector<std::pair<int, int>> res = y.ShowReverseStack();

    EXPECT_EQ(res[0].first, 7);
    EXPECT_EQ(res[1].first, 6);
    EXPECT_EQ(res[2].first, 4);
}

TEST(ModifStack, Can_Create_Stack_In_Copy_Constructor) {
    // Arrange
    std::vector<int> x = {1, 2, 3};
    ModifStack y(x);

    // Act
    ModifStack q(y);

    // Assert
    std::vector<std::pair<int, int>> res = q.ShowReverseStack();

    EXPECT_EQ(res[0].first, 3);
    EXPECT_EQ(res[1].first, 2);
    EXPECT_EQ(res[2].first, 1);
}

TEST(ModifStack, Can_Top_In_Empty_Stack) {
    // Arrange
    std::vector<int> x;
    ModifStack y(x);

    // Act & Assert
    ASSERT_ANY_THROW(y.Top());
}

TEST(ModifStack, Can_Top_In_Stack) {
    // Arrange
    std::vector<int> x = {3, 4, 27};
    ModifStack y(x);
    int last = 0;

    // Act
    last = y.Top().first;

    // Assert
    EXPECT_EQ(27, last);
}

TEST(ModifStack, Can_Pop_In_Empty_Stack) {
    // Arrange
    std::vector<int> x;
    ModifStack y(x);

    // Act
    y.Pop();

    // Assert
    EXPECT_EQ(y.Size(), 0);
}

TEST(ModifStack, Can_Pop_In_Non_Empty_Stack) {
    // Arrange
    std::vector<int> x = {7, 21, 6, 25, 1};
    ModifStack y(x);

    // Act
    y.Pop();

    // Assert
    EXPECT_EQ(25, y.Top().first);
}

TEST(Modif_Stack, Can_Get_Min_Via_Top_In_Stack) {
    // Arrange
    std::vector<int> x = {4, 29, 3};
    ModifStack y(x);
    int min = 0;

    // Act
    min = y.Top().second;

    // Assert
    EXPECT_EQ(3, min);
}

TEST(ModifStack, Can_Push_In_Stack) {
    // Arrange
    std::vector<int> x = {4, 29, 3};
    ModifStack y(x);

    // Act
    y.Push(21);

    // Assert
    EXPECT_EQ(21, y.Top().first);
}

TEST(ModifStack, Can_Define_Empty_Stack) {
    // Arrange
    std::vector<int> x = {4};
    ModifStack y(x);
    bool valid = false;
    y.Pop();

    // Act
    valid = y.Empty();

    // Assert
    EXPECT_TRUE(valid == true);
}
