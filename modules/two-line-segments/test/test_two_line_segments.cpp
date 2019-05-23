// Copyright 2019 Iamshchikov Ivan

#include <gtest/gtest.h>

#include "include/two_line_segments.h"

TEST(TwoLineSegmentsTest, Can_Create_Via_Default_Constructor) {
    // Arrange

    // Act & Assert
    ASSERT_NO_THROW(TwoLineSegments tls);
}

TEST(TwoLineSegmentsTest, Can_Create_Via_Parameterized_Constructor) {
    // Arrange
    LineSegment ls1;
    ls1.p1.SetCoordinatesToPoint(0, 0);
    ls1.p2.SetCoordinatesToPoint(5, 0);

    LineSegment ls2;
    ls2.p1.SetCoordinatesToPoint(5, 0);
    ls2.p2.SetCoordinatesToPoint(0, 7);

    // Act & Assert
    ASSERT_NO_THROW(TwoLineSegments tls(ls1, ls2));
}

TEST(TwoLineSegmentsTest,
     Can_Get_Coordinates_Of_Lines_Created_Via_Parameterized_Constructor) {
    // Arrange
    LineSegment ls1;
    ls1.p1.SetCoordinatesToPoint(0, 0);
    ls1.p2.SetCoordinatesToPoint(5, 0);

    LineSegment ls2;
    ls2.p1.SetCoordinatesToPoint(5, 0);
    ls2.p2.SetCoordinatesToPoint(0, 7);

    // Act
    TwoLineSegments tls(ls1, ls2);

    // Assert
    EXPECT_EQ(0, tls.GetLineSegment1().p1.GetX());
    EXPECT_EQ(0, tls.GetLineSegment1().p1.GetY());
    EXPECT_EQ(5, tls.GetLineSegment1().p2.GetX());
    EXPECT_EQ(0, tls.GetLineSegment1().p2.GetY());
    EXPECT_EQ(5, tls.GetLineSegment2().p1.GetX());
    EXPECT_EQ(0, tls.GetLineSegment2().p1.GetY());
    EXPECT_EQ(0, tls.GetLineSegment2().p2.GetX());
    EXPECT_EQ(7, tls.GetLineSegment2().p2.GetY());
}

TEST(TwoLineSegmentsTest, Can_Create_Via_Copy_Constructor) {
    // Arrange
    LineSegment ls1;
    ls1.p1.SetCoordinatesToPoint(0, 0);
    ls1.p2.SetCoordinatesToPoint(5, 0);

    LineSegment ls2;
    ls2.p1.SetCoordinatesToPoint(5, 0);
    ls2.p2.SetCoordinatesToPoint(0, 7);

    TwoLineSegments tls(ls1, ls2);

    // Act & Assert
    ASSERT_NO_THROW(TwoLineSegments(tls));
}

TEST(TwoLineSegmentsTest,
     Can_Get_Coordinates_Of_Lines_Created_Via_Copy_Constructor) {
    // Arrange
    LineSegment ls1;
    ls1.p1.SetCoordinatesToPoint(1, 2);
    ls1.p2.SetCoordinatesToPoint(5, 6);

    LineSegment ls2;
    ls2.p1.SetCoordinatesToPoint(5, 0);
    ls2.p2.SetCoordinatesToPoint(3, 7);

    TwoLineSegments tls1(ls1, ls2);

    // Act
    TwoLineSegments tls2(tls1);

    // Assert
    EXPECT_EQ(1, tls2.GetLineSegment1().p1.GetX());
    EXPECT_EQ(2, tls2.GetLineSegment1().p1.GetY());
    EXPECT_EQ(5, tls2.GetLineSegment1().p2.GetX());
    EXPECT_EQ(6, tls2.GetLineSegment1().p2.GetY());
    EXPECT_EQ(5, tls2.GetLineSegment2().p1.GetX());
    EXPECT_EQ(0, tls2.GetLineSegment2().p1.GetY());
    EXPECT_EQ(3, tls2.GetLineSegment2().p2.GetX());
    EXPECT_EQ(7, tls2.GetLineSegment2().p2.GetY());
}

TEST(TwoLineSegmentsTest, Can_Set_And_Get_Coorditanes_Of_First_Line_Segment) {
    // Arrange
    Point p1, p2;
    p1.SetCoordinatesToPoint(5, 7);
    p2.SetCoordinatesToPoint(-1, -8);
    TwoLineSegments tls;

    // Act
    tls.SetCoordinatesToFirstLine(p1, p2);

    // Assert
    EXPECT_EQ(5, tls.GetLineSegment1().p1.GetX());
    EXPECT_EQ(7, tls.GetLineSegment1().p1.GetY());
    EXPECT_EQ(-1, tls.GetLineSegment1().p2.GetX());
    EXPECT_EQ(-8, tls.GetLineSegment1().p2.GetY());
}

TEST(TwoLineSegmentsTest,
     Can_Set_And_Get_Coorditanes_Of_Second_Line_Segment) {
    // Arrange
    Point p1, p2;
    p1.SetCoordinatesToPoint(5, 7);
    p2.SetCoordinatesToPoint(-3, -8);
    TwoLineSegments tls;

    // Act
    tls.SetCoordinatesToSecondLine(p1, p2);

    // Assert
    EXPECT_EQ(5, tls.GetLineSegment2().p1.GetX());
    EXPECT_EQ(7, tls.GetLineSegment2().p1.GetY());
    EXPECT_EQ(-3, tls.GetLineSegment2().p2.GetX());
    EXPECT_EQ(-8, tls.GetLineSegment2().p2.GetY());
}

TEST(TwoLineSegmentsTest,
     Checking_Of_Intersection_When_Line_Segments_Are_Parallel) {
    // Arrange
    Point p1, p2, p3, p4;
    p1.SetCoordinatesToPoint(0, 0);
    p2.SetCoordinatesToPoint(10, 0);
    p3.SetCoordinatesToPoint(0, 3);
    p4.SetCoordinatesToPoint(10, 3);
    TwoLineSegments tls;

    tls.SetCoordinatesToFirstLine(p1, p2);
    tls.SetCoordinatesToSecondLine(p3, p4);

    // Act & Assert
    EXPECT_EQ(0, tls.AreIntersect());
}

TEST(TwoLineSegmentsTest,
     Checking_Of_Intersection_When_Line_Segments_Intersects) {
    // Arrange
    Point p1, p2, p3, p4;
    p1.SetCoordinatesToPoint(0, 0);
    p2.SetCoordinatesToPoint(10, 0);
    p3.SetCoordinatesToPoint(2, -5);
    p4.SetCoordinatesToPoint(2, 5);
    TwoLineSegments tls;

    tls.SetCoordinatesToFirstLine(p1, p2);
    tls.SetCoordinatesToSecondLine(p3, p4);

    // Act & Assert
    EXPECT_EQ(1, tls.AreIntersect());
}

TEST(TwoLineSegmentsTest,
     No_Intersection_When_Second_Line_Is_Point_And_Not_Belongs_To_First_Line) {
    // Arrange
    Point p1, p2, p3, p4;
    p1.SetCoordinatesToPoint(0, 0);
    p2.SetCoordinatesToPoint(10, 0);
    p3.SetCoordinatesToPoint(2, 1);
    p4.SetCoordinatesToPoint(2, 1);
    TwoLineSegments tls;

    tls.SetCoordinatesToFirstLine(p1, p2);
    tls.SetCoordinatesToSecondLine(p3, p4);

    // Act & Assert
    EXPECT_EQ(0, tls.AreIntersect());
}

TEST(TwoLineSegmentsTest,
     Intersection_When_Second_Line_Is_Point_And_Belongs_To_First_Line) {
    // Arrange
    Point p1, p2, p3, p4;
    p1.SetCoordinatesToPoint(0, 0);
    p2.SetCoordinatesToPoint(10, 0);
    p3.SetCoordinatesToPoint(5, 0);
    p4.SetCoordinatesToPoint(5, 0);
    TwoLineSegments tls;

    tls.SetCoordinatesToFirstLine(p1, p2);
    tls.SetCoordinatesToSecondLine(p3, p4);

    // Act & Assert
    EXPECT_EQ(1, tls.AreIntersect());
}

TEST(TwoLineSegmentsTest,
     Intersection_When_Both_Lines_Are_Points_With_Equal_Coordinates) {
    // Arrange
    Point p1, p2, p3, p4;
    p1.SetCoordinatesToPoint(1, 2);
    p2.SetCoordinatesToPoint(1, 2);
    p3.SetCoordinatesToPoint(1, 2);
    p4.SetCoordinatesToPoint(1, 2);
    TwoLineSegments tls;

    tls.SetCoordinatesToFirstLine(p1, p2);
    tls.SetCoordinatesToSecondLine(p3, p4);

    // Act & Assert
    EXPECT_EQ(1, tls.AreIntersect());
}

TEST(TwoLineSegmentsTest,
     No_Intersection_When_Both_Lines_Are_Points_With_Not_Equal_Coordinates) {
    // Arrange
    Point p1, p2, p3, p4;
    p1.SetCoordinatesToPoint(1, 2);
    p2.SetCoordinatesToPoint(1, 2);
    p3.SetCoordinatesToPoint(5, 0);
    p4.SetCoordinatesToPoint(5, 0);
    TwoLineSegments tls;

    tls.SetCoordinatesToFirstLine(p1, p2);
    tls.SetCoordinatesToSecondLine(p3, p4);

    // Act & Assert
    EXPECT_EQ(0, tls.AreIntersect());
}
