// Copyright 2019 Savkin Yuriy

#include <gtest/gtest.h>

#include <climits>
#include "include/segment_tree.h"


TEST(SegmentTree, Can_Create_Segment_Tree) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(SegmentTree a(1, 2));
}

TEST(SegmentTree, Cant_Create_Segment_Tree_With_Wrong_Barriers) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(SegmentTree a(2, 1));
}

TEST(SegmentTree, Can_Add_Value) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.AddValue(1, 9));
}

TEST(SegmentTree, Cant_Add_Value_To_Wrong_Position) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.AddValue(3, 9));
}

TEST(SegmentTree, Can_Add_To_Segment) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.AddValue(1, 2, 9));
}

TEST(SegmentTree, Cant_Add_Out_Of_Range) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.AddValue(1, 3, 9));
}

TEST(SegmentTree, Cant_Add_With_Incorrect_Barriers) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.AddValue(2, 1, 9));
}

TEST(SegmentTree, Can_Set_Value) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.SetValue(1, 9));
}

TEST(SegmentTree, Can_Set_On_Segment) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.SetValue(1, 2, 9));
}

TEST(SegmentTree, Cant_Set_Out_Of_Range) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.SetValue(0, 2, 9));
}

TEST(SegmentTree, Cant_Set_Value_On_Wrong_Position) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.SetValue(0, 9));
}

TEST(SegmentTree, Cant_Set_With_Incorrect_Barriers) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.SetValue(2, 1, 9));
}

TEST(SegmentTree, Can_Get_Value) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.GetValue(2));
}

TEST(SegmentTree, Cant_Get_Value_On_Wrong_Position) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.GetValue(3));
}

TEST(SegmentTree, Can_Get_On_Segment) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(a.GetValue(1, 2));
}

TEST(SegmentTree, Cant_Get_Out_Of_Range) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.GetValue(1, 3));
}

TEST(SegmentTree, Cant_Get_With_Incorrect_Barriers) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_ANY_THROW(a.GetValue(1, 3));
}

TEST(SegmentTree, Can_Get_Base_Element) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    EXPECT_EQ(0, a.GetBaseElem());
}

TEST(SegmentTree, Can_Get_Left_Barrier) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    EXPECT_EQ(1, a.GetLeftBarr());
}

TEST(SegmentTree, Can_Get_Right_Barrier) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    EXPECT_EQ(2, a.GetRightBarr());
}

TEST(SegmentTree, Can_Create_From_Other) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    ASSERT_NO_THROW(SegmentTree b(a));
}

TEST(SegmentTree, Can_Assign_From_Other) {
    // Arrange
    SegmentTree a(1, 2), b(5, 9);
    // Act & Assert
    ASSERT_NO_THROW(a = b);
}

TEST(SegmentTree, Get_Value_Is_Correct) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    EXPECT_EQ(a.GetBaseElem(), a.GetValue(1));
}

TEST(SegmentTree, Get_Value_On_Segment_Is_Correct) {
    // Arrange
    SegmentTree a(1, 2);
    // Act & Assert
    EXPECT_EQ(a.GetBaseElem(), a.GetValue(1, 2));
}

TEST(SegmentTree, Can_Get_Added_Value) {
    // Arrange
    SegmentTree a(1, 2);
    // Act
    a.AddValue(1, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(1));
}

TEST(SegmentTree, Added_Value_Affects_Segment) {
    // Arrange
    SegmentTree a(1, 2);
    // Act
    a.AddValue(1, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(1, 2));
}

TEST(SegmentTree, Added_Value_Dont_Affects_Other_Value) {
    // Arrange
    SegmentTree a(1, 2);
    // Act
    a.AddValue(1, 7);
    // Assert
    EXPECT_EQ(0, a.GetValue(2));
}

TEST(SegmentTree, Can_Get_Setted_Value) {
    // Arrange
    SegmentTree a(1, 2);
    // Act
    a.SetValue(1, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(1));
}

TEST(SegmentTree, Setted_Value_Affects_Segment) {
    // Arrange
    SegmentTree a(1, 2);
    // Act
    a.SetValue(1, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(1, 2));
}

TEST(SegmentTree, Setted_Value_Dont_Affects_Other_Value) {
    // Arrange
    SegmentTree a(1, 2);
    // Act
    a.SetValue(1, 7);
    // Assert
    EXPECT_EQ(0, a.GetValue(2));
}

TEST(SegmentTree, Can_Get_Added_On_Segment_Value) {
    // Arrange
    SegmentTree a(1, 7);
    // Act
    a.AddValue(1, 4, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(2));
}

TEST(SegmentTree, Added_On_Segment_Value_Affects_Segment) {
    // Arrange
    SegmentTree a(1, 7);
    // Act
    a.AddValue(1, 4, 7);
    // Assert
    EXPECT_EQ(14, a.GetValue(3, 6));
}

TEST(SegmentTree, Added_On_Segment_Value_Dont_Affects_Other_Value) {
    // Arrange
    SegmentTree a(1, 7);
    // Act
    a.AddValue(1, 4, 7);
    // Assert
    EXPECT_EQ(0, a.GetValue(5));
}

TEST(SegmentTree, Can_Get_Setted_On_Segment_Value) {
    // Arrange
    SegmentTree a(1, 7);
    // Act
    a.SetValue(1, 4, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(4));
}

TEST(SegmentTree, Setted_On_Segment_Value_Affects_Segment) {
    // Arrange
    SegmentTree a(1, 7);
    // Act
    a.SetValue(1, 4, 7);
    // Assert
    EXPECT_EQ(21, a.GetValue(2, 4));
}

TEST(SegmentTree, Setted_On_Segment_Value_Dont_Affects_Other_Value) {
    // Arrange
    SegmentTree a(1, 7);
    // Act
    a.SetValue(1, 4, 7);
    // Assert
    EXPECT_EQ(0, a.GetValue(5, 7));
}

TEST(SegmentTree, Tree_Work_With_Other_Functions) {
    // Arrange
    SegmentTree a(1, 7, [](int a, int b, int c)->int {
        if (a < b)
            return a;
        return b;
    }, INT_MAX);
    // Act
    a.AddValue(1, 8);
    a.AddValue(2, 5, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(1, 2));
}

TEST(SegmentTree, Correct_Adding_After_Setting) {
    // Arrange
    SegmentTree a(1, 7);
    // Act
    a.SetValue(4, 7);
    a.AddValue(4, 3);
    // Assert
    EXPECT_EQ(10, a.GetValue(1, 5));
}

TEST(SegmentTree, Correct_Adding_After_Setting_On_Segment) {
    // Arrange
    SegmentTree a(1, 7);
    // Act
    a.SetValue(1, 4, 7);
    a.AddValue(2, 3, 3);
    // Assert
    EXPECT_EQ(34, a.GetValue(1, 5));
}

TEST(SegmentTree, Correct_Setting_After_Adding) {
    // Arrange
    SegmentTree a(-5, -2);
    // Act
    a.AddValue(-3, 3);
    a.SetValue(-3, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(-3));
}

TEST(SegmentTree, Correct_Setting_After_Adding_On_Segment) {
    // Arrange
    SegmentTree a(-5, -2);
    // Act
    a.AddValue(-4, -2, 3);
    a.SetValue(-5, -3, 7);
    // Assert
    EXPECT_EQ(24, a.GetValue(-5, -2));
}

TEST(SegmentTree, Correct_Setting_After_Setting_On_Segment) {
    // Arrange
    SegmentTree a(0, 6);
    // Act
    a.SetValue(0, 2, 7);
    a.SetValue(1, 3);
    // Assert
    EXPECT_EQ(17, a.GetValue(0, 4));
}

TEST(SegmentTree, Can_Create_Very_Big_Tree) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(SegmentTree a(0, INT_MAX));
}

TEST(SegmentTree, Can_Add_To_Very_Big_Tree) {
    // Arrange
    SegmentTree a(0, INT_MAX);
    // Act & Assert
    ASSERT_NO_THROW(a.AddValue(457876, 4));
}

TEST(SegmentTree, Can_Add_To_Very_Big_Tree_On_Segment) {
    // Arrange
    SegmentTree a(0, INT_MAX);
    // Act & Assert
    ASSERT_NO_THROW(a.AddValue(457876, 1000000000, 4));
}

TEST(SegmentTree, Can_Set_To_Very_Big_Tree_On_Segment) {
    // Arrange
    SegmentTree a(0, INT_MAX);
    // Act & Assert
    ASSERT_NO_THROW(a.SetValue(457876, 1000000000, 4));
}

TEST(SegmentTree, Can_Set_To_Very_Big_Tree) {
    // Arrange
    SegmentTree a(0, INT_MAX);
    // Act & Assert
    ASSERT_NO_THROW(a.SetValue(457876, 76));
}

TEST(SegmentTree, Can_Get_From_Very_Big_Tree) {
    // Arrange
    SegmentTree a(0, INT_MAX);
    // Act
    a.AddValue(457876, 4);
    // Assert
    EXPECT_EQ(4, a.GetValue(0, 500000));
}

TEST(SegmentTree, Can_Create_Very_Small_Tree) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(SegmentTree a(0, 0));
}

TEST(SegmentTree, Can_Add_To_Very_Small_Tree) {
    // Arrange
    SegmentTree a(0, 0);
    // Act & Assert
    ASSERT_NO_THROW(a.AddValue(0, 5));
}

TEST(SegmentTree, Can_Set_To_Very_Small_Tree) {
    // Arrange
    SegmentTree a(0, 0);
    // Act & Assert
    ASSERT_NO_THROW(a.SetValue(0, 5));
}

TEST(SegmentTree, Can_Get_From_Very_Small_Tree) {
    // Arrange
    SegmentTree a(0, 0);
    // Act & Assert
    EXPECT_EQ(0, a.GetValue(0));
}

TEST(SegmentTree, Can_Get_Added_Value_From_Very_Small_Tree) {
    // Arrange
    SegmentTree a(0, 0);
    // Act
    a.AddValue(0, 7);
    // Assert
    EXPECT_EQ(7, a.GetValue(0));
}

TEST(SegmentTree, Difficult_Test_For_Adding) {
    // Arrange
    SegmentTree a(0, 9);
    // Act
    a.SetValue(4, 7, 5);
    for (int i = 0; i < 10; ++i)
        a.AddValue(i, 9, i);
    // Assert
    EXPECT_EQ(185, a.GetValue(0, 9));
}

TEST(SegmentTree, Difficult_Test_For_Setting) {
    // Arrange
    SegmentTree a(0, 9);
    // Act
    for (int i = 0; i < 10; ++i)
        a.SetValue(i, 9, i);
    a.AddValue(4, 6, 5);
    // Assert
    EXPECT_EQ(60, a.GetValue(0, 9));
}

TEST(SegmentTree, Copyed_Tree_Equal_To_Original) {
    // Arrange
    SegmentTree a(0, 9);
    bool flag = true;
    for (int i = 0; i < 10; ++i)
        a.SetValue(i, 9, i);
    a.AddValue(4, 6, 5);
    // Act
    SegmentTree b(a);
    for (int i = 0; i < 10; ++i)
        if (a.GetValue(i) != b.GetValue(i))
            flag = false;
    // Assert
    EXPECT_TRUE(flag);
}

TEST(SegmentTree, Assigned_Tree_Equal_To_Original) {
    // Arrange
    SegmentTree a(0, 9);
    SegmentTree b(0, 2);
    bool flag = true;
    for (int i = 0; i < 10; ++i)
        a.SetValue(i, 9, i);
    a.AddValue(4, 6, 5);
    // Act
    b = a;
    for (int i = 0; i < 10; ++i)
        if (a.GetValue(i) != b.GetValue(i))
            flag = false;
    // Assert
    EXPECT_TRUE(flag);
}

TEST(SegmentTree, Can_Assign_To_Itself) {
    // Arrange
    SegmentTree a(0, 9);
    // Act & Assert
    ASSERT_NO_THROW(a = a);
}

TEST(SegmentTree, Can_Assign_Filled_Tree) {
    // Arrange
    SegmentTree a(0, 9);
    SegmentTree b(0, 2);
    for (int i = 0; i < 10; ++i)
        a.SetValue(i, 9, i);
    a.AddValue(4, 6, 5);
    // Act & Assert
    ASSERT_NO_THROW(a = b);
}

TEST(SegmentTree, Correct_Get_After_Set_On_Segment) {
    // Arrange
    SegmentTree a(0, 4);
    bool flag = true;
    for (int i = 0; i < 5; ++i)
        a.SetValue(i, i);
    // Act
    a.SetValue(3, 4, 10);
    // Assert
    EXPECT_EQ(10, a.GetValue(3));
}

TEST(SegmentTree, Cant_Get_Added_Value_With_Incorrect_Barriers) {
    // Arrange
    SegmentTree a(0, 4);
    // Act & Assert
    ASSERT_ANY_THROW(a.GetValue(4, 2));
}

TEST(SegmentTree, Correct_Get_After_Set_And_Add_On_Segment) {
    // Arrange
    SegmentTree a(0, 7);
    bool flag = true;
    for (int i = 0; i < 8; ++i)
        a.SetValue(i, i);
    // Act
    a.SetValue(4, 7, 10);
    a.AddValue(4, 5, 12);
    // Assert
    EXPECT_EQ(22, a.GetValue(5));
}
