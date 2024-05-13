#include "Animal.hpp"

#include <iostream>

class Dog : public Animal
{
public:
    Dog() = default;
    Dog(float w, uint a) : Animal(w, a) {}

    void voice() const override
    {
        std::cout << "woof" << std::endl;
    }
};
