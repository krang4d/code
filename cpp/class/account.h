#ifndef ACCOUNT_H
#define ACCOUNT_H

namespace Program
{
    typedef unsigned int ui;
    class Account
    {
    private:
        char* ID;
        char* Name;
        ui Balance;
        ui Max;
    public:
        Account();
        Account(char* ID = "No000", char* Name = " ", ui Balance = 0);


        void setID(char*);
        char* getID() const;
        void setName(char*);
        char* getName() const;
        void setBalance(ui);
        ui getBalance() const;
        void AddBalance(ui);
        void TakeMoney(ui);
        Account MAX(Account&);

        ~Account();
    };
}
#endif // ACCOUNT_H
