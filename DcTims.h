#ifndef DCTIMS_H
#define DCTIMS_H

#include <iostream>
#include "property.h"

class Player;

class DcTims : public Property{
    public:
        void addOwner(Player *p) override;
        bool isNewOwnable() override;
        void applyRule(Player *p) override; 
        Player *getOwner() override;
};

#endif
