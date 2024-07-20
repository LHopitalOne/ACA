#include <iostream>
#include <thread>

#include "Matrix.hpp"

void matrix_sum(unsigned int& sum, Matrix& mat, std::size_t start_row, std::size_t start_col, std::size_t end_row, std::size_t end_col)
{
    for (std::size_t i = start_row; i < end_row; i++)
        for (std::size_t j = start_col; j < end_col; j++)
            sum += mat(i, j);
}

int main(int argc, char const *argv[])
{
    Matrix mat(50, 50);
    
    int k = 1;
    for (std::size_t i = 0; i < mat.rows(); i++)
        for (std::size_t j = 0; j < mat.cols(); j++)
            mat(i, j) = k++;
    
    unsigned int sum = 0;

    std::thread t1(matrix_sum, std::ref(sum), std::ref(mat), 0, 0, mat.rows() / 2, mat.cols() / 2);
    std::thread t2(matrix_sum, std::ref(sum), std::ref(mat), 0, mat.cols() / 2, mat.rows() / 2, mat.cols());
    std::thread t3(matrix_sum, std::ref(sum), std::ref(mat), mat.rows() / 2, 0, mat.rows(), mat.cols() / 2);
    std::thread t4(matrix_sum, std::ref(sum), std::ref(mat), mat.rows() / 2, mat.cols() / 2, mat.rows(), mat.cols());

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << sum;

    return 0;
}

