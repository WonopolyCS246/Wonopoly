#ifndef OWNABLE_H
#define OWNABLE_H
#include <iostream>
#include <vector>
#include <string>
#include "property.h"
#include "state.h"
#include "info.h"
#include "subject.h"
#include "observer.h"

class Player; // forward declaration
class Ownable : public Property, public Subject, public Observer
{

    Info info;
    // stores the neighbours of the property
public:
    Ownable(Player *owner, std::string name, int position, Faculty faculty, int increments, bool mortaged);
    void notify(Subject &whoFrom) override;
    std::string getName() override;
    void attach(Property *o) override;

    void addincrement(Player *p); // this is to increment the particular monopolies of the faculty

    Info getInfo() override;
    void addOwner(Player *p) override;
    bool isNewOwnable() override;
    void applyRule(Player *p) override;
    Player *getOwner() override;

    bool isMortgaged() override;

    int getPrice() override;
    void setMortgaged(Player *p) override; // this is to set the mortgaged status of the property

    void unMortgaged(Player *p) override; // // this is to unmortage the property

    void removeincrement(Player *p) override; // this removes just one increment of the monopoly
    void addincrement(Player *p) override;    // this is to add increments to property.

    void setMortgaged(bool mortgaged) override;
};

#endif
