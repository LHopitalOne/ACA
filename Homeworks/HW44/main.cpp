#include <iostream>
#include "unique_ptr.hpp"

class Test
{
public:
    Test() { std::cout << "Test object created.\n"; }
    ~Test() { std::cout << "Test object destroyed.\n"; }
    void sayHello() { std::cout << "Hello from Test object.\n"; }
};

int main()
{
    {
        unique_ptr<Test> ptr(new Test);
        ptr->sayHello();
    }
    
    std::cout << "Exiting main.\n";
    return 0;
}
