#include "stdafx.h"
#include "Line.h"


Line::Line(const Point &_a, const Point &_b)
:a(_a), b(_b)
{}


Line::~Line()
{}

void Line::Draw(HDC &hdc)const
{
	MoveToEx(hdc, a.x, a.y, 0);
	LineTo(hdc, b.x, b.y);
}
