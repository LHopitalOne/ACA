#ifndef HIPPO_HPP
#define HIPPO_HPP

#include <iostream>

#include "Animal.hpp"

class Hippo : public Animal
{
public:
    Hippo() {}

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
