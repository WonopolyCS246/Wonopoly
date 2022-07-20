#ifndef GRID
#define GRID

#include <iostream>
#include <string>
#include "player.h"
#include "property.h"
#include "vector.h"
#include <unordered_map>
#include <fstream>
// using namespace std;

class Grid
{
  int numPlayers; // field added
  std::vector<Property *> cards;
  std::vector<Player *> players;
  std::vector<char> disp; // stores each player's character with which it is represented on the board
  std::unordered_map<std::string, int> piece;
  std::unordered_map<std::string, Player*> names;

  void print();
  Player *info(std::ifstream &file, int *impr);

public:
  Grid(std::ifstream infile);
  ~Grid();
  void roll();
  void nextTurn();
  void trade();
  Property *getProperty(std::string propertyName);
  void buyProperty(Property *p);
  void sellProperty(Property *p);
  void mortgage(Property *p);
  void unmortgage(Property *p);
  bool bankrupt();
  int assets();
  int all();
  // Explicitly defining the type of auction
  void auctionProperty(Property *p);
  // auctionPlayer() calls auctionProperty() on all properties owned by player
  void auctionPlayer(Player *p);
  void transfer(Player *p1, Player *p2);
  // transfers all assets of player p1 to player p2
};

#endif
