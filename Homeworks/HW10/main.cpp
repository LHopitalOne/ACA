#include <iostream>
#include <cstdlib>
#include <new>
#include <exception>

class Matrix {
private:
    uint mRows;
    uint mCols;

    int* pData;

public:
    Matrix() = default;
    Matrix(const Matrix& mat) 
        :
            mRows(mat.mRows), 
            mCols(mat.mCols),
            pData(new int[mRows * mCols]) {

        for (uint i = 0; i < mRows * mCols; i++)
            pData[i] = mat.pData[i];
        
    }

    Matrix(uint rows, uint cols)
        :
            mRows(rows),
            mCols(cols),
            pData(new int[rows * cols]){}

    void transpose() {
        for (uint i = 0; i < mRows; i++) {
            for (uint j = i + 1; j < mCols; j++)
                std::swap(pData[i * mCols + j], pData[j * mRows + i]);
        }        
        std::swap(mRows, mCols);
    }

    Matrix& operator=(const Matrix& mat) {
        if (this != &mat) {
            mRows = mat.mRows;
            mCols = mat.mCols;

            int* newData = new int[mRows * mCols];
            for (uint i = 0; i < mRows * mCols; i++)
                pData[i] = mat.pData[i];

            delete[] pData;

            pData = newData;
        }

        return *this;
    }

    Matrix operator+(const Matrix& mat) {
        if (mat.mRows != mRows || mat.mCols != mCols)
            throw std::invalid_argument("Invalid argument: the two operands have to be of the same size.");

        Matrix result = Matrix(mRows, mCols);
        
        for (uint i = 0; i < mRows; i++)
            for (uint j = 0; j < mCols; j++)
                result[i][j] = pData[i * mCols + j] + mat[i][j];

        return result;
    }

    static void* operator new(std::size_t byte, uint sz0, uint sz1) {
        Matrix* mat = static_cast<Matrix*>(::operator new(byte));
        mat->mRows = sz0;
        mat->mCols = sz1;
        mat->pData = static_cast<int*>(::operator new(sz0 * sz1 * sizeof(int)));
        return mat;
    }
    
    int* operator[](uint i) const {
        return pData + i * mCols;
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

    Matrix other = *mat;
    std::cout << (other + *mat);

    delete mat;

    return 0;
}
