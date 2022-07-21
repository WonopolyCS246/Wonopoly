#ifndef PROPERTY_H
#define PROPERTY_H

class Player; // forward declaration

class Property
{
  Player *owner; // pointer to the owner of the property
  bool canImprove;    // stores whether the property can have improvements or not (it will only be true for ownable properties and false for the rest)

public:
  Property(); // default constructor
  virtual void addOwner(Player *p) = 0;
  virtual bool isNewOwnable() = 0;
  virtual void applyRule(Player *p) = 0; // note that is it important on know which we are applying rule
  virtual Player *getOwner() = 0;
};

#endif
