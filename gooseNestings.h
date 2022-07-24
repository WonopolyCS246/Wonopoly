#ifndef GOOSENEST_H
#define GOOSENEST_H

#include <iostream>
#include "property.h"

// class Player;

class gooseNestings : public Property{
    public:
        gooseNestings(int position);
        void addOwner(Player *p) override;
        bool isNewOwnable() override;
        void applyRule(Player *p) override; 
        Player *getOwner() override;
};

#endif
