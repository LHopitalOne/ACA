#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <memory>

class Matrix
{
public:
    Matrix(std::size_t rows, std::size_t cols)
        : rows_(rows), cols_(cols), data_(std::make_unique<double[]>(rows * cols)) {}

    Matrix(const Matrix& other)
        : rows_(other.rows_), cols_(other.cols_), data_(std::make_unique<double[]>(other.rows_ * other.cols_))
    {
        std::copy(other.data_.get(), other.data_.get() + rows_ * cols_, data_.get());
    }

    Matrix& operator=(const Matrix& other)
    {
        rows_ = other.rows_;
        cols_ = other.cols_;
        data_ = std::make_unique<double[]>(rows_ * cols_);
        std::copy(other.data_.get(), other.data_.get() + rows_ * cols_, data_.get());
        return *this;
    }

    Matrix(Matrix&& other)
        : rows_(other.rows_), cols_(other.cols_), data_(std::move(other.data_))
    {
        other.rows_ = 0;
        other.cols_ = 0;
    }

    Matrix& operator=(Matrix&& other)
    {
        if (this == &other) return *this;

        rows_ = other.rows_;
        cols_ = other.cols_;
        data_ = std::move(other.data_);
        
        other.rows_ = 0;
        other.cols_ = 0;

        return *this;
    }

    std::size_t rows() const
    {
        return rows_;
    }

    std::size_t cols() const
    {
        return cols_;
    }

    double& operator()(std::size_t row, std::size_t col)
    {
        return data_[row * cols_ + col];
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat)
    {
        for (std::size_t i = 0; i < mat.rows_; i++)
        {
            for (std::size_t j = 0; j < mat.cols_; j++)
                os << mat.data_[i * mat.cols_ + j] << ' ';
            os << '\n';
        }

        return os;
    }

private:
    std::size_t rows_, cols_;
    std::unique_ptr<double[]> data_;
};

#endif // MATRIX_HPP
