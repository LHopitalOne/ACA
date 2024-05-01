#include <iostream>

#include "Dog.hpp"
#include "Cat.hpp"
#include "Pig.hpp"
#include "Cow.hpp"
#include "Lion.hpp"

int main() {
    Animal** zoo = new Animal*[5];

    zoo[0] = new Dog();
    zoo[1] = new Cat();
    zoo[2] = new Pig();
    zoo[3] = new Cow();
    zoo[4] = new Lion();

    for (size_t i = 0; i < 5; i++)
    {
        zoo[i]->voice();
        zoo[i]->printInfo();
    }

    return 0;
}
