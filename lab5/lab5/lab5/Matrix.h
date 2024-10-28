#pragma once
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Matrix {
private:
    int rows, cols;
    T* data;

public:
    Matrix(int rows, int cols);            
    Matrix(const Matrix& other);             
    ~Matrix();                              

    T& at(int row, int col);                
    const T& at(int row, int col) const;     

    Matrix<T>& operator=(const Matrix& other); 

    template <typename U>
    friend std::istream& operator>>(std::istream& is, Matrix<U>& matrix);

    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& matrix);
};


template <typename T>
Matrix<T>::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    if (rows <= 0 || cols <= 0) {
        throw std::invalid_argument("Size of matrix should be positive!");
    }
    data = new T[rows * cols](); 
}

template <typename T>
Matrix<T>::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new T[rows * cols];
    for (int i = 0; i < rows * cols; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    delete[] data;
}

template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other) {
    if (this != &other) {
        delete[] data;
        rows = other.rows;
        cols = other.cols;
        data = new T[rows * cols];
        for (int i = 0; i < rows * cols; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

template <typename T>
T& Matrix<T>::at(int row, int col) {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Out of range");
    }
    return data[row * cols + col];
}

template <typename T>
const T& Matrix<T>::at(int row, int col) const {
    if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Out of range");
    }
    return data[row * cols + col];
}

template <typename T>
std::istream& operator>>(std::istream& is, Matrix<T>& matrix) {
    for (int i = 0; i < matrix.rows * matrix.cols; i++) {
        is >> matrix.data[i];
    }
    return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix) {
    for (int i = 0; i < matrix.rows; i++) {
        for (int j = 0; j < matrix.cols; j++) {
            os << matrix.at(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

#endif // MATRIX_H