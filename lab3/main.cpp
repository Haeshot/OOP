#include "Matrix.h"
#include <iostream>

int main() {
    Matrix m1;
    Matrix m2(3); 
    Matrix m3(3, 4); 
    Matrix m4(2, 3);

    std::cout << "m1: " << m1.getRows() << "x" << m1.getCols() << '\n';
    std::cout << "m2: " << m2.getRows() << "x" << m2.getCols() << '\n';
    std::cout << "m3: " << m3.getRows() << "x" << m3.getCols() << '\n';
    std::cout << "m4: " << m4.getRows() << "x" << m4.getCols() << '\n';

    return 0;
}