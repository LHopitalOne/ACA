#include "Animal.hpp"

#include <iostream>

class Pig : public Animal
{
public:
    Pig() = default;
    void voice() const override
    {
        std::cout << "oink" << std::endl;
    }
};
