#ifndef GOTODCTIMS_H
#define GOTODCTIMS_H

#include <iostream>
#include "property.h"


class Player;

class goToDcTims : public Property {
    public:
        void addOwner(Player *p) override;
        bool isNewOwnable() override;
        void applyRule(Player *p) override; 
        Player *getOwner() override;
};

#endif
