// Copyright 2019 Evdokimov Artem

#include <gtest/gtest.h>

#include "include/shapes_volume.h"

TEST(Evdokimov_Artem_ShapesVolume , Can_Calculate_Volume_Of_Sphere) {
    // Arrange
    double radius = 2.5;
    // Act
    double result = ShapesVolume::SphereVolume(radius);
    // Assert
    double exp_ans = 65.44;
    EXPECT_NEAR(exp_ans , result , 0.01);
}

TEST(Evdokimov_Artem_ShapesVolume , Can_Calculate_Volume_Of_Cylinder) {
    // Arrange
    double radius = 2.0;
    double height = 3.0;
    // Act
    double result = ShapesVolume::CylinderVolume(radius , height);
    // Assert
    double exp_ans = 37.69;
    EXPECT_NEAR(exp_ans , result , 0.01);
}

TEST(Evdokimov_Artem_ShapesVolume , Can_Calculate_Volume_Of_Cube) {
    // Arrange
    double edgeLength = 2.0;
    // Act
    double result = ShapesVolume::CubeVolume(edgeLength);
    // Assert
    double exp_ans = 8.0;
    EXPECT_EQ(exp_ans , result);
}

TEST(Evdokimov_Artem_ShapesVolume , Can_Calculate_Volume_Of_Parallelepiped) {
    // Arrange
    double edgeLength = 2.0;
    double edgeHeight = 3.0;
    double edgeWidth = 6.0;
    // Act
    double result = ShapesVolume::ParallelepipedVolume(edgeLength ,
                                                       edgeHeight ,
                                                       edgeWidth);
    // Assert
    double exp_ans = 36.0;
    EXPECT_EQ(exp_ans , result);
}

TEST(Evdokimov_Artem_ShapesVolume , Can_Calculate_Volume_Of_Cone) {
    // Arrange
    double radius = 2.5;
    double height = 3.0;
    // Act
    double result = ShapesVolume::ConeVolume(radius , height);
    // Assert
    double exp_ans = 19.63;
    EXPECT_NEAR(exp_ans , result , 0.01);
}

TEST(Evdokimov_Artem_ShapesVolume , Can_Calculate_Volume_Of_Tetrahedron) {
    // Arrange
    double edgeLength = 5.0;
    // Act
    double result = ShapesVolume::TetrahedronVolume(edgeLength);
    // Assert
    double exp_ans = 14.73;
    EXPECT_NEAR(exp_ans , result , 0.01);
}
