#include <iostream>

#include "Amphibia.hpp"

int main(int argc, char const *argv[])
{
    Amphibia frog("Kirakos", 5, "Yerevan lake", "Yerevan mall");
    frog.speak();
    frog.showAbilities();

    frog("Martiros");
    frog("Bardughimeos");

    return 0;
}

