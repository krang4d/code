#include<iostream>
#include<fstream>
#include"String.h"

using namespace std;

int main()
{
    String a("Hello, world!");
    cout << "String a: \""; a.Print();
    cout << "\", Len=" << a.Len() << endl;

    String b = a;
    cout << "String b: \""; b.Print();
    cout << "\", Len=" << b.Len() << endl;

    b = a;		//b.operator=(a);
    cout << "String b: \""; b.Print();
    cout << "\", Len=" << b.Len() << endl;

    b = b;		//самоприсваивание
    cout << "String b: \""; b.Print();
    cout << "\", Len=" << b.Len() << endl;

    a += b;
    cout << "String a: \""; a.Print();
    cout << "\", Len=" << a.Len() << endl;

    a = "Bruce Lee ";	//a.operator=(String("Bruce Lee "))
    a += "Hi! Hi!";
    cout << "String a: \""; a.Print();
    cout << "\", Len=" << a.Len() << endl;

    a = a + b;
    cout << "String a: \""; a.Print();
    cout << "\", Len=" << a.Len() << endl;
    a = a + "Bruce Lee ";
    cout << "String a: \""; a.Print();
    cout << "\", Len=" << a.Len() << endl;
    a = "Bruce Lee " + b;
    cout << "String a: \""; a.Print();
    cout << "\", Len=" << a.Len() << endl;

    String *p = new String("Good bye!");
    cout << "String in heap: \""; p->Print();
    cout << "\", Len=" << p->Len() << endl;
    delete p;

    a[0] = 'h';
    cout << "a[0] = " << a[0] << endl;
    b[100] = '@';
    cout << "a[100] = " << b[100] << endl;

    cout << (a==b) << endl;
    cout << (a!=b) << endl;
    cout << (a>b) << endl;

    cout << "Test << :" << a << endl;

    cout << "Enter your name: ";
    cin >> a;
    cout << "Hello " << a << endl;

    ofstream file("Test2.txt");
    file << b << endl << a <<endl;
    file.close();

    return 0;
    //system("pause");
}
