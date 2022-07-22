#ifndef REZ_H
#define REZ_H

#include <iostream>
#include <vector>
#include <string>
#include "property.h"

class Player; // forward declaration

//  virtual void addOwner(Player *p) = 0;
//   virtual bool isNewOwnable() = 0;
//   virtual void applyRule(Player *p) = 0; // note that is it important on know which we are applying rule
//   virtual Player *getOwner() = 0;

// Ownable(Player *owner, std::string name, int position, Faculty faculty, int increments, bool mortaged)

class Rez : public Property
{
    Player *owner; // pointer to the owner of the property
    bool mortgaged;
    bool cost;
    std::vector<Property *> otherRez; // this needs to be set later indivsually.
    std::string name;
    int position;

public:
    Rez(Player *owner, std::string name, int position, bool mortaged);
    void addOwner(Player *p);
    bool isNewOwnable() override;
    void applyRule(Player *p) override;
    Player *getOwner() override;  // this is to get the owner of the property
    void setMortgaged(Player *p); // this is to set the mortgaged status of the property
    void unMortgaged(Player *p);  // // this is to unmortage the property
    void setOtherRez(std::vector<Property *> otherRez);
};

#endif // REZ_H
