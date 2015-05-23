#include<iostream>
#include "Pixel.h"

using namespace std;

int Pixel::k = 0;

Pixel::Pixel(int x, int y, const Color &clr)
    : p(x,y), c(clr)
{ ++k; }

Pixel::Pixel(const Point &pt , const Color &clr)
    : p(pt), c(clr)
{ ++k; }

Pixel::Pixel(const Pixel &px)
    : p(px.p), c(px.c)
{ ++k; }

Pixel::~Pixel()
{ --k; }

const Pixel::Color & Pixel::GetColor()const
{
    return c;
}
void Pixel::SetColor(const Color & clr)
{
    c = clr;
}

void Pixel::Move(int delta_x, int delta_y)
{
    p.Move(delta_x, delta_y);
}

double Pixel::Dist(const Pixel &px) const
{
    return p.qDist(px.p);
}

void Pixel::Print()const
{
    p.Print();
    cout << ':' << c;
}


