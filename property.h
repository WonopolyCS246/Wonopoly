#ifndef PROPERTY_H
#define PROPERTY_H

#include <string>
class Player; // forward declaration

class Property {
  protected:
    int position;
  public:
  //Property(); // default constructor
  virtual void addOwner(Player *p);
  virtual bool isNewOwnable();
  virtual void applyRule(Player *p) = 0; // note that is it important on know which we are applying rule
  virtual Player *getOwner();

  virtual bool isMortgaged(); // this is to check if the property is mortgaged

  virtual void setMortgaged(Player *p); // this is to set the mortgaged status of the property

  virtual void unMortgaged(Player *p); // // this is to unmortage the property

  virtual void setMortgaged(bool mortgaged); // this is to set the mortgaged status of the property

  virtual void removeincrement(Player *p); // this removes just one increment of the monopoly
  virtual void addincrement(Player *p);
  virtual void attach(Property *o);
  virtual int getPrice();
  virtual int getPosition();
  virtual void setPosition(int Position);
  virtual std::string getName();
  virtual int getIncrementcost(); 
  virtual void setOwner(Player *owner);
  virtual void setIncrement(int x);

  virtual void setOther(Property * other);
};

#endif
