#pragma once

class Shape
{
public:
	virtual void Draw(HDC &hdc)const = 0 {}
	virtual ~Shape() {}
};

struct Point
{
	int x, y;
	Point(int _x=0, int _y=0) :x(_x), y(_y)
	{}
};

