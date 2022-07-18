#include <iostream>
#include "property.h"
#include "player.h"
#include "zeroToOne.h"

class templateDesign {
    float random();
    public:
        void applyRule();
        bool isNewOwnable();
        void Rule() = 0;
        void addOwner(Player *p);
}

class Slc : public templateDesign {
    float Back3 = 1/8;
    float Back2 = Back3 + 1/6; 
    float Back1 = Back2 + 1/6;
    float Forward1 = Back1 + 1/8;
    float Forward2 = Forward1 + 1/6;
    float Forward3 = Forward2 + 1/6;
    float GoToDC = Forward3 + 1/24;
    float CollectOSAP = GoToDC + 1/24;
    public:
        void Rule() override;
}

class Nhall : public templateDesign {
    float neg200 = 1/18;
    float neg100 = neg200 + 1/9;
    float neg50 = neg100 + 1/6;
    float pos25 = neg100 + 1/3;
    float pos50 = pos25 + 1/6;
    float pos100 = pos50 + 1/9;
    float pos200 = pos100 + 1/18;
    public:
        void Rule() override;
}
