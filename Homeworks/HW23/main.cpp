#include <string>
#include <vector>
#include <iostream>

#include "file.hpp"
#include "Matrix.hpp"

int main()
{
    file* f = file::init("./input1.in");
    
    Matrix mat = Matrix({{1, 2, 3}, {4, 5, 6}});
    f->putMatrix(mat);
    delete f;

    Matrix mat1;
    Matrix mat2;

    f = file::init("./input1.in");
    mat1 = f->getMatrix();
    delete f;

    f = file::init("./input2.in");
    mat2 = f->getMatrix();
    delete f;

    std::cout << mat1.dot(mat2);

    return 0;
}
