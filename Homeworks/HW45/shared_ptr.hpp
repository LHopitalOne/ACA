#ifndef SHARED_PTR_HPP
#define SHARED_PTR_HPP

template<typename _ValueT>
class shared_ptr
{
private:
    _ValueT* ptr;
    int* ref_count;

public:
    shared_ptr() : ptr(nullptr), ref_count(new int(0)) {}
    explicit shared_ptr(_ValueT* p) : ptr(p), ref_count(new int(1)) {}

    shared_ptr(const shared_ptr<_ValueT>& sp) : ptr(sp.ptr), ref_count(sp.ref_count)
    {
        ++(*ref_count);
    }

    shared_ptr<_ValueT>& operator=(const shared_ptr<_ValueT>& sp)
    {
        if (this != &sp)
        {
            if (--(*ref_count) == 0)
            {
                delete ptr;
                delete ref_count;
            }

            ptr = sp.ptr;
            ref_count = sp.ref_count;
            ++(*ref_count);
        }
        return *this;
    }

    ~shared_ptr()
    {
        if (--(*ref_count) == 0)
        {
            delete ptr;
            delete ref_count;
        }
    }

    _ValueT& operator*() const
    {
        return *ptr;
    }

    _ValueT* operator->() const
    {
        return ptr;
    }

    int use_count() const
    {
        return *ref_count;
    }
};

#endif // SHARED_PTR_HPP
