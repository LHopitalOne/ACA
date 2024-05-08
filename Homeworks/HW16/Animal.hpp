#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
protected:
    std::string name;
    int age;

public:
    Animal(std::string n, int a) : name(n), age(a) {}

    virtual void speak() = 0;

    virtual ~Animal() {}
};

#endif // ANIMAL_HPP
