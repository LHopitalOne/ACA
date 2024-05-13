#include "Animal.hpp"

#include <iostream>

class Pig : public Animal
{
public:
    Pig() = default;
    Pig(float w, uint a) : Animal(w, a) {}

    void voice() const override
    {
        std::cout << "oink" << std::endl;
    }
};
