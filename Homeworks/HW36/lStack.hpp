#ifndef LSTACK_HPP
#define LSTACK_HPP

#include "list.hpp"

template<typename _ValueT>
class lStack
{
protected:
    void print(const std::ostream& os)
    {
        lStack<_ValueT> temp = *this;
        while (!temp.empty())
        {
            os << top() << " ";
            pop();
        }
    }

private:
    list<_ValueT> _l;

public:
    _ValueT top() const;

    bool empty() const;
    std::size_t size() const;

    void push(_ValueT element);
    void pop();

    void swap(lStack<_ValueT>& other);

    lStack<_ValueT>& operator=(const lStack<_ValueT>& other);
    friend std::ostream& operator<<(const lStack<_ValueT>& st, std::ostream& os)
    {
        st.print(os);
        return os;
    }
};

template <typename _ValueT>
lStack<_ValueT>& lStack<_ValueT>::operator=(const lStack<_ValueT>& other)
{
    if (this != &other)
        this->_l = other._l;
    return *this;
}

template <typename _ValueT>
inline _ValueT lStack<_ValueT>::top() const
{
    return *(_l.begin());
}

template <typename _ValueT>
inline bool lStack<_ValueT>::empty() const
{
    return _l.isEmpty();
}

template <typename _ValueT>
inline std::size_t lStack<_ValueT>::size() const
{
    return _l.size();
}

template <typename _ValueT>
void lStack<_ValueT>::push(_ValueT element)
{
    _l.push_front(element);
}

template <typename _ValueT>
void lStack<_ValueT>::pop()
{
    _l.pop_front();
}

template <typename _ValueT>
void lStack<_ValueT>::swap(lStack<_ValueT> &other)
{
    lStack<_ValueT> temp;
    
    temp = *this;
    *this = other;
    other = temp;
}

#endif // LSTACK_HPP

