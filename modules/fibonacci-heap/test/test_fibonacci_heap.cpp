// Copyright 2019 Trubina Anastasia

#include "gtest/gtest.h"

#include "include/fibonacci_heap.h"

TEST(FibonacciHeapTest, Can_Create_Node_Default_Constructor) {
    // Arrange & Act
    Node x;

    // Assert
    EXPECT_EQ(0, x.GetKey());
    EXPECT_EQ(nullptr, x.GetParent());
    EXPECT_EQ(nullptr, x.GetChild());
    EXPECT_EQ(nullptr, x.GetLeft());
    EXPECT_EQ(nullptr, x.GetRight());
    EXPECT_EQ(0, x.GetDegree());
    ASSERT_TRUE(x.IsMarked());
}

TEST(FibonacciHeapTest, Can_Create_Node_Initialization_Constructor_By_Key) {
    // Arrange & Act
    Node x(23);

    // Assert
    EXPECT_EQ(23, x.GetKey());
    EXPECT_EQ(nullptr, x.GetParent());
    EXPECT_EQ(nullptr, x.GetChild());
    EXPECT_EQ(nullptr, x.GetLeft());
    EXPECT_EQ(nullptr, x.GetRight());
    EXPECT_EQ(0, x.GetDegree());
    ASSERT_TRUE(x.IsMarked());
}

TEST(FibonacciHeapTest, Can_Create_Node_Initialization_Constructor) {
    // Arrange
    Node _parent, _child, _left, _right;

    // Act
    Node x(23, &_parent, &_child, &_left, &_right, 1, true);

    // Assert
    EXPECT_EQ(23, x.GetKey());
    EXPECT_EQ(&_parent, x.GetParent());
    EXPECT_EQ(&_child, x.GetChild());
    EXPECT_EQ(&_left, x.GetLeft());
    EXPECT_EQ(&_right, x.GetRight());
    EXPECT_EQ(1, x.GetDegree());
    ASSERT_TRUE(x.IsMarked());
}

TEST(FibonacciHeapTest, Check_Sets_In_Node) {
    // Arrange
    Node a, b, c, d, x;
    x.SetKey(23);
    x.SetParent(&a);
    x.SetChild(&b);
    x.SetLeft(&c);
    x.SetRight(&d);
    x.SetDegree(1);
    x.SetMark(false);

    // Act & Assert
    EXPECT_EQ(23, x.GetKey());
    EXPECT_EQ(&a, x.GetParent());
    EXPECT_EQ(&b, x.GetChild());
    EXPECT_EQ(&c, x.GetLeft());
    EXPECT_EQ(&d, x.GetRight());
    EXPECT_EQ(1, x.GetDegree());
    ASSERT_FALSE(x.IsMarked());
}

TEST(FibonacciHeapTest, Node_Has_Child) {
    // Arrange
    Node _child;
    Node x(23, nullptr, &_child, nullptr, nullptr, 1, true);

    // Act & Assert
    ASSERT_TRUE(x.HasChild());
}

TEST(FibonacciHeapTest, Node_Has_Parent) {
    // Arrange
    Node _parent;
    Node x(23, &_parent, nullptr, nullptr, nullptr, 1, true);

    // Act & Assert
    ASSERT_TRUE(x.HasParent());
}

TEST(FibonacciHeapTest, Can_Create_Fibonacci_Heap_Default_Constructor) {
    // Arrange & Act
    FibonacciHeap h;

    // Assert
    ASSERT_TRUE(h.IsEmpty());
}

TEST(FibonacciHeapTest, Fibonacci_Heap_Is_Not_Empty) {
    // Arrange
    FibonacciHeap h;

    // Act
    h.Insert(23);

    // Assert
    ASSERT_FALSE(h.IsEmpty());
}

TEST(FibonacciHeapTest, Can_Get_Minimum_Node) {
    // Arrange
    FibonacciHeap h;
    h.Insert(23);
    h.Insert(5);

    // Act & Assert
    EXPECT_EQ(5, h.GetMinimum());
}

TEST(FibonacciHeapTest, Can_Not_Find_Node_In_Empty_Heap) {
    // Arrange
    FibonacciHeap h;

    // Act & Assert
    EXPECT_EQ(nullptr, h.Find(2));
}

TEST(FibonacciHeapTest, Can_Not_Find_Node_With_Key) {
    // Arrange
    FibonacciHeap h;

    // Act
    h.Insert(3);

    // Act & Assert
    EXPECT_EQ(nullptr, h.Find(2));
}

TEST(FibonacciHeapTest, Find_Node_With_Key) {
    // Arrange
    FibonacciHeap h;
    h.Insert(23);

    // Act & Assert
    EXPECT_EQ(h.GetHeap(), h.Find(23));
}

TEST(FibonacciHeapTest, Can_Merge_Two_Empty_Heap) {
    // Arrange
    FibonacciHeap h1, h2;

    // Act
    h1.Merge(h2);

    // Assert
    ASSERT_TRUE(h1.IsEmpty());
    ASSERT_TRUE(h2.IsEmpty());
}
