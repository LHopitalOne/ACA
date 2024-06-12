#ifndef LIST_HPP
#define LIST_HPP

#include <cstdlib>
#include <utility>
#include <stdexcept>
#include <initializer_list>

namespace l
{
    template<typename _ValueT>
    class list;

    template<typename _ValueT>
    void mergeSort(list<_ValueT>& lst, std::size_t left, std::size_t right)
    {
        if (left < right)
        {
            std::size_t middle = left + (right - left) / 2;
            mergeSort(lst, left, middle);
            mergeSort(lst, middle + 1, right);
            merge(lst, left, middle, right);
        }
    }

    template<typename _ValueT>
    void merge(list<_ValueT>& _l, std::size_t left, std::size_t middle, std::size_t right)
    {
        std::size_t n1 = middle - left + 1;
        std::size_t n2 = right - middle;

        std::vector<_ValueT> L(n1), R(n2);

        for (std::size_t i = 0; i < n1; i++)
            L[i] = _l[left + i];
        for (std::size_t i = 0; i < n2; i++)
            R[i] = _l[middle + 1 + i];

        std::size_t i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                _l[k] = L[i];
                i++;
            }
            else
            {
                _l[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            _l[k] = L[i];
            ++i;
            ++k;
        }

        while (j < n2)
        {
            _l[k] = R[j];
            ++j;
            ++k;
        }
    }

    template<typename _ValueT>
    void bubbleSort(list<_ValueT>& _l)
    {
        bool swapped = false;
        do
        {
            swapped = false;
            for (std::size_t i = 0; i < _l.size() - 1; i++)
            {
                if (_l[i] > _l[i + 1])
                {
                    std::swap(_l[i], _l[i + 1]);
                    swapped = true;
                }
            }
        } while (swapped);
    }

    template<typename _ValueT>
    void quickSort(list<_ValueT>& _l, std::size_t left, std::size_t right)
    {
        if (left >= right)
            return;

        _ValueT pivot_index = partition(_l, left, right);
        quickSort(_l, left, pivot_index - 1);
        quickSort(_l, pivot_index + 1, right);
    }

    template<typename _ValueT>
    std::size_t partition(list<_ValueT>& _l, std::size_t left, std::size_t right)
    {
        _ValueT pivot = _l[right];
        std::size_t i = left - 1;

        for (int j = left; j < right; j++)
        {
            if (_l[j] <= pivot)
            {
                i++;
                std::swap(_l[i], _l[j]);
            }
        }
        std::swap(_l[i + 1], _l[right]);

        return i + 1;
    }

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
        class input_iterator;

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

        input_iterator begin() const;
        input_iterator end() const;

        friend std::ostream& operator<<(std::ostream& os, const list<_ValueT>& l)
        {
            l.print(os);

            return os;
        }

        ~list();
        
    private:
        class Node
        {
        private:
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

            friend class list;
        };

        class input_iterator
        {
        private:
            Node* current = nullptr;
        public:
            input_iterator(Node* node) : current(node) {}
            input_iterator(const input_iterator& other)
            {
                current->setNext(current->next());
                current->setPrev(current->prev());
                current->setValue(current->value());
            }
            input_iterator& operator++()
            {
                current = current->next();
                return *this;
            }
            _ValueT& operator*()
            {
                return current->mValue;
            }
            input_iterator operator++(int)
            {
                input_iterator iter = *this;
                if (current->next())
                    current = current->next();
                return iter;
            }
            input_iterator& operator->()
            {
                return *this;
            }
            input_iterator& operator=(const input_iterator& other)
            {
                current->setNext(current->next());
                current->setPrev(current->prev());
                current->setValue(current->value());

                return *this;
            }
            bool operator==(const input_iterator& other)
            {
                return current == other.current;
            }
            bool operator!=(const input_iterator& other)
            {
                return current != other.current;
            }
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
    typename list<_ValueT>::input_iterator list<_ValueT>::begin() const
    {
        return input_iterator(head->mNextNode);
    }

    template<typename _ValueT>
    typename list<_ValueT>::input_iterator list<_ValueT>::end() const
    {
        return input_iterator(tail);
    }

    template<typename _ValueT>
    list<_ValueT>::~list()
    {
        Node* cur = head->mNextNode;
        while (mSize--)
        {
            Node* nextNode = cur->mNextNode;
            delete cur;
            cur = nextNode;
        }
        
        delete head;
        delete tail;
    }

} // namespace list


#endif // LIST_HPP
