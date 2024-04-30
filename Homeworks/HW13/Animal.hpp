#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
public:
    Animal() = default;
    virtual void voice() const = 0;
    virtual ~Animal() = default;
};

#endif // ANIMAL_HPP
