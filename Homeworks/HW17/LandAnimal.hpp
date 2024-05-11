#ifndef LANDANIMAL_HPP
#define LANDANIMAL_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"

class LandAnimal : virtual public Animal
{
protected:
    std::string habitat;

public:
    LandAnimal(std::string n, int a, std::string h)
        : Animal(n, a), habitat(h) {}

    void run()
    {
        std::cout << name << " runs in " << habitat << std::endl;
    }

    virtual void speak() override
    {
        std::cout << name << " makes land animal sound" << std::endl;
    }

    ~LandAnimal(){}
};

#endif // LANDANIMAL_HPP
