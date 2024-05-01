#include "Animal.hpp"

#include <iostream>

class Dog : public Animal
{
public:
    Dog() = default;
    void voice() const override
    {
        std::cout << "woof" << std::endl;
    }
};
