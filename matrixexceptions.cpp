//
// Created by patgi on 2018-10-14.
//

#include <iostream>
#include <exception>

struct negative_exception : std::exception {
    const char * what() const throw() {
        return "must be greater than 0";
    }
};

struct zero_exception : std::exception {
    const char * what() const throw() {
        return "values cannot be 0";
    }
};

struct sqrt_exception : std::exception {
    const char * what() const throw() {
        return "must be a square root number";
    }
};

struct bound_exception : std::exception {
    const char * what() const throw() {
        return "row or column not in bound";
    }
};

struct size_exception : std::exception {
    const char * what() const throw() {
        return "size of the matrices must be the same";
    }
};