#include "stdafx.h"
#include "Squer.h"


Squer::Squer(const Point &_a, const Point &_c) : a(_a), c(_c)
{
}


Squer::~Squer()
{
}

void Squer::Draw(HDC &hdc)const
{
	Rectangle(hdc, a.x, a.y, c.x, c.y);
}