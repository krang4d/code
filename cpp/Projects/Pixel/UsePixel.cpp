#include <iostream>
#include "Point.h"
#include "Pixel.h"
using namespace std;

int main()
{
    cout << Pixel::GetK() << endl;
    {
    cout << "Урок 6. Наследование классов." << endl;
    cout << "-----------------------------" << endl;

    Pixel a(10,20, Pixel::red);
    cout << "Pixel a: "; a.Print(); cout << endl;

    cout << Pixel::GetK() << endl;

    Pixel b(Point(30,40), Pixel::blue);
    cout << "Pixel b: "; b.Print(); cout << endl;

    cout << Pixel::GetK() << endl;

    b.SetColor(Pixel::green);
    b.Move(10,20);
    cout << "Pixel b: "; b.Print(); cout << endl;

    cout << "Dist =" << a.Dist(b) <<endl;
    cout << "Color of Pixel b = " << b.GetColor() << endl;

    Pixel c = a;
    cout << "Pixel c = "; c.Print(); cout << endl;

    }
    cout << Pixel::GetK() << endl;
    return 0;
}

