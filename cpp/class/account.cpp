#include "account.h"

namespace Program
{
    Account::Account()
    {
        ID = "No001";
        Name = "Pasha";
        Balance = 1;
        Max = 1000000;
    }

    Account::Account(char* id, char* name, ui balance)
    {
        ID = id;
        Name = name;
        Balance = balance;
        Max = 1000000;
    }

    Account::~Account()
    {

    }

    void Account::setID(char* id)
    {
        ID = id;
    }

    char* Account::getID() const
    {
        return ID;
    }

    void Account::setName(char* name)
    {
        Name = name;
    }

    char* Account::getName() const
    {
        return Name;
    }

    void Account::setBalance(ui balance)
    {
        if (balance < Max)
            Balance = balance;
    }

    ui Account::getBalance() const
    {
        return Balance;
    }

    void Account::AddBalance(ui add)
    {
        if (Balance + add <= Max)
            Balance += add;
    }

    void Account::TakeMoney(ui tm)
    {
        if (Balance >= tm)
            Balance -= tm;
    }

    Account Account::MAX(Account & obj)
    {
        if (obj.getBalance() > Balance)
            return obj;
        else return *this;
    }

}
