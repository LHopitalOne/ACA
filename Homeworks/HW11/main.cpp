#include <iostream>
#include <string>

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

class Car
{
private:
    std::string mManufacturer;
    std::string mModel;
    uint mDate;
    Engine mEngine;
    Color mColor;
    
public:
    Car() = default;
    Car(const Car& other)
        : mManufacturer(other.mManufacturer),
          mModel(other.mModel),
          mDate(other.mDate),
          mEngine(other.mEngine),
          mColor(other.mColor) {}
    Car(std::string manufacturer, std::string model, uint date, Engine engine, Color color)
        : mManufacturer(manufacturer),
          mModel(model),
          mDate(date),
          mEngine(engine),
          mColor(color) {}

    std::string name() const
    {
        return mModel;
    }

    friend std::ostream& operator<<(std::ostream& o, const Car& c)
    {
        o << c.mManufacturer << " model " << c.mModel << " year " << c.mDate << " " << c.mColor << " " << c.mEngine << std::endl;

        return o;
    }
};

class Parking
{
protected:
    uint mRows;
    uint mCols;

    Car** mLots;

public:
    Parking()
        : mRows(0),
          mCols(0),
          mLots(nullptr) {}
    
    Parking(const Parking& other) 
        : mRows(other.mRows),
          mCols(other.mCols),
          mLots(other.mLots) {}

    Parking(uint rows, uint cols)
        : mRows(rows),
          mCols(cols)
    {
        mLots = new Car*[rows];
        
        for (uint i = 0; i < rows; i++)
            mLots[i] = new Car[cols];
    }

    Car* operator[](uint index) const
    {
        return mLots[index];
    }

    friend std::ostream& operator<<(std::ostream& o, const Parking& p)
    {
        for (uint i = 0; i < p.mRows; i++)
        {
            for (uint j = 0; j < p.mCols; j++)
                o << " | " << p.mLots[i][j].name() << " | ";
            o << "\n";
        }

        return o;
    }

    ~Parking()
    {
        for (uint i = 0; i < mRows; i++)
            delete[] mLots[i];

        delete[] mLots;
    }
};

int main() {
    Car c0("Mersedes-Benz", "SL-Roadster", 2023, Engine(4.7, 8), Color(252, 186, 3));
    Car c1("Porsche", "911", 2023, Engine(3, 6), Color(97, 124, 88));
    
    Parking parking(2, 2);
    parking[0][0] = c0;
    parking[0][1] = c1;
    parking[1][0] = c1;
    parking[1][1] = c0;

    std::cout << parking << std::endl;
    std::cout << parking[1][0] << std::endl;

    return 0;
}
