#include <iostream>

#include "Matrix.hpp"

int main()
{
    Matrix mat({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    });

    std::cout << mat++ << std::endl;
    std::cout << mat << std::endl;
    std::cout << ++mat << std::endl;
    
    return 0;
}
