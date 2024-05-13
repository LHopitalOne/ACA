#include "Animal.hpp"

#include <iostream>

class Lion : public Animal
{
public:
    Lion() = default;
    Lion(float w, uint a) : Animal(w, a) {}

    void voice() const override
    {
        std::cout << "roar" << std::endl;
    }
};
