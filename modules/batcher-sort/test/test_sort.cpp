// Copyright 2019 Dudchenko Anton

#include <vector>
#include "gtest/gtest.h"
#include "include/BatcherSort.h"

TEST(Test_Batcher_Sort, Can_Create_Elem_Without_Args) {
    // Assert
    ASSERT_NO_THROW(BatcherSort b);
}

TEST(Test_Batcher_Sort, Can_Create_Elem_With_Size_Equal_Power_Of_Two) {
    // Assert
    ASSERT_NO_THROW(BatcherSort b({3, 1, 4, 1, 5, 9, 2, 6}));
}

TEST(Test_Batcher_Sort, Cant_Create_Elem_With_Size_No_Equal_Power_Of_Two) {
    // Assert
    ASSERT_ANY_THROW(BatcherSort b({ 3, 1, 4}));
}


TEST(Test_Batcher_Sort, Can_Get_Vector_Size) {
    // Arrange
    BatcherSort b({ 3, 1, 4, 1, 5, 9, 2, 6 });

    // Assert
    EXPECT_EQ(8, b.GetSize());
}

TEST(Test_Batcher_Sort, Can_Get_Vector) {
    // Arrange
    std::vector<int> vec = { 3, 1, 4, 1, 5, 9, 2, 6 };
    BatcherSort b(vec);

    // Assert
    EXPECT_EQ(vec, b.GetVec());
}

TEST(Test_Batcher_Sort, Can_Sort) {
    // Arrange
    std::vector<int> result = { 1, 1, 2, 3, 4, 5, 6, 9 };
    BatcherSort b({ 3, 1, 4, 1, 5, 9, 2, 6 });

    // Act
    b.BatcherMergeSort(0, b.GetSize() - 1);

    // Assert
    EXPECT_EQ(result, b.GetVec());
}
