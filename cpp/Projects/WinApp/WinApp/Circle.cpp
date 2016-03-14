#include "stdafx.h"
#include "Circle.h"

Circle::Circle(const Point &_c, int _r) :c(_c), r(_r)
{}

Circle::~Circle()
{}

void Circle::Draw(HDC &hdc)const
{
	Ellipse(hdc, c.x - r, c.y - r, c.x + r, c.y + r);
}

