template <typename ValueT>
class unique_ptr
{
private:
    ValueT* ptr;

public:
    unique_ptr(ValueT* p = nullptr)
        : ptr(p) {}
    
    ~unique_ptr()
    {
        delete ptr;
    }
    
    unique_ptr(unique_ptr&& other) noexcept
        : ptr(other.ptr)
    {
        other.ptr = nullptr;
    }
    
    unique_ptr& operator=(unique_ptr&& other) noexcept
    {
        if (this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
    
    ValueT& operator*() const
    {
        return *ptr;
    }
    
    ValueT* operator->() const
    {
        return ptr;
    }
};
