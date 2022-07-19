#include <iostream>
#include "property.h"
#include "player.h"
#include "zeroToOne.h"
#include <string>

class templateDesign: public Property {
    public:
        float random();
        void addOwner(Player *p) override;
        bool isNewOwnable() override;
        virtual void applyRule(Player *p);
        Player *getOwner() override;
        virtual std::string Rule(float compare) = 0;
};

class Slc : public templateDesign {
    public:
        void applyRule(Player *p) override;
        std::string Rule(float compare);
};

class Nhall : public templateDesign {
    public:
        void applyRule(Player *p) override;
        std::string Rule(float compare);
};


