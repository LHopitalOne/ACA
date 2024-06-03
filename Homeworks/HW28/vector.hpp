#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <cstdlib>
#include <utility>
#include <stdexcept>
#include <initializer_list>

template<typename _ValueT>
class vector
{
private:
    std::size_t mSize;
    std::size_t mCapacity;
    
    _ValueT* mData;

    std::size_t back_index;
    std::size_t front_index;

public:
    vector();
    vector(vector&& other);
    vector(const vector& other);
    vector(std::size_t capacity);
    vector(std::size_t capacity, _ValueT value);
    vector(const std::initializer_list<_ValueT>& values);

    vector<_ValueT>& operator=(vector<_ValueT>&& other);
    vector<_ValueT>& operator=(const vector<_ValueT>& other);

    std::size_t size() const;
    std::size_t capacity() const;

    bool isEmpty() const;
    
    _ValueT* end() const;
    _ValueT* begin() const;

    void pop_back();
    void pop_front();
    void push_front(_ValueT value);
    void push_back(_ValueT value);

    void insert(std::size_t index, _ValueT value);

    _ValueT& operator[](std::size_t index) const;

    ~vector();

private:
    void resize(std::size_t newCapacity);
    std::size_t internal_index(std::size_t index) const;
};

template<typename _ValueT>
vector<_ValueT>::vector()
    : mSize(0),
      mCapacity(10),
      mData(new _ValueT[mCapacity]),
      back_index(0),
      front_index(0) {}

template<typename _ValueT>
vector<_ValueT>::vector(const vector<_ValueT>& other)
    : mSize(other.mSize),
      mCapacity(other.mCapacity),
      mData(new _ValueT[mCapacity]),
      back_index(other.back_index),
      front_index(other.front_index)
{
    for (size_t i = 0; i < mSize; i++)
        mData[i] = other.mData[i];
}

template<typename _ValueT>
vector<_ValueT>::vector(vector<_ValueT>&& other)
    : mSize(std::exchange(other.mSize, 0)),
      mCapacity(std::exchange(other.mCapacity, 0)),
      mData(new _ValueT[mCapacity]),
      back_index(std::exchange(other.back_index, 0)),
      front_index(std::exchange(other.front_index, 0))
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
      mData(new _ValueT[mCapacity]),
      back_index(0),
      front_index(0) {}

template<typename _ValueT>
vector<_ValueT>::vector(std::size_t capacity, _ValueT _val)
    : mSize(capacity),
      mCapacity(capacity),
      mData(new _ValueT[mCapacity]),
      back_index(mSize),
      front_index(0)
{
    for (size_t i = 0; i < mSize; i++)
        mData[i] = _val;
}

template<typename _ValueT>
vector<_ValueT>::vector(const std::initializer_list<_ValueT>& _values)
    : mSize(_values.size()),
      mCapacity(_values.size()),
      mData(new _ValueT[mCapacity]),
      back_index(mSize),
      front_index(0)
{
    for (size_t i = 0; i < mSize; i++)
        mData[front_index + i] = *(_values.begin() + i);
}

template<typename _ValueT>
vector<_ValueT>& vector<_ValueT>::operator=(vector<_ValueT>&& other)
{
    mSize           = std::exchange(other.mSize, 0);
    mCapacity       = std::exchange(other.mCapacity, 0);
    
    back_index      = std::exchange(other.back_index, 0);
    front_index     = std::exchange(other.front_index, 0);

    mData           = new _ValueT[mCapacity];

    for (size_t i = 0; i < mSize; i++)
        mData[i] = other.mData[i];
    delete[] other.mData;
    other.mData = nullptr;
    
    return *this;
}

template<typename _ValueT>
vector<_ValueT>& vector<_ValueT>::operator=(const vector<_ValueT>& other)
{
    mSize           = other.mSize;
    mCapacity       = other.mCapacity;
    
    back_index      = other.back_index;
    front_index     = other.front_index;

    mData           = new _ValueT[mCapacity];

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
    return mData + back_index;
}

template<typename _ValueT>
_ValueT* vector<_ValueT>::begin() const
{
    return mData + front_index;
}

template<typename _ValueT>
void vector<_ValueT>::pop_back()
{
    if (mSize)
    {
        back_index = (back_index == 0) ? mCapacity - 1 : back_index - 1;
        mSize--;
    }
    else
        throw std::out_of_range{"Error: calling pop_back() on empty vector."};
}

template<typename _ValueT>
void vector<_ValueT>::pop_front()
{
    if (mSize)
    {
        front_index = (front_index + 1) % mCapacity;
        mSize--;
    }
    else
        throw std::out_of_range{"Error: calling pop_front() on empty vector."};
}

template<typename _ValueT>
void vector<_ValueT>::push_back(_ValueT value)
{
    if (mSize == mCapacity)
        resize(mCapacity > 0 ? mCapacity * 2 : 1);
    mData[back_index] = value;
    back_index = (back_index + 1) % mCapacity;
    mSize++;
}

template<typename _ValueT>
void vector<_ValueT>::push_front(_ValueT value)
{
    if (mSize == mCapacity) 
        resize(mCapacity > 0 ? mCapacity * 2 : 1);
    front_index = (front_index == 0) ? mCapacity - 1 : front_index - 1;
    mData[front_index] = value;
    mSize++;
}

template<typename _ValueT>
void vector<_ValueT>::insert(std::size_t index, _ValueT value)
{
    if (index > mSize)
        throw std::out_of_range("Index out of range");
    if (mSize == mCapacity)
        resize(mCapacity > 0 ? mCapacity * 2 : 1);
    std::size_t insertPos = (front_index + index) % mCapacity;
    if (index < mSize / 2)
    {
        front_index = (front_index == 0) ? mCapacity - 1 : front_index - 1;
        for (std::size_t i = 0; i < index; i++)
            mData[(front_index + i) % mCapacity] = mData[(front_index + i + 1) % mCapacity];
    }
    else
    {
        for (std::size_t i = mSize; i > index; i--)
            mData[(front_index + i) % mCapacity] = mData[(front_index + i - 1) % mCapacity];
        back_index = (back_index + 1) % mCapacity;
    }
    mData[insertPos] = value;
    mSize++;
}

template<typename _ValueT>
_ValueT& vector<_ValueT>::operator[](std::size_t index) const
{
    if (index < mSize)
        return mData[internal_index(index)];
    throw std::out_of_range{"Error: trying to access element out of the array."};
}

template<typename _ValueT>
vector<_ValueT>::~vector()
{
    delete[] mData;
}

template<typename _ValueT>
void vector<_ValueT>::resize(std::size_t newCapacity)
{
    _ValueT* newData = new _ValueT[newCapacity];
    for (std::size_t i = 0; i < mSize; i++)
        newData[i] = mData[(front_index + i) % mCapacity];
    delete[] mData;

    mData     = newData;
    mCapacity = newCapacity;

    front_index    = 0;
    back_index     = mSize;
}

template<typename _ValueT>
std::size_t vector<_ValueT>::internal_index(std::size_t index) const
{
    return (front_index + index) % mCapacity;
}

#endif // VECTOR_HPP
