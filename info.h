#ifndef __INFO_H__
#define __INFO_H__
#include <cstddef>
#include "string"
#include "state.h"

class Player; // forward declaration

struct Info
{
    Player *owner;    // stores the player who owns the property
    bool mortgaged;   // stores whether the property is mortgaged or not
    bool monopoly;    // stores whether the property is part of a monopoly or not
    int cost;         // stores the cost of the property
    std::string name; // stores the name of the property
    int increments;   // stores the number of increments the property has been owned for
    Faculty faculty;
};

#endif