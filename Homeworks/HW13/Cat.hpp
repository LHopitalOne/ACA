#include "Animal.hpp"

#include <iostream>

class Cat : public Animal
{
public:
    Cat() = default;
    void voice() const override
    {
        std::cout << "meow" << std::endl;
    }
};
