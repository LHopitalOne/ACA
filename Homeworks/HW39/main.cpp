#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>

#include "hash_table.hpp"

class Car
{
private:
    std::string make;
    std::string model;
    int year;
public:

    Car(const std::string& make, const std::string& model, int year)
        : make(make),
          model(model),
          year(year) {}

    bool operator==(const Car& other) const
    {
        return make == other.make && model == other.model && year == other.year;
    }

    friend struct CarHash;
    friend std::ostream& operator<<(std::ostream& os, const Car& car)
    {
        os << car.make << " " << car.model << " " << car.year;
        return os;
    }
};

struct CarHash
{
    std::size_t operator()(const Car& car) const 
    {
        return std::hash<std::string>()(car.make) ^ std::hash<std::string>()(car.model) ^ std::hash<int>()(car.year);
    }
};

int main()
{
    std::unordered_set<Car, CarHash> carSet;

    carSet.insert(Car("Toyota", "Camry", 2020));
    carSet.insert(Car("Honda", "Civic", 2019));
    carSet.insert(Car("Ford", "Mustang", 2021));

    for (auto& car : carSet)
        std::cout << car << "\n";

    std::cout << "\n-----------custom hash_table----------\n\n";

    hash_table<int, std::string, std::hash<int>> myHashTable(10);

    myHashTable.insert(1, "one");
    myHashTable.insert(2, "two");
    myHashTable.insert(3, "three");

    std::cout << "Size after insertion: " << myHashTable.size() << std::endl;
    std::cout << "Is empty: " << std::boolalpha << myHashTable.is_empty() << std::endl;

    std::string value;
    if (myHashTable.find(2, value))
        std::cout << "Found value for key 2: " << value << std::endl;
    else
        std::cout << "Key 2 not found" << std::endl;

    if (myHashTable.find(4, value))
        std::cout << "Found value for key 4: " << value << std::endl;
    else
        std::cout << "Key 4 not found" << std::endl;

    myHashTable.remove(2);
    std::cout << "Size after removing key 2: " << myHashTable.size() << std::endl;

    if (myHashTable.find(2, value))
        std::cout << "Found value for key 2: " << value << std::endl;
    else
        std::cout << "Key 2 not found" << std::endl;


    return 0;
}
