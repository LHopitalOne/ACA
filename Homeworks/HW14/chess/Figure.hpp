enum Color
{
    BLACK = 0x0,
    WHITE = 0x1
}

struct Position
{
    uint x;
    uint y;
}

class Figure
{
private:
    Color mColor;
    Position mPosition;
public:
    Figure() = default;
    Figure(const Figure& other) = default;

    Position getPosition() const
    {
        return mPosition;
    }

    Color getColor() const
    {
        return mColor;
    }

    virtual ~Figure() {};
};
