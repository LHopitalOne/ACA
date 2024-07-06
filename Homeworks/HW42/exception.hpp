#include <string>
#include <exception>

class exception : public std::exception
{
private:
    std::string msg;
public:
    exception(std::string message)
    {
        msg = message;
    }
    
    const char* what() const noexcept override
    {
        return msg.c_str();
    }
};
