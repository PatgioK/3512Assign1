//
// Created by patgi on 2018-10-14.
//

#include <iostream>
#include "matrix.hpp"
#include <vector>
#include <cmath>
#include <array>
#include <string>
#include "matrixexceptions.cpp"

//default constructor, creates 1x1 matrix and sets value to 0
matrix::matrix() {
    size = 1;
    matrix_arr = new double[size];
    matrix_arr[0] = 0.0;
}

//1param constructor, makes nxn matrix and sets values to 0
matrix::matrix(int n) {
    if(n < 0) {
        throw negative_exception();
    } else {
        row = n;
        col = n;
        size = row * col;
        matrix_arr = new double[size];
        clear();
    }
}

//2param constructor, makes rxc matrix and sets values to 0
matrix::matrix(int r, int c) {
    if(r < 0 || c < 0) {
        throw negative_exception();
    }
    if(r == 0 || c == 0) {
        throw zero_exception();
    } else {
        row = r;
        col = c;
        size = row * col;
        matrix_arr = new double[size];
        clear();
    }
}

//1 param constructor, accepts array, checks size to make a square matrix
matrix::matrix(double array[], int n) {

    int sqrt_num = sqrt(n);

    if ((sqrt_num * sqrt_num) != n) {
        throw sqrt_exception();
    }
    else {
        row = sqrt_num;
        col = sqrt_num;
        size = n;
        matrix_arr = new double[size];
        for (int i = 0; i < size; ++i) {
            matrix_arr[i] = array[i];
        }

    }
}
matrix::matrix(const matrix &m) {
    row = m.row;
    col = m.col;
    size = row * col;
    matrix_arr = new double[size];
    for (int i = 0; i < size; ++i) {
        matrix_arr[i] = m.matrix_arr[i];
    }
}
//setter for a value in the matrix, checks if params are in matrix
void matrix::set_value(int r, int c, double value) {
    if(r < 0 || c < 0) {
        throw negative_exception();
    }
    if(r < get_row() || c < get_col()) {
        throw bound_exception();
    }
    int i = r * row + c;
    matrix_arr[i] = value;
}

//getter for values in matrix. checks if params are in bound.
double matrix::get_value(int r, int c) const {
    if(r > get_row() || c > get_col()) {
        throw bound_exception();
    }
    int i = r * row + c;
    return matrix_arr[i];
}

//sets all values in the matrix to 0
void matrix::clear() {
    for(int i = 0; i < matrix::size; i++) {
        matrix_arr[i] = 0;
    }
}

//overloaded method to print values in the matrix.
std::ostream& operator<< (std::ostream & out,  matrix& matrix) {
    for(int r = 0; r < matrix.get_row(); r++) {
        for(int c = 0; c < matrix.get_col(); c++) {
            out << matrix.get_value(r, c);
        }
        out << "/n";
    }
    return out;
}

//method to compare if two matrices are the same.
bool operator==(const matrix& mat1, const matrix& mat2) {
    if(mat1.get_size() != mat2.get_size()) {
        return false;
    }
    for(int i = 0; i < mat1.get_size(); i++) {
        if((mat1.matrix_arr[i] - mat2.matrix_arr[i]) > mat1.TOLERANCE) {
            return false;
        }
    }
    return true;
}

//method to check if matrices are different.
bool operator!=(const matrix& lhs, const matrix& rhs) {
    return !operator==(lhs, rhs);
}

//method to prefix increment values in the matrix.
matrix & matrix::operator++() {
    for (int i = 0; i < this->size; i++) {
        this->matrix_arr[i]++;
    }
    return *this;
}

//method to postfix increment values in the matrix
matrix matrix::operator++(int) {
    matrix temp(*this);
    operator++();
    return temp;
}

//method to prefix decrement
matrix & matrix::operator--() {
    for (int i = 0; i < this->size; i++) {
        this->matrix_arr[i]--;
    }
    return *this;
}

//method to postfix decrement
matrix matrix::operator--(int) {
    matrix temp(*this);
    operator--();
    return temp;
}

//assignment method copy and swap
matrix& matrix::operator=(matrix && mat2) {
    if (this != &mat2) {
        row = mat2.row;
        col = mat2.col;
        size = mat2.size;
        for (int i = 0; i < size; ++i) {
            matrix_arr[i] = mat2.matrix_arr[i];
        }
        mat2.row = 0;
        mat2.col = 0;
        mat2.size = 0;
        mat2.matrix_arr = nullptr;
    }
    return *this;
}

//method to add a matrices
matrix & matrix::operator+=(const matrix & mat2) {
    if (size != mat2.size) {
        throw size_exception();
    }
    else {
        for (int i = 0; i < size; ++i) {
            matrix_arr[i] += mat2.matrix_arr[i];
        }
    }
    return *this;
}

//method to add matrices
matrix operator+(matrix mat1, const matrix & mat2) {
    if (mat1.size != mat2.size) {
        throw size_exception();
    }
    else {
        mat1 += mat2;
        return mat1;
    }
}

//method to subtract matrices
matrix & matrix::operator-=(const matrix & mat2) {
    if (size != mat2.size) {
        throw size_exception();
    }
    else {
        for (int i = 0; i < size; ++i) {
            matrix_arr[i] -= mat2.matrix_arr[i];
        }
    }
    return *this;
}

//method to subtract matrices
matrix operator-(matrix mat1, const matrix & mat2) {
    if (mat1.size != mat2.size) {
        throw size_exception();
    }
    else {
        mat1 -= mat2;
        return mat1;
    }
}

//method to multiply matrices
matrix operator*(const matrix& mat1, const matrix& mat2) {
    if (mat1.get_col() != mat2.get_row()) {
        throw size_exception();
    }
    matrix result(mat1.get_row(), mat2.get_col());
    double value;
    for (int i = 0; i < result.get_row(); ++i) {
        for (int j = 0; j < result.get_col(); ++j) {
            value = 0;
            for (int k = 0; k < mat1.get_row(); ++k) {
                value += mat1.get_value(i, k) * mat2.get_value(k, j);
                result.set_value(i, j, value);
            }
        }
    }
    return result;
}

//method to get number of rows in a matrix
int matrix::get_row()const {
    return row;
}

//method to get number of columns in a matrix.
int matrix::get_col()const {
    return col;
}

//method to get number of elements in a matrix.
int matrix::get_size()const {
    return size;
}