#include <iostream>

#include "vector.hpp"

class A
{
public:
    A(){}
    ~A()
    {
        try
        {
            throw std::string("string thrown");
        }
        catch(const std::string& e)
        {
            std::cerr << e << '\n';
        }
    }
};

unsigned int runtime_six() // Emulate runtime input
{
    return 6u;
}
 
int main()
{
    A a;

    vector<int> data = {1, 2, 4, 5, 5, 6};
 
    // Set element 1
    data.at(1) = 88;
 
    // Read element 2
    std::cout << "Element at index 2 has value " << data.at(2) << '\n';
 
    std::cout << "data size = " << data.size() << '\n';
 
    try
    {
        // Set element 6, where the index is determined at runtime
        data.at(runtime_six()) = 666;
    }
    catch (exception const& exc)
    {
        std::cout << exc.what() << '\n';
    }
 
    // Print final values
    std::cout << "data:";
    for (int elem : data)
        std::cout << ' ' << elem;
    std::cout << '\n';
}

