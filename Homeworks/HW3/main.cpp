#include <iostream>
#include <random>
#include <ctime>

int** createMatrix(uint size) {
    int** mat = new int*[size];
    
    for (uint i = 0; i < size; i++)
        mat[i] = new int[size];
    
    return mat;
}

void initializeMatrix(int** mat, int size) {
    for (uint i = 0; i < size; i++)
        for (uint j = 0; j < size; j++)
            mat[i][j] = rand() % 100; // for easier debugging use
}

void print(int** mat, int size) {
    for (uint i = 0; i < size; i++) {
        for (uint j = 0; j < size; j++)
            std::cout << mat[i][j] << " ";
        std::cout << "\n";
    }

    for (uint i = 0; i < size; i++)
        delete[] mat[i];
    delete[] mat;
}

int main(int argc, char const *argv[]) {
    srand((uint)time(0));

    const uint size = 5;

    int** mat = createMatrix(size);
    initializeMatrix(mat, size);
    print(mat, size);
    
    return 0;
}

