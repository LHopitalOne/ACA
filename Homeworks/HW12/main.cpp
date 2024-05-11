#include <iostream>
#include <string>

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

class PublicTransport : public Car
{
protected:
    uint mSeats;
    uint mPrice;
    uint mAvailableSeats;
    uint mBudget;
public:
    PublicTransport() = default;
    PublicTransport(const PublicTransport& other)
        : Car(other.mManufacturer,
              other.mModel,
              other.mDate,
              other.mEngine,
              other.mColor
              ),
          mSeats(other.mSeats),
          mPrice(other.mPrice),
          mAvailableSeats(other.mAvailableSeats),
          mBudget(other.mBudget) {}
    PublicTransport(uint seats, uint price, uint availableSeats, uint budget)
        : Car(),
          mSeats(seats),
          mPrice(price),
          mAvailableSeats(availableSeats),
          mBudget(budget) {}

    void addPassanger()
    {
        mAvailableSeats--;
        mBudget += mPrice;
    }
        
    ~PublicTransport() {}
};

class PersonalTransport : public Car
{
protected:
    uint mLicenceExiryYear;
    std::string mWeightType;
public:
    PersonalTransport() = default;
    PersonalTransport(const PersonalTransport& other)
        : Car(other.mManufacturer,
              other.mModel,
              other.mDate,
              other.mEngine,
              other.mColor
              ),
          mLicenceExiryYear(other.mLicenceExiryYear),
          mWeightType(other.mWeightType) {}

    friend std::ostream& operator<<(std::ostream& o, const PersonalTransport& c)
    {
        o << c.mManufacturer << " model " << c.mModel << " year " << c.mDate << " " << c.mColor << " " << c.mEngine << " car weight category is " << c.mWeightType << " license will expire in " << c.mLicenceExiryYear << std::endl;

        return o;
    }

    ~PersonalTransport() {}
};

class Bus : public PublicTransport
{
public:
    Bus()
        : mSeats(30),
          mPrice(300),
          mBudget(0),
          mAvailableSeats(30) {}
    Bus(const Bus& other) = default;

    friend std::ostream& operator<<(std::ostream& o, const Bus& c)
    {
        o << c.mManufacturer << " model " << c.mModel << " year " << c.mDate << " " << c.mColor << " " << c.mEngine << c.mSeats << " seats " << c.mPrice << " drams " << ", already has " << c.mBudget << " drams" << " there are " << c.mAvailableSeats << " seats available" << std::endl;

        return o;
    }

    ~Bus() {}
};

class Trolik : public PublicTransport
{
private:
    uint mNumberOfIcons; // srsly, I got no idea what else to add
public:
    Trolik()
        : PublicTransport(),
          mPrice(50),
          mSeats(50), 
          mAvailableSeats(50),
          mBudget(0),
          mNumberOfIcons(10) {}
    Trolik(const Trolik& other) = default;

    void addIcon()
    {
        mNumberOfIcons++;
    }

    friend std::ostream& operator<<(std::ostream& o, const Trolik& c)
    {
        o << c.mManufacturer << " model " << c.mModel << " year " << c.mDate << " " << c.mColor << " " << c.mEngine << c.mSeats << " seats " << c.mPrice << " drams " << ", already has " << c.mBudget << " drams" << " there are " << c.mAvailableSeats << " seats available" << " number of icons existent is " << c.mNumberOfIcons << std::endl;

        return o;
    }

    ~Trolik();
};

class Metro : public PublicTransport
{
private:
    uint mNumberOfWagons;
public:
    Metro()
        : PublicTransport(),
          mPrice(100),
          mSeats(200), 
          mAvailableSeats(200),
          mBudget(0),
          mNumberOfWagons(3) {}
    Metro(const Metro& other) = default;
    Matro(uint wagons)
        : Metro()
    {
        mNumberOfWagons = wagons;
    }

    friend std::ostream& operator<<(std::ostream& o, const Metro& c)
    {
        o << c.mManufacturer << " model " << c.mModel << " year " << c.mDate << " " << c.mColor << " " << c.mEngine << c.mSeats << " seats " << c.mPrice << " drams " << ", already has " << c.mBudget << " drams" << " there are " << c.mAvailableSeats << " seats available" << " number of wagons existent is " << c.mNumberOfWagons << std::endl;

        return o;
    }

    ~Metro();
};

class Truck : public PersonalTransport
{
public:
    Truck()
        : PersonalTransport(),
        mWeightType("heavy") {}
    Truck(const Truck& other) = default;
    ~Truck();
};

class Sedan : public PersonalTransport
{
public:
    Sedan()
        : PersonalTransport(),
        mWeightType("medium") {}
    Sedan(const Sedan& other) = default;
    ~Sedan();
};

class Coupet : public PersonalTransport
{
public:
    Coupet()
        : PersonalTransport(),
        mWeightType("light") {}
    Coupet(const Coupet& other) = default;
    ~Coupet();
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
