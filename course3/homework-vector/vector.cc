#include <iostream>
#include <cassert>

class Vector
{
public:

    Vector() : _x(0), _y(0){}
    Vector(int x, int y) : _x(x), _y(y){}

    int GetX() const
    {
        return _x;
    }

    int GetY() const
    {
        return _y;
    }

    void SetX(int x)
    {
        _x = x;
    }

    void SetY(int y)
    {
        _y = y;
    }

    bool operator==(const Vector other) const
    {
        return _x == other.GetX() && _y == other.GetY();
    }

    bool operator!=(const Vector other) const
    {
        return _x != other.GetX() || _y != other.GetY();
        //return !(this==other);
    }

    Vector operator+(const Vector other) const
    {
        return Vector(_x + other.GetX(), _y + other.GetY());
    }

private:
    int _x = 0;
    int _y = 0;
};

std::ostream& operator<<(std::ostream& stream, const Vector& vector)
{
    stream << "(" << vector.GetX() << "," << vector.GetY() << ")";
    return stream;
}

int main()
{
    // this all should compile and work
    
    Vector v1;
    Vector v2(5, 6);
    
    assert(v2.GetX() == 5);
    assert(v2.GetY() == 6);
    
    v1 = v2;
    assert(v1.GetX() == 5);
    assert(v1.GetY() == 6);
    assert(v1 == v2);
    
    v1.SetY(7);
    assert(v1.GetY() == 7);
    assert(v1 != v2);
    
    Vector v3 = v1 + v2;
    assert(v3.GetX() == 10);
    assert(v3.GetY() == 13);
    
    std::cout << v1 << " + " << v2 << " = " << v3 << std::endl;
}
