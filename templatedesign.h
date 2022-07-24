#include <iostream>
#include "property.h"
#include "player.h"
#include "randomUint.h"
#include "nHallRandom.h"
#include <string>
#include "slcRandom.h"

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
        void applyRule(Player *p) override;
        //std::string Rule(float compare);
};

class Nhall : public templateDesign {
    public:
        void applyRule(Player *p) override;
        //std::string Rule(float compare);
};


