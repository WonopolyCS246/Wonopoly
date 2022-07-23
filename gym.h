#ifndef GYM_H
#define GYM_H

#include <iostream>
#include <vector>
#include <string>
#include "property.h"
   
class Player; // forward declaration

class Gym : public Property
{
    Player *owner; // pointer to the owner of the property
    bool mortgaged;
    bool cost;
    std::vector<Property *> otherGym; // this needs to be set later individually.
    std::string name;
    int position;

public:
    Gym(Player *owner, std::string name, int position, bool mortaged);
    void addOwner(Player *p);
    bool isNewOwnable() override;
    void applyRule(Player *p) override; // is called assuming that this gym is owned either by the player who landed on it or some other player
    Player *getOwner() override;  // this is to get the owner of the property
    void setMortgaged(Player *p); // this is to set the mortgaged status of the property
    void unMortgaged(Player *p);  // // this is to unmortage the property
    void setOtherGym(std::vector<Property *> otherGym);
};

#endif 
