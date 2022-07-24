#ifndef GRID
#define GRID

#include "player.h"
#include "property.h"
#include "ownable.h"
#include "gym.h"
#include "rez.h"
#include "templatedesign.h"
#include "DcTims.h"
#include "goToDcTims.h"
#include "CoOpfee.h"
#include "gooseNestings.h"
#include "tuition.h"

#include <iostream>
#include <string>

#include "start.h"


#include <vector>
#include <unordered_map>
#include <fstream>

// using namespace std;

class Grid
{
  int numPlayers; // field added
  
  std::vector<Property *> cards{new Start{0},
                                new Ownable{nullptr, "AL", 1, Faculty::Arts1, 0, false},
                                new Slc{2},
                                new Ownable{nullptr, "ML", 3, Faculty::Arts1, 0, false},
                                new Tuition{4},
                                new Rez{nullptr, "MKV", 5, false},
                                new Ownable{nullptr, "ECH", 6, Faculty::Arts2, 0, false},
                                new Nhall{7},
                                new Ownable{nullptr, "PAS", 8, Faculty::Arts2, 0, false},
                                new Ownable{nullptr, "HH", 9, Faculty::Arts2, 0, false},
                                new DcTims{10},
                                new Ownable{nullptr, "RCH", 11, Faculty::Eng, 0, false},
                                new Gym{nullptr, "PAC", 12, false},
                                new Ownable{nullptr, "DWE", 13, Faculty::Eng, 0, false},
                                new Ownable{nullptr, "CPH", 14, Faculty::Eng, 0, false},
                                new Rez{nullptr, "UWP", 15, false},
                                new Ownable{nullptr, "LHI", 16, Faculty::Health, 0, false},
                                new Slc{17},
                                new Ownable{nullptr, "BMH", 18, Faculty::Health, 0, false},
                                new Ownable{nullptr, "OPT", 19, Faculty::Health, 0, false},
                                new gooseNestings{20},
                                new Ownable{nullptr, "EV1", 21, Faculty::Env, 0, false},
                                new Nhall{22},
                                new Ownable{nullptr, "EV2", 23, Faculty::Env, 0, false},
                                new Ownable{nullptr, "EV3", 24, Faculty::Env, 0, false},
                                new Rez{nullptr, "V1", 25, false},
                                new Ownable{nullptr, "PHYS", 26, Faculty::Sci1, 0, false},
                                new Ownable{nullptr, "B1", 27, Faculty::Sci1, 0, false},
                                new Gym{nullptr, "CIF", 28, false},
                                new Ownable{nullptr, "B2", 29, Faculty::Sci1, 0, false},
                                new DcTims{30},
                                new Ownable{nullptr, "EIT", 31, Faculty::Sci2, 0, false},
                                new Ownable{nullptr, "ESC", 32, Faculty::Sci2, 0, false},
                                new Slc{33},
                                new Ownable{nullptr, "C2", 34, Faculty::Sci2, 0, false},
                                new Rez{nullptr, "REV", 35, false},
                                new Nhall{36},
                                new Ownable{nullptr, "MC", 37, Faculty::Math, 0, false},
                                new CoOp{38},
                                new Ownable{nullptr, "DC", 39, Faculty::Math, 0, false}};

  std::vector<Player *> players;
  std::vector<char> disp; // stores each player's character with which it is represented on the board
  // std::unordered_map<std::string, int> piece;
  std::unordered_map<std::string, Player *> names;
  std::unordered_map<std::string, char> characters;

  void attachObservers();
  void playerMap();
  void characterMapInit(); // initializes the Player to character map

public:
  Grid();
  Grid(std::ifstream infile);
  ~Grid();
  void play();
  void trade(Player *p, Player *p2, int amount, Property *pt);
  void trade(Player *p, Player *p2, Property *pt1, Property *pt2);
  void trade(Player *p, Player *p2, Property *pt1, int amount);

  int raise(Player *p, int amount); // player p raise amount of money.

  int raisetution(Player *p, int amount);
  // Explicitly defining the type of auction
  void auctionProperty(Property *p, Player *p1);
  // auctionPlayer() calls auctionProperty() on all properties owned by player
  void auctionPlayer(Player *p);
  // void transfer(Player *p1, Player *p2);
  int handlePre(Player *p);
  void handleRoll(Player *p);
  int handlePost(Player *p);
  void handlepassthorugh(int sum, Player *p);
  void newownable(Player *pl, Property *p);
  void handletims(Player *p);
  void HandleTrade(Player *p, std::stringstream &ss);
  void handlecard(Property *p, Player *p1);
  Player *getPlayer(std::string s);
  Property *getProperty(std::string s);

  void handletution(Player *p1);
  void handleCoop(Player *p1);
  void save(std::string fname, int index);

  // transfers all assets of player p1 to player p2
};

#endif