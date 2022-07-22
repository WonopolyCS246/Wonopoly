#ifndef GRID
#define GRID

#include <iostream>
#include <string>
#include "player.h"
#include "property.h"
#include <vector>
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
  std::unordered_map<std::string, Property*> prop;
  int index; // keeps track of the index in players, whose turn it is
  Player *current; // this is the current player whose turn it is

  void print();
  Player *info(std::ifstream &file, int *impr);

public:
  Grid(std::ifstream infile);
  ~Grid();
  void play(); // this is where the game starts
  void roll();
  void nextTurn();
  void trade(Player *p, int money, Property *q); // offers a trade to p, offering money for q
  void trade(Player *p, Property *q1, Property *q2); // offers a trade to p, offering q1 for q2
  void trade(Player *p, Property *q, int money); // offers a trade to p, offering q for money
  void buyImprovement(Property *p);
  void sellImprovement(Property *p);
  void mortgage(Property *p);
  void unmortgage(Property *p);
  //bool bankrupt();
  void assets(); // return type changed from int to void
  void all(); // return type changed from int to void
  void save(string fname);
  // Explicitly defining the type of auction
  void auctionProperty(Property *p);
  // auctionPlayer() calls auctionProperty() on all properties owned by player
  void auctionPlayer(Player *p);
  void transfer(Player *p1, Player *p2);
  // transfers all assets of player p1 to player p2
  Property *getProperty(string name);
  Player *getPlayer(string name);
};

#endif
