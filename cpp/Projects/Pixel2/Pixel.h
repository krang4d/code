#ifndef PIXEL_H
#define PIXEL_H
#include "Point.h"

class Pixel : public Point  // ... is a ...
{
public:
    enum Color {black, blue, green, red=4, yellow=15, white};
    Pixel(int =0, int =0, const Color& =black);
    Pixel(const Point & , const Color& =black);
    Pixel(const Pixel & );
    ~Pixel();

    const Color & GetColor()const;
    void SetColor(const Color &);

    void Print() const;

private:
    Color c;
};

#endif // PIXEL_H
