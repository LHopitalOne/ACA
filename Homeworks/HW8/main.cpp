#include <iostream>
#include <cstdlib>
#include <new>

class Matrix {
private:
    uint mRows;
    uint mCols;

    int* pData;

public:
    Matrix() = default;
    Matrix(uint rows, uint cols) : mRows(rows), mCols(cols), pData(new int[rows * cols]) {}

    void transpose() {
        for (uint i = 0; i < mRows; i++) {
            for (uint j = i + 1; j < mCols; j++)
                std::swap(pData[i * mCols + j], pData[j * mRows + i]);
        }        
        std::swap(mRows, mCols);
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
        os << "-------------------\n";

        for (uint i = 0; i < mat.mRows; i++) {
            for (uint j = 0; j < mat.mCols; j++)
                os << mat.pData[i * mat.mCols + j] << " ";
            os << "\n";
        }
        os << "-------------------";

        return os;
    }

    static void* operator new(std::size_t byte, uint sz0, uint sz1) {
        Matrix* mat = static_cast<Matrix*>(::operator new(byte));
        mat->mRows = sz0;
        mat->mCols = sz1;
        mat->pData = static_cast<int*>(::operator new(sz0 * sz1 * sizeof(int)));
        return mat;
    }
    
    int* operator[](uint i) {
        return pData + i * mCols;
    }

    ~Matrix() {
        delete[] pData;
    }
};

int main() {
    uint n = 5;
    Matrix* mat = new(n, n) Matrix;

    for (uint i = 0, k = 0; i < n; ++i) {
        for (uint j = 0; j < n; ++j) {
            (*mat)[i][j] = ++k;
        }
    }
    
    std::cout << (*mat) << std::endl;
    mat->transpose();
    std::cout << (*mat);

    delete mat;

    return 0;
}
