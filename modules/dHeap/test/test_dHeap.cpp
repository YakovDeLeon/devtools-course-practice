// Copyright 2019 Soluyanov Alexsey

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/dHeap.h"

TEST(DHeapTest, Can_Create_DHeap_With_d) {
    // Arrange
    unsigned int _d = 2;

    // Act
    DHeap my_heap = DHeap(_d);

    // Assert
    EXPECT_EQ(_d, my_heap.get_d());
}

TEST(DHeapTest, Can_Create_DHeap_With_d_and_Weight) {
    // Arrange
    unsigned int _d = 2;
    std::vector<int> w = { 1, 2, 3 };

    // Act
    DHeap my_heap = DHeap(_d, w);

    // Assert
    EXPECT_EQ(w, my_heap.get_weight());
}

TEST(DHeapTest, Get_Parent) {
    // Arrange
    unsigned int _d = 2;
    std::vector<int> w = { 3, 6, 4, 9, 8, 12, 7, 11, 9 };

    // Act
    DHeap my_heap = DHeap(_d, w);

    // Assert
    EXPECT_EQ(0, my_heap.get_parent(2));
}

TEST(DHeapTest, Get_Left_Child) {
    // Arrange
    unsigned int _d = 2;
    std::vector<int> w = { 5, 6, 7, 4, 8, 11, 12, 9 };

    // Act
    DHeap my_heap = DHeap(_d, w);

    // Assert
    EXPECT_EQ(3, my_heap.get_left_child(1));
}

TEST(DHeapTest, Get_Right_Child) {
    // Arrange
    unsigned int _d = 2;
    std::vector<int> w = { 5, 6, 7, 4, 8, 11, 12, 9 };

    // Act
    DHeap my_heap = DHeap(_d, w);

    // Assert
    EXPECT_EQ(4, my_heap.get_right_child(1));
}

TEST(DHeapTest, Get_Min_Child) {
    // Arrange
    unsigned int _d = 3;
    std::vector<int> w = { 1, 2, 2, 2, 3, 4, 5 };

    // Act
    DHeap my_heap = DHeap(_d, w);

    // Assert
    EXPECT_EQ(4, my_heap.get_min_child(1));
}

TEST(DHeapTest, Insert_Element) {
    // Arrange
    unsigned int _d = 2;
    std::vector<int> w = { 1, 4, 3, 5 };
    std::vector<int> res = { 1, 2, 3, 5, 4};
    // Act
    DHeap my_heap = DHeap(_d, w);
    my_heap.Insert(2);

    // Assert
    EXPECT_EQ(res, my_heap.get_weight());
}

TEST(DHeapTest, Delete_Elements) {
    // Arrange
    unsigned int _d = 2;
    std::vector<int> w = { 1, 4, 3, 5 };
    std::vector<int> res = { 1, 5, 3};
    // Act
    DHeap my_heap = DHeap(_d, w);
    my_heap.Delete(1);

    // Assert
    EXPECT_EQ(res, my_heap.get_weight());
}

TEST(DHeapTest, Delete_Min_Element) {
    // Arrange
    unsigned int _d = 2;
    std::vector<int> w = { 1, 4, 3, 5 };
    std::vector<int> res = { 3, 4, 5 };
    // Act
    DHeap my_heap = DHeap(_d, w);
    my_heap.Delete_min();

    // Assert
    EXPECT_EQ(res, my_heap.get_weight());
}

TEST(DHeapTest, No_Right_Child) {
    // Arrange
    unsigned int _d = 2;
    std::vector<int> w = { 5, 6, 7, 4, 8, 11, 12, 9 };
    // Act
    DHeap my_heap = DHeap(_d, w);

    // Assert
    EXPECT_EQ(-1, my_heap.get_right_child(4));
}
