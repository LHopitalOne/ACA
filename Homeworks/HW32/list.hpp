#ifndef LIST_HPP
#define LIST_HPP

#include <cstdlib>
#include <utility>
#include <stdexcept>
#include <initializer_list>

namespace list
{    
    template<typename _ValueT>
    class list // Doubly Linked List
    {
    protected:
        void print(std::ostream& os) const
        {
            Node* cur = head->mNextNode;
            
            while(cur != tail)
            {
                os << cur->mValue << " ";
                cur = cur->mNextNode;
            }
        }

    private:
        class Node;

        std::size_t mSize;

        Node* head;
        Node* tail;

    public:
        list();
        list(list&& other);
        list(const list& other);
        list(std::size_t size);
        list(std::size_t size, _ValueT value);
        list(std::initializer_list<_ValueT> values);

        list<_ValueT>& operator=(list<_ValueT>&& other);
        list<_ValueT>& operator=(const list<_ValueT>& other);

        std::size_t size() const;

        bool isEmpty() const;

        void pop_back();
        void pop_front();
        void push_front(_ValueT value);
        void push_back(_ValueT value);

        void insert(std::size_t index, _ValueT value);

        _ValueT& operator[](std::size_t index) const;

        friend std::ostream& operator<<(std::ostream& os, const list<_ValueT>& l)
        {
            l.print(os);

            return os;
        }

        ~list();
        
    private:
        class Node
        {
        public:
            Node* mNextNode;
            Node* mPrevNode;

            _ValueT mValue;
        public:
            Node() : mNextNode(nullptr), mPrevNode(nullptr), mValue(_ValueT()) {}
            Node(_ValueT _value) : mNextNode(nullptr), mPrevNode(nullptr), mValue(_value) {}

            Node* next() const { return mNextNode; }
            Node* prev() const { return mPrevNode; }
            _ValueT value() const { return mValue; }

            void setNext(Node* _node) { mNextNode = _node; }
            void setPrev(Node* _node) { mPrevNode = _node; }
            void setValue(_ValueT _value) { mValue = _value; }
        };
    
        static void bind(Node* first, Node* second)
        {
            first->mNextNode = second;
            second->mPrevNode = first;
        }
    };

    template<typename _ValueT>
    list<_ValueT>::list()
    {
        head = new Node();
        tail = new Node();

        mSize = 0;

        bind(head, tail);
    }

    template<typename _ValueT>
    list<_ValueT>::list(list<_ValueT>&& other)
    {
        head = std::exchange(other.head, new Node());
        tail = std::exchange(other.tail, new Node());

        mSize = std::exchange(other.mSize, 0);

        bind(other.head, other.tail);
    }

    template<typename _ValueT>
    list<_ValueT>::list(const list<_ValueT>& other)
    {
        mSize = other.mSize;
        std::size_t n = other.mSize;

        head = new Node();
        tail = new Node();

        Node* cur = other.head->mNextNode;
        Node* curPrevThis = head;
        
        while (n--)
        {
            Node* newNode = new Node(cur->mValue);
            bind(curPrevThis, newNode);
            
            cur = cur->mNextNode;
            curPrevThis = curPrevThis->mNextNode;
        }

        bind(curPrevThis, tail);
    }

    template<typename _ValueT>
    list<_ValueT>::list(std::size_t size)
    {
        mSize = size;

        head = new Node();
        tail = new Node();

        Node* cur = head;
        
        while (size--)
        {
            Node* newNode = new Node();
            bind(cur, newNode);
            
            cur = cur->mNextNode;
        }

        bind(cur, tail);
    }

    template<typename _ValueT>
    list<_ValueT>::list(std::size_t size, _ValueT value)
    {
        mSize = size;

        head = new Node();
        tail = new Node();

        Node* cur = head;
        
        while (size--)
        {
            Node* newNode = new Node(value);
            bind(cur, newNode);
            
            cur = cur->mNextNode;
        }

        bind(cur, tail);
    }

    template<typename _ValueT>
    list<_ValueT>::list(std::initializer_list<_ValueT> values)
    {
        mSize = values.size();
        std::size_t n = mSize;

        head = new Node();
        tail = new Node();

        Node* cur = head;
        
        while (n)
        {
            Node* newNode = new Node(*(values.begin() + mSize - n));
            bind(cur, newNode);
            
            cur = cur->mNextNode;

            n--;
        }

        bind(cur, tail);
    }

    template<typename _ValueT>
    list<_ValueT>& list<_ValueT>::operator=(list<_ValueT>&& other)
    {
        head = std::exchange(other.head, new Node());
        tail = std::exchange(other.tail, new Node());

        mSize = std::exchange(other.mSize, 0);

        bind(other.head, other.tail);

        return *this;
    }

    template<typename _ValueT>
    list<_ValueT>& list<_ValueT>::operator=(const list<_ValueT>& other)
    {
        mSize = other.mSize;
        std::size_t n = other.mSize;

        head = new Node();
        tail = new Node();

        Node* cur = other.head->mNextNode;
        Node* curPrevThis = head;
        
        while (cur != other.tail)
        {
            Node* newNode = new Node(cur->mValue);
            bind(curPrevThis, newNode);
            
            cur = cur->mNextNode;
            curPrevThis = curPrevThis->mNextNode;
        }

        bind(curPrevThis, tail);

        return *this;
    }

    template<typename _ValueT>
    std::size_t list<_ValueT>::size() const
    {
        return mSize;
    }

    template<typename _ValueT>
    bool list<_ValueT>::isEmpty() const
    {
        return mSize == 0;
    }

    template<typename _ValueT>
    void list<_ValueT>::pop_back()
    {
        if (mSize == 0)
            throw std::out_of_range{"Error: argument index is out of range."};

        Node* newEnd = tail->mPrevNode->mPrevNode;
        delete tail->mPrevNode;
        
        bind(newEnd, tail);
        
        mSize--;
    }
    
    template<typename _ValueT>
    void list<_ValueT>::pop_front()
    {
        if (mSize == 0)
            throw std::out_of_range{"Error: argument index is out of range."};

        Node* newFront = head->mNextNode->mNextNode;
        delete head->mNextNode;
        
        bind(head, newFront);
        
        mSize--;
    }
    
    template<typename _ValueT>
    void list<_ValueT>::push_front(_ValueT value)
    {
        Node* newNode = new Node(value);

        bind(newNode, head->mNextNode);
        bind(head, newNode);

        mSize++;
    }
    
    template<typename _ValueT>
    void list<_ValueT>::push_back(_ValueT value)
    {
        Node* newNode = new Node(value);

        bind(tail->mPrevNode, newNode);
        bind(newNode, tail);

        mSize++;
    }

    template<typename _ValueT>
    void list<_ValueT>::insert(std::size_t index, _ValueT value)
    {
        if (index >= mSize || index < 0)
            throw std::out_of_range{"Error: argument index is out of range."};
            Node* newNode = new Node(value);

        Node* cur = head->mNextNode;
        while (--index)
            cur = cur->mNextNode;
        
        bind(newNode, cur->mNextNode);
        bind(cur, newNode);

        mSize++;
    }

    template<typename _ValueT>
    _ValueT& list<_ValueT>::operator[](std::size_t index) const
    {
        if (index >= mSize || index < 0)
            throw std::out_of_range{"Error: argument index is out of range."};

        Node* cur = head->mNextNode;
        while (index--)
            cur = cur->mNextNode;
        return cur->mValue;
    }

    template<typename _ValueT>
    list<_ValueT>::~list()
    {
        Node* cur = head->mNextNode;
        while (mSize--)
        {
            delete cur;
            cur = cur->mNextNode;
        }
        
        delete head;
        delete tail;
    }

} // namespace list


#endif // LIST_HPP
