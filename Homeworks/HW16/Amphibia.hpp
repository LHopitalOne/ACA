#ifndef AMPHIBIA_HPP
#define AMPHIBIA_HPP

#include <iostream>
#include <string>

#include "LandAnimal.hpp"
#include "MarineAnimal.hpp"

#include "Animal.hpp"

class Amphibia : public MarineAnimal, public LandAnimal
{
public:
    Amphibia(std::string n, int a, std::string ocean, std::string h)
        : Animal(n, a), MarineAnimal(n, a, ocean), LandAnimal(n, a, h) {}

    void speak() override
    {
        std::cout << name << " makes both marine and land animal sounds" << std::endl;
    }

    void showAbilities()
    {
        swim();
        run();
    }

    void operator()(std::string newName)
    {
        std::cout << name << " is no longer " << name << ". From now on it's " << newName << std::endl;
        name = newName;
    }
};

#endif // AMPHIBIA_HPP
