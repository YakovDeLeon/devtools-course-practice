// Copyright 2019 Tolstikov Maksim

#include <gtest/gtest.h>

#include <string>

#include "include/vector_3d.h"

class Vector3dTest : public ::testing::Test {};

TEST_F(Vector3dTest, Can_Create_Vector_With_X_Y_Z) {
    // Arrange
    double x = 4.0;
    double y = 15.0;
    double z = 27.0;

    // Act
    Vector3d v(x, y, z);

    // Assert
    EXPECT_EQ(x, v.getX());
    EXPECT_EQ(y, v.getY());
    EXPECT_EQ(z, v.getZ());
}

TEST_F(Vector3dTest, Can_Create_Vector_With_Vector) {
    // Arrange
    Vector3d v(3.0, 4.0, 1.0);

    // Act
    Vector3d v1(v);

    // Assert
    EXPECT_EQ(v1, v);
}

TEST_F(Vector3dTest, Can_Assign) {
    // Arrange
    Vector3d v(3.0, 4.0, 1.0);
    Vector3d expected_v;

    // Act
    expected_v = v;

    // Assert
    EXPECT_EQ(expected_v, v);
}

TEST_F(Vector3dTest, Can_Set_X) {
    // Arrange
    Vector3d v;
    double x = 20.0;

    // Act
    v.setX(x);

    // Assert
    EXPECT_EQ(x, v.getX());
}

TEST_F(Vector3dTest, Can_Set_Y) {
    // Arrange
    Vector3d v;
    double y = 2.0;

    // Act
    v.setY(y);

    // Assert
    EXPECT_EQ(y, v.getY());
}

TEST_F(Vector3dTest, Can_Set_Z) {
    // Arrange
    Vector3d v;
    double z = 15.0;

    // Act
    v.setZ(z);

    // Assert
    EXPECT_EQ(z, v.getZ());
}

TEST_F(Vector3dTest, Can_Add_Vector) {
    // Arrange
    Vector3d v1(26.0, 14.0, 5.0);
    Vector3d v2(1.0, 1.0, 1.0);

    // Act
    Vector3d v = v2 + v1;

    // Assert
    Vector3d expected_v(27.0, 15.0, 6.0);
    EXPECT_EQ(expected_v, v);
}

TEST_F(Vector3dTest, Can_Difference_Vector) {
    // Arrange
    Vector3d v1(26.0, 14.0, 5.0);
    Vector3d v2(1.0, 1.0, 1.0);

    // Act
    Vector3d v = v2 - v1;

    // Assert
    Vector3d expected_v(-25.0, -13.0, -4.0);
    EXPECT_EQ(expected_v, v);
}

TEST_F(Vector3dTest, Can_Multiply_By_Scalar) {
    // Arrange
    Vector3d v1(26.0, 14.0, 5.0);
    double d = 2.0;

    // Act
    Vector3d v = v1 * d;

    // Assert
    EXPECT_EQ(52.0, v.getX());
    EXPECT_EQ(28.0, v.getY());
    EXPECT_EQ(10.0, v.getZ());
}

TEST_F(Vector3dTest, Can_Divide_By_Scalar) {
    // Arrange
    Vector3d v1(26.0, 14.0, 5.0);
    double d = 2.0;

    // Act
    Vector3d v = v1 / d;

    // Assert
    EXPECT_EQ(13.0, v.getX());
    EXPECT_EQ(7.0, v.getY());
    EXPECT_EQ(2.5, v.getZ());
}

TEST_F(Vector3dTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    Vector3d v(26.0, 14.0, 5.0);
    double d = 0.0;

    // Act & Assert
    EXPECT_THROW(v / d, std::string);
}

TEST_F(Vector3dTest, Can_Scalar_Multiplication) {
    // Arrange
    Vector3d v1(1.0, 2.0, 3.0);
    Vector3d v2(4.0, 5.0, 6.0);

    // Act
    double d = v1 * v2;

    // Assert
    double expected_d = 32.0;
    EXPECT_EQ(expected_d, d);
}

TEST_F(Vector3dTest, Can_Multiply_Vector) {
    // Arrange
    Vector3d v1(6.0, 4.0, 5.0);
    Vector3d v2(1.0, 2.0, 3.0);

    // Act
    Vector3d v = v1.Cross(v2);

    // Assert
    Vector3d expected_v(2.0, -13.0, 8.0);
    EXPECT_EQ(expected_v, v);
}

TEST_F(Vector3dTest, Can_Find_Norm) {
    // Arrange
    Vector3d v(3.0, -4.0, 0.0);

    // Act
    double d = v.Norma();

    // Assert
    double expected_d = 5.0;
    EXPECT_EQ(expected_d, d);
}

TEST_F(Vector3dTest, Do_Throw_When_Vector_Null) {
    // Arrange
    Vector3d v(0.0, 0.0, 0.0);

    // Act & Assert
    EXPECT_THROW(v.Normalize(), std::string);
}

TEST_F(Vector3dTest, Can_Normalize_Vector) {
    // Arrange
    Vector3d v1(3.0, 0.0, -4.0);

    // Act
    Vector3d v = v1.Normalize();

    // Assert
    Vector3d expected_v(0.6, 0.0, -0.8);
    EXPECT_EQ(expected_v, v);
}

TEST_F(Vector3dTest, Vector_Is_Equal_To_Itself) {
    // Arrange
    Vector3d v(26.0, 14.0, 5.0);

    // Act & Assert
    EXPECT_TRUE(v == v);
}

TEST_F(Vector3dTest, Equal_Vectors_Are_Equal) {
    // Arrange
    Vector3d v1(26.0, 14.0, 5.0);
    Vector3d v2(26.0, 14.0, 5.0);

    // Act & Assert
    EXPECT_EQ(v1, v2);
}

TEST_F(Vector3dTest, Different_Vectors_Not_Equal) {
    // Arrange
    Vector3d v1(26.0, 14.0, 5.0);
    Vector3d v2(26.1, 14.1, 5.1);

    // Act & Assert
    EXPECT_TRUE(v1 != v2);
}
