#ifndef MARINEANIMAL_HPP
#define MARINEANIMAL_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"

class MarineAnimal : virtual public Animal
{
protected:
    std::string favoriteOcean;

public:
    MarineAnimal(std::string n, int a, std::string ocean)
        : Animal(n, a), favoriteOcean(ocean) {}

    void swim()
    {
        std::cout << name << " swims in the " << favoriteOcean << std::endl;
    }

    virtual void speak() override
    {
        std::cout << name << " makes oceanic sound" << std::endl;
    }

    ~MarineAnimal() {}
};

#endif // MARINEANIMAL_HPP