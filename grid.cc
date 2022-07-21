#include "grid.h"
#include "sstream"
using namespace std;

// std::vector<Property *> cards;
// std::vector<Player *> players;
// std::vector<char> disp;
// std::unordered_map<std::string, int> piece;
// std::unordered_map<std::string, Player*> names;

istringstream Grid::info(ifstream &file, int *impr) {
    string line;
    getline(file, line);
    istringstream ss{line};
    string s;
    ss >> s; // building name
    ss >> s; // name of property
    int n;
    ss >> n;
    *impr = n; // stores the number of improvements
    return names[s]; // returns the appropriate player* using the unordered list
}

Grid::Grid(std::ifstream infile) {
    string s;
    getline(infile, s);
    istringstream line{s};
    line >> numPlayers; // first line of the file is the number of players
    for (int a=0; a<numPlayers; a++) { // reading in the details of the players
        getline(infile, s);
        istringstream data{s};
        string name;
        data >> name; // Player name
        char ch;
        data >> ch; // Player character
        int tc;
        data >> tc; // Tim Cards
        int assets;
        data >> assets; // Assets/Money
        int pos;
        data >> pos; // Position on the board
        Player *p = new Player{name, assets, pos};
        p->setRUTR(tc);
        if (pos == 10) { // means that the player is at Dc Tims
            int n;
            data >> n;
            if (n == 0) {
                // player is at Dc Tims but has not been sent there so nothing happens
            } else if (n == 1) {
                int num; // between 0 and 2, indicates the number of turns the player has been at DC Tims
                data >> num;
                p->setTurnsAtTims(num);
            }
        } 
        players.emplace_back(p);
        disp.emplace_back(ch);
    }
    // now, time to create the names map that maps player names to player ptrs
    for(int a=0; a<numPlayers; a++) {
        string name = players[a]->getName();
        names[name] = players[a];
    }
    cards.emplace_back(new Start{});
    int *impr = new int{0};
    Player *p = info(infile, impr);
    cards.emplace_back(new Ownable{p,})
}

Grid::~Grid() {

void Grid::roll()
{
}

void Grid::nextTurn()
{
}

void Grid::nextTurn(){
    
}

Property *Grid::getProperty(string propertyName)
{
}

Property* Grid::getProperty(std::string propertyName){

}

void Grid::sellProperty(Property *p)
{
}

void Grid::mortgage(Property *p)
{
}

void Grid::unmortgage(Property *p)
{
}

bool Grid::bankrupt()
{
}

int Grid::assets()
{
}

int Grid::all() {

}
// Explicitly defining the type of auction
void Grid::auctionProperty(Property * p) {

}
// auctionPlayer() calls auctionProperty() on all properties owned by player
void Grid::auctionPlayer(Player *p)
{
}

void Grid::transfer(Player *p1, Player *p2)
{
}

void print() {

}
