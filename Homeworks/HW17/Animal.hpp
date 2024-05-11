#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
private:
    static uint count;
protected:
    std::string name;
    int age;

    virtual void sendToStream(std::ostream& os) const = 0;
public:
    Animal()
    {
        count++;
    }
    Animal(std::string n, int a) : name(n), age(a)
    {
        count++;
    }

    static uint getCount()
    {
        return count;
    }

    virtual void speak() = 0;

    friend std::ostream& operator<<(std::ostream& os, Animal& obj)
    {
        obj.sendToStream(os);
        return os;
    }

    virtual ~Animal() {};
};

uint Animal::count = 0;

#endif // ANIMAL_HPP
