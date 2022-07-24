#ifndef REZ_H
#define REZ_H

#include <iostream>
#include <vector>
#include <string>
#include "property.h"

class Player; // forward declaration

class Rez : public Property
{
    Player *owner; // pointer to the owner of the property
    bool mortgaged;
    int cost;
    std::vector<Property *> otherRez; // this needs to be set later individually.
    std::string name;
    int position;

public:
    Rez(Player *owner, std::string name, int position, bool mortaged);
    void addOwner(Player *p);
    bool isNewOwnable() override;
    void applyRule(Player *p) override; // is called assuming that this rez is owned either by the player who landed on it or some other player
    Player *getOwner() override;  // this is to get the owner of the property
    void setMortgaged(Player *p); // this is to set the mortgaged status of the property
    void unMortgaged(Player *p);  // // this is to unmortage the property
    void setOther(std::vector<Property *> other)  override;
    void setOwner(Player *owner) override;
};

#endif 
