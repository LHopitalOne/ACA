#ifndef AXOLOTLE_HPP
#define AXOLOTLE_HPP

#include <iostream>

#include "Animal.hpp"

class Axolotle : public Animal
{
public:
    Axolotle() {}

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
