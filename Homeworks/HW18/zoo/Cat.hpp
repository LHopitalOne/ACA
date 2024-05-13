#include "Animal.hpp"

#include <iostream>

class Cat : public Animal
{
public:
    Cat() = default;
    Cat(float w, uint a) : Animal(w, a) {}

    void voice() const override
    {
        std::cout << "meow" << std::endl;
    }
};
