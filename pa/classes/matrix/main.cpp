#include "Matrix.hpp"
#include <iostream>

using namespace std;

int main() {
    Matrix a(3, 4), b(3, 4);

    a.ones();

    a(0, 0) = 42;

    cout << "Matrix A: ";
    a.print();

    b = a;

    cout << "Matrix B: ";
    b.print();

    return 0;
}