#include <iostream>
#include "Matrix.hpp" // Assuming Matrix class is defined in Matrix.h

int main() {
    // Create a matrix
    Matrix mat(3, 3); // Example: 3x3 matrix of integers
    
    // Populate the matrix with some values
    for (int i = 0; i < mat.dim().first; ++i) {
        for (int j = 0; j < mat.dim().second; ++j) {
            mat.at(i, j) = i * 10 + j; // Example: Assigning values
        }
    }
    
    // Test accessing elements using the at function (similar to vector::at)
    try {
        std::cout << "Value at (1, 1): " << mat.at(1, 1) << std::endl;
        std::cout << "Value at (0, 2): " << mat.at(0, 2) << std::endl;
        
        // Accessing out-of-bounds element should throw an exception
        std::cout << "Value at (3, 2): " << mat.at(3, 2) << std::endl; // This should throw
    } catch (const std::out_of_range& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    
    return 0;
}
