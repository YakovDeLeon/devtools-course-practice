// Copyright 2019 Kurakin Mikhail

#include <gtest/gtest.h>

#include "include/shapes_area.h"

TEST(Kurakin_Mikhail_ShapesArea, Can_Calculate_Area_Of_Sphere) {
    // Arrange
    double radius = 3.4;
    // Act
    double result = ShapesArea::SphereArea(radius);
    // Assert
    double exp_ans = 145.2672;
    EXPECT_NEAR(exp_ans, result, 4);
}

TEST(Kurakin_Mikhail_ShapesArea, Can_Calculate_Area_Of_Cylinder) {
    // Arrange
    double radius = 3.4;
    double height = 4.0;
    // Act
    double result = ShapesArea::CylinderArea(radius, height);
    // Assert
    double exp_ans = 158.0849;
    EXPECT_NEAR(exp_ans, result, 4);
}

TEST(Kurakin_Mikhail_ShapesArea, Can_Calculate_Area_Of_Cube) {
    // Arrange
    double a = 4.0;
    // Act
    double result = ShapesArea::CubeArea(a);
    // Assert
    double exp_ans = 96.0;
    EXPECT_NEAR(exp_ans, result, 4);
}

TEST(Kurakin_Mikhail_ShapesArea, Can_Calculate_Area_Of_Parallelepiped) {
    // Arrange
    double a = 4.0;
    double b = 3.0;
    double c = 2.0;
    // Act
    double result = ShapesArea::ParallelepipedArea(a, b, c);
    // Assert
    double exp_ans = 52.0;
    EXPECT_NEAR(exp_ans, result, 4);
}

TEST(Kurakin_Mikhail_ShapesArea, Can_Calculate_Area_Of_Cone) {
    // Arrange
    double radius = 5.5;
    double generator = 3.2;
    // Act
    double result = ShapesArea::ConeArea(radius, generator);
    // Assert
    double exp_ans = 150.3252;
    EXPECT_NEAR(exp_ans, result, 4);
}

TEST(Kurakin_Mikhail_ShapesArea, Can_Calculate_Area_Of_Tetrahedron) {
    // Arrange
    double a = 8.8;
    // Act
    double result = ShapesArea::TetrahedronArea(a);
    // Assert
    double exp_ans = 134.1300;
    EXPECT_NEAR(exp_ans, result, 4);
}
