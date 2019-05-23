// Copyright 2019 Likholat Ann

#include <gtest/gtest.h>

#include "include/complex.h"

TEST(ComplexTest, Can_Create_With_Real_And_Imaginary) {
    // Arrange
    double re = 26.0;
    double im = 20.0;

    // Act
    Complex z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(re, z.get_re());
    EXPECT_DOUBLE_EQ(im, z.get_im());
}

TEST(ComplexTest, Can_Create_Only_With_Real) {
    // Arrange
    double re = 26.0;

    // Act
    Complex z(re);

    // Assert
    EXPECT_DOUBLE_EQ(re, z.get_re());
    EXPECT_DOUBLE_EQ(0, z.get_im());
}

TEST(ComplexTest, Assignment_Returns_Correct_Link) {
    // Arrange
    Complex z1;
    Complex z2(2.0, 3.0);
    Complex *returned_link;

    // Act
    returned_link = &(z1 = z2);

    // Assert
    EXPECT_EQ(returned_link, &z1);
}

TEST(ComplexTest, Can_Create_Via_Copying) {
    // Arrange
    Complex z(26.0, 20.0);

    // Act
    Complex expected_z = z;

    // Assert
    EXPECT_EQ(expected_z, z);
}

TEST(ComplexTest, Can_Set_Real) {
    // Arrange
    Complex z;
    double re = 20.0;

    // Act
    z.set_re(re);

    // Assert
    EXPECT_DOUBLE_EQ(re, z.get_re());
}

TEST(ComplexTest, Can_Set_Imaginary) {
    // Arrange
    Complex z;
    double im = 26.0;

    // Act
    z.set_im(im);

    // Assert
    EXPECT_DOUBLE_EQ(im, z.get_im());
}

TEST(ComplexTest, Can_Add_Complex) {
    // Arrange
    Complex z1(26.0, 14.0);
    Complex z2(1.0, 7.0);

    // Act
    Complex z = z1 + z2;

    // Assert
    Complex expected_z(27.0, 21.0);
    EXPECT_EQ(expected_z, z);
}

TEST(ComplexTest, Can_Difference_Complex) {
    // Arrange
    Complex z1(26.0, 14.0);
    Complex z2(1.0, 1.0);

    // Act
    Complex z = z2 - z1;

    // Assert
    Complex expected_z(-25.0, -13.0);
    EXPECT_EQ(expected_z, z);
}

TEST(ComplexTest, Can_Multiply_Complex) {
    // Arrange
    Complex z1(5.0, 3.0);
    Complex z2(4.0, 6.0);

    // Act
    Complex z = z1 * z2;

    // Assert
    Complex expected_z(2.0, 42.0);
    EXPECT_EQ(expected_z, z);
}

TEST(ComplexTest, Can_Division_Complex) {
    // Arrange
    Complex z1(15.0, 20.0);
    Complex z2(27.0, 30.0);

    // Act
    Complex z = z2 / z1;

    // Assert
    Complex expected_z(1.608, -0.144);
    EXPECT_EQ(expected_z, z);
}

TEST(ComplexTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    Complex z1(0.0, 0.0);
    Complex z2(26.0, 14.0);

    // Act & Assert
    ASSERT_ANY_THROW(z2 / z1);
}

TEST(ComplexTest, Number_Is_Equal_To_Itself) {
    // Arrange
    Complex z(26.0, 14.0);

    // Act & Assert
    EXPECT_TRUE(z == z);
}

TEST(ComplexTest, Equal_Numbers_Are_Equal) {
    // Arrange
    Complex z1(26.0, 14.0);
    Complex z2(26.0, 14.0);

    // Act & Assert
    EXPECT_EQ(z1, z2);
}

TEST(ComplexTest, Different_Numbers_Not_Equal) {
    // Arrange
    Complex z1(26.0, 14.0);
    Complex z2(26.1, 14.1);

    // Act & Assert
    EXPECT_TRUE(z1 != z2);
}

TEST(ComplexTest, Can_Create_Copy) {
    // Arrange
    Complex z(2.3, 1.4);

    // Act
    Complex z_1(z);

    // Assert
    EXPECT_EQ(z, z_1);
}

TEST(ComplexTest, Can_Add_Associativy) {
    // Arrange
    Complex z(2.0, 1.4);
    Complex z_1(4.6, 3.0);
    Complex z_2(7.3, 1.2);

    // Act
    Complex res = (z + z_1) + z_2;
    Complex res_1 = z + (z_1 + z_2);

    // Assert
    EXPECT_DOUBLE_EQ(res.get_re(), res_1.get_re());
    EXPECT_DOUBLE_EQ(res.get_im(), res_1.get_im());
}

TEST(ComplexTest, Can_Multiply_By_Zero) {
    // Arrange
    Complex z(2.0, 1.0);
    Complex zero(0.0, 0.0);

    // Act
    Complex res = z * zero;

    // Assert
    EXPECT_EQ(res, zero);
}

TEST(ComplexTest, Can_Multiply_By_Itself) {
    // Arrange
    Complex z(2.3, 1.2);

    // Act
    Complex res = z * z;

    // Assert
    Complex expected_res(3.85, 5.52);
    EXPECT_DOUBLE_EQ(expected_res.get_re(), res.get_re());
    EXPECT_DOUBLE_EQ(expected_res.get_im(), res.get_im());
}

TEST(ComplexTest, Can_Add_And_Asiign_Complex) {
    // Arrange
    Complex z1(26.0, 14.0);
    Complex z2(1.0, 7.0);

    // Act
    z1 += z2;

    // Assert
    Complex expected_z(27.0, 21.0);
    EXPECT_EQ(expected_z, z1);
}

TEST(ComplexTest, Can_Difference_And_Asiign_Complex) {
    // Arrange
    Complex z1(26.0, 14.0);
    Complex z2(1.0, 7.0);

    // Act
    z2 -= z1;

    // Assert
    Complex expected_z(-25.0, -7.0);
    EXPECT_EQ(expected_z, z2);
}

TEST(ComplexTest, Can_Multiply_And_Asiign_Complex) {
    // Arrange
    Complex z1(5.0, 3.0);
    Complex z2(4.0, 6.0);

    // Act
    z1 *= z2;

    // Assert
    Complex expected_z(2.0, 42.0);
    EXPECT_EQ(expected_z, z1);
}

TEST(ComplexTest, Can_Division_And_Asiign_Complex) {
    // Arrange
    Complex z1(15.0, 20.0);
    Complex z2(27.0, 30.0);

    // Act
    z2 /= z1;

    // Assert
    Complex expected_z(1.608, -0.144);
    EXPECT_EQ(expected_z, z2);
}

TEST(ComplexTest, Do_Throw_When_Division_And_Assign_By_Zero) {
    // Arrange
    Complex z1(0.0, 0.0);
    Complex z2(26.0, 14.0);

    // Act & Assert
    ASSERT_ANY_THROW(z2 /= z1);
}

TEST(ComplexTest, Add_Operators_Are_Equal) {
    // Arrange
    Complex z1(15.0, 20.0);
    Complex z2(27.0, 30.0);

    // Act
    Complex z = z1 + z2;
    z1 += z2;

    // Assert
    EXPECT_EQ(z, z1);
}

TEST(ComplexTest, Difference_Operators_Are_Equal) {
    // Arrange
    Complex z1(26.0, 14.0);
    Complex z2(1.0, 7.0);

    // Act
    Complex z = z2 - z1;
    z2 -= z1;

    // Assert
    EXPECT_EQ(z, z2);
}

TEST(ComplexTest, Multiplication_Operators_Are_Equal) {
    // Arrange
    Complex z1(5.0, 3.0);
    Complex z2(4.0, 6.0);

    // Act
    Complex z = z1 * z2;
    z1 *= z2;

    // Assert
    EXPECT_EQ(z, z1);
}

TEST(ComplexTest, Division_Operators_Are_Equal) {
    // Arrange
    Complex z1(15.0, 20.0);
    Complex z2(27.0, 30.0);

    // Act
    Complex z = z2 / z1;
    z2 /= z1;

    // Assert
    EXPECT_EQ(z, z2);
}

TEST(ComplexTest, Can_Count_Complex_Abs) {
    // Arrange
    Complex z(15.0, 20.0);

    // Act
    double abs = z.abs();

    // Assert
    double expected_abs = 25.0;
    EXPECT_DOUBLE_EQ(expected_abs, abs);
}
