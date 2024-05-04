#include <iostream>

#include "Car.hpp"

int main(int argc, char const *argv[])
{
    Car c0("Mersedes-Benz", "SL-Roadster", 2023, Engine(4.7, 8), Color(252, 186, 3));
    Car c1("Porsche", "911", 2023, Engine(3, 6), Color(97, 124, 88));

    c0.start();
    c0.accelerate(100);
    c0.accelerate(150);

    std::cout << c1 << "\n" << c0;

    c1.start();
    c1.accelerate(70);

    std::cout << c1 << "\n" << c0;

    c0.stop();
    c1.stop();

    std::cout << c1 << "\n" << c0;

    return 0;
}

