#include <iostream>
#include <random>
#include <ctime>

void print(int** mat, const int& rows, const int& cols) {
    for (uint i = 0; i < rows; i++) {
        for (uint j = 0; j < cols; j++)
            std::cout << mat[i][j] << " ";
        std::cout << "\n";
    }
    std::cout << std::endl;
}

int summarizeMainDiag(int** mat, const int& rows, const int& cols) {
    int sum = 0;

    for (uint i = 0; i < rows; i++)
        for (uint j = 0; j < cols; j++)
            if (j < i)
                sum += mat[i][j];
    
    return sum;
}

int** transpose(int** mat, uint& rows, uint& cols) {
    int temp = rows;
    rows = cols;
    cols = temp;

    int** _matrix = new int*[rows];
    for (uint i = 0; i < rows; i++)
        _matrix[i] = new int[cols];

    for (uint i = 0; i < rows; i++)
        for (uint j = 0; j < cols; j++)
            _matrix[i][j] = mat[j][i];

    return _matrix;
}

int main(int argc, char const *argv[]) {
    srand((uint)time(0));

    uint rows = 5;
    uint columns = 7;

    int** matrix = new int*[rows];
    for (uint i = 0; i < rows; i++)
        matrix[i] = new int[columns];

    for (uint i = 0; i < rows; i++)
        for (uint j = 0; j < columns; j++)
            matrix[i][j] = rand() % 100;

    print(matrix, rows, columns);
    std::cout << summarizeMainDiag(matrix, rows, columns) << std::endl;
    
    matrix = transpose(matrix, rows, columns);
    print(matrix, rows, columns);

    for (uint i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;
    
    return 0;
}

