#pragma once
#include "Shape.h"
class Squer :
	public Shape
{
public:
	Squer(const Point &, const Point &);
	virtual ~Squer();
	virtual void Draw(HDC &hdc)const;

private:
	Point a, c;
};

