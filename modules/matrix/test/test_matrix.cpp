// Copyright 2019 Trykin Alexander

#include <string>

#include "gtest/gtest.h"
#include "include/matrix.h"

TEST(MatrixTest, Can_Create_Matrix_Via_Explicit_Constructor) {
    // Arrange & Act
    Matrix A(2, 2);

    // Assert
    EXPECT_EQ(2, A.getRows());
    EXPECT_EQ(2, A.getCols());

    EXPECT_EQ(0, A(0, 0));
    EXPECT_EQ(0, A(0, 1));

    EXPECT_EQ(0, A(1, 0));
    EXPECT_EQ(0, A(1, 1));
}

TEST(MatrixTest, Can_Create_Matrix_Via_Initializer_List) {
    // Arrange & Act
    Matrix A = {
            {2, 0, -1},
            {-1, 4, 3},
            {4, 2, 1},
    };

    // Assert
    EXPECT_EQ(3, A.getRows());
    EXPECT_EQ(3, A.getCols());

    EXPECT_EQ(2, A(0, 0));
    EXPECT_EQ(0, A(0, 1));
    EXPECT_EQ(-1, A(0, 2));

    EXPECT_EQ(-1, A(1, 0));
    EXPECT_EQ(4, A(1, 1));
    EXPECT_EQ(3, A(1, 2));

    EXPECT_EQ(4, A(2, 0));
    EXPECT_EQ(2, A(2, 1));
    EXPECT_EQ(1, A(2, 2));
}

TEST(MatrixTest, Can_Create_Via_Copy_Constructor) {
    // Arrange
    Matrix A = {
            {2, 0},
            {-3, 1}
    };

    // Act
    Matrix B(A);

    // Assert
    EXPECT_EQ(B, A);
}

TEST(MatrixTest, Can_Create_Via_Assignment_Operator) {
    // Arrange
    Matrix A = {
            {2, 0},
            {-3, 1}
    };

    // Act
    Matrix B(3, 6);
    B = A;

    // Assert
    EXPECT_EQ(B, A);
}

TEST(MatrixTest, Can_Get_Rows) {
    // Arrange
    Matrix A = {
            {2, 0, -1},
            {-1, 4, 3},
            {4, 2, 1},
            {1, 1, 1}
    };

    // Act & Assert
    EXPECT_EQ(4, A.getRows());
}

TEST(MatrixTest, Can_Get_Cols) {
    // Arrange
    Matrix A = {
            {2, 0, -1},
            {-1, 4, 3},
            {4, 2, 1},
            {1, 1, 1}
    };

    // Act & Assert
    EXPECT_EQ(3, A.getCols());
}

TEST(MatrixTest, Can_Get_Elem) {
    // Arrange
    Matrix A = {
            {2, 0, -1},
            {-1, 4, 3},
            {7, 2, 1},
    };

    // Act & Assert
    EXPECT_EQ(7, A(2, 0));
}

TEST(MatrixTest, Can_Get_Const_Elem) {
    // Arrange
    const Matrix A = {
            {2, 0, -1},
            {-1, 4, 3},
            {7, 2, 1},
    };

    // Act & Assert
    EXPECT_EQ(3, A(1, 2));
}

TEST(MatrixTest, Equal_Matrices_Are_Equal) {
    // Arrange
    Matrix A = {
            {2, 0},
            {-3, 1}
    };
    Matrix B = {
            {2, 0},
            {-3, 1}
    };

    // Act & Assert
    EXPECT_TRUE(A == B);
}

TEST(MatrixTest, Different_Matrices_Are_Not_Equal) {
    // Arrange
    Matrix A = {
            {2, 0},
            {-3, 1}
    };
    Matrix B = {
            {-3, 1},
            {2, 7}
    };

    // Act & Assert
    EXPECT_FALSE(A == B);
}

TEST(MatrixTest, Do_Throw_When_Compare_Incommensurate_Matrices) {
    // Arrange
    Matrix A = {
            {2, 0},
            {-3, 1}
    };
    Matrix B = {
            {2, 0, 4},
            {-3, 1, -1},
            {0, 1, 0}
    };

    // Act & Assert
    EXPECT_THROW(A.operator==(B), std::string);
}

TEST(MatrixTest, Can_Add_Matrices) {
    // Arrange
    Matrix A = {
            {2, 0, -1, 1},
            {-1, 4, 3, 1},
            {4, 2, 1, 1}
    };
    Matrix B = {
            {0, 1, -1, 3},
            {4, 0, -2, 5},
            {3, -4, 3, -1}
    };

    // Act
    Matrix C = A + B;

    // Assert
    Matrix expected = {
            {2, 1, -2, 4},
            {3, 4, 1, 6},
            {7, -2, 4, 0}
    };
    EXPECT_EQ(expected, C);
}

TEST(MatrixTest, Can_Sub_Matrices) {
    // Arrange
    Matrix A = {
            {2, 0, -1, 1},
            {-1, 4, 3, 1},
            {4, 2, 1, 1}
    };
    Matrix B = {
            {0, 1, -1, 3},
            {4, 0, -2, 5},
            {3, -4, 3, -1}
    };

    // Act
    Matrix C = A - B;

    // Assert
    Matrix expected = {
            {2, -1, 0, -2},
            {-5, 4, 5, -4},
            {1, 6, -2, 2}
    };
    EXPECT_EQ(expected, C);
}

TEST(MatrixTest, Can_Mul_Matrices) {
    // Arrange
    Matrix A = {
            {2, 0, -1},
            {-1, 4, 3},
            {4, 2, 1},
            {1, 1, 1}
    };
    Matrix B = {
            {0, 1, -1, 3},
            {4, 0, -2, 5},
            {3, -4, 3, -1}
    };

    // Act
    Matrix C = A * B;

    // Assert
    Matrix expected = {
            {-3, 6, -5, 7},
            {25, -13, 2, 14},
            {11, 0, -5, 21},
            {7, -3, 0, 7}
    };
    EXPECT_EQ(expected, C);
}

TEST(MatrixTest, Can_Add_Combined_With_Assignment) {
    // Arrange
    Matrix A = {
            {2, 0, -1, 1},
            {-1, 4, 3, 1},
            {4, 2, 1, 1}
    };
    Matrix B = {
            {0, 1, -1, 3},
            {4, 0, -2, 5},
            {3, -4, 3, -1}
    };

    // Act
    A += B;

    // Assert
    Matrix expected = {
            {2, 1, -2, 4},
            {3, 4, 1, 6},
            {7, -2, 4, 0}
    };
    EXPECT_EQ(expected, A);
}

TEST(MatrixTest, Can_Sub_Combined_With_Assignment) {
    // Arrange
    Matrix A = {
            {2, 0, -1, 1},
            {-1, 4, 3, 1},
            {4, 2, 1, 1}
    };
    Matrix B = {
            {0, 1, -1, 3},
            {4, 0, -2, 5},
            {3, -4, 3, -1}
    };

    // Act
    A -= B;

    // Assert
    Matrix expected = {
            {2, -1, 0, -2},
            {-5, 4, 5, -4},
            {1, 6, -2, 2}
    };
    EXPECT_EQ(expected, A);
}

TEST(MatrixTest, Can_Mul_Combined_With_Assignment) {
    // Arrange
    Matrix A = {
            {2, 0, -1},
            {-1, 4, 3},
            {4, 2, 1}
    };
    Matrix B = {
            {0, 1, -1},
            {4, 0, -2},
            {3, -4, 3}
    };

    // Act
    A *= B;

    // Assert
    Matrix expected = {
            {-3, 6, -5},
            {25, -13, 2},
            {11, 0, -5}
    };
    EXPECT_EQ(expected, A);
}

TEST(MatrixTest, Do_Throw_When_Add_Incommensurate_Matrices) {
    // Arrange
    Matrix A = {
            {2, 0, -1},
            {-1, 4, 3},
            {4, 2, 1}
    };
    Matrix B = {
            {0, 1, -1, 3},
            {4, 0, -2, 5},
            {3, -4, 3, -1},
            {1, 4, -2, 4}
    };

    // Act & Assert
    EXPECT_THROW(A + B, std::string);
}

TEST(MatrixTest, Do_Throw_When_Sub_Incommensurate_Matrices) {
    // Arrange
    Matrix A = {
            {2, 0, -1},
            {-1, 4, 3},
            {4, 2, 1}
    };
    Matrix B = {
            {0, 1, -1, 3},
            {4, 0, -2, 5},
            {3, -4, 3, -1},
            {1, 4, -2, 4}
    };

    // Act & Assert
    EXPECT_THROW(A - B, std::string);
}

TEST(MatrixTest, Do_Throw_When_Mul_Incommensurate_Matrices) {
    // Arrange
    Matrix A = {
            {2, 0, -1},
            {-1, 4, 3},
            {4, 2, 1}
    };
    Matrix B = {
            {0, 1, -1, 3},
            {4, 0, -2, 5},
            {3, -4, 3, -1},
            {1, 4, -2, 4}
    };

    // Act & Assert
    EXPECT_THROW(A * B, std::string);
}

TEST(MatrixTest, Do_Throw_When_Add_With_Assignment_Incommensurate_Matrices) {
    // Arrange
    Matrix A = {
            {2, 0, -1},
            {-1, 4, 3},
            {4, 2, 1}
    };
    Matrix B = {
            {0, 1, -1, 3},
            {4, 0, -2, 5},
            {3, -4, 3, -1},
            {1, 4, -2, 4}
    };

    // Act & Assert
    EXPECT_THROW(A += B, std::string);
}

TEST(MatrixTest, Do_Throw_When_Sub_With_Assignment_Incommensurate_Matrices) {
    // Arrange
    Matrix A = {
            {2, 0, -1},
            {-1, 4, 3},
            {4, 2, 1}
    };
    Matrix B = {
            {0, 1, -1, 3},
            {4, 0, -2, 5},
            {3, -4, 3, -1},
            {1, 4, -2, 4}
    };

    // Act & Assert
    EXPECT_THROW(A -= B, std::string);
}

TEST(MatrixTest, Do_Throw_When_Mul_With_Assignment_Incommensurate_Matrices) {
    // Arrange
    Matrix A = {
            {2, 0, -1},
            {-1, 4, 3},
            {4, 2, 1}
    };
    Matrix B = {
            {0, 1, -1, 3},
            {4, 0, -2, 5},
            {3, -4, 3, -1},
            {1, 4, -2, 4}
    };

    // Act & Assert
    EXPECT_THROW(A *= B, std::string);
}

TEST(MatrixTest, Can_Transpose_Matrix) {
    // Arrange
    Matrix A = {
            {2, 0, -1},
            {-1, 4, 3},
            {4, 2, 1},
            {1, 1, 1}
    };

    // Act
    Matrix B = A.Transpose();

    // Assert
    Matrix expected = {
            {2, -1, 4, 1},
            {0, 4, 2, 1},
            {-1, 3, 1, 1},
    };
    EXPECT_EQ(expected, B);
}

TEST(MatrixTest, Can_Calculate_Determinant) {
    // Arrange
    Matrix A = {
            {-3, 6, -5, 7},
            {25, -13, 2, 14},
            {11, 2, -5, 21},
            {7, -3, 3, 7}
    };

    // Act & Assert
    EXPECT_FLOAT_EQ(-574, A.Det());
}

TEST(MatrixTest, Do_Throw_When_Calculate_Determinant_Non_Square_Matrix) {
    // Arrange
    Matrix A = {
            {-3, 6, -5},
            {25, -13, 2},
            {11, 0, -5},
            {7, -3, 3}
    };

    // Act & Assert
    EXPECT_THROW(A.Det(), std::string);
}

TEST(MatrixTest, Can_Get_Minor) {
    // Arrange
    Matrix A = {
            {-3, 6, -5, 7},
            {25, -13, 2, 14},
            {11, 2, -5, 21},
            {7, -3, 3, 7}
    };

    // Act
    double det_minor = A.Minor(2, 1);

    // Assert
    EXPECT_FLOAT_EQ(896, det_minor);
}

TEST(MatrixTest, Do_Throw_When_Get_Minor_Out_Of_Range) {
    // Arrange
    Matrix A = {
            {-3, 6, -5, 7},
            {25, -13, 2, 14},
            {11, 2, -5, 21},
            {7, -3, 3, 7}
    };

    // Act & Assert
    EXPECT_THROW(A.Minor(5, 2), std::string);
}

TEST(MatrixTest, Do_Throw_When_Get_Minor_Non_Square_Matrix) {
    // Arrange
    Matrix A = {
            {-3, 6, -5, 7},
            {25, -13, 2, 14},
            {11, 2, -5, 21},
    };

    // Act & Assert
    EXPECT_THROW(A.Minor(1, 1), std::string);
}

TEST(MatrixTest, Can_Inverse_Matrix) {
    // Arrange
    Matrix A = {
            {3, 4, -2},
            {-2, 1, 0},
            {2, 3, 0},
    };

    // Act
    Matrix B = A.Inverse();

    // Assert
    Matrix expected = {
            {0.0,           -3.0 / 8.0,      1.0 / 8.0},
            {0.0,            1.0 / 4.0,      1.0 / 4.0},
            {-1.0 / 2.0,    -1.0 / 16.0,    11.0 / 16.0},
    };
    EXPECT_EQ(expected, B);
}

TEST(MatrixTest, Do_Throw_When_Inverse_Non_Square_Matrix) {
    // Arrange
    Matrix A = {
            {3, 5, 7},
            {2, 3, 4},
    };

    // Act & Assert
    EXPECT_THROW(A.Inverse(), std::string);
}

TEST(MatrixTest, Do_Throw_When_Inverse_Matrix_With_Null_Determinant) {
    // Arrange
    Matrix A = {
            {0, 5, 7},
            {0, 3, 4},
            {0, -2, -3},
    };

    // Act & Assert
    EXPECT_THROW(A.Inverse(), std::string);
}
