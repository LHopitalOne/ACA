#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

#include "vector.hpp"

template<typename _ValueT>
class stack
{
protected:
    void print(const std::ostream& os)
    {
        stack<_ValueT> temp = *this;
        while (!temp.empty())
        {
            os << top() << " ";
            pop();
        }
    }

private:
    vector<_ValueT> _v;

public:
    _ValueT top() const;

    bool empty() const;
    std::size_t size() const;

    void push(_ValueT element);
    void pop();

    void swap(stack<_ValueT>& other);

    stack<_ValueT>& operator=(const stack<_ValueT>& other);
    friend std::ostream& operator<<(std::ostream& os, const stack<_ValueT>& st)
    {
        st.print(os);
        return os;
    }
};

template <typename _ValueT>
stack<_ValueT>& stack<_ValueT>::operator=(const stack<_ValueT>& other)
{
    if (this != &other)
        this->_v = other._v;
    return *this;
}

template <typename _ValueT>
inline _ValueT stack<_ValueT>::top() const
{
    return *(_v.end() - 1);
}

template <typename _ValueT>
inline bool stack<_ValueT>::empty() const
{
    return _v.isEmpty();
}

template <typename _ValueT>
inline std::size_t stack<_ValueT>::size() const
{
    return _v.size();
}

template <typename _ValueT>
void stack<_ValueT>::push(_ValueT element)
{
    _v.push_back(element);
}

template <typename _ValueT>
void stack<_ValueT>::pop()
{
    _v.pop_back();
}

template <typename _ValueT>
void stack<_ValueT>::swap(stack<_ValueT> &other)
{
    stack<_ValueT> temp;
    
    temp = *this;
    *this = other;
    other = temp;
}

#endif // STACK_HPP
