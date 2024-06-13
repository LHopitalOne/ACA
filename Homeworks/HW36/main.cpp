#include <iostream>

#include "lStack.hpp"
#include "vStack.hpp"

bool isValid_vector(std::string s)
{
    vStack<char> stack;

    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
            stack.push(ch);
        else
        {
            if (stack.empty()) return false;
            char top = stack.top();
            if ((ch == ')' && top == '(') || 
                (ch == '}' && top == '{') || 
                (ch == ']' && top == '['))
                stack.pop();
            else
                return false;
        }
    }
    return stack.empty();
}

bool isValid_list(std::string s)
{
    lStack<char> stack;

    for (char ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[')
            stack.push(ch);
        else
        {
            if (stack.empty()) return false;
            char top = stack.top();
            if ((ch == ')' && top == '(') || 
                (ch == '}' && top == '{') || 
                (ch == ']' && top == '['))
                stack.pop();
            else
                return false;
        }
    }
    return stack.empty();
}

int main(int argc, char const *argv[])
{
    std::string s = "{[(()[{(()())}{[]}])]}([{])}";
    if (isValid_list(s))
        std::cout << "The string is valid." << std::endl;
    else
        std::cout << "The string is not valid." << std::endl;

    s = "{[(()[{(()())}{[]}])]}([])";
    if (isValid_list(s))
        std::cout << "The string is valid." << std::endl;
    else
        std::cout << "The string is not valid." << std::endl;

    std::cout << "\n---------------------------------------\n\n";

    s = "{[(()[{(()())}{[]}])]}([{])}";
    if (isValid_vector(s))
        std::cout << "The string is valid." << std::endl;
    else
        std::cout << "The string is not valid." << std::endl;

    s = "{[(()[{(()())}{[]}])]}([])";
    if (isValid_vector(s))
        std::cout << "The string is valid." << std::endl;
    else
        std::cout << "The string is not valid." << std::endl;

    return 0;
}
