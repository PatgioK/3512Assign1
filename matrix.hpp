//
// Created by patgi on 2018-10-14.
//

#ifndef INC_3512ASSIGN1_MATRIX_HPP
#include <iostream>
#define INC_3512ASSIGN1_MATRIX_HPP

class matrix {
private:
    static int size;
    int row;
    int col;
    double * matrix_arr;

public:
    matrix();
    matrix(int n);
    matrix(int r, int c);
    matrix(double array[], int n);
    matrix(const matrix &m);
    matrix& operator=(matrix&& mat2);
    void set_value(int r, int c, double value);
    double get_value(int r, int c) const;
    void clear();
    int get_row() const;
    int get_col() const;
    int get_size() const;
    virtual ~matrix() {
        if (matrix_arr) {
        }
    };
    friend std::ostream& operator<<(std::ostream& out, matrix& matrix);
    static constexpr double TOLERANCE = 0.0001;

    friend bool operator==(const matrix& mat1, const matrix& mat2);
    friend bool operator!=(const matrix& mat1, const matrix& mat2);

    matrix& operator++();
    matrix operator++(int);
    matrix& operator--();
    matrix operator--(int);


    matrix& operator+=(const matrix& mat2);
    friend matrix operator+(matrix lhs, const matrix& rhs);
    matrix& operator-=(const matrix& mat2);
    friend matrix operator-(matrix lhs, const matrix& rhs);


    friend matrix operator*(const matrix& lhs, const matrix& rhs);
    matrix& operator*=(const double& num);

};

#endif //INC_3512ASSIGN1_MATRIX_HPP
