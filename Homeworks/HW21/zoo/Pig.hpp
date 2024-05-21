#include "Animal.hpp"

#include <iostream>

class Pig : public Animal
{
public:
    Pig() = default;
    Pig(const Pig&) = default;

    Pig(Pig&& other)
    {
        weight = std::exchange(other.weight, 0);
        age = std::exchange(other.age, 0);
    }
    
    Pig(float w, uint a) : Animal(w, a) {}

    Pig& operator=(Pig&& other)
    {
        weight = std::exchange(other.weight, 0);
        age = std::exchange(other.age, 0);

        return *this;
    }

    void voice() const override
    {
        std::cout << "oink" << std::endl;
    }
};
