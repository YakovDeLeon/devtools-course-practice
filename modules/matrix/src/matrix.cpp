// Copyright 2019 Trykin Alexander

#include "include/matrix.h"

#include <algorithm>
#include <cmath>
#include <functional>
#include <iterator>
#include <string>
#include <vector>
#include <utility>

Matrix::Matrix(int rows, int cols) :
        rows_(rows),
        cols_(cols),
        matrix_(std::vector<double>(rows_ * cols_)) {
}

Matrix::Matrix(
        const std::initializer_list<std::initializer_list<double>> &list) :
        rows_(list.size()),
        cols_(list.begin()->size()),
        matrix_(std::vector<double>(rows_ * cols_)) {
    int count = 0;
    for (const auto &row : list) {
        std::move(row.begin(), row.end(), matrix_.begin() + cols_ * count);
        ++count;
    }
}

int Matrix::getRows() const {
    return rows_;
}

int Matrix::getCols() const {
    return cols_;
}

double& Matrix::operator()(int i, int j) {
    return matrix_[i * cols_ + j];
}

const double& Matrix::operator()(int i, int j) const {
    return matrix_[i * cols_ + j];
}

Matrix operator+(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.rows_ != rhs.rows_ || lhs.cols_ != rhs.cols_) {
        throw std::string("NotEqualLengthsOfMatrixException");
    } else {
        Matrix res(lhs.rows_, lhs.cols_);

        for (int i = 0; i < res.rows_; ++i) {
            for (int j = 0; j < res.cols_; ++j) {
                res(i, j) = lhs(i, j) + rhs(i, j);
            }
        }

        return res;
    }
}

Matrix operator-(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.rows_ != rhs.rows_ || lhs.cols_ != rhs.cols_) {
        throw std::string("NotEqualLengthsOfMatrixException");
    } else {
        Matrix res(lhs.rows_, lhs.cols_);

        for (int i = 0; i < res.rows_; ++i) {
            for (int j = 0; j < res.cols_; ++j) {
                res(i, j) = lhs(i, j) - rhs(i, j);
            }
        }

        return res;
    }
}

Matrix operator*(const Matrix &lhs, const Matrix &rhs) {
    if (lhs.cols_ != rhs.rows_) {
        throw std::string("NotEqualLengthsOfMatrixException");
    } else {
        Matrix res(lhs.rows_, rhs.cols_);

        for (int i = 0; i < res.rows_; ++i) {
            for (int j = 0; j < res.cols_; ++j) {
                for (int k = 0; k < lhs.cols_; ++k) {
                    res(i, j) += lhs(i, k) * rhs(k, j);
                }
            }
        }

        return res;
    }
}

Matrix &Matrix::operator+=(const Matrix &src) {
    if (rows_ != src.rows_ || cols_ != src.cols_) {
        throw std::string("NotEqualLengthsOfMatrixException");
    } else {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                this->operator()(i, j) += src(i, j);
            }
        }

        return *this;
    }
}

Matrix &Matrix::operator-=(const Matrix &src) {
    if (rows_ != src.rows_ || cols_ != src.cols_) {
        throw std::string("NotEqualLengthsOfMatrixException");
    } else {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                this->operator()(i, j) -= src(i, j);
            }
        }

        return *this;
    }
}

Matrix &Matrix::operator*=(const Matrix &src) {
    return *this = *this * src;
}

bool Matrix::operator==(const Matrix &src) const {
    if (rows_ != src.rows_ || cols_ != src.cols_) {
        throw std::string("NotEqualLengthsOfMatrixException");
    } else {
        for (int i = 0; i < rows_; ++i) {
            for (int j = 0; j < cols_; ++j) {
                if (this->operator()(i, j) != src(i, j)) {
                    return false;
                }
            }
        }

        return true;
    }
}

Matrix Matrix::Transpose() const {
    Matrix res(cols_, rows_);

    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            res(j, i) = this->operator()(i, j);
        }
    }

    return res;
}

Matrix Matrix::Inverse() const {
    if (rows_ != cols_) {
        throw std::string("NotSquareMatrixException");
    } else {
        double det = this->Det();
        if (det == 0) {
            throw std::string("NullDeterminantException");
        }

        auto cofactor = [](int inv_count) -> int {
            return (inv_count % 2 == 0) ? 1 : -1;
        };

        int size = rows_;
        Matrix algebraic_supplement(size, size);
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                algebraic_supplement(i, j) =
                        cofactor(i + j) * this->Minor(i, j) / det;
            }
        }

        return algebraic_supplement.Transpose();
    }
}

double Matrix::Minor(int row, int col) const {
    if (row < 0 || row >= rows_ || col < 0 || col >= cols_) {
        throw std::string("OutOfRangeException");
    } else if (rows_ != cols_) {
        throw std::string("NotSquareMatrixException");
    } else {
        int size = rows_;
        Matrix res(size - 1, size - 1);

        int offset_rows = 0, offset_cols = 0;
        for (int i = 0; i < size - 1; ++i) {
            if (i == row) {
                offset_rows = 1;
            }

            for (int j = 0; j < size - 1; ++j) {
                if (j == col) {
                    offset_cols = 1;
                }

                res(i, j) = this->operator()(i + offset_rows, j + offset_cols);
            }

            offset_cols = 0;
        }

        return res.Det();
    }
}

double Matrix::Det() const {
    if (rows_ != cols_) {
        throw std::string("NotSquareMatrixException");
    } else {
        int size = rows_;
        std::vector<int> numbers_of_index(size);
        for (int i = 0; i < size; ++i) {
            numbers_of_index[i] = i;
        }

        auto inv_count = [](std::vector<int> &numbers_of_index) -> int {
            int count = 0;
            for (unsigned int i = 0; i < numbers_of_index.size() - 1; i++) {
                for (unsigned int j = i + 1; j < numbers_of_index.size(); j++) {
                    if (numbers_of_index[i] > numbers_of_index[j]) {
                        count++;
                    }
                }
            }

            return count;
        };

        auto cofactor = [](int inv_count) -> int {
            return (inv_count % 2 == 0) ? 1 : -1;
        };

        double det = 0.0;
        do {
            double local_sum = 1.0;
            for (int i = 0; i < size; i++) {
                local_sum *= this->operator()(numbers_of_index[i], i);
            }

            local_sum *= cofactor(inv_count(numbers_of_index));
            det += local_sum;
        } while (std::next_permutation(numbers_of_index.begin(),
                                       numbers_of_index.end()));

        return det;
    }
}
