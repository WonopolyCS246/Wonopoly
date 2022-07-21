#ifndef PROPERTY_H
#define PROPERTY_H

class Player; // forward declaration

class Property
{

public:
  Property(); // default constructor
  virtual void addOwner(Player *p) = 0;
  virtual bool isNewOwnable() = 0;
  virtual void applyRule(Player *p) = 0; // note that is it important on know which we are applying rule
  virtual Player *getOwner() = 0;
};

#endif
