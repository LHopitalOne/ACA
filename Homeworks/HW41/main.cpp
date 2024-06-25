#include <vector>
#include <iostream>
#include <functional>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    os << "{ ";

    std::string out = "";
    for (const T& el : vec)
        out += std::to_string(el) + ", ";
    out.erase(out.size() - 2, out.size());
    os << out;

    os << " }";

    return os;
}

int main(int argc, char const *argv[])
{
    std::vector<int> vec;
    for (size_t i = 1; i < 101; i++)
        vec.push_back(i);

    std::cout << vec << std::endl;

    std::cout << "\n\n----------------------------\n\n";

    auto it = std::remove_if(vec.begin(), vec.end(), [](int n){if(n<2)return true; for(int i = 2; i * i <= n; i++){if(!(n % i))return true;} return false;});
    vec.erase(it, vec.end());
    std::cout << vec << std::endl;

    return 0;
}
