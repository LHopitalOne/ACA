#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

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

    return 0;
}
