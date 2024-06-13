#include <map>
#include <string>
#include <iostream>
#include <initializer_list>

std::string digitToLiteral(int digit)
{
    std::map<int, std::string> digitMap =
    {
        {0, "zero"},
        {1, "one"},
        {2, "two"},
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"}
    };

    if (digitMap.find(digit) != digitMap.end())
        return digitMap[digit];
    return "Invalid digit";
}

int main()
{
    std::initializer_list<int> digits = {4, 7, 1, 8, 3, 9, 2, 0, 5, 6};
    for (auto& i : digits)
        std::cout << i << " is: " << digitToLiteral(i) << std::endl;

    return 0;
}
