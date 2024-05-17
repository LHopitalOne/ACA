#include "Animal.hpp"

#include <iostream>

class Cow : public Animal
{
public:
    Cow() = default;
    
    Cow(Cow&& other)
    {
        weight = std::exchange(other.weight, 0);
        age = std::exchange(other.age, 0);
    }

    
    Cow(float w, uint a) : Animal(w, a) {}
    
    Cow& operator=(Cow&& other)
    {
        weight = std::exchange(other.weight, 0);
        age = std::exchange(other.age, 0);

        return *this;
    }

    void voice() const override
    {
        std::cout << "moo" << std::endl;
    }
};
