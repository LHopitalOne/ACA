#include <iostream>

#include "./zoo/Cat.hpp"
#include "./zoo/Cow.hpp"
#include "./zoo/Dog.hpp"
#include "./zoo/Lion.hpp"
#include "./zoo/Pig.hpp"

void testConstructors() {
    Cat cat1;
    Cat cat2(5.5, 2);
    Cat cat3(cat2);
    Cat cat4(std::move(cat3));

    Dog dog1;
    Dog dog2(10.2, 3);
    Dog dog3(dog2);
    Dog dog4(std::move(dog3));

    Cow cow1;
    Cow cow2(15.0, 4);
    Cow cow3(cow2);
    Cow cow4(std::move(cow3));

    Lion lion1;
    Lion lion2(20.0, 5);
    Lion lion3(lion2);
    Lion lion4(std::move(lion3));

    Pig pig1;
    Pig pig2(8.5, 1);
    Pig pig3(pig2);
    Pig pig4(std::move(pig3));
}

void testComparisonOperators() {
    Cat cat1(4.0, 2);
    Cat cat2(5.0, 3);

    Dog dog1(8.0, 4);
    Dog dog2(7.5, 2);

    std::cout << "Cat1 < Cat2: " << (cat1 < cat2) << std::endl;
    std::cout << "Cat1 > Cat2: " << (cat1 > cat2) << std::endl;
    std::cout << "Cat1 == Cat2: " << (cat1 == cat2) << std::endl;

    std::cout << "Dog1 < Dog2: " << (dog1 < dog2) << std::endl;
    std::cout << "Dog1 > Dog2: " << (dog1 > dog2) << std::endl;
    std::cout << "Dog1 == Dog2: " << (dog1 == dog2) << std::endl;

    Cow cow1(14.0, 3);
    Cow cow2(16.0, 4);

    Lion lion1(18.0, 5);
    Lion lion2(20.0, 6);

    Pig pig1(6.5, 2);
    Pig pig2(7.0, 3);

    std::cout << "Cow1 < Cow2: " << (cow1 < cow2) << std::endl;
    std::cout << "Lion1 < Lion2: " << (lion1 < lion2) << std::endl;
    std::cout << "Pig1 < Pig2: " << (pig1 < pig2) << std::endl;

    std::cout << "Cat1 < Dog1: " << (cat1 < dog1) << std::endl;
    std::cout << "Lion1 > Pig1: " << (lion1 > pig1) << std::endl;
    std::cout << "Cow2 == Lion2: " << (cow2 == lion2) << std::endl;
}

int main() {
    testConstructors();
    testComparisonOperators();

    return 0;
}
