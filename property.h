#include <iostream>
#include "player.h"
class Property{
  void addOwner(Player * p) = 0;
  bool isNewOwnable() = 0;
  void applyRule() = 0;
  Player* getOwner() = 0;
};
