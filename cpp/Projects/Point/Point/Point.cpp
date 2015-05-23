//Реализация класса
#include <iostream>
#include "Point.h"
using namespace std;

void Point::SetX(int _x)
{
	x = _x >= 0 ? _x : 0;
}

void Point::SetY(int _y)
{
	y = _y >= 0 ? _y : 0;
}

void Point::Print()
{
	cout<<"("<<GetX()<<", "<<GetY()<<")";
}

void Point::Move(int dx, int dy)
{
	SetX(dx + x);
	SetY(dy + y);
}