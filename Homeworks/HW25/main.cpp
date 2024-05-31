#include <iostream>

constexpr int fib(int N)
{
    int f0 = 1;
    int f1 = 1;
    
    int f = 1;
    for (size_t i = 0; i < N - 2; i++)
    {
        f = f0 + f1;
        f0 =  f1;
        f1 = f;
    }

    return f;
}

int main(int argc, char const *argv[])
{
    constexpr int N = 10;
    
    std::cout << fib(N);
    
    return 0;
}
