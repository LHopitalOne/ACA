#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

#include "list.hpp"

template<typename _ValueT>
class queue
{
protected:
    void print(std::ostream& os) const
    {
        int n = size();
        auto iter = _v.begin();

        while (n--)
        {
            os << *iter << " ";
            iter++;
        }
    }

private:
    list<_ValueT> _v;

public:
    _ValueT back() const;
    _ValueT front() const;

    bool isEmpty() const;
    std::size_t size() const;

    void pop();
    void push(const _ValueT& element);

    queue<_ValueT>& operator=(const queue<_ValueT>& other);

    friend std::ostream& operator<<(std::ostream& os, const queue<_ValueT>& q)
    {
        q.print(os);
        return os;
    }
};

template<typename _ValueT>
inline _ValueT queue<_ValueT>::front() const
{
    return *_v.begin();
}

template<typename _ValueT>
_ValueT queue<_ValueT>::back() const
{
    auto backIter = front();
    int n = size() - 1;
    
    while (n--)
        backIter++;

    return *backIter;
}

template <typename _ValueT>
bool queue<_ValueT>::isEmpty() const
{
    return _v.isEmpty();
}

template <typename _ValueT>
std::size_t queue<_ValueT>::size() const
{
    return _v.size();
}

template <typename _ValueT>
void queue<_ValueT>::pop()
{
    _v.pop_front();
}

template <typename _ValueT>
void queue<_ValueT>::push(const _ValueT& element)
{
    _v.push_back(element);
}

template <typename _ValueT>
queue<_ValueT>& queue<_ValueT>::operator=(const queue<_ValueT>& other)
{
    _v = other._v;
}

#endif // QUEUE_HPP
