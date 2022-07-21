#ifndef NORENT_H
#define NORENT_H
#include <iostream>
// an error class to indicate that rent cannot be paid
class NoRent
{
    int rent; // the rent that cannot be paid
public:
    NoRent(int rent)
    {
        this->rent = rent;
    }
};

class NotOwner
{
};

class NotMortgaged
{
};

class IllegalMove
{
};

#endif // NORENT_H
