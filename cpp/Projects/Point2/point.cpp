#include <iostream>
#include"point.h"

using namespace std;


Point::Point(const Point &other)
: x(other.x), y(other.y)    //список инициализации
{
//  x = other.x;
//  y = other.y;
//  для отладки
    cout << "Point(const Point &other)" << ":" ; Print(); cout << endl;
}

Point::Point(int _x, int _y)
{
    x = _x;     //здесь следовало бы использовать set методы
    y = _y;     //методы set ...
    //для отладки
    cout << "Point(int, int)" << ":" ; Print(); cout << endl;
}

Point::Point(int _x)
{
    x = _x;     //здесь следовало бы использовать set методы
    y = 0;     //методы set ...
    //для отладки
    cout << "Point(int)" << ":" ; Print(); cout << endl;
}

Point::Point()
: x(0), y(0)
{
//  x = y = 0;
    //для отладки
    cout << "Point()" << ":" ; Print(); cout << endl;
}

void Point::Print() const
{
        cout<<"("<<x<<", "<<y<<")";
}

Point::~Point()
{
    //для отладки
    cout << "~Point()" << ":" ; Print(); cout << endl;
}



