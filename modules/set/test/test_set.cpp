// Copyright 2019 Alexander Batashev

#include <gtest/gtest.h>
#include <algorithm>
#include <vector>

#include "include/set.h"

TEST(SetTest, Can_Create_Set_Via_Initializer_List) {
    // Arrange & Act
    Set<int> mSet = {3, 5, 1, 6};

    // Assert
    EXPECT_EQ(mSet.size(), 4);
    EXPECT_TRUE(mSet.Contains(1));
    EXPECT_TRUE(mSet.Contains(3));
    EXPECT_TRUE(mSet.Contains(5));
    EXPECT_TRUE(mSet.Contains(6));
}

TEST(SetTest, Can_Add_Item) {
    // Arrange
    Set<int> mSet;

    // Act
    mSet.Add(5);

    // Assert
    EXPECT_TRUE(mSet.Contains(5));
}

TEST(SetTest, Added_Items_Are_Unique) {
    // Arrange
    Set<int> mSet;

    // Act
    mSet.Add(5);
    mSet.Add(5);
    mSet.Add(5);

    // Assert
    EXPECT_EQ(mSet.size(), 1);
    EXPECT_EQ(*mSet.begin(), 5);
}

TEST(SetTest, Added_Items_Are_Sorted) {
    // Arrange
    Set<int> mSet;

    // Act
    mSet.Add(3);
    mSet.Add(2);
    mSet.Add(1);

    // Assert
    EXPECT_TRUE(std::is_sorted(mSet.begin(), mSet.end()));
}

TEST(SetTest, Can_Remove_Items) {
    // Arrange
    Set<int> mSet;

    mSet.Add(3);
    mSet.Add(2);
    mSet.Add(1);

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

    mSet1.Add(5);

    // Act & Assert
    ASSERT_NO_THROW(mSet2 = mSet1);
    EXPECT_EQ(*mSet2.begin(), 5);
}

TEST(SetTest, Can_Create_Union) {
    // Arrange
    Set<int> mSet1 = {1, 2};
    Set<int> mSet2 = {2, 3};

    // Act
    Set<int> res = Set<int>::Union(mSet1, mSet2);

    // Assert
    EXPECT_EQ(res.size(), 3);
    EXPECT_TRUE(res.Contains(1));
    EXPECT_TRUE(res.Contains(2));
    EXPECT_TRUE(res.Contains(3));
}

TEST(SetTest, Can_Create_Difference) {
    // Arrange
    Set<int> mSet1 = {1, 2};
    Set<int> mSet2 = {2, 3};

    // Act
    Set<int> res = Set<int>::Difference(mSet1, mSet2);

    // Assert
    EXPECT_EQ(res.size(), 1);
    EXPECT_EQ(*res.begin(), 1);
}

TEST(SetTest, Can_Create_Symmetric_Difference) {
    // Arrange
    Set<int> mSet1 = {1, 2};
    Set<int> mSet2 = {2, 3};

    // Act
    Set<int> res = Set<int>::SymmetricDifference(mSet1, mSet2);

    // Assert
    EXPECT_EQ(res.size(), 2);
    EXPECT_TRUE(res.Contains(1));
    EXPECT_TRUE(res.Contains(3));
}

TEST(SetTest, Can_Create_Intersection) {
    // Arrange
    Set<int> mSet1 = {1, 2};
    Set<int> mSet2 = {2, 3};

    // Act
    Set<int> res = Set<int>::Intersection(mSet1, mSet2);

    // Assert
    EXPECT_EQ(res.size(), 1);
    EXPECT_TRUE(res.Contains(2));
}

TEST(SetTest, Can_Subset) {
    // Arrange
    Set<int> mSet1 = {2, 3, 5};
    Set<int> mSet2 = {1, 2, 3, 4, 5, 6};

    // Act
    bool isSubset = mSet2.IsSubset(mSet1);

    // Assert
    EXPECT_TRUE(isSubset);
}

TEST(SetTest, Set_Can_Is_Not_Be_Subset) {
    // Arrange
    Set<int> mSet1 = {1, 2, 3, 4, 5, 6};
    Set<int> mSet2 = {8, 3, 5};

    // Act
    bool isSubset = mSet1.IsSubset(mSet2);

    // Assert
    EXPECT_FALSE(isSubset);
}

TEST(SetTest, Can_Define_Equality_Of_Sets) {
    // Arrange
    Set<int> mSet1 = {1, 4, 5};
    Set<int> mSet2 = {1, 4, 5};

    // Act
    bool isSubset = mSet1 == mSet2;

    // Assert
    EXPECT_TRUE(isSubset);
}

TEST(SetTest, Can_Define_Non_Equality_Of_Sets) {
    // Arrange
    Set<int> mSet1 = {1, 4, 5};
    Set<int> mSet2 = {1, 3, 5};

    // Act
    bool isSubset = mSet1 != mSet2;

    // Assert
    EXPECT_TRUE(isSubset);
}
