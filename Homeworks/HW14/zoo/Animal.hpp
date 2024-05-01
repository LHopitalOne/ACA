#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
    float weight;
    uint age;

public:
    Animal() = default;
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
