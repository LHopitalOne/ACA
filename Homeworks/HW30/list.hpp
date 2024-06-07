#ifndef LIST_HPP
#define LIST_HPP

#include <cstdlib>
#include <utility>
#include <iostream>
#include <stdexcept>
#include <initializer_list>

namespace list
{
    template<typename _ValueT>
    class list // Singly Linked List
    {
    protected:
        void print(std::ostream& os) const
        {
            if (lastElement)
            {
                Node* cur = head->mNextNode;
                
                while(cur)
                {
                    os << cur->mValue << " ";
                    cur = cur->mNextNode;
                }
            }  
        }

    private:
        class Node;

        std::size_t mSize;

        Node* head;
        Node* lastElement;

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

        bool thereIsCycle() const;

        static list<int> cyclicList()
        {
            list<int> _l = {1, 2, 3, 4, 5, 6};
            _l.head->mNextNode->mNextNode->mNextNode->mNextNode->mNextNode->mNextNode = _l.head->mNextNode->mNextNode;

            return _l;
        }

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
            _ValueT mValue;
        public:
            Node() : mNextNode(nullptr), mValue(_ValueT()) {}
            
            Node(const Node& other) : mValue(other.mValue)
            {
                std::cout << "Node copy\n";

                mNextNode = new Node(mValue);
                mNextNode->mNextNode = other.mNextNode;
            }

            Node(Node* next) : mNextNode(next), mValue(_ValueT()) {}
            Node(_ValueT value) : mNextNode(nullptr), mValue(value) {}
            Node(_ValueT value, Node* next) : mNextNode(next), mValue(value) {}

            Node* next() const { return mNextNode; }
            _ValueT value() const { return mValue; }

            void setNext(Node* _node) { mNextNode = _node; }
            void setValue(_ValueT _value) { mValue = _value; }
        };
    };
    
    template<typename _ValueT>
    list<_ValueT>::list() : mSize(0), head(new Node(nullptr)), lastElement(head->mNextNode) {}

    template<typename _ValueT>
    list<_ValueT>::list(list<_ValueT>&& other)
        : mSize(std::exchange(other.mSize, 0)), head(std::exchange(other.head, nullptr)), lastElement(std::exchange(other.lastElement, nullptr)) {}
    
    template<typename _ValueT>
    list<_ValueT>::list(const list<_ValueT>& other)
        : mSize(other.mSize), head(new Node())
    {
        Node* curOther = other.head;
        Node* curThis = head;

        while (curOther->mNextNode)
        {
            curThis->mNextNode = new Node(curOther->mNextNode->mValue);
            curThis = curThis->mNextNode;
            curOther = curOther->mNextNode;
        }
        
        lastElement = curThis;
    }

    template<typename _ValueT>
    list<_ValueT>::list(std::size_t size)
        : mSize(size)
    {
        head = new Node();
        Node* cur = head;

        while (size)
        {
            Node* newNode = new Node;

            cur->mNextNode = newNode;
            cur = cur->mNextNode;

            if (size == 1)
                lastElement = newNode;

            size--;
        }
    }

    template<typename _ValueT>
    list<_ValueT>::list(std::size_t size, _ValueT value)
        : mSize(size)
    {
        head = new Node();
        Node* cur = head;

        while (size)
        {
            Node* newNode = new Node(value);

            cur->mNextNode = newNode;
            cur = cur->mNextNode;

            if (size == 1)
                lastElement = newNode;

            size--;
        }
    }

    template<typename _ValueT>
    list<_ValueT>::list(std::initializer_list<_ValueT> values)
        : mSize(values.size())
    {
        head = new Node();
        int size = mSize;

        Node* cur = head;

        while (size)
        {
            auto element = *(values.begin() + (mSize - size));
            Node* newNode = new Node(element);
            
            cur->mNextNode = newNode;
            cur = cur->mNextNode;
            
            if (size == 1)
                lastElement = newNode;

            size--;
        }
    }
    
    template<typename _ValueT>
    list<_ValueT>& list<_ValueT>::operator=(list<_ValueT>&& other)
    {
        mSize = std::exchange(other.mSize, 0);
        head = std::exchange(other.head, nullptr);
        lastElement = std::exchange(other.lastElement, nullptr);

        return *this;
    }

    template<typename _ValueT>
    list<_ValueT>& list<_ValueT>::operator=(const list<_ValueT>& other)
    {
        *this = std::move(list<_ValueT>(other));

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
        return head->mNextNode == nullptr;
    }

    template <typename _ValueT>
    void list<_ValueT>::push_front(_ValueT value)
    {
        Node* newNode = new Node(value);
        
        newNode->mNextNode = head->mNextNode;
        head->mNextNode = newNode;

        if (!lastElement)
            lastElement = newNode;
        
        mSize++;
    }
    
    template <typename _ValueT>
    void list<_ValueT>::push_back(_ValueT value)
    {
        Node* newNode = new Node(value);
        
        lastElement->mNextNode = newNode;
        lastElement = newNode;

        mSize++;
    }

    template <typename _ValueT>
    void list<_ValueT>::insert(std::size_t index, _ValueT value)
    {
        std::size_t i = 0;
        Node* cur = head;

        while (i != index)
        {
            cur = cur->mNextNode;
            i++;
        }
        
        Node* nextNode = cur->mNextNode;
        Node* newNode = new Node(value);
        
        cur->mNextNode = newNode;
        cur = newNode;
        cur->mNextNode = nextNode;

        mSize++;
    }

    template <typename _ValueT>
    void list<_ValueT>::pop_front()
    {
        if (!mSize)
            throw std::out_of_range{"Trying to call pop_front on empty list!"};

        Node* node = head;
        head = head->mNextNode;

        delete node;

        mSize--;
    }

    template <typename _ValueT>
    void list<_ValueT>::pop_back()
    {
        if (!mSize)
            throw std::out_of_range{"Trying to call pop_back on empty list!"};

        Node* cur = head->mNextNode;

        while (cur->mNextNode != lastElement)
            cur = cur->mNextNode;
        
        delete lastElement;
        lastElement = cur;
        lastElement->mNextNode = nullptr;

        mSize--;
    }

    template<typename _ValueT>
    _ValueT& list<_ValueT>::operator[](std::size_t index) const
    {
        std::size_t i = 0;
        Node* cur = head;

        while (i != index)
        {
            cur = cur->mNextNode;
            i++;
        }

        return cur->mValue;
    }

    template<typename _ValueT>
    bool list<_ValueT>::thereIsCycle() const
    {
        Node* slow = head;
        Node* fast = head;

        while (fast && fast->mNextNode)
        {
            slow = slow->mNextNode;
            fast = fast->mNextNode->mNextNode;

            if (fast == slow)
                return true;
        }

        return false;
    }

    template<typename _ValueT>
    list<_ValueT>::~list()
    {
        Node* cur = head;

        while (mSize--)
        {
            Node* nextNode = cur->mNextNode;
            delete cur;
            cur = nextNode;
        }
    }
    

} // namespace list


#endif // LIST_HPP
