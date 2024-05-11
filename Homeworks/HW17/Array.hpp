#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

#include "Animal.hpp"

class Array
{
private:

    Animal** mData;
    std::size_t mLength;

public:
    Array()
        : mData(new Animal*[10]),
          mLength(10) {}

    Array(const Array& other)
        : mData(new Animal*[other.mLength]),
          mLength(other.mLength)
    {
        for (size_t i = 0; i < mLength; i++)
            mData[i] = other.mData[i];   
    }

    Array(std::size_t length) : mLength(length)
    {
        mData = new Animal*[mLength];
    }
    
    Array(Animal** begin, Animal** end)
    {
        mLength = end - begin;
        mData = new Animal*[mLength];
        
        for (std::size_t i = 0; i < mLength; i++)
            mData[i] = *(begin + i);
    }

    Animal*& operator[](uint i) const
    {
        return mData[i];
    }

    friend std::ostream& operator<<(std::ostream& os, Array& arr)
    {
        for (std::size_t i = 0; i < arr.mLength; i++)
            os << *(arr.mData[i]) << "\n";
        return os;
    }

    uint size() const
    {
        return mLength;
    }

    ~Array()
    {
        for (size_t i = 0; i < mLength; i++)
            delete mData[i];
        delete[] mData;
    }
};

#endif // ARRAY_HPP
