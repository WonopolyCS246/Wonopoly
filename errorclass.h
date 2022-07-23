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
};

class IllegalMove
{
    public:
    IllegalMove()
    {
        std::cout << "This is an illegal move." << std::endl;
    }
};

class NotMonopoly
{
    public:
    NotMonopoly()
    {
        std::cout << "You do not own all of the properties in this set." << std::endl;
    }
};

class MaxImprovements
{
    public:
    MaxImprovements()
    {
        std::cout << "You cannot improve this property anymore" << std::endl;
    }
};

class MinImprovements
{
    public:
    MinImprovements()
    {
        std::cout << "You must improve this property at least once" << std::endl;
    }
};

class CoOp {

};

class Tuition{

};

#endif
