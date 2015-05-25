#include <iostream>
#include"point.h"

using namespace std;

Point test(Point q)
{
    return q;
}

int main()
{
    cout << "Вспомогательные (специальные) методы классов. Урок 3, 4.\n--------------------------------------------------------" << endl;
    Point a;
    Point b(100,200);

    Point b1 = Point(101,201);

    Point d(10);
    Point d1 = Point(11);
    Point d2 =12;
    Point c = a;

    Point *p  = new Point;
    Point *p1 = new Point(111);
    Point *p2 = new Point(111, 222);

    delete p2;
    delete p1;
    delete p;

    Point arr[4] = {Point(1,2),Point(3),4};
    //b.Print(); cout << endl;


    test(b);
    test(static_cast<Point>(777));
    //test(77.7);
    //test('7');
    //test("7");

    //cout << sizeof a << endl;
    return 0;
}

