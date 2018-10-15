#include <iostream>
#include "matrix.hpp"
#include "pagerank.hpp"
#include <fstream>
using namespace std;

int main() {
    matrix m(2, 2);
    m.set_value(0, 0, 1);
    m.set_value(0, 1, 2);
    m.set_value(1, 0, 3);
    m.set_value(1, 1, 4);
    cout << m;

    matrix move1(move(m));

    cout << move1;
    cout << m;
    matrix equals;
    equals = move(move1);
    cout << equals;
    cout << move1;
    system("pause");
    return 0;
}