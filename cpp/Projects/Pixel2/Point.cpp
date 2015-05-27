#include <iostream>
#include "Point.h"
#include "math.h"

using namespace std;
//using namespace point_ns;

void Point::SetX(int _x)
{
        x = _x >= 0 ? _x : 0;
        //return this;
}

void Point::SetY(int _y)
{
        y = _y >= 0 ? _y : 0;
}

void Point::Print(std::ostream &os) const
{
        os <<"("<<GetX()<<", "<<GetY()<<")";
}

void Point::Move(int dx, int dy)
{
        SetX(dx + x);
        SetY(dy + y);
}

double Point::qDist(const Point &a) const //ссылки для эффективности
{
    return sqrt(pow((static_cast<double>(GetX())-a.GetX()),2)
               +pow((static_cast<double>(GetY())-a.GetY()),2));
}

Point::Point(int x, int y)
{
    SetX(x);
    SetY(y);
}

double fDist(const Point &a, const Point &b)
{
    return sqrt(pow(static_cast<double>(a.x-b.x),2)
               +pow(static_cast<double>(a.y-b.y),2));
}

