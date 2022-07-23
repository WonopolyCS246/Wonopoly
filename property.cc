#include <iostream>
#include <vector>
#include <string>
#include "player.h"
#include "property.h"

//  virtual void addOwner(Player *p);
//   virtual bool isNewOwnable();
//   virtual void applyRule(Player *p) = 0; // note that is it important on know which we are applying rule
//   virtual Player *getOwner();

//   virtual void setMortgaged(Player *p); // this is to set the mortgaged status of the property

//   virtual void unMortgaged(Player *p); // // this is to unmortage the property

//   virtual void removeincrement(Player *p); // this removes just one increment of the monopoly
//   virtual void addincrement(Player *p);

void Property::setMortgaged(Player *p)
{

} // this is to set the mortgaged status of the property

void Property::unMortgaged(Player *p)
{

} // // this is to unmortage the property

void Property::removeincrement(Player *p)
{

} // this removes just one increment of the monopoly

void Property::addincrement(Player *p)
{

} // this is to add increments to property.

void Property::addOwner(Player *p)
{

} // this is to add the owner of the property

Player *Property::getOwner()
{
    return nullptr;
} // this is to get the owner of the property

bool Property::isNewOwnable()
{
    return false;
} // this is to check if the property is new ownable

void Property::attach(Property *o)
{
}

std::string Property::getName()
{
    return "";
}

int Property::getPrice()
{
    return 0;
}

bool Property::isMortgaged()
{
    return false;
}

void Property::setMortgaged(bool mortgaged)
{
}
