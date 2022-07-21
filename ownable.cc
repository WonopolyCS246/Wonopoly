#include "ownable.h"
#include "player.h"
#include "errorclass.h"

using namespace std;

// Ownable(std::string name, int position, int price, int rent, Faculty faculty);
//     void notify(Subject &whoFrom) override;
//     void setState(State newS);
//     Info getInfo() override;
//     void addOwner(Player *p) override;
//     bool isNewOwnable() override;
//     void applyRule(Player *p) override;
//     Player *getOwner() override;
//     Info getInfo() override;
//     void notify(Subject &whoFrom) override;

Ownable::Ownable(Player *owner, std::string name, int position, int price, int rent, Faculty faculty) : state{State{nullptr, StateType::EstMono, Direction::Left, Faculty::Arts1, false}},
                                                                                                        info{Info{owner, false, false, price, rent, name, 0, position, faculty}}
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

Info Ownable::getInfo()
{
    return info;
}

void Ownable::addOwner(Player *p)
{
    // Note that I am yet to deduct the annual fee from the player's balance.
    // Also I am yet to add the property to the player's property vector.
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
    if (info.owner == p)
    {
        return;
    }
    else
    {

    }
}

Player* Ownable::getOwner() {
    return info.owner;
}

// struct Info
// {
//     Player *owner;    // stores the player who owns the property
//     bool mortgaged;   // stores whether the property is mortgaged or not
//     bool monopoly;    // stores whether the property is part of a monopoly or not
//     int cost;         // stores the cost of the property
//     int rent;         // stores the rent of the property
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