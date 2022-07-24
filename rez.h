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
    bool mortgaged = false;
    int cost;
    std::vector<Property *> otherRez; // this needs to be set later individually.
    std::string name;

public:
    Rez(Player *owner, std::string name, int position, bool mortgaged);
    void addOwner(Player *p) override;
    bool isNewOwnable() override;
    void applyRule(Player *p) override; // is called assuming that this rez is owned either by the player who landed on it or some other player
    Player *getOwner() override;  // this is to get the owner of the property
    void setMortgaged(Player *p) override; // this is to set the mortgaged status of the property
    void unMortgaged(Player *p) override;  // // this is to unmortage the property
    void setOther(Property * other)  override;
    void setOwner(Player *owner) override;
    int getPrice() override; 
};

#endif 
