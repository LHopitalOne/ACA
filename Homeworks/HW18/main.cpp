#include <iostream>

#include "./zoo/Dog.hpp"
#include "./zoo/Cat.hpp"
#include "./zoo/Pig.hpp"
#include "./zoo/Cow.hpp"
#include "./zoo/Lion.hpp"

#include "Zoo.hpp"

int main() {
    // Animal** zoo = new Animal*[5];

    Zoo& zoo = Zoo::init(10);

    zoo.get(0) = new Dog(1, 3);
    zoo.get(1) = new Cat(2, 5);
    zoo.get(2) = new Pig(30, 3);
    zoo.get(3) = new Cow(150, 4);
    zoo.get(4) = new Lion(80, 9);

    for (size_t i = 0; i < 5; i++)
    {
        zoo.get(i)->voice();
        zoo.get(i)->printInfo();
    }

    return 0;
}
