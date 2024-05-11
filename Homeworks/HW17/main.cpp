#include <iostream>

#include "Axolotle.hpp"
#include "Hippo.hpp"

#include "Array.hpp"

int main(int argc, char const *argv[])
{
    Array arr;
    for (size_t i = 0; i < arr.size() / 2; i++)
        arr[i] = new Axolotle();

    for (size_t i = arr.size() / 2; i < arr.size(); i++)
        arr[i] = new Hippo();
    
    arr[0] = new Hippo();

    std::cout << arr;

    arr[1]->speak();
    return 0;
}

