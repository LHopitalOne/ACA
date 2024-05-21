#include "Animal.hpp"

#include <iostream>

class Lion : public Animal
{
public:
    Lion() = default;
    Lion(const Lion&) = default;

    Lion(Lion&& other)
    {
        weight = std::exchange(other.weight, 0);
        age = std::exchange(other.age, 0);
    }

    Lion(float w, uint a) : Animal(w, a) {}

    Lion& operator=(Lion&& other)
    {
        weight = std::exchange(other.weight, 0);
        age = std::exchange(other.age, 0);

        return *this;
    }

    void voice() const override
    {
        std::cout << "roar" << std::endl;
    }
};
