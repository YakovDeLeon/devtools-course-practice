// Copyright 2019 Andronov Maxim

#include <gtest/gtest.h>

#include "include/priority_queue.h"

TEST(PriorityQueueTest, Can_Push_Element_In_Empty_Queue) {
    // Arrange
    PriorityQueue q;
    int prior = 1;
    int val = 1;
    // Act
    q.Push(prior, val);
    // Assert
    EXPECT_EQ(val, q.Top());
}

TEST(PriorityQueueTest, Element_With_Minimal_Priority_Push_In_Bottom_Queue) {
    // Arrange
    PriorityQueue q;
    int prior1 = 1;
    int val1 = 1;
    int prior2 = 2;
    int val2 = 2;
    int prior3 = 3;
    int val3 = 3;
    // Act
    q.Push(prior2, val2);
    q.Push(prior3, val3);
    q.Push(prior1, val1);
    q.Pop();
    q.Pop();
    // Assert
    EXPECT_EQ(val1, q.Top());
}

TEST(PriorityQueueTest, Element_With_Maximal_Priority_Push_In_Top_Queue) {
    // Arrange
    PriorityQueue q;
    int prior1 = 1;
    int val1 = 1;
    int prior2 = 2;
    int val2 = 2;
    int prior3 = 3;
    int val3 = 3;
    // Act
    q.Push(prior1, val1);
    q.Push(prior2, val2);
    q.Push(prior3, val3);
    // Assert
    EXPECT_EQ(val3, q.Top());
}

TEST(PriorityQueueTest, Element_With_No_Max_And_No_Min_Priority_Push_In_Queue) {
    // Arrange
    PriorityQueue q;
    int prior1 = 1;
    int val1 = 1;
    int prior2 = 2;
    int val2 = 2;
    int prior3 = 3;
    int val3 = 3;
    int prior4 = 4;
    int val4 = 4;
    // Act
    q.Push(prior1, val1);
    q.Push(prior2, val2);
    q.Push(prior4, val4);
    q.Push(prior3, val3);
    q.Pop();
    // Assert
    EXPECT_EQ(val3, q.Top());
}

TEST(PriorityQueueTest, Cant_Pop_Element_From_Empty_Queue) {
    // Arrange
    PriorityQueue q;
    // Act & Assert
    ASSERT_ANY_THROW(q.Pop());
}

TEST(PriorityQueueTest, Can_Pop_Element_From_Queue_With_One_Element) {
    // Arrange
    PriorityQueue q;
    int prior = 1;
    int val = 1;
    // Act
    q.Push(prior, val);
    q.Pop();
    // Assert
    EXPECT_EQ(0, q.Size());
}

TEST(PriorityQueueTest, Can_Pop_Element_From_Queue_With_Several_Elements) {
    // Arrange
    PriorityQueue q;
    int prior1 = 1;
    int val1 = 1;
    int prior2 = 2;
    int val2 = 2;
    int prior3 = 3;
    int val3 = 3;
    // Act
    q.Push(prior1, val1);
    q.Push(prior2, val2);
    q.Push(prior3, val3);
    q.Pop();
    // Assert
    EXPECT_EQ(2, q.Size());
}

TEST(PriorityQueueTest, Cant_Top_Element_From_Empty_Queue) {
    // Arrange
    PriorityQueue q;
    // Act & Assert
    ASSERT_ANY_THROW(q.Top());
}

TEST(PriorityQueueTest, Can_Top_Element_From_Queue_With_One_Element) {
    // Arrange
    PriorityQueue q;
    int prior = 1;
    int val = 1;
    // Act
    q.Push(prior, val);
    // Assert
    EXPECT_EQ(val, q.Top());
}

TEST(PriorityQueueTest, Can_Top_Element_From_Queue_With_Several_Elements) {
    // Arrange
    PriorityQueue q;
    int prior1 = 1;
    int val1 = 1;
    int prior2 = 2;
    int val2 = 2;
    int prior3 = 3;
    int val3 = 3;
    // Act
    q.Push(prior1, val1);
    q.Push(prior2, val2);
    q.Push(prior3, val3);
    // Assert
    EXPECT_EQ(val3, q.Top());
}

TEST(PriorityQueueTest, If_Queue_Empty_Return_True) {
    // Arrange
    PriorityQueue q;
    // Act & Assert
    EXPECT_TRUE(q.Empty());
}

TEST(PriorityQueueTest, If_Queue_No_Empty_Return_False) {
    // Arrange
    PriorityQueue q;
    int prior = 1;
    int val = 1;
    // Act
    q.Push(prior, val);
    // Assert
    EXPECT_FALSE(q.Empty());
}

TEST(PriorityQueueTest, If_Queue_Empty_Return_0) {
    // Arrange
    PriorityQueue q;
    // Act & Assert
    EXPECT_EQ(0, q.Size());
}

TEST(PriorityQueueTest, If_Queue_No_Empty_Return_Size) {
    // Arrange
    PriorityQueue q;
    int prior = 1;
    int val = 1;
    // Act
    q.Push(prior, val);
    // Assert
    EXPECT_EQ(1, q.Size());
}
