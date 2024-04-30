#include "Animal.hpp"

#include <iostream>

class Lion : public Animal
{
public:
    Lion() = default;
    void voice() const override
    {
        std::cout << "roar" << std::endl;
    }
};
