//Определение класса Point
#ifndef POINT_H
#define POINT_H

class Point
{
private:
	int x, y;
public:
	int GetX() { return x; } //inline по умолчания
	int GetY();
	void SetX(int);
	void SetY(int);
	void Print();
	void Move(int delta_x, int delta_y);
};

inline int Point::GetY() { return y; }

#endif