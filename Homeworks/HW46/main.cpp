#include <iostream>

#include "Matrix.hpp"

int main()
{
    Matrix mat1(2, 3);
    mat1(0, 0) = 1.0;
    mat1(0, 1) = 2.0;
    mat1(0, 2) = 3.0;
    mat1(1, 0) = 4.0;
    mat1(1, 1) = 5.0;
    mat1(1, 2) = 6.0;

    std::cout << "Matrix mat1:\n";
    std::cout << mat1;

    Matrix mat2 = mat1; // Copy constructor
    std::cout << "\nMatrix mat2 (after copy from mat1):\n";
    std::cout << mat2;

    Matrix mat3(2, 2);
    mat3 = mat1; // Copy assignment
    std::cout << "\nMatrix mat3 (after copy assignment from mat1):\n";
    std::cout << mat3;

    Matrix mat4 = std::move(mat1); // Move constructor
    std::cout << "\nMatrix mat4 (after move from mat1):\n";
    std::cout << mat4 << "\n" << "Mat1:" << mat1;

    Matrix mat5(2, 2);
    mat5 = std::move(mat2); // Move assignment
    std::cout << "\nMatrix mat5 (after move assignment from mat2):\n";
    std::cout << mat5;

    return 0;
}
