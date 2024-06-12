#include <list>
#include <vector>
#include <iostream>

bool isPrime(int n)
{
    if (n < 2) return false;
    else if (n < 4) return true;

    for (size_t i = 2; i * i <= n; i++)
        if (!(n % i))
            return false;
    
    return true;
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec;
    for (size_t i = 0; i < 100; i++)
        vec.push_back(i);
    
    for (auto it = vec.begin(); it != vec.end();)
    {
        if (isPrime(*it))
        {
            it = vec.erase(it);
        }
        else
        {
            it++;
        }
    }

    for (auto it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << " ";

    std::cout << "\n\n--------------------------------\n\n";

    std::list<int> lst;
    float avg = 0;
    for (size_t i = 0; i < 100; i++)
    {
        lst.push_back(i);
        avg += i;
    }
    avg /= 100;

    for (auto it = lst.begin(); it != lst.end();)
    {
        if (*it < avg)
        {
            it = lst.erase(it);
        }
        else
        {
            it++;
        }
    }
    
    for (auto it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << " ";

    return 0;
}

