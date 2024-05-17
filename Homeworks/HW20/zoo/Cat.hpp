#include "Animal.hpp"

#include <iostream>

class Cat : public Animal
{
public:
    Cat() = default;

    Cat(Cat&& other)
    {
        weight = std::exchange(other.weight, 0);
        age = std::exchange(other.age, 0);
    }

    Cat(float w, uint a) : Animal(w, a) {}

    Cat& operator=(Cat&& other)
    {
        weight = std::exchange(other.weight, 0);
        age = std::exchange(other.age, 0);

        return *this;
    }

    void voice() const override
    {
        std::cout << "meow" << std::endl;
    }
};
