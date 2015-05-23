#include <iostream>
#include "Point.h"
#include "Pixel.h"
using namespace std;

void test(Point *p)
{
    p->Print();
    p->Move(1,1);
    p->Print();
    cout << endl;
}


int main()
{
    cout << "Урок 6. Наследование классов." << endl;
    cout << "-----------------------------" << endl;

    Pixel a(10,20, Pixel::red);
    cout << "Pixel a: "; a.Print(); cout << endl;

    Pixel b(Point(30,40), Pixel::blue);
    cout << "Pixel b: "; b.Print(); cout << endl;

    b.SetColor(Pixel::green);
    b.Move(10,20);
    cout << "Pixel b: "; b.Print(); cout << endl;

    cout << "Dist =" << a.qDist(b) <<endl;
    cout << "Color of Pixel b = " << b.GetColor() << endl;

    Pixel c = a;
    cout << "Pixel c = "; c.Print(); cout << endl;

    cout << "Pixel c = "; c.Point::Print(); cout << endl;

    //---------------------------------------------------

    Point *p;
    Pixel *q = &a;
    p = q;              // **восходящее** приведение
    p = &c;             // **восходящее** приведение

    q = static_cast<Pixel *>(p);
    q->Print();

    test(c);

    return 0;
}

