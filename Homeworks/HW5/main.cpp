#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <new>

void* operator new(std::size_t sz) {
    std::cout << "Hello World\n";

    if (void* ptr = malloc(sz))
        return ptr;
    
    throw std::bad_alloc{};
}

void* operator new[](std::size_t sz) {
    std::cout << "Hello World\n";

    if (void* ptr = malloc(sz))
        return ptr;
    
    throw std::bad_alloc();
}

int** createMatrix(uint size) {
    int** mat = (int**)malloc(size * sizeof(int*));

    for (uint i = 0; i < size; i++)
        mat[i] = (int*)malloc(size * sizeof(int));

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
}

void swapRows(int** mat, uint i, uint j) {
    int* temp = mat[i];
    mat[i] = mat[j];
    mat[j] = temp;
}

void swapCols(int** mat, int rows, int i, int j) {
    for (uint r = 0; r < rows; r++) {
        int temp = mat[r][i];
        mat[r][i] = mat[r][j];
        mat[r][j] = temp;
    }
}

void m_Deallocate(int** mat, uint size) {
    for (uint i = 0; i < size; i++) {
        delete[] mat[i];
        mat[i] = nullptr;
    }
    delete[] mat;
    mat = nullptr;
}

int main(int argc, char const *argv[]) {
    srand((uint)time(0));

    const uint size = 5;

    int** mat = createMatrix(size);
    initializeMatrix(mat, size);
    print(mat, size);

    std::cout << "\n-----------------\n\n";

    swapRows(mat, 1, 2);
    print(mat, size);

    std::cout << "\n-----------------\n\n";

    swapCols(mat, size, 1, 2);
    print(mat, size);

    m_Deallocate(mat, size);

    // int* ptr = new int(5);
    // int* ptrArr = new int[5];

    // std::cout << *ptr << std::endl;
    // for (uint i = 0; i < 5; i++)
    //     ptrArr[i] = i;

    // for (uint i = 0; i < 5; i++)
    //     std::cout << ptrArr[i] << std::endl;    

    // delete ptr;
    // delete[] ptrArr;

    return 0;
}

