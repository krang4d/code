//Использование классов
#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
	system("color f0");
	Point a;
	a.SetX(10);
	a.SetY(20);
	a.Print();
	cout<<endl;
	a.Move(5, 10);
	a.Print();
	cout<<endl;
	system("pause");
}