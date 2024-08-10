#include <iostream>

void print() {}

template<typename T, typename ... Args>
void print(const T& value, const Args&... args)
{
    std::cout << value;
    if (sizeof...(args))
        std::cout << " ";
    print(args...);
}

int main(int argc, char const *argv[])
{
    print(1, 2, 3, 4, "miban", 'a', "nother miban", nullptr);

    return 0;
}
