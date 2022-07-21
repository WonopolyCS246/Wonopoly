#include "ownable.h"
#include "player.h"
#include "errorclass.h"
#include "mapclass.h"

MapClass a{};

using namespace std;

//  Ownable(Player *owner, std::string name, int position, Faculty faculty, int increments);
//     void notify(Subject &whoFrom) override;
//     void setState(State newS);
//     Info getInfo() override;
//     void addOwner(Player *p) override;
//     bool isNewOwnable() override;
//     void applyRule(Player *p) override;
//     Player *getOwner() override;
//     void notify(Subject &whoFrom) override;
// void setMortgaged(bool value)

Ownable::Ownable(Player *owner, std::string name, int position, Faculty faculty, int increments, bool mortaged) : state{State{nullptr, StateType::EstMono, Direction::Left, Faculty::Arts1, false}},
                                                                                                                  info{Info{owner, mortaged, false, a.getprice(name), name, increments, position, faculty}}
{
}

void Ownable::notify(Subject &whoFrom)
{
    auto inf = whoFrom.getInfo();
    auto stat = whoFrom.getState();

    int x = getLen();

    if (stat.owner)
    {
        if (stat.owner->getProp().size() == x)
        {
            info.monopoly = true; // if the player owns all the properties of the faculty, he is in a monopoly
        }
        else
        {
            info.monopoly = false; // if the player does not own all the properties of the faculty, he is not in a monopoly
        }
    }
}

void Ownable::setState(State newS)
{
    state = newS;
}

void Ownable::addOwner(Player *p)
{
    // Note that I am yet to deduct the annual fee from the player's balance.
    // Also I am yet to add the property to the player's property vector.

    p->setAssets(p->getAssets() - info.cost);
    p->addProp(this);
    info.owner = p;
    state = State{p, StateType::EstMono, Direction::Left, info.faculty, false};
    notifyObservers(); // but state needs to change
}

bool Ownable::isNewOwnable()
{
    if (info.owner)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Ownable::applyRule(Player *p)
{
    if (info.owner == p || info.mortgaged)
    {
        return;
    }
    else
    {
        if (p->getAssets() >= a.getrent(info.name, info.increments))
        {
            p->setAssets(p->getAssets() - a.getrent(info.name, info.increments));
            info.owner->setAssets(info.owner->getAssets() + a.getrent(info.name, info.increments));
            return;
        }
        else
        {
            throw NoRent{a.getrent(info.name, info.increments)};
        }
    }
}

Player *Ownable::getOwner()
{
    return info.owner;
}

Info Ownable::getInfo()
{
    return info;
}

void Ownable::setMortgaged(Player *p)
{
    if (p != info.owner || info.mortgaged)
    {
        throw NotOwner();
    }
    else
    {
        if (info.increments > 0)
        {
            throw IllegalMove();
        }
        else
        {
            p->setAssets(p->getAssets() + (info.cost / 2));
            info.mortgaged = true;
        }
    }
}

void Ownable::unMortgaged(Player *p)
{
    if (p != info.owner)
    {
        throw NotOwner();
    }
    else
    {
        if (!info.mortgaged)
        {
            throw IllegalMove();
        }
        else
        {
            p->setAssets(p->getAssets() - (info.cost * 0.6));
            info.mortgaged = false;
        }
    }
}

void Ownable::attach(Observer *o)
{
    observers.push_back(o);
}

void Ownable::addincrement(Player *p)
{
    if (info.owner != p)
    {
        throw NotOwner();
    }
    else
    {
        if (info.mortgaged)
        {
            throw IllegalMove();
        }
        else
        {
            // check if all the increments are same on neighbouring properties

            int x = 0;
            for (int i = 0; i < getLen(); i++)
            {
                if (((Ownable *)observers[i])->getInfo().increments != info.increments)
                {
                    x = 1;
                    break;
                }
            }

            if (x == 0)
            {
                ++info.increments;
                return;
            }
            x = 0;
            // now check if there is an element such that it's increment is one more than the current increment
            for (int i = 0; i < getLen(); ++i)
            {
                if (((Ownable *)observers[i])->getInfo().increments == info.increments + 1)
                {
                    x = 1;
                    break;
                }
            }

            if (x == 1)
            {
                ++info.increments;
                return;
            }
            else
            {
                throw IllegalMove();
            }
        }
    }
}

// struct Info
// {
//     Player *owner;    // stores the player who owns the property
//     bool mortgaged;   // stores whether the property is mortgaged or not
//     bool monopoly;    // stores whether the property is part of a monopoly or not
//     int cost;         // stores the cost of the property

//     std::string name; // stores the name of the property
//     int increments;   // stores the number of increments the property has been owned for
//     int position;
//     Faculty faculty;
// };

// struct State
// {
//         StateType type;      // For Monopoly
//         Direction direction; // Relative Position of the piece
//         Faculty faculty;     // Faculty of the piece
//         bool monopoly;       // Is the piece in a monopoly?
// };