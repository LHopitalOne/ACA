#include <iostream>

#include "container.hpp"

int main(int argc, char const *argv[])
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    std::cout << q;

    q.pop();

    std::cout << q;

    return 0;
}

