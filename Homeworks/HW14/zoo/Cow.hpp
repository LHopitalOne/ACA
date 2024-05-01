#include "Animal.hpp"

#include <iostream>

class Cow : public Animal
{
public:
    Cow() = default;
    void voice() const override
    {
        std::cout << "moo" << std::endl;
    }
};
