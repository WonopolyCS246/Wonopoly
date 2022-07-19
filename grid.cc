#include "grid.h"
using namespace std;

// std::vector<Property *> card;
// std::vector<Player *> players;
// std::vector<char> disp;
// std::unordered_map<std::string, int> piece;

Grid::Grid(std::ifstream infile) {
    string s;
    while (infile >> s) {
        getline(cin, s);
        cin >> numPlayers; // first line of the file is the number of players
        for (int a=0; a<numPlayers; a++) { // reading in the details of the players
            getline(cin, s);
            string name;
            cin >> name; // Player name
            char ch;
            cin >> ch; // Player character
            int tc;
            cin >> tc; // Tim Cards
            int assets;
            cin >> assets; // Assets/Money
            int pos;
            cin >> pos; // Position on the board
            if (pos == 10) { // means that the player is at 
                
            }
            Player *p = new Player{name, assets, pos};
            p->setRUTR(tc);
            players.emplace_back(p);
            disp.emplace_back(ch);
        }
        

    }
}

Grid::~Grid() {

}

void Grid::roll(){

}

void Grid::nextTurn(){

}

void Grid::trade(){

}

Property* Grid::getProperty(std::string propertyName){

}

void Grid:: Grid::buyProperty(Property* p){

}

void Grid::sellProperty(Property* p){

}

void Grid::mortgage(Property* p){

}

void Grid::unmortgage(Property* p){

}


bool Grid::bankrupt(){

}

int Grid::assets(){

}

int Grid::all() {

}
// Explicitly defining the type of auction
void Grid::auctionProperty(Property * p) {

}
// auctionPlayer() calls auctionProperty() on all properties owned by player 
void Grid::auctionPlayer(Player * p){

}

void Grid::transfer(Player * p1, Player * p2){

}

void print() {

}
