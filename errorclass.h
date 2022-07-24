#ifndef NORENT_H
#define NORENT_H
#include <iostream>
// an error class to indicate that rent cannot be paid
class NoRent{
    int rent;
    public:
    NoRent(int rent);
    int getRent();
};

class NotMortgage{
    double amount;
    public:
        NotMortgage(double amount);
        double getAmount();
};

class NoTution
{
};

class IllegalMove
{
    public:
    IllegalMove();
};

class NotMonopoly
{
    public:
    NotMonopoly();
};

class MaxImprovements
{
    public:
    MaxImprovements();
};

class MinImprovements
{
    public:
    MinImprovements();
};

class CoOp {

};

class Tuition{

};

#endif
