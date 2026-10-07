#include "Matrix.h"

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr)));

    Matrix m1;
    Matrix m2(3);
    Matrix m3(3, 4);
    Matrix m4(2, 3);

    std::cout << "m2 (единичная 3x3):\n";
    m2.print();

    std::cout << "\nm3 (3x4, нули):\n";
    m3.print();

    std::cout << "\nm4 (2x3, нули):\n";
    m4.print();

    for (int i = 0; i < m2.getRows(); ++i) {
        for (int j = 0; j < m2.getCols(); ++j) {
            m2.set(i, j, i * j);
        }
    }

    std::cout << "\nm2 после заполнения i * j:\n";
    m2.print();

    m3.fillRandom();
    std::cout << "\nm3 после fillRandom():\n";
    m3.print();

    std::cout << "\nВведите " << m4.getRows() * m4.getCols()
              << " чисел для m4 (2x3):\n";
    m4.inputFromKeyboard();

    std::cout << "\nm4 после ввода:\n";
    m4.print();

    std::cout << "\nСумма элементов m3: " << m3.sum() << '\n';

    return 0;
}