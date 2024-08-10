#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "list.hpp"

class queue {
private:
    list<int> queue;

public:
    void enqueue(int value) {
        queue.push_back(value);
    }

    void dequeue() {
        if (queue.isEmpty()) {
            return;
        }

        queue.pop_front();
    }

    int peek() {
        if (queue.isEmpty())
        {
            return -1;
        }
        return *queue.begin();
    }

    bool isEmpty() {
        return queue.isEmpty();
    }
};

#endif // QUEUE_HPP
