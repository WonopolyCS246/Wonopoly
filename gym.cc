#include "gym.h"
#include "player.h"
#include "mapclass.h"
#include "errorclass.h"

Gym::Gym(Player *owner, std::string name, int position, bool mortgaged) : owner{owner}, mortgaged{mortgaged}, cost{150}, name{name}, position{position}
{
} 

void Gym::addOwner(Player *p) {
    if (p->getAssets() < cost) {
        throw IllegalMove();
    } else {
        p->setAssets(p->getAssets() - cost);
        p->addProp(this);
        owner = p;
    }
}

bool Gym::isNewOwnable() {
    if (owner) {
        return false;
    } else {
        return true;
    }
}

void Gym::applyRule(Player *p) {
    if (owner == p || mortgaged) {
        return; // cannot buy if you are the owner or if mortgaged
    } else {
        int count = 0; // this is the count of the other gyms owned by this owner
        for(int a=0; a<otherGym.size(); a++) {
            if(otherGym[a]->getOwner() == owner) {
                count++;
            }
        }
        int roll = p->getPrevRoll(); // this is the amount the player rolled to land on this property
        int rent = 0;
        if (count == 0) { // the owner only owns this gym
            rent = 4 * roll;
        } else if (count == 1) { // the owner owns both gyms
            rent = 10 * roll;
        }

        if (p->getAssets() < rent) {
            throw NoRent(rent);
        } else {
            p->setAssets(p->getAssets() - rent);
            owner->setAssets(owner->getAssets() + rent);
        }
    }    
}

Player* Gym::getOwner() { 
    return owner;
}  

void Gym::setMortgaged(Player *p) {
    if (owner == p) {
        if (mortgaged) { // already mortaged
            throw IllegalMove{};
        } else {
            p->setAssets(p->getAssets() + (cost / 2));
            mortgaged = true;
        }
    } else {
        throw IllegalMove(); 
    }
} 

void Gym::unMortgaged(Player *p) {
    if (owner == p) {
        if (!mortgaged) { // not mortaged
            throw IllegalMove{};
        } else {
            if (p->getAssets() < (0.6) * cost) { // doesn't have enough money
                throw NotMortgage{(0.6 * cost)};
            } else {
                p->setAssets(p->getAssets() - (cost * 0.6));
                mortgaged = false;
            }
        }
    } else {
        throw IllegalMove(); 
    }
}

void Gym::setOther(std::vector<Property *> other) {
    this->otherGym = otherGym;
}

void Gym::setOwner(Player *owner) {
    this->owner = owner;
}
