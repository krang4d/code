#include <iostream>
#include "/home/krang/cpp/class/account.h"
#include "/home/krang/cpp/class/extraaccount.h"


using namespace std;
using Program::Account;

int main()
{
   /* Account a;
    a.setName("Yura");
    a.setID("N002");
    a.setBalance(1000000000);
    cout << "Hello\t" << a.getName() << "!" << endl;
    cout << "ID\t" << a.getID() << endl;
    cout << "Balance\t" << a.getBalance()<< "$" << endl;
    */

    Account a("No1", "Pasha", 1000);
    Account b("No1", "Pasha", 2000);
    Account c();

    cout << a.getBalance() << endl;
    cout << b.getBalance() << endl;
    //cout << c.getBalance() << endl;

    cout << (a.MAX(b)).getBalance() << endl;

    //ExtraAccount b;
    //cout << "\nHi\t" << b.getName() << endl;

    return 0;
}
