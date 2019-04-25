// Copyright 2019 Alexander Batashev

#include <gtest/gtest.h>
#include <algorithm>

#include "include/set.h"

TEST(SetTest, Can_Add_Item) {
  // Arrange
  Set<int> mSet;

  // Act
  mSet.Insert(5);

  // Assert
  EXPECT_TRUE(mSet.Contains(5));
}

TEST(SetTest, Added_Items_Are_Unique) {
  // Arrange
  Set<int> mSet;

  // Act
  mSet.Insert(5);
  mSet.Insert(5);
  mSet.Insert(5);

  // Assert
  EXPECT_EQ(mSet.Size(), 1);
  EXPECT_EQ(*mSet.begin(), 5);
}

TEST(SetTest, Added_Items_Are_Sorted) {
  // Arrange
  Set<int> mSet;

  // Act
  mSet.Insert(3);
  mSet.Insert(2);
  mSet.Insert(1);

  // Assert
  EXPECT_TRUE(std::is_sorted(mSet.begin(), mSet.end()));
}

TEST(SetTest, Can_Remove_Items) {
  // Arrange
  Set<int> mSet;

  mSet.Insert(3);
  mSet.Insert(2);
  mSet.Insert(1);

  // Act
  mSet.Remove(2);

  // Assert
  for (const auto &it : mSet) {
    EXPECT_NE(it, 2);
  }
}

TEST(SetTest, Can_Copy) {
  // Arrange
  Set<int> mSet1;
  Set<int> mSet2;

  mSet1.Insert(5);

  // Act & assert
  ASSERT_NO_THROW(mSet2 = mSet1);
  EXPECT_EQ(*mSet2.begin(), 5);
}

TEST(SetTest, Can_Move) {
  // Arrange
  Set<int> mSet1;
  Set<int> mSet2;

  mSet1.Insert(5);

  // Act & assert
  ASSERT_NO_THROW(mSet2 = std::move(mSet1));
  EXPECT_EQ(*mSet2.begin(), 5);
  EXPECT_EQ(mSet1.Size(), 0);
}

TEST(SetTest, Can_Create_Union) {
    // Arrange
    Set<int> mSet1;
    Set<int> mSet2;

    mSet1.Insert(1);
    mSet1.Insert(2);

    mSet2.Insert(2);
    mSet2.Insert(3);

    // Act
    mSet1.Expand(mSet2);

    // Assert
    EXPECT_EQ(mSet1.Size(), 3);
    EXPECT_TRUE(mSet1.Contains(1));
    EXPECT_TRUE(mSet1.Contains(2));
    EXPECT_TRUE(mSet1.Contains(3));
}

TEST(SetTest, Can_Create_Difference) {
    // Arrange
    Set<int> mSet1;
    Set<int> mSet2;

    mSet1.Insert(1);
    mSet1.Insert(2);

    mSet2.Insert(2);
    mSet2.Insert(3);

    // Act
    mSet1.Subtract(mSet2);

    // Assert
    EXPECT_EQ(mSet1.Size(), 1);
    EXPECT_EQ(*mSet1.begin(), 1);
}

TEST(SetTest, Can_Create_Symmetric_Difference) {
    // Arrange
    Set<int> mSet1;
    Set<int> mSet2;

    mSet1.Insert(1);
    mSet1.Insert(2);

    mSet2.Insert(2);
    mSet2.Insert(3);

    // Act
    Set<int> res = Set<int>::SymmetricDifference(mSet1, mSet2);

    // Assert
    EXPECT_EQ(res.Size(), 2);
    EXPECT_TRUE(res.Contains(1));
    EXPECT_TRUE(res.Contains(3));
}

TEST(SetTest, Can_Create_Intersection) {
    // Arrange
    Set<int> mSet1;
    Set<int> mSet2;

    mSet1.Insert(1);
    mSet1.Insert(2);

    mSet2.Insert(2);
    mSet2.Insert(3);

    // Act
    Set<int> res = Set<int>::Intersect(mSet1, mSet2);

    // Assert
    EXPECT_EQ(res.Size(), 1);
    EXPECT_TRUE(res.Contains(2));
}

