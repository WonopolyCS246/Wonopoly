#ifndef PROPERTY_H
#define PROPERTY_H

class Player; // forward declaration

class Property
{

  Player *owner; // pointer to the owner of the property

public:
  Property(); // default constructor
  virtual void addOwner(Player *p) = 0;
  virtual bool isNewOwnable() = 0;
  virtual void applyRule(Player *p) = 0; // note that is it important on know which we are applying rule
  virtual Player *getOwner() = 0;
  virtual void setMortgaged(Player *p); // this is to set the mortgaged status of the property
  virtual void unMortgaged(Player *p); // // this is to unmortage the property
  virtual void removeincrement(Player *p); // this removes just one increment of the monopoly
  virtual void addincrement(Player *p);    // this is to add increments to property.
};

#endif
