#include "Matrix.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Matrix a(3, 4);
    a.fillRandom();
    std::cout << "Matrix a:\n";
    a.print();

    Matrix b = a;

    b.set(0, 0, 999);

    std::cout << "\nAfter b.set(0, 0, 999):\n";
    std::cout << "Matrix a:\n";
    a.print();
    std::cout << "Matrix b:\n";
    b.print();

    return 0;
}