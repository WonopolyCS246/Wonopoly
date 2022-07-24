#ifndef TEMPLATE_DESIGN
#define TEMPLATE_DESIGN

#include <iostream>
#include "property.h"
#include "player.h"
#include "randomUint.h"
#include <string>

class templateDesign: public Property {
    public:
        unsigned random();
        void addOwner(Player *p) override;
        bool isNewOwnable() override;
        // void applyRule(Player *p) override;
        Player *getOwner() override;
        //virtual std::string Rule(float compare) = 0;
};

class Slc : public templateDesign {
    public:
        Slc(int Position);
        void applyRule(Player *p) override;
        //std::string Rule(float compare);
};

class Nhall : public templateDesign {
    public:
        Nhall(int Position);
        void applyRule(Player *p) override;
        //std::string Rule(float compare);
};

#endif
