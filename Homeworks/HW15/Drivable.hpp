#include <string>

#ifndef DRIVABLE_HPP

class Drivable {
public:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void accelerate(uint pace) = 0;
    virtual void brake(uint pace) = 0;
    virtual ~Drivable() {}
};

#endif // DRIVABLE_HPP
