#ifndef POINT_H
#define POINT_H

class Point
{
private:
    int x, y;
public:
    int GetX() const { return x; } //inline ïî óìîë÷àíèÿ
    int GetY() const;
    void SetX(int);
    void SetY(int);
    void Print() const;
    void Move(int delta_x, int delta_y);
    double qDist(const Point &) const;
    Point(int x=0, int y=0);
    ~Point();

    friend double fDist(const Point &, const Point &);
};

inline int Point::GetY() const { return y; }

#endif // POINT_H
