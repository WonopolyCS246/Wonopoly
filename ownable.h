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
    State state;
    Info info;
    std::vector<Subject *> neighnours; // stores the neighbours of the property
public:
    Ownable(Player *owner, std::string name, int position, Faculty faculty, int increments, bool mortaged);
    void notify(Subject &whoFrom) override;
    void setState(State newS);

    void addincrement(Player *p); // this is to increment the particular monopolies of the faculty

    void attach(Observer *o) override; // this is to attach the observer

    Info getInfo() override;
    void addOwner(Player *p) override;
    bool isNewOwnable() override;
    void applyRule(Player *p) override;
    Player *getOwner() override;

    void setMortgaged(Player *p); // this is to set the mortgaged status of the property

    void unMortgaged(Player *p); // // this is to unmortage the property

    void removeincrement(Player *p); // this removes just one increment of the monopoly
    void addincrement(Player *p);    // this is to add increments to property.
};

#endif
