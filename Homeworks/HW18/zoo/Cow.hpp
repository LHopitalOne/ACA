#include "Animal.hpp"

#include <iostream>

class Cow : public Animal
{
public:
    Cow() = default;
    Cow(float w, uint a) : Animal(w, a) {}
    
    void voice() const override
    {
        std::cout << "moo" << std::endl;
    }
};
