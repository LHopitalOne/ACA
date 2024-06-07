#include <iostream>
#include "list.hpp"

int main(int argc, char const *argv[])
{
    list::list<int> lst1;
    std::cout << "Default constructor: " << lst1 << "\n";

    // Test constructor with size
    list::list<int> lst2(5);
    std::cout << "Constructor with size (5): " << lst2 << "\n";

    // Test constructor with size and value
    list::list<int> lst3(5, 10);
    std::cout << "Constructor with size (5) and value (10): " << lst3 << "\n";

    // Test initializer list::list constructor
    list::list<int> lst4 = {1, 2, 3, 4, 5};
    std::cout << "Initializer list::list constructor: " << lst4 << "\n";

    // Test move constructor
    list::list<int> lst5 = std::move(lst4);
    std::cout << "Move constructor: " << lst5 << "\n";
    std::cout << "Original list::list after move: " << lst4 << "\n";

    // Test copy constructor
    list::list<int> lst6(lst5);
    std::cout << "Copy constructor: " << lst6 << "\n";

    // Test move assignment operator
    lst1 = std::move(lst5);
    std::cout << "Move assignment operator: " << lst1 << "\n";
    std::cout << "Original list::list after move: " << lst5 << "\n";

    // Test copy assignment operator
    lst2 = lst6;
    std::cout << "Copy assignment operator: " << lst2 << "\n";

    // Test push_back
    lst2.push_back(6);
    std::cout << "After push_back(6): " << lst2 << "\n";

    // Test pop_back
    lst2.pop_back();
    std::cout << "After pop_back: " << lst2 << "\n";

    // Test push_front
    lst2.push_front(0);
    std::cout << "After push_front(0): " << lst2 << "\n";

    // Test pop_front
    lst2.pop_front();
    std::cout << "After pop_front: " << lst2 << "\n";

    // Test insert
    lst2.insert(2, 99);
    std::cout << "After insert(2, 99): " << lst2 << "\n";

    // Test size
    std::cout << "Size: " << lst2.size() << "\n";

    // Test isEmpty
    std::cout << "Is empty: " << (lst2.isEmpty() ? "Yes" : "No") << "\n";
    
    // Test finding the cycle;
    std::cout << "Is cyclic: " << std::boolalpha << list::list<int>::cyclicList().thereIsCycle() << "\n";

    return 0;
}
