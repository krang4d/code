#include <iostream>
#include "point.h"

using namespace std;
//using namespace point_ns;

int main()
{
        //system("color f0");
        Point a,b; //создание объекта в стеке
        a.Print(); cout<<endl;


        a.SetX(15);
        a.SetY(30);

        b.SetX(20);
        b.SetY(30);
        a.Print(); cout<<endl;
        b.Print(); cout<<endl;
        double d1 = a.qDist(b);
        double d = fDist(a, b);
        cout << "Расстояние между точками = " << d << " d1 =" << d1 << endl;


        //a.Move(5, 10);
        //a.Print(); cout<<endl;

        Point *p = new Point; //создание объекта в куче (динамической памяти)
        p->Print(); cout<<endl;

        //Здесь д.б. обработка ошибок при выделении памяти

        //p->SetX(65);
        //p->SetY(85);
        //p->Print(); cout<<endl;
        //d = a::qDist(a,b);
        //cout << d << endl;
        //delete p;


}

