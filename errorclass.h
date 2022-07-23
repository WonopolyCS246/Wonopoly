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

    int getRent()
    {
        return rent;
    }
};

class NotMortgage
{
    int amount;

public:
    NotMortgage(int amount)
    {
        this->amount = amount;
    }

    int getAmount()
    {
        return amount;
    }
};

class NoTution
{
    int amount;

public:
    NoTution(int amount)
    {
        this->amount = amount;
    }

    int getAmount()
    {
        return amount;
    }
};

class NotOwner
{
};

class IllegalMove
{
};

class NotMonopoly
{
};

class MaxImprovements
{
};

class MinImprovements
{
};

class CoOp {

};

class Tuition{

};
#endif
