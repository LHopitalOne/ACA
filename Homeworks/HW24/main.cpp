#include <iostream>
#include "vector.hpp"

int main() {
    vector<int> v1;
    std::cout << "Default constructor test: Size = " << v1.size() << ", Capacity = " << v1.capacity() << "\n";

    vector<int> v2(5);
    std::cout << "Constructor with capacity test: Size = " << v2.size() << ", Capacity = " << v2.capacity() << "\n";

    vector<int> v3(5, 10);
    std::cout << "Constructor with capacity and value test: Size = " << v3.size() << ", Capacity = " << v3.capacity() << "\n";
    std::cout << "Values: ";
    for (std::size_t i = 0; i < v3.size(); ++i)
    {
        std::cout << v3[i] << " ";
    }
    std::cout << "\n";

    v3.push_back(20);
    std::cout << "After push_back(20): Size = " << v3.size() << ", Capacity = " << v3.capacity() << "\n";
    std::cout << "Values: ";
    for (std::size_t i = 0; i < v3.size(); ++i)
    {
        std::cout << v3[i] << " ";
    }
    std::cout << "\n";

    v3.pop_back();
    std::cout << "After pop_back: Size = " << v3.size() << ", Capacity = " << v3.capacity() << "\n";
    std::cout << "Values: ";
    for (std::size_t i = 0; i < v3.size(); ++i)
    {
        std::cout << v3[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Is v1 empty? " << (v1.isEmpty() ? "Yes" : "No") << "\n";

    vector<int> v4(v3);
    std::cout << "Copy constructor test: Size = " << v4.size() << ", Capacity = " << v4.capacity() << "\n";
    std::cout << "Values: ";
    for (std::size_t i = 0; i < v4.size(); ++i)
    {
        std::cout << v4[i] << " ";
    }
    std::cout << "\n";

    vector<int> v5(std::move(v3));
    std::cout << "Move constructor test: Size = " << v5.size() << ", Capacity = " << v5.capacity() << "\n";
    std::cout << "Values: ";
    for (std::size_t i = 0; i < v5.size(); ++i)
    {
        std::cout << v5[i] << " ";
    }
    std::cout << "\n";
    
    v1 = v2;
    std::cout << "Copy assignment test: Size = " << v1.size() << ", Capacity = " << v1.capacity() << "\n";

    v2 = std::move(v5);
    std::cout << "Move assignment test: Size = " << v2.size() << ", Capacity = " << v2.capacity() << "\n";

    v1.pop_back();

    return 0;
}
