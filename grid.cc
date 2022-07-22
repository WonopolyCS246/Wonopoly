#include "grid.h"
#include "sstream"
using namespace std;

// int numPlayers; // field added
// std::vector<Property *> cards;
// std::vector<Player *> players;
// std::vector<char> disp; // stores each player's character with which it is represented on the board
// std::unordered_map<std::string, int> piece;
// std::unordered_map<std::string, Player*> names;
// std::unordered_map<std::string, Property*> prop;
// int index; // keeps track of the index in players, whose turn it is
// Player *current; // this is the current player whose turn it is

Player *Grid::info(ifstream &file, int *impr) {
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
    cards.emplace_back(new Ownable{p,});
    // MORE CODE NEEDED HERE
    index = 0;
    current = players[index];
}

Grid::~Grid() {

}

void Grid::play() {
    string cmd;
    while (true) {
        cin >> cmd;
        if (cmd == "roll") {
            roll();
            nextTurn();
        } else if (cmd == "next") {
            nextTurn();
        } else if (cmd == "trade") {
            bool chk1 = false, chk2 = false; // false means int and true means string
            Property *q1, *q2;
            int n1, n2;
            string s;
            string name;
            cin >> name; // name of the person who the current players offers the trade to
            string s1;
            cin >> s1;
            istringstream ss1{s1};
            ss1 >> n1;
            if (ss1.fail()) { // the first input was property and not money
                ss1.clear();
                chk1 = true; // s1 is the correct property string
            }
            string s2;
            cin >> s2;
            istringstream ss2{s2};
            ss2 >> n2;
            if (ss2.fail()) { // the first input was property and not money
                ss1.clear();
                chk2 = true; // s1 is the correct property string
            }
            if (chk1 && chk2) { // both true, means that I need to trade 2 properties
                trade(names[name], prop[s1], prop[s2]);
            } else if (chk1) { // and chk2 is false so first one is a property and the second one is money
                trade(names[name], prop[s1], n2);
            } else if (chk2) { // and chk1 is false so first one is money and the second one is a property
                trade(names[name], n1, prop[s2]);
            } else { // cannot trade money for money
                cout << "Sorry, you cannot trade money for money. Please try again." << endl;
            }
        } else if (cmd == "improve") {
            string property; // property name
            cin >> property;
            string action; // action: buy or sell
            cin >> action;
            if (action == "buy") {
                buyImprovement(prop[property]);
            } else if (action == "sell") {
                sellImprovement(prop[property]);
            }
        } else if (cmd == "mortgage") {
            string property; // property name
            cin >> property;
            mortgage(prop[property]);
        } else if (cmd == "unmortgage") {
            string property; // property name
            cin >> property;
            unmortgage(prop[property]);
        } else if (cmd == "bankrupt") {
            cout << "Better luck next time, beggar!" << endl;
            current->setBankruptcy(true); // player is set as bankrupt
        } else if (cmd == "assets") {
            assets();
        } else if (cmd == "all") {
            all();
        } else if (cmd == "save") {
            string fname;
            cin >> fname;
            save(fname);
            cout << "Thank you for playing Watopoly! Until next time!" << endl;
            return;
        } else { // invalid command
            cout << "Please enter a valid command." << endl;
        }
    }
}

void Grid::roll() {

}

void Grid::nextTurn() {
    if (index == (players.size()-1)) {
        index = 0;
    } else {
        index++;
    }
    current = players[index];
}

void trade(Player *p, int money, Property *q) { // offers a trade to p, offering money for q
    if (q->getOwner() != p) { // p does not own q so cannot trade it with the current player 
        cout << "Sorry, you cannot trade. The player you are trading with does not own the property you want" << endl;
        return;
    }
    
}

void trade(Player *p, Property *q1, Property *q2) { // offers a trade to p, offering q1 for q2

}

void trade(Player *p, Property *q, int money) { // offers a trade to p, offering q for money

}

void Grid::buyImprovement(Property* p){
    try {
        p->addIncrement(current);
    } catch (const char* msg) {
        cout << msg << endl;
    }

}

void Grid::sellImprovement(Property* p){
    // similar to buyImprovement above
}

void Grid::mortgage(Property* p){

}

void Grid::unmortgage(Property* p){

}


// bool Grid::bankrupt(){

// }

void Grid::assets(){

}

void Grid::all() {

}

void Grid::save(string fname) {

}

// Explicitly defining the type of auction
void Grid::auctionProperty(Property * p) {

}
// auctionPlayer() calls auctionProperty() on all properties owned by player 
void Grid::auctionPlayer(Player * p){

}

void Grid::transfer(Player * p1, Player * p2){

}

void Grid::print() {

}

Property* Grid::getProperty(string name) {
    return prop[name];
}

Player* Grid::getPlayer(string name) {
    return names[name];
}
