#pragma once
#include "Shape.h"
class Circle :
	public Shape
{
public:
	Circle(const Point&, int);
	virtual ~Circle();
	virtual void Draw(HDC &hdc)const;

private:
	Point c;
	int r;
};

