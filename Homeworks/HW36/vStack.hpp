#ifndef VSTACK_HPP
#define VSTACK_HPP

#include "vector.hpp"

template<typename _ValueT>
class vStack
{
protected:
    void print(const std::ostream& os)
    {
        vStack<_ValueT> temp = *this;
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

    void swap(vStack<_ValueT>& other);

    vStack<_ValueT>& operator=(const vStack<_ValueT>& other);
    friend std::ostream& operator<<(const vStack<_ValueT>& st, std::ostream& os)
    {
        st.print(os);
        return os;
    }
};

template <typename _ValueT>
vStack<_ValueT>& vStack<_ValueT>::operator=(const vStack<_ValueT>& other)
{
    if (this != &other)
        this->_v = other._v;
    return *this;
}

template <typename _ValueT>
inline _ValueT vStack<_ValueT>::top() const
{
    return *(_v.end() - 1);
}

template <typename _ValueT>
inline bool vStack<_ValueT>::empty() const
{
    return _v.isEmpty();
}

template <typename _ValueT>
inline std::size_t vStack<_ValueT>::size() const
{
    return _v.size();
}

template <typename _ValueT>
void vStack<_ValueT>::push(_ValueT element)
{
    _v.push_back(element);
}

template <typename _ValueT>
void vStack<_ValueT>::pop()
{
    _v.pop_back();
}

template <typename _ValueT>
void vStack<_ValueT>::swap(vStack<_ValueT> &other)
{
    vStack<_ValueT> temp;
    
    temp = *this;
    *this = other;
    other = temp;
}

#endif // VSTACK_HPP
