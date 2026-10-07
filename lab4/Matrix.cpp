#include "Matrix.h"

#include <iostream>
#include <cstdlib>

Matrix::Matrix()
    : data_(nullptr), rows_(0), cols_(0) {
}

Matrix::Matrix(int size)
    : data_(nullptr), rows_(size), cols_(size) {
    if (size < 0) {
        throw std::invalid_argument("Размерность не может быть отрицательной");
    }
    if (size == 0) {
        return;
    }

    data_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new int[cols_]();
        data_[i][i] = 1;
    }
}

Matrix::Matrix(int rows, int cols)
    : data_(nullptr), rows_(rows), cols_(cols) {
    if (rows < 0 || cols < 0) {
        throw std::invalid_argument("Размерность не может быть отрицательной");
    }
    if (rows == 0 || cols == 0) {
        return;
    }

    data_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new int[cols_]();
    }
}

Matrix::Matrix(const Matrix& other)
    : data_(nullptr), rows_(other.rows_), cols_(other.cols_) {
    if (rows_ == 0 || cols_ == 0) {
        rows_ = 0;
        cols_ = 0;
        return;
    }

    data_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new int[cols_];
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = other.data_[i][j];
        }
    }
}

Matrix::~Matrix() {
    if (data_ == nullptr) {
        return;
    }
    for (int i = 0; i < rows_; ++i) {
        delete[] data_[i];
    }
    delete[] data_;
}

int Matrix::get(int i, int j) const {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
        throw std::out_of_range("Индекс вне диапазона");
    }
    return data_[i][j];
}

void Matrix::set(int i, int j, int value) {
    if (i < 0 || i >= rows_ || j < 0 || j >= cols_) {
        throw std::out_of_range("Индекс вне диапазона");
    }
    data_[i][j] = value;
}

void Matrix::inputFromKeyboard() {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            std::cin >> data_[i][j];
        }
    }
}

void Matrix::fillRandom() {
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            data_[i][j] = std::rand() % 100;
        }
    }
}

void Matrix::print() const {
    if (rows_ == 0 || cols_ == 0) {
        std::cout << "(пустая матрица)\n";
        return;
    }
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            std::cout << data_[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int Matrix::sum() const {
    int total = 0;
    for (int i = 0; i < rows_; ++i) {
        for (int j = 0; j < cols_; ++j) {
            total += data_[i][j];
        }
    }
    return total;
}

int Matrix::getRows() const {
    return rows_;
}

int Matrix::getCols() const {
    return cols_;
}