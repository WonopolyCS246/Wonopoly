#ifndef START_H
#define START_H

#include <iostream>
#include "property.h"

class Player;

class Start : public Property {
    public:
        Start(int position);
        void addOwner(Player *p) override;
        bool isNewOwnable() override;
        void applyRule(Player *p) override; 
        Player *getOwner() override;
};

#endif
