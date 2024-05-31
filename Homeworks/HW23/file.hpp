#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include <fstream>
#include <iostream>

#include "Matrix.hpp"

#define MAX_LEN 100

class file
{
private:
    file();

    std::fstream _f;
    std::string _fname;

    static file* instance;
public:
    template<typename _StringT>
    static file* init(_StringT _filename)
    {
        if (!instance)
        {
            instance = new file;
            instance->_f.open(_filename, std::ios_base::in);
            instance->_fname = _filename;
        }
        return instance;
    }

    ~file();

    char getChar();
    std::string getline();
    Matrix getMatrix();

    bool eof() const;

    template<typename _CharT>
    void putChar(_CharT _c);
    
    template<typename _StringT>
    void putline(_StringT _str);
    
    void putMatrix(Matrix _mat);
};


template<typename _CharT>
void file::putChar(_CharT _c)
{
    _f.close();
    _f.open(_fname, std::ios_base::out | std::ios_base::app);
    _f.put(_c);
    _f.close();
    _f.open(_fname, std::ios_base::in);
}

template<typename _StringT>
void file::putline(_StringT str)
{
    _f.close();
    _f.open(_fname, std::ios_base::out | std::ios_base::app);
    _f << str << "\n";
    _f.close();
    _f.open(_fname, std::ios_base::in);
}
#endif // FILE_HPP
