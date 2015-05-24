#include <iostream>
#include "Point.h"
#include "Pixel.h"
using namespace std;

//Liskov
// 7 урок 1:32

void test(Point *p)
{
    cout << "test(Point *p): ";
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
    //q->Print(); cout << endl;

    Point pt(11,12);
    test(&pt);
    test(&a);

    cout << "-------------------------" << endl;
    cout << "Полиморфизм" << endl;
    cout << "-------------------------" << endl;

    Point *arr[] = {&pt, &a, &b, &c};
    const int n = sizeof arr / sizeof *arr;

    for (int i=0 ; i<n; ++i)
    {   arr[i]->Print(); cout <<endl; }
    for (int i=0 ; i<n; ++i)
    {   arr[i]->Move(10,20); cout <<endl; }
    for (int i=0 ; i<n; ++i)
    {   arr[i]->Print(); cout <<endl; }

    cout << "Pixel a: " << a << endl;


    return 0;
}

