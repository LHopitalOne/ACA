#include "Animal.hpp"

#include <iostream>

class Dog : public Animal
{
public:
    Dog() = default;
    Dog(const Dog&) = default;

    Dog(Dog&& other)
    {
        weight = std::exchange(other.weight, 0);
        age = std::exchange(other.age, 0);
    }

    Dog(float w, uint a) : Animal(w, a) {}
    
    Dog& operator=(Dog&& other)
    {
        weight = std::exchange(other.weight, 0);
        age = std::exchange(other.age, 0);
        
        return *this;
    }

    void voice() const override
    {
        std::cout << "woof" << std::endl;
    }
};
