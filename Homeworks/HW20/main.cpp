#include <iostream>

#include "./zoo/Dog.hpp"
#include "Matrix.hpp"

int main()
{
    Matrix mat({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    });

    Matrix mat2 = std::move(mat);
    
    std::cout << mat << std::endl;
    std::cout << mat2 << std::endl;

    Dog d1(3, 4);
    d1.printInfo();
    
    Dog d2 = std::move(d1);
    d1.printInfo();
    d2.printInfo();
    
    return 0;
}
