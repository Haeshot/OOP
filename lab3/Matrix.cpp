#include "Matrix.h"

Matrix::Matrix()
    : data_(nullptr), rows_(0), cols_(0) {
}

Matrix::Matrix(int size)
    : data_(nullptr), rows_(size), cols_(size) {
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
    if (rows == 0 || cols == 0) {
        return;
    }

    data_ = new int*[rows_];
    for (int i = 0; i < rows_; ++i) {
        data_[i] = new int[cols_](); 
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
    return data_[i][j];
}

void Matrix::set(int i, int j, int value) {
    data_[i][j] = value;
}

int Matrix::getRows() const {
    return rows_;
}

int Matrix::getCols() const {
    return cols_;
}