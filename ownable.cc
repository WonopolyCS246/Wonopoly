#include "ownable.h"
#include "player.h"
#include "errorclass.h"
#include "mapclass.h"

MapClass a{};

using namespace std;

// Player *owner;    // stores the player who owns the property
//     bool mortgaged;   // stores whether the property is mortgaged or not
//     bool monopoly;    // stores whether the property is part of a monopoly or not
//     int cost;         // stores the cost of the property
//     std::string name; // stores the name of the property
//     int increments;   // stores the number of increments the property has been owned for
//     int position;
//     Faculty faculty;

// Player *owner;       //
//         StateType type;      // For Monopoly
//         Direction direction; // Relative Position of the piece
//         Faculty faculty;     // Faculty of the piece
//         bool monopoly;  



Ownable::Ownable(Player *owner, std::string name, int position, Faculty faculty, int increments, bool mortaged) : Property{} ,Subject(State{nullptr, StateType::EstMono, Direction::Left, Faculty::Arts1, false}), Observer{}, 
                                                                                                                  info{Info{owner, mortaged, false, a.getprice(name), name, increments, position, faculty}}
{
}

void Ownable::attach(Property *o)
{
    Subject::attach(o);
}
void Ownable::notify(Subject &whoFrom)
{
    auto inf = whoFrom.getInfo();
    auto stat = whoFrom.getState();

    int x = getLen();

    if (stat.type == StateType::EstMono)
    {
        info.monopoly = true;
    }
    else if (stat.type == StateType::DisMono)
    {
        info.monopoly = false;
    }
}

void Ownable::addOwner(Player *p)
{
    // Note that I am yet to deduct the annual fee from the player's balance.
    // Also I am yet to add the property to the player's property vector.

    if (p->getAssets() < info.cost)
    {
        throw IllegalMove();
    }

    vector<Property *> other = p->getProp();
    int count = 0;

    for (int i = 0; i < other.size(); ++i)
    {
        if (other[i]->getOwner() == info.owner)
        {
            count++;
        }
    }

    if (count == getLen())
    {
        info.monopoly = true;
        State s = State{p, StateType::EstMono, Direction::Left, info.faculty, false};
        setState(s);
    }
    else
    {
        info.monopoly = false;
        State s = State{p, StateType::DisMono, Direction::Left, info.faculty, false};
        setState(s);
    }

    info.owner = p;
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
    if (info.owner == p && info.mortgaged)
    {
        // handling this case is up to grid.
        // it must conduct auction if neccessary or unmortgage the property.
        throw NotMortgage(info.cost * (0.6));
    }

    if (info.owner == p || info.mortgaged)
    {
        return;
    }
    else
    {
        int rent; 

        if(info.monopoly){
            rent = 2*  a.getrent(info.name, info.increments); 
        }
        else{
            rent = a.getrent(info.name, info.increments); 
        }

        if (p->getAssets() >= rent)
        {
            p->setAssets(p->getAssets() - rent);
            info.owner->setAssets(info.owner->getAssets() + rent);
            return;
        }
        else
        {
            throw NoRent(rent);
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
        throw IllegalMove();
    }
    else
    {
        if (info.increments > 0)
        {
            throw IllegalMove();
        }
        else
        {
            info.mortgaged = true;
        }
    }
}

void Ownable::unMortgaged(Player *p)
{
    if (p != info.owner)
    {
        throw IllegalMove();
    }
    else
    {
        if (!info.mortgaged)
        {
            throw IllegalMove();
        }
        else
        {

            info.mortgaged = false;
        }
    }
}

void Ownable::addincrement(Player *p)
{
    // yet to deduct money from the player's balance.
    if (info.owner != p)
    {
        throw IllegalMove();
    }
    else
    {
        if (info.mortgaged || !info.monopoly)
        {
            throw IllegalMove();
        }
        else if (info.increments == 5)
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
                p->setAssets(p->getAssets() - a.getIncrementcost(info.name));
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
                p->setAssets(p->getAssets() - a.getIncrementcost(info.name));
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

int Ownable::getIncrementcost()
{
    return info.increments*(a.getIncrementcost(info.name));
}

void Ownable::removeincrement(Player *p)
{
    // yet to add money to the player's balance.
    if (info.owner != p)
    {
        throw IllegalMove();
    }
    else
    {
        if (info.mortgaged || !info.monopoly)
        {
            throw IllegalMove();
        }

        else if (info.increments == 0)
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
                p->setAssets(p->getAssets() + (a.getIncrementcost(info.name)) * (0.5));
                --info.increments;
                return;
            }
            x = 0;
            // now check if there is an element such that it's increment is one more than the current increment
            for (int i = 0; i < getLen(); ++i)
            {
                if (((Ownable *)observers[i])->getInfo().increments == info.increments - 1)
                {
                    x = 1;
                    break;
                }
            }

            if (x == 1)
            {
                p->setAssets(p->getAssets() + (a.getIncrementcost(info.name)) * (0.5));
                --info.increments;
                return;
            }
            else
            {
                throw IllegalMove();
            }
        }
    }
}

string Ownable::getName()
{
    return info.name;
}

int Ownable::getPrice()
{
    return info.cost;
}

bool Ownable::isMortgaged()
{
    return info.mortgaged;
}

void Ownable::setMortgaged(bool b)
{
    info.mortgaged = b;
}

void Ownable::setOwner(Player *owner) {
    info.owner = owner;
}

void Ownable::setIncrement(int x) {
    info.increments = x;
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
//         Player *owner;       //
//         StateType type;      // For Monopoly
//         Direction direction; // Relative Position of the piece
//         Faculty faculty;     // Faculty of the piece
//         bool monopoly;       // Is the piece in a monopoly?
// };