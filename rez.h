#ifndef REZ_H
#define REZ_H

#include <iostream>
#include <vector>
#include <string>
#include "property.h"

class Player; // forward declaration

class Rez : public Property
{
    Player *owner; // pointer to the owner of the property
    std::vector<Property *> otherRez;
    std::string name; 


    public: 
    Rez(Player *owner, )

}; 

#endif // REZ_H