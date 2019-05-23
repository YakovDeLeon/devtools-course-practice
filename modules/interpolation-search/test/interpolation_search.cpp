// Copyright 2019 Perov Dima

#include <gtest/gtest.h>

#include "include/InterpolationSearch.h"

class InterpolationSearchTest : public ::testing::Test {};

TEST_F(InterpolationSearchTest, Check_Size) {
    // Arrange
    int myData[] = {4, 5, 6, 33, 200};
    unsigned mySize = 5;

    // Act
    InterpolationSearch mySearch(myData, mySize);

    // Assert
    EXPECT_EQ(mySize, mySearch.GetSizeData());
}

TEST_F(InterpolationSearchTest, Check_Ptr) {
    // Arrange
    int myData[] = {4, 5, 6, 33, 200};
    unsigned mySize = 5;

    // Act
    InterpolationSearch mySearch(myData, mySize);

    // Assert
    EXPECT_EQ(myData, mySearch.GetPointerData());
}

TEST_F(InterpolationSearchTest, Can_Set) {
    // Arrange
    int myData[] = {4, 5, 6, 33, 200};
    unsigned mySize = 5;
    InterpolationSearch mySearch;

    // Act
    mySearch.SetSortedData(myData, mySize);

    // Assert
    EXPECT_EQ(myData, mySearch.GetPointerData());
}

TEST_F(InterpolationSearchTest, Can_Find_1) {
    // Arrange
    int myData[] = {-4, 5, 6, 33, 200};
    unsigned mySize = 5;
    int64_t findIndex = 0;
    InterpolationSearch mySearch(myData, mySize);

    // Act
    findIndex = mySearch.Search(6);

    // Assert
    EXPECT_EQ(2, findIndex);
}

TEST_F(InterpolationSearchTest, Can_Find_2) {
    // Arrange
    int myData[] = {4, 5, 6, 33, 200};
    unsigned mySize = 5;
    int64_t findIndex = 0;
    InterpolationSearch mySearch(myData, mySize);

    // Act
    findIndex = mySearch.Search(200);

    // Assert
    EXPECT_EQ(4, findIndex);
}

TEST_F(InterpolationSearchTest, Can_Find_3) {
    // Arrange
    int myData[] = {4, 5, 6, 33, 99, 200, 248, 2888, 9992};
    unsigned mySize = 9;
    int64_t findIndex = 0;
    InterpolationSearch mySearch(myData, mySize);

    // Act
    findIndex = mySearch.Search(2888);

    // Assert
    EXPECT_EQ(7, findIndex);
}

TEST_F(InterpolationSearchTest, Can_Find_4) {
    // Arrange
    int myData[] = {0, 1, 2};
    unsigned mySize = 3;
    int64_t findIndex = 0;
    InterpolationSearch mySearch(myData, mySize);

    // Act
    findIndex = mySearch.Search(1);

    // Assert
    EXPECT_EQ(1, findIndex);
}

TEST_F(InterpolationSearchTest, Can_Get_Find_Index) {
    // Arrange
    int myData[] = {4, 5, 6, 33, 200};
    unsigned mySize = 5;
    InterpolationSearch mySearch(myData, mySize);

    // Act
    mySearch.Search(6);

    // Assert
    EXPECT_EQ(2, mySearch.GetFindIndex());
}

TEST_F(InterpolationSearchTest, Can_Undefined_1) {
    // Arrange
    int myData[] = {4, 5, 6, 33, 99, 200, 248, 2888, 9992};
    unsigned mySize = 9;
    int64_t findIndex = 0;
    InterpolationSearch mySearch(myData, mySize);

    // Act
    findIndex = mySearch.Search(69);

    // Assert
    EXPECT_EQ(-1, findIndex);
}

TEST_F(InterpolationSearchTest, Can_Undefind_2) {
    // Arrange
    int myData[] = {1, 2, 3, 4, 5, 60, 72, 72, 77, 82, 90, 100};
    unsigned mySize = 12;
    int64_t findIndex = 0;
    InterpolationSearch mySearch(myData, mySize);

    // Act
    findIndex = mySearch.Search(70);

    // Assert
    EXPECT_EQ(-1, findIndex);
}

TEST_F(InterpolationSearchTest, Can_Find_With_Param_1) {
    // Arrange
    int myData[] = {4, 5, 6, 6, 6, 33, 99, 200, 248, 2888, 9992};
    unsigned mySize = 11;
    int64_t findIndex = 0;
    InterpolationSearch mySearch(myData, mySize);

    // Act
    findIndex = mySearch.Search(6, 4, 10);

    // Assert
    EXPECT_EQ(4, findIndex);
}

TEST_F(InterpolationSearchTest, Can_Find_With_Param_2) {
    // Arrange
    int myData[] = {4, 5, 6, 6, 6, 33, 99, 200, 248, 2888, 9992};
    unsigned mySize = 11;
    int64_t findIndex = 0;
    InterpolationSearch mySearch(myData, mySize);

    // Act
    findIndex = mySearch.Search(2888, 4, 10);

    // Assert
    EXPECT_EQ(9, findIndex);
}

TEST_F(InterpolationSearchTest, Can_Find_With_Param_3) {
    // Arrange
    int myData[] = {4, 5, 6, 6, 6, 33, 99, 200, 248, 2888, 9992};
    unsigned mySize = 11;
    int64_t findIndex = 0;
    InterpolationSearch mySearch(myData, mySize);

    // Act
    findIndex = mySearch.Search(9992, 4, 10);

    // Assert
    EXPECT_EQ(10, findIndex);
}

TEST_F(InterpolationSearchTest, Can_Find_With_Param_4) {
    // Arrange
    int myData[] = {4, 5, 6, 6, 6, 33, 99, 200, 248, 2888, 9992};
    unsigned mySize = 11;
    int64_t findIndex = 0;
    InterpolationSearch mySearch(myData, mySize);

    // Act
    findIndex = mySearch.Search(33, 4, 10);

    // Assert
    EXPECT_EQ(5, findIndex);
}

TEST_F(InterpolationSearchTest, Can_Find_With_Param_5) {
    // Arrange
    int myData[] = {0, 1, 2};
    unsigned mySize = 3;
    int64_t findIndex = 0;
    InterpolationSearch mySearch(myData, mySize);

    // Act
    findIndex = mySearch.Search(1, 0, 2);

    // Assert
    EXPECT_EQ(1, findIndex);
}

TEST_F(InterpolationSearchTest, Can_Undefind_With_Param_1) {
    // Arrange
    int myData[] = {4, 5, 6, 6, 6, 33, 99, 200, 248, 2888, 9992};
    unsigned mySize = 11;
    int64_t findIndex = 0;
    InterpolationSearch mySearch(myData, mySize);

    // Act
    findIndex = mySearch.Search(6, 5, 10);

    // Assert
    EXPECT_EQ(-1, findIndex);
}

TEST_F(InterpolationSearchTest, Can_Undefind_With_Param_2) {
    // Arrange
    int myData[] = {1, 2, 3, 4, 5, 60, 72, 72, 77, 82, 90, 100};
    unsigned mySize = 12;
    int64_t findIndex = 0;
    InterpolationSearch mySearch(myData, mySize);

    // Act
    findIndex = mySearch.Search(70, 0, 11);

    // Assert
    EXPECT_EQ(-1, findIndex);
}
