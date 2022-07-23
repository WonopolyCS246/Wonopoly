#include "rez.h"
#include "player.h"
#include "mapclass.h"
#include "errorclass.h"

Rez::Rez(Player *owner, std::string name, int position, bool mortaged) : owner{owner}, mortgaged{mortgaged}, cost{200}, name{name}, position{position}
{
}

void Rez::addOwner(Player *p)
{
    if (p->getAssets() < cost)
    {
        throw IllegalMove();
    }
    else
    {
        p->setAssets(p->getAssets() - cost);
        p->addProp(this);
        owner = p;
    }
}

bool Rez::isNewOwnable()
{
    if (owner)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Rez::applyRule(Player *p)
{
    if (owner == p || mortgaged)
    {
        return;
    }
    else
    {
        int count = 0;

        for (int i = 0; i < otherRez.size(); i++)
        {
            if (otherRez[i]->getOwner() == owner)
            {
                count++;
            }
        }
        int rent;

        if (count + 1 == 1)
        {
            rent = 25;
        }
        else if (count + 1 == 2)
        {
            rent = 50;
        }
        else if (count + 1 == 3)
        {
            rent = 100;
        }
        else if (count + 1 == 4)
        {
            rent = 200;
        }

        if (rent > p->getAssets())
        {
            throw NoRent(rent);
        }
        else
        {
            p->setAssets(p->getAssets() - rent);
            owner->setAssets(owner->getAssets() + rent);
        }
    }
}

Player *Rez::getOwner()
{
    return owner;
}

void Rez::setMortgaged(Player *p)
{
    if (owner != p){
        throw IllegalMove();
    } else if (mortgaged) { // already mortaged
        throw IllegalMove();
    }
    else // p is the owner and the property is not mortgaged
    {
        p->setAssets(p->getAssets() + (cost / 2));
        mortgaged = true;
    }
}

void Rez::unMortgaged(Player *p)
{

    if (owner != p)
    {
        throw IllegalMove();
    }
    else
    {
        if (!mortgaged)
        {
            throw IllegalMove();
        }
        else
        {
            if (p->getAssets() < (0.6) * cost)
            {
                throw NotMortgage(0.6 * cost);
            }
            p->setAssets(p->getAssets() - (cost * 0.6));
            mortgaged = false;
        }
    }
}

void Rez::setOtherRez(std::vector<Property *> otherRez)
{
    this->otherRez = otherRez;
}
