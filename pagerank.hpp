//
// Created by patgi on 2018-10-14.
//

#ifndef INC_3512ASSIGN1_PAGERANK_HPP
#include "matrix.hpp"
#include <iostream>
#include <fstream>
#define INC_3512ASSIGN1_PAGERANK_HPP


class pagerank : public matrix {
private:
    double array[16];
    int count = 0;
    int sum;
public:
    const double P{0.85};
    void open_file();
    void createranks(matrix& mat);
    void importance(matrix& mat);
    void set_n(matrix& mat);
    void check(matrix& mat);
    void divide_sum(matrix& mat);

    void rankmatrix();
};


#endif //INC_3512ASSIGN1_PAGERANK_HPP
