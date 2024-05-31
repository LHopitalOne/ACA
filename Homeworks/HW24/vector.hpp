#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstdlib>

template<typename _ValueT>
class vector
{
private:
    std::size_t mSize;
    std::size_t mCapacity;
    
    _ValueT* mData;

public:
    vector();
    vector(vector&& other);
    vector(const vector& other);
    vector(std::size_t capacity);
    vector(std::size_t capacity, _ValueT value);

    vector<_ValueT>& operator=(vector<_ValueT>&& other);
    vector<_ValueT>& operator=(const vector<_ValueT>& other);

    std::size_t size() const;
    std::size_t capacity() const;

    bool isEmpty() const;
    
    _ValueT* end() const;
    _ValueT* begin() const;

    void pop_back();
    void push_back(_ValueT value);

    _ValueT& operator[](std::size_t index) const;

    ~vector();
};

#include <utility>
#include <stdexcept>

template<typename _ValueT>
vector<_ValueT>::vector()
    : mSize(0),
      mCapacity(10),
      mData(new _ValueT[mCapacity]) {}

template<typename _ValueT>
vector<_ValueT>::vector(const vector<_ValueT>& other)
    : mSize(other.mSize),
      mCapacity(other.mCapacity),
      mData(new _ValueT[mCapacity])
{
    for (size_t i = 0; i < mSize; i++)
        mData[i] = other.mData[i];
}

template<typename _ValueT>
vector<_ValueT>::vector(vector<_ValueT>&& other)
    : mSize(std::exchange(other.mSize, 0)),
      mCapacity(std::exchange(other.mCapacity, 0)),
      mData(new _ValueT[mCapacity])
{
    for (size_t i = 0; i < mSize; i++)
        mData[i] = other.mData[i];
    delete[] other.mData;
    other.mData = nullptr;
}

template<typename _ValueT>
vector<_ValueT>::vector(std::size_t capacity)
    : mSize(0),
      mCapacity(capacity),
      mData(new _ValueT[mCapacity]) {}

template<typename _ValueT>
vector<_ValueT>::vector(std::size_t capacity, _ValueT _val)
    : mSize(capacity),
      mCapacity(capacity),
      mData(new _ValueT[mCapacity])
{
    for (size_t i = 0; i < mSize; i++)
        mData[i] = _val;
}

template<typename _ValueT>
vector<_ValueT>& vector<_ValueT>::operator=(vector<_ValueT>&& other)
{
    mSize     = std::exchange(other.mSize, 0);
    mCapacity = std::exchange(other.mCapacity, 0);

    mData     = new _ValueT[mCapacity];

    for (size_t i = 0; i < mSize; i++)
        mData[i] = other.mData[i];
    delete[] other.mData;
    other.mData = nullptr;
    
    return *this;
}

template<typename _ValueT>
vector<_ValueT>& vector<_ValueT>::operator=(const vector<_ValueT>& other)
{
    mSize     = other.mSize;
    mCapacity = other.mCapacity;

    mData     = new _ValueT[mCapacity];

    for (size_t i = 0; i < mSize; i++)
        mData[i] = other.mData[i];

    return *this;
}

template<typename _ValueT>
std::size_t vector<_ValueT>::size() const
{
    return mSize;
}

template<typename _ValueT>
std::size_t vector<_ValueT>::capacity() const
{
    return mCapacity;
}

template<typename _ValueT>
bool vector<_ValueT>::isEmpty() const
{
    return mSize == 0;
}

template<typename _ValueT>
_ValueT* vector<_ValueT>::end() const
{
    return mData + mSize;
}

template<typename _ValueT>
_ValueT* vector<_ValueT>::begin() const
{
    return mData;
}

template<typename _ValueT>
void vector<_ValueT>::pop_back()
{
    if (mSize)
        mSize--;
    else
        throw std::out_of_range{"Error: calling pop_back() on empty vector."};
}

template<typename _ValueT>
void vector<_ValueT>::push_back(_ValueT value)
{
    if (mSize == mCapacity)
    {
        _ValueT* temp = new _ValueT[mCapacity];
        for (size_t i = 0; i < mSize; i++)
            temp[i] = mData[i];

        mCapacity *= 2;
        
        mData = new _ValueT[mCapacity];
        for (size_t i = 0; i < mSize; i++)
            mData[i] = temp[i];
    }
    mData[mSize++] = value;
}

template<typename _ValueT>
_ValueT& vector<_ValueT>::operator[](std::size_t index) const
{
    if (index < mSize)
        return mData[index];
    throw std::out_of_range{"Error: trying to access element out of the array."};
}

template<typename _ValueT>
vector<_ValueT>::~vector()
{
    delete[] mData;
}

#endif // VECTOR_HPP
