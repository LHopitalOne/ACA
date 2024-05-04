#include <iostream>
#include <string>
#include <algorithm>

#include "Drivable.hpp"

#ifndef CAR_HPP

class Engine
{
private:
    float mCapacity;
    uint mNPistons;
public:
    Engine() = default;
    Engine(const Engine& other)
        : mCapacity(other.mCapacity),
          mNPistons(other.mNPistons) {}
    Engine(float capacity, uint pistons)
        : mCapacity(capacity),
          mNPistons(pistons) {}

    float capacity() const
    {
        return mCapacity;
    }

    uint numPistons() const
    {
        return mNPistons;
    }

    friend std::ostream& operator<<(std::ostream& o, const Engine& e)
    {
        o << e.mNPistons << "-Pistons" << " " << e.mCapacity << " L " << "Engine";

        return o;
    }
};

class Color
{
private:
    uint r;
    uint g;
    uint b;

public:
    Color() = default;
    Color(const Color& other)
        : r(other.r),
          g(other.g),
          b(other.b) {}
    Color(uint _r, uint _g, uint _b)
        : r(_r),
          g(_g),
          b(_b) {}

    uint red() const
    {
        return r;
    }
    
    uint green() const
    {
        return g;
    }
    
    uint blue() const
    {
        return b;
    }

    friend std::ostream& operator<<(std::ostream& o, const Color& c)
    {
        o << "rgb(" << c.r << ", " << c.g << ", " << c.b << ") Color";

        return o;
    }
};

class Car : public Drivable {
private:
    std::string mManufacturer;
    std::string mModel;
    uint mDate;
    Engine mEngine;
    Color mColor;
    uint speed;

public:
    Car() : speed(0) {}
    Car(const Car& other)
        : mManufacturer(other.mManufacturer),
          mModel(other.mModel),
          mDate(other.mDate),
          mEngine(other.mEngine),
          mColor(other.mColor),
          speed(0) {}
    Car(std::string manufacturer, std::string model, uint date, Engine engine, Color color)
        : mManufacturer(manufacturer),
          mModel(model),
          mDate(date),
          mEngine(engine),
          mColor(color),
          speed(0) {}

    void start() override
    {
        std::cout << mManufacturer << " " << mModel << " started" << std::endl;
    }

    void stop() override {
        speed = 0;
        std::cout << mManufacturer << " " << mModel << " stopped" << std::endl;
    }

    void accelerate(uint pace) override
    {
        speed += pace;
    }

    void brake(uint pace) override
    {
        speed = std::max((uint)0, speed - pace);
    }

    friend std::ostream& operator<<(std::ostream& o, const Car& c)
    {
        o << c.mManufacturer << " " << c.mModel << ", Year: " << c.mDate << ", " << c.mColor << ", " << c.mEngine << ", Current Speed: " << c.speed << " km/h";
        return o;
    }
};

#endif // CAR_HPP