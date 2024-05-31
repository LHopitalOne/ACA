#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <map>
#include <vector>
#include <cstdlib>
#include <utility>
#include <iostream>

#include "file.hpp"

template<typename T>
using vector_matrix = std::vector<std::vector<T>>;

class Matrix
{
protected:
    std::size_t mRows;
    std::size_t mColumns;

    int** mData;

    virtual std::ostream& print(std::ostream& os) const
    {
        for (size_t i = 0; i < mRows; i++)
        {
            for (size_t j = 0; j < mColumns; j++)
                os << mData[i][j] << " ";
            os << "\n";
        }

        return os;
    }

public:
    Matrix() : mRows(0), mColumns(0), mData(nullptr) {}
    virtual ~Matrix()
    {
        for (size_t i = 0; i < mRows; i++)
        {
            delete[] mData[i];
            mData[i] = nullptr;
        }
        delete[] mData;
        mData = nullptr;

        mRows = 0;
        mColumns = 0;
    }

    Matrix(const Matrix& other)
        : mRows(other.mRows),
          mColumns(other.mColumns),
          mData(new int*[other.mRows])
    {
        for (size_t i = 0; i < mRows; i++)
        {
            mData[i] = new int[mColumns];
            
            for (size_t j = 0; j < mColumns; j++)
                mData[i][j] = other.mData[i][j];
        }
    }

    Matrix(Matrix&& other)
        : mRows(std::exchange(other.mRows, 0)),
          mColumns(std::exchange(other.mColumns, 0))
    {
        mData = new int*[mRows];

        for (size_t i = 0; i < mRows; i++)
        {
            mData[i] = new int[mColumns];
            
            for (size_t j = 0; j < mColumns; j++)
                mData[i][j] = other.mData[i][j];
        }

        other.~Matrix();
    }

    Matrix(const vector_matrix<int>& mat)
        : mRows(mat.size()),
          mColumns(mat[0].size()),
          mData(new int*[mat.size()])
    {
        for (size_t i = 0; i < mRows; i++)
        {
            mData[i] = new int[mColumns];
            
            for (size_t j = 0; j < mColumns; j++)
                mData[i][j] = mat[i][j];
        }
    }

    Matrix(std::size_t rows, std::size_t columns, int* value = new int(0))
        : mRows(rows),
          mColumns(columns),
          mData(new int*[rows])
    {
        for (size_t i = 0; i < mRows; i++)
        {
            mData[i] = new int[mColumns];
            
            for (size_t j = 0; j < mColumns; j++)
                mData[i][j] = *value;
        }
    }

    std::pair<int, int> dim() const
    {
        return std::make_pair(mRows, mColumns);
    }

    Matrix& operator=(Matrix&& other)
    {
        mRows = std::exchange(other.mRows, 0);
        mColumns = std::exchange(other.mColumns, 0);
        
        mData = new int*[mRows];

        for (size_t i = 0; i < mRows; i++)
        {
            mData[i] = new int[mColumns];
            
            for (size_t j = 0; j < mColumns; j++)
                mData[i][j] = other.mData[i][j];
        }

        other.~Matrix();

        return *this;
    }

    int*& operator[](std::size_t i) const
    {
        return mData[i];
    }

    Matrix dot(Matrix other) const
    {
        Matrix _res(mRows, other.mColumns, new int(0));

        for (size_t i = 0; i < mRows; i++)
            for (size_t j = 0; j < other.mColumns; j++)
                for (size_t k = 0; k < mColumns; k++)
                    _res.mData[i][j] += mData[i][k] * other.mData[k][j];         

        return _res;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat)
    {
        mat.print(os);

        return os;
    }
};

#endif // MATRIX_HPP