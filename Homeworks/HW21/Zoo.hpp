#ifndef ZOO_HPP
#define ZOO_HPP

#include <cstdlib>

#include "./zoo/Animal.hpp"

class Zoo
{
private:

    static Zoo* instance;
    
    Animal** data = nullptr;
    std::size_t size = 0;
    std::size_t capacity = 0;

    Zoo() {};
    ~Zoo()
    {
        for (size_t i = 0; i < instance->capacity; i++)
            delete instance->data[i];
        delete[] instance->data;
    }

public:
    Zoo(const Zoo& other) = delete;
    Zoo& operator=(const Zoo& other) = delete;

    static Zoo& init(std::size_t n)
    {
        if (!instance)
        {
            instance = new Zoo();
            
            instance->capacity = n;
            instance->data = new Animal*[instance->capacity];
        }
        
        return *instance;
    }

    Animal*& get(std::size_t index) const
    {
        return instance->data[index];
    }

    void push_back(Animal* animal)
    {
        if (instance->size + 1 < instance->capacity)
            instance->data[instance->size++] = animal;
        else
        {
            instance->capacity *= 2;
            Animal** temp = new Animal*[instance->capacity];
            
            for (size_t i = 0; i < instance->size; i++)
                temp[i] = instance->data[i];
        
            temp[instance->size++] = animal;
            instance->data = temp;
        }
    }
};

Zoo* Zoo::instance = nullptr;

#endif // ZOO_HPP
