#ifndef FREADER_HPP
#define FREADER_HPP

#include <string>
#include <fstream>
#include <iostream>

#define MAX_LEN 100

namespace fr
{
    template<typename _StringT>
    class freader
    {
    private:
        std::ifstream is;

    public:
        freader(_StringT _filename);
        ~freader();

        bool eof() const;
        char getChar() const;
        std::string getline();
    };

    template<typename _StringT>
    freader<_StringT>::freader(_StringT _filename)
    {
        is = std::ifstream(_filename, std::ios_base::in);
    }

    template<typename _StringT>
    freader<_StringT>::~freader()
    {
        is.close();
    }

    template<typename _StringT>
    bool freader<_StringT>::eof() const
    {
        return is.eof();
    }

    template<typename _StringT>
    std::string freader<_StringT>::getline()
    {
        char buf[MAX_LEN] = "";
        std::size_t len = 0;
        while (is.peek() != '\n' && is.peek() != EOF && len < MAX_LEN)     
            buf[len++] = is.get();
        
        is.get();
        
        if (is.peek() == '\n')
            is.get();

        return std::string(buf);
    }

    template<typename _StringT> freader(_StringT) -> freader<_StringT>;
}

#endif // FREADER_HPP
