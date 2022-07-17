#include <iostream>
#include <string>

// using namespace std;


class Grid {
  <Property *> card;
  <Players *> players;
  <string, int> piece;
  public:
    void roll();
    void nextTurn();
    void trade();
    Property* getProperty(string propertyName);
    void buyProperty(Property* p);
    void sellProperty(Property* p);
    void mortgage(Property* p);
    void unmortgage(Property* p);
    bool bankrupt();
    int assets();
    int all;
    // Explicitly defining the type of auction
    void auctionProperty(Property * p);
    // auctionPlayer() calls auctionProperty() on all properties owned by player 
    void auctionPlayer(Player * p);
    void transfer(Player * p1, Player * p2);
  
};


