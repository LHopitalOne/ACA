#include "file.hpp"

#include "utils.hpp"

file* file::instance = nullptr;

file::file(){}
file::~file()
{
    // instance->_f.close();

    // delete instance;
    _f.close();
    
    instance = nullptr;
}

char file::getChar()
{
    return _f.peek();
}

std::string file::getline()
{
    char buf[MAX_LEN] = "";
    std::size_t len = 0;
    while (_f.peek() != '\n' && _f.peek() != EOF && len < MAX_LEN)     
        buf[len++] = _f.get();
    
    _f.get();
    
    if (_f.peek() == '\n')
        _f.get();

    return std::string(buf);
}

Matrix file::getMatrix()
{
    int r, c;
    auto _stringDims = split(getline(), " ");
    
    r = std::stoi(_stringDims[0]);
    c = std::stoi(_stringDims[1]);

    Matrix mat(r, c);

    int i = 0, j = 0;
    while(r--)
    {
        auto _stringValues = split(getline(), " ");
        
        int temp = c;
        while (temp)
        {
            mat[i][j] = std::stoi(_stringValues[j]);
            
            j++;
            temp--;
        }
        i++;
        j = 0;
        temp = c;
    }

    return mat;
}

void file::putMatrix(Matrix _mat)
{
    auto dim = _mat.dim();
    
    int r = dim.first;
    int c = dim.second;

    putline(std::to_string(r) + " " + std::to_string(c));

    int i = 0, j = 0;
    while(r--)
    {
        std::string line = "";
        line += std::to_string(_mat[i][j++]);

        int temp = c - 1;
        while (temp)
        {
            line += " " + std::to_string(_mat[i][j++]);
            temp--;
        }
        i++;
        j = 0;
        // temp = c;

        putline(line);
    }
    
}

bool file::eof() const
{
    return _f.eof();
}
