#include <vector>
#include <iostream>

#include "parser.hpp"
#include "freader.hpp"

int main()
{
    fr::freader reader("./input.txt");
    
    std::vector<int> integers;
    std::vector<float> floats;
    std::vector<std::string> strings;

    parse::parser& P = parse::parser::init();

    while (!reader.eof())
    {
        std::string line = reader.getline();

        auto rendered = P.render(line);

        if (rendered.type() == parse::__BasicT::__INTEGER)
            integers.push_back(rendered.get<int>());
        else if (rendered.type() == parse::__BasicT::__FLOAT)
            floats.push_back(rendered.get<float>());
        else
            strings.push_back(rendered.get<std::string>());
    }

    std::cout << "integers: \n";
    for (auto& i : integers)
        std::cout << i << " ";
    std::cout << std::endl;
    
    std::cout << "floats: \n";
    for (auto& i : floats)
        std::cout << i << " ";
    std::cout << std::endl;
    
    std::cout << "strings: \n";
    for (auto& i : strings)
        std::cout << i << " ";
    std::cout << std::endl;
    
    return 0;
}
