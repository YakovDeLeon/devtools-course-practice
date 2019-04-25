// Copyright 2019 Kumbrasev Pavel

#include <gtest/gtest.h>
#include <vector>
#include "include/heap.h"


TEST(TemplateHeapTest, Can_Create_Empty_Heap) {
    // Arrange
    Heap<int> heap{};

    // Act & Assert
    EXPECT_EQ(0, heap.GetSize());
}

TEST(TemplateHeapTest, Can_Copy_Heap) {
    // Arrange
    Heap<int> heap{};
    // Act
    heap.Insert(3);
    heap.Insert(7);
    Heap<int> test_heap{heap};
    std::vector<int> test_vec;
    std::vector<int> res_vec = {7, 3};
    test_vec.emplace_back(test_heap.Remove());
    test_vec.emplace_back(test_heap.Remove());
    // Assert
    EXPECT_EQ(test_vec, res_vec);
}

TEST(TemplateHeapTest, Can_Move_Heap) {
    // Arrange
    Heap<int> heap{};
    // Act
    heap.Insert(3);
    heap.Insert(7);
    Heap<int> test_heap{std::move(heap)};
    std::vector<int> test_vec;
    std::vector<int> res_vec = {7, 3};
    test_vec.emplace_back(test_heap.Remove());
    test_vec.emplace_back(test_heap.Remove());
    // Assert
    EXPECT_EQ(test_vec, res_vec);
}

TEST(TemplateHeapTest, Can_Insert_Element_In_Empty_Heap) {
    // Arrange
    Heap<int> heap{};

    // Act
    heap.Insert(7);
    // Assert
    EXPECT_EQ(1, heap.GetSize());
}

TEST(TemplateHeapTest, Can_Insert_Element_In_Not_Empty_Heap) {
    // Arrange
    Heap<int> heap{};
    std::vector<int> test_vec = {3, 1, 2, 4, 5, 7, 6, 8, 9, 10, 22};
    // Act
    for (auto elem : test_vec)
        heap.Insert(elem);
    // Assert
    ASSERT_NO_THROW(heap.Remove());
}

TEST(TemplateHeapTest, Can_Not_Remove_Element_From_Empty_Heap) {
    // Arrange
    Heap<int> heap{};

    // Act && Assert
    ASSERT_ANY_THROW(heap.Remove());
}

TEST(TemplateHeapTest, Can_Remove_Element_From_Not_Empty_Heap) {
    // Arrange
    Heap<int> heap{};
    heap.Insert(7);

    // Act && Assert
    EXPECT_EQ(7, heap.Remove());
}

TEST(TemplateHeapTest, Can_Insert_More_Than_Ten_Elements) {
    // Arrange
    Heap<int> heap{};
    std::vector<int> test_vec = {3, 1, 2, 4, 5, 7, 6, 8, 9, 10};
    // Act
    for (auto elem : test_vec)
        heap.Insert(elem);
    // Assert
    ASSERT_NO_THROW(heap.Insert(22));
}

TEST(TemplateHeapTest, Size_Empty_Heap_Equals_Zero) {
    // Arrange
    Heap<int> heap{};
    heap.Insert(7);

    // Act && Assert
    EXPECT_EQ(7, heap.Remove());
}
