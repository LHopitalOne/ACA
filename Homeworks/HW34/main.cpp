#include <iostream>
#include "list.hpp"

int main(int argc, char const *argv[])
{
    l::list<int> lst1;
    std::cout << "Default constructor: " << lst1 << "\n";

    // Test constructor with size
    l::list<int> lst2(5);
    std::cout << "Constructor with size (5): " << lst2 << "\n";

    // Test constructor with size and value
    l::list<int> lst3(5, 10);
    std::cout << "Constructor with size (5) and value (10): " << lst3 << "\n";

    // Test initializer l::list constructor
    l::list<int> lst4 = {5, 3, 1, 4, 2};
    std::cout << "Initializer l::list constructor: " << lst4 << "\n";

    // Test move constructor
    l::list<int> lst5 = std::move(lst4);
    std::cout << "Move constructor: " << lst5 << "\n";
    std::cout << "Original l::list after move: " << lst4 << "\n";

    // Test copy constructor
    l::list<int> lst6(lst5);
    std::cout << "Copy constructor: " << lst6 << "\n";

    // Test move assignment operator
    lst1 = std::move(lst5);
    std::cout << "Move assignment operator: " << lst1 << "\n";
    std::cout << "Original l::list after move: " << lst5 << "\n";

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

    // Test quickSort
    l::quickSort(lst2, 0, lst2.size() - 1);
    std::cout << "After QuickSort: " << lst2 << "\n";

    lst2 = l::list<int>{3, -5, 6, -40, 1};

    // Test bubbleSort
    l::bubbleSort(lst2);
    std::cout << "After BubbleSort: " << lst2 << "\n";

    lst2 = l::list<int>{3, -5, 6, -40, 1};
    
    // Test mergeSort
    l::mergeSort(lst2, 0, lst2.size() - 1);
    std::cout << "After MergeSort: " << lst2 << "\n";

    // Test iterator
    std::cout << "Input iterator: " << lst2 << "\n";
    for (auto& i : lst2)
    {
        std::cout << i << " ";
    }
    
    return 0;
}
