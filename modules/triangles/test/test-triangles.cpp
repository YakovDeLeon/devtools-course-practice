// Copyright 2019 Shkerin Igor

#include <gtest/gtest.h>

#include <cmath>
#include <vector>

#include "include/triangles.h"

double epsilon = 0.0002;

TEST(TrianglesTest, Can_Create_Default_Point) {
    // Arrange
    Point a;

    // Act & Assert
    ASSERT_TRUE(a.x == 0.0 && a.y == 0.0);
}

TEST(TrianglesTest, Possibility_Of_Assigning_Point) {
    // Arrange
    Point a(0.1, 0.3);

    // Act
    ASSERT_TRUE(a.x == 0.1 && a.y == 0.3);
    Point b = a;

    // Assert
    ASSERT_TRUE(b.x == 0.1 && b.y == 0.3);
}

TEST(TrianglesTest, Equal_Points_Are_Equal) {
    // Arrange
    Point a(0.1, 0.3);
    Point b(0.1, 0.3);

    // Act & Assert
    EXPECT_EQ(a, b);
}

TEST(TrianglesTest, Correct_Comparison_Of_Two_Not_Equal_Points) {
    // Arrange
    Point a(0.1, 0.3);
    Point b(1.0, 0.3);

    // Act & Assert
    ASSERT_FALSE(a == b);
}

TEST(TrianglesTest, Correct_Comparison_Of_Two_Equal_Points) {
    // Arrange
    Point a(0.1, 0.3);
    Point b(0.1, 0.3);

    // Act & Assert
    ASSERT_TRUE(a == b);
}

TEST(TrianglesTest, Can_Create_Point) {
    // Arrange
    Point a(3.0, 2.0);

    // Act & Assert
    ASSERT_TRUE(a.x == 3.0 && a.y == 2.0);
}

TEST(TrianglesTest, Can_Create_Negative_Point) {
    // Arrange
    Point a(-3.0, -2.0);

    // Act & Assert
    ASSERT_TRUE(a.x == -3.0 && a.y == -2.0);
}

TEST(TrianglesTest, Can_Create_Default_Triangle) {
    // Arrange
    Triangle abc;
    Point a(-3.0, 0.0);
    Point b(3.0, 0.0);
    Point c(0.0, 3.0);

    // Act & Assert
    ASSERT_TRUE(abc.get_point_a() == a && abc.get_point_b() == b &&
                abc.get_point_c() == c);
}

TEST(TrianglesTest, Can_Create_Triangle_On_Coordinates) {
    // Arrange
    Triangle abc(5.0, 2.0, 3.0, 1.0, 0.0, 0.0);
    Point a(5.0, 2.0);
    Point b(3.0, 1.0);
    Point c(0.0, 0.0);

    // Act & Assert
    ASSERT_TRUE(abc.get_point_a() == a && abc.get_point_b() == b &&
                abc.get_point_c() == c);
}

TEST(TrianglesTest, Throw_When_Create_Triangle_On_Wrong_Coordinates) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(Triangle abc(1.0, 2.0, 3.0, 4.0, 5.0, 6.0));
}

TEST(TrianglesTest, Can_Create_Triangle_From_Vector) {
    // Arrange
    std::vector<double> coordinates = { 5.0, 2.0, 3.0, 1.0, 0.0, 0.0 };
    Triangle abc(coordinates);
    Point a(5.0, 2.0);
    Point b(3.0, 1.0);
    Point c(0.0, 0.0);

    // Act & Assert
    ASSERT_TRUE(abc.get_point_a() == a && abc.get_point_b() == b &&
                abc.get_point_c() == c);
}

TEST(TrianglesTest, Throw_When_Create_Wrong_Triangle_From_Vector) {
    // Arrange
    std::vector<double> coordinates = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0 };

    // Act & Assert
    ASSERT_ANY_THROW(Triangle abc(coordinates));
}

TEST(TrianglesTest, Throw_When_Create_Triangle_From_Vector_Not_Six_Size) {
    // Arrange
    std::vector<double> coordinates = { 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0 };

    // Act & Assert
    ASSERT_ANY_THROW(Triangle abc(coordinates));
}

TEST(TrianglesTest, Throw_When_Create_Triangle_From_Empty_Vector) {
    // Arrange
    std::vector<double> coordinates = { };

    // Act & Assert
    ASSERT_ANY_THROW(Triangle abc(coordinates));
}

TEST(TrianglesTest, Can_Create_Triangle_On_Three_Points) {
    // Arrange
    Point a(5.0, 2.0);
    Point b(3.0, 1.0);
    Point c(0.0, 0.0);
    Triangle abc(a, b, c);

    // Act & Assert
    ASSERT_TRUE(abc.get_point_a() == a && abc.get_point_b() == b &&
                abc.get_point_c() == c);
}

TEST(TrianglesTest, Throw_When_Create_Triangle_From_Wrong_Points) {
    // Arrange
    Point a(1.0, 2.0);
    Point b(3.0, 4.0);
    Point c(5.0, 6.0);

    // Act & Assert
    ASSERT_ANY_THROW(Triangle abc(a, b, c));
}

TEST(TrianglesTest, Normal_Triangle_Is_Exist) {
    // Arrange
    Point a(-3.0, 0.0);
    Point b(3.0, 0.0);
    Point c(0.0, 3.0);
    Triangle abc(a, b, c);

    // Act & Assert
    ASSERT_TRUE(abc.IsTriangleExist());
}

TEST(TrianglesTest, Zero_Triangle_Is_No_Exist) {
    // Arrange
    Point a;
    Point b;
    Point c;

    // Act & Assert
    ASSERT_ANY_THROW(Triangle abc(a, b, c));
}

TEST(TrianglesTest, Linear_Triangle_Is_No_Exist) {
    // Arrange
    Point a(0.0, 0.0);
    Point b(-3.0, 0.0);
    Point c(3.0, 0.0);

    // Act & Assert
    ASSERT_ANY_THROW(Triangle abc(a, b, c));
}

TEST(TrianglesTest, Can_Set_And_Get_A_B_C) {
    // Arrange
    Triangle abc;
    Point a(-3.0, 0.0);
    Point b(3.0, 0.0);
    Point c(0.0, 3.0);

    // Act
    abc.set_point_a(a);
    abc.set_point_b(b);
    abc.set_point_c(c);

    // Assert
    ASSERT_TRUE(abc.get_point_a() == a && abc.get_point_b() == b &&
                abc.get_point_c() == c);
}

TEST(TrianglesTest, Correct_Side_Length_Calculation) {
    // Arrange
    Point a(-3.0, 0.0);
    Point b(3.0, 0.0);
    Point c(0.0, 3.0);
    double length_ab = 6.0;
    Triangle abc(a, b, c);

    // Act & Assert
    EXPECT_EQ(length_ab, abc.SideLength(a, b));
}

TEST(TrianglesTest, Length_Of_Side_Does_Not_Depend_On_Order_Points) {
    // Arrange
    Point a(-3.0, 0.0);
    Point b(3.0, 0.0);
    Point c(0.0, 3.0);
    double length_ab = 6.0;
    double length_ba = 6.0;
    Triangle abc(a, b, c);

    // Act & Assert
    EXPECT_EQ(length_ab + length_ba, abc.SideLength(a, b) +
              abc.SideLength(b, a));
}

TEST(TrianglesTest, Correctly_Calculate_Perimeter) {
    // Arrange
    Point a(-3.0, 0.0);
    Point b(3.0, 0.0);
    Point c(0.0, 3.0);
    Triangle abc(a, b, c);

    // Act
    double length_ab = abc.SideLength(a, b);
    double length_ac = abc.SideLength(a, c);
    double length_bc = abc.SideLength(b, c);

    // Assert
    EXPECT_EQ(length_ab + length_ac + length_bc, abc.Perimeter());
}

TEST(TrianglesTest, Get_Angle_A) {
    // Arrange
    Point a(0.0, 0.0);
    Point b(4.0, 0.0);
    Point c(0.0, 6.0);
    Triangle abc(a, b, c);

    // Act & Assert
    ASSERT_TRUE(fabs(abc.get_angle_a() - 90.0) < epsilon);
}

TEST(TrianglesTest, Get_Angle_B) {
    // Arrange
    Point a(4.0, 0.0);
    Point b(0.0, 0.0);
    Point c(0.0, 6.0);
    Triangle abc(a, b, c);

    // Act & Assert
    ASSERT_TRUE((abc.get_angle_b()- 90.0) < epsilon);
}

TEST(TrianglesTest, Get_Angle_C) {
    // Arrange
    Point a(4.0, 0.0);
    Point b(0.0, 6.0);
    Point c(0.0, 0.0);
    Triangle abc(a, b, c);

    // Act & Assert
    ASSERT_TRUE(fabs(abc.get_angle_c() - 90.0) < epsilon);
}

TEST(TrianglesTest, Sum_All_Angles_Of_Triangle_Is_180_Degrees) {
    // Arrange
    Point a(4.0, 0.0);
    Point b(0.0, 6.0);
    Point c(0.0, 0.0);
    Triangle abc(a, b, c);

    // Act & Assert
    ASSERT_TRUE(fabs(abc.get_angle_a() + abc.get_angle_b() +
                abc.get_angle_c() - 180.0) < epsilon);
}

TEST(TrianglesTest, Correctly_Calculate_Square) {
    // Arrange
    Point a(-3.0, 0.0);
    Point b(3.0, 0.0);
    Point c(0.0, 3.0);
    Triangle abc(a, b, c);
    double square = 9.0;

    // Act & Assert
    ASSERT_TRUE(fabs(abc.Square() - square) < epsilon);
}

TEST(TrianglesTest, Throw_When_Set_Wrong_Coordinate_In_Point_A) {
    // Arrange
    Point a(0.0, 3.0);
    Point b(-3.0, 0.0);
    Point c(3.0, 0.0);
    Triangle abc(a, b, c);
    Point wrong_point_a(0.0, 0.0);

    // Act & Assert
    ASSERT_ANY_THROW(abc.set_point_a(wrong_point_a));
}

TEST(TrianglesTest, Throw_When_Set_Wrong_Coordinate_In_Point_B) {
    // Arrange
    Point a(0.0, 3.0);
    Point b(-3.0, 0.0);
    Point c(3.0, 0.0);
    Triangle abc(a, b, c);
    Point wrong_point_b(0.0, 3.0);

    // Act & Assert
    ASSERT_ANY_THROW(abc.set_point_b(wrong_point_b));
}

TEST(TrianglesTest, Throw_When_Set_Wrong_Coordinate_In_Point_C) {
    // Arrange
    Point a(0.0, 3.0);
    Point b(-3.0, 0.0);
    Point c(3.0, 0.0);
    Triangle abc(a, b, c);
    Point wrong_point_c(0.0, 3.0);

    // Act & Assert
    ASSERT_ANY_THROW(abc.set_point_c(wrong_point_c));
}

TEST(TrianglesTest, Correct_Convert_To_Radian) {
    // Arrange
    Point a(0.0, 3.0);
    Point b(0.0, 0.0);
    Point c(3.0, 0.0);
    Triangle abc(a, b, c);

    // Act
    double degree = abc.get_angle_b();
    ASSERT_TRUE(fabs(degree - 90.0) < epsilon);
    double radian = abc.ConvertToRadian(degree);

    // Assert
    ASSERT_TRUE(fabs(radian - 1.5708) < epsilon);
}

TEST(TrianglesTest, Correct_Convert_To_Degree) {
    // Arrange
    Point a(0.0, 3.0);
    Point b(0.0, 0.0);
    Point c(3.0, 0.0);
    Triangle abc(a, b, c);
    double radian = 1.5708;

    // Act
    double degree = abc.get_angle_b();

    // Assert
    ASSERT_TRUE(fabs(radian - abc.ConvertToRadian(degree)) < epsilon);
}
