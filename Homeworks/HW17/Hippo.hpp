#ifndef HIPPO_HPP
#define HIPPO_HPP

#include <iostream>

#include "MarineAnimal.hpp"
#include "LandAnimal.hpp"

class Hippo : public MarineAnimal, public LandAnimal
{
public:
    Hippo()
        : MarineAnimal("Hippi", 3, "Indian"),
          LandAnimal("Hippi", 3, "Africa"),
          Animal("Hippi", 3) {}
    Hippo(std::string n, int a, std::string favoriteOcean, std::string favoriteLand)
        : MarineAnimal(n, 3, favoriteOcean),
          LandAnimal(n, a, favoriteLand),
          Animal(n, a) {}

    void speak() override
    {
        std::cout << "grrrrrr" << std::endl;
    }

    void sendToStream(std::ostream& os) const override
    {
        os << "I am an hippo";
    }
};

#endif // HIPPO_HPP
