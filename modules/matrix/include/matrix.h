// Copyright 2019 Trykin Alexander

#ifndef MODULES_MATRIX_INCLUDE_MATRIX_H_
#define MODULES_MATRIX_INCLUDE_MATRIX_H_

#include <initializer_list>
#include <vector>

class Matrix {
 private:
    int rows_;
    int cols_;
    std::vector<double> matrix_;

 public:
    Matrix() = default;
    Matrix(const Matrix &src) = default;
    Matrix& operator=(const Matrix &src) = default;
    ~Matrix() = default;

    explicit Matrix(int rows, int cols);
    Matrix(const std::initializer_list<std::initializer_list<double>> &list);

    int getRows() const;
    int getCols() const;

    double& operator()(int i, int j);
    const double& operator()(int i, int j) const;

    friend Matrix operator+(const Matrix &lhs, const Matrix &rhs);
    friend Matrix operator-(const Matrix &lhs, const Matrix &rhs);
    friend Matrix operator*(const Matrix &lhs, const Matrix &rhs);

    Matrix& operator+=(const Matrix &src);
    Matrix& operator-=(const Matrix &src);
    Matrix& operator*=(const Matrix &src);

    bool operator==(const Matrix &src) const;

    Matrix Transpose() const;
    Matrix Inverse() const;
    double Minor(int row, int col) const;
    double Det() const;
};

#endif  // MODULES_MATRIX_INCLUDE_MATRIX_H_
