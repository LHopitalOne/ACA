#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <utility>

class Animal
{
protected:
    float weight;
    uint age;

public:
    Animal() = default;
    Animal(const Animal& other) = default;
    
    Animal(Animal&& other)
    {
        weight = std::exchange(other.weight, 0);
        age = std::exchange(other.age, 0);
    }

    Animal(float w, uint a) : weight(w), age(a) {}
    
    Animal& operator=(Animal&& other)
    {
        weight = std::exchange(other.weight, 0);
        age = std::exchange(other.age, 0);

        return *this;
    }

    virtual void voice() const = 0;
    virtual ~Animal() = default;

    virtual void printInfo()
    {
        std::cout << "says ";
        voice();
        std::cout << "weights " << weight << " and it " << age << " years old" << std::endl;
    }
};

#endif // ANIMAL_HPP
