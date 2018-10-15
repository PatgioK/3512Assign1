//
// Created by patgi on 2018-10-14.
//

#include "pagerank.hpp"
#include <fstream>
#include <iostream>
using namespace std;

//opens and reads a connectivity matrix into an array
void pagerank::open_file() {
    std::ifstream file;
    file.open("connectivity.txt");
    while (!file.eof()) {
        file >> array[count];
        count++;
    }
}

//assigns values to rank matrix
void pagerank::createranks(matrix& mat1) {
    for(int i = 0; i < mat1.get_row(); i++) {
        mat1.set_value(i, 0 , 1);
    }
}

//divides 1's in rank matrix by sum of each column
void pagerank::importance(matrix &mat1) {
    for (int i = 0; i < mat1.get_col(); ++i) {
        sum = 0;
        for (int j = 0; j < mat1.get_row(); ++j) {
            if (mat1.get_value(j, i) == 1)
                sum++;
        }
        if (sum > 0) {
            for (int k = 0; k < mat1.get_row(); ++k) {
                mat1.set_value(k, i, mat1.get_value(k, i) / sum);
            }
        }
    }
}

//sets values of rank matrix to 1/n where n is number of elements in the col.
void pagerank::set_n(matrix &mat) {
    for (int i = 0; i < mat.get_col(); ++i) {
        for (int j = 0; j < mat.get_row(); ++j) {
            mat.set_value(i, j, ((double)1 / mat.get_col()));
        }
    }
}

//checks if columns are empty, if empty sets to 1/n where n is num of elements in the col.
void pagerank::check(matrix &mat) {
    for (int i = 0; i < mat.get_col(); i++) {
        bool check = true;
        for (int j = 0; j < mat.get_row(); j++) {
            if (mat.get_value(j, i) != 0)
                check = false;
        }
        if (check) {
            for (int k = 0; k < mat.get_row(); k++) {
                mat.set_value(k, i, (double)1 / mat.get_row());
            }
        }
    }
}


//sums ranks in rank matrix and values by the sum.
void pagerank::divide_sum(matrix & m)
{
    double sum = 0;
    for (int i = 0; i < m.get_row(); ++i) {
        sum += m.get_value(i, 0);
    }
    std::cout << sum;
    for (int i = 0; i < m.get_row(); ++i) {
        m.set_value(i, 0, m.get_value(i, 0) / sum);
    }
}

void pagerank::rankmatrix() {
    open_file();
    matrix g(array, count);
    matrix s(g);
    cout << "G matrix: \n" << g << endl;
    importance(s);
    check(s);
    cout << "G matrix: \n" << g << endl;
    cout << "S matrix: \n" << s << endl;
    matrix q(g.get_col());
    set_n(q);
    cout << q << endl;
    matrix m = s + q;
    cout << "M matrix: \n " << m << endl;
    matrix rank(m.get_col(), 1);
    createranks(rank);
    cout << "Rank matrix: \n" << rank << endl;
    //rank = compare(m, rank);
    cout << "Rank matrix: \n" << rank << endl;
    divide_sum(rank);
    cout << rank << endl;
}