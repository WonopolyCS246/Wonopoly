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

public:
    Ownable(Player *owner, std::string name, int position, int price, int rent, Faculty faculty);
    void notify(Subject &whoFrom) override;
    void setState(State newS);
    Info getInfo() override;
    void addOwner(Player *p) override;
    bool isNewOwnable() override;
    void applyRule(Player *p) override;
    Player *getOwner() override;
    // Info getInfo() override;
    // void notify(Subject &whoFrom) override;
    // ^ Two methods repeated
};

#endif
