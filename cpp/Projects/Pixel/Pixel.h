#ifndef PIXEL_H
#define PIXEL_H
#include "Point.h"

class Pixel
{
public:
    enum Color {black, blue, green, red=4, yellow=15, white};
    Pixel(int =0, int =0, const Color& =black);
    Pixel(const Point & , const Color& =black);
    Pixel(const Pixel & );
    ~Pixel();

    const Color & GetColor()const;
    void SetColor(const Color &);

    void Move(int delta_x, int delta_y);
    double Dist(const Pixel &)const;

    void Print()const;

    static int GetK() { return k; }

private:
    Point p;
    Color c;
    static int k;
};

#endif // PIXEL_H
