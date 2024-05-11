#ifndef AXOLOTLE_HPP
#define AXOLOTLE_HPP

#include <iostream>

#include "MarineAnimal.hpp"

class Axolotle : public MarineAnimal
{
public:
    Axolotle()
        : MarineAnimal("Axi", 3, "Pacific"),
          Animal("Axi", 3) {}
    Axolotle(std::string n, int a, std::string favoriteOcean)
        : MarineAnimal(n, a, favoriteOcean) {}

    void speak() override
    {
        std::cout << "We don't speak" << std::endl;
    }

    void sendToStream(std::ostream& os) const override
    {
        os << "I am an axolotle";
    }
};

#endif // AXOLOTLE_HPP
