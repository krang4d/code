#pragma once
#include "Shape.h"
class Line :
	public Shape
{
public:
	Line(const Point &, const Point &);
	virtual ~Line();
	virtual void Draw(HDC &hdc)const;

private:
	Point a, b;
};

