#include "grid.h"
#include "sstream"
#include "property.h"
#include "ownable.h"
#include "player.h"
using namespace std;

// std::vector<Property *> cards;
// std::vector<Player *> players;
// std::vector<char> disp;
// std::unordered_map<std::string, int> piece;
// std::unordered_map<std::string, Player*> names;

istringstream Grid::info(ifstream &file, int *impr)
{
    string line;
    getline(file, line);
    istringstream ss{line};
    string s;
    ss >> s; // building name
    ss >> s; // name of property
    int n;
    ss >> n;
    *impr = n;       // stores the number of improvements
    return names[s]; // returns the appropriate player* using the unordered list
}

Grid::Grid(std::ifstream infile)
{
    string s;
    getline(infile, s);
    istringstream line{s};
    line >> numPlayers; // first line of the file is the number of players
    for (int a = 0; a < numPlayers; a++)
    { // reading in the details of the players
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
        if (pos == 10)
        { // means that the player is at Dc Tims
            int n;
            data >> n;
            if (n == 0)
            {
                // player is at Dc Tims but has not been sent there so nothing happens
            }
            else if (n == 1)
            {
                int num; // between 0 and 2, indicates the number of turns the player has been at DC Tims
                data >> num;
                p->setTurnsAtTims(num);
            }
        }
        players.emplace_back(p);
        disp.emplace_back(ch);
    }
    // now, time to create the names map that maps player names to player ptrs
    for (int a = 0; a < numPlayers; a++)
    {
        string name = players[a]->getName();
        names[name] = players[a];
    }
    cards.emplace_back(new Start{});
    int *impr = new int{0};
    Player *p = info(infile, impr);
    cards.emplace_back(new Ownable{
        p,
    })
}

Grid::~Grid()
{
}

void Grid::roll()
{
}

void Grid::nextTurn()
{
}

void Grid::nextTurn()
{
}

Property *Grid::getProperty(string propertyName)
{
}

Property *Grid::getProperty(std::string propertyName)
{
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

int Grid::all()
{
}
// Explicitly defining the type of auction
void Grid::auctionProperty(Property *p)
{
}
// auctionPlayer() calls auctionProperty() on all properties owned by player
void Grid::auctionPlayer(Player *p)
{
}

void Grid::transfer(Player *p1, Player *p2)
{
}

void print()
{
}

void auction(Property *p)
{
}

// we need to do heavy typecasting.
void newownable(Player *pl, Property *p)
{
    cout << "You have landed on a new property!" << endl;
    cout << "Enter (improve property buy) to buy or no to pass:" << endl;

    while (true)
    {
        string s;
        getline(cin, s);
        stringstream ss{s};
        string g;
        ss >> g;
        if (g == "no" || g == "No")
        {
            auction(p);
            // function to conduct auction
        }
        else if (g == "buy")
        {
            try
            {
                p->addOwner(pl);
            }
            catch (...)
            {
                cout << "You do not have enough money to buy this property" << endl;
            }
        }
    }
}

void NoRent(int amount, Player *ownee, Player *owned)
{
    cout << "You are short of money to pay rent!" << endl;
    cout << "You have to pay " << amount << " to " << owned->getName() << endl;
    cout << "Raise money or declare bankruptcy" << endl;

    while (true)
    {
        cout << "Type in a valid command" << endl;
        if (ownee->getAssets() >= amount)
        {
            ownee->setAssets(ownee->getAssets() - amount);
            owned->setAssets(owned->getAssets() + amount);
            break;
        }

        string s;
        getline(cin, s);
        stringstream ss{s};
        string g;
        ss >> g;
        if (g == "bankrupt")
        {
            // toogling backrupty in transfer method
            ownee->transfer(owned);
        }

        else if (g == "trade")
        {
            // handle logic for trading
        }

        else if (g == "improve")
        {
            // handle for selling improvements

            cin >> g;

            // note that using typecasting here to covert to ownable where I can use the methods but need to
            // implement checks here

            Ownable *p = (Ownable *)getProperty(g);

            cin >> g;

            if (g == "sell")
            {
                try
                {
                    p->removeincrement(ownee);
                }
                catch (...)
                {
                    cout << "Either you don't own this property or or this is an illegal move" << endl;
                }
            }
        }

        else if (g == "mortgage")
        {
            // logic for handling mortage

            ss >> g;
            Property *p = getProperty(g);

            try
            {
                (Ownable *)p->mortgage();
            }
            catch (...)
            {
                cout << "You don't own this" << endl;
            }
        }
    }
}

// this is a function that takes in sum and updates the player's postion and if the player crosses start,
// he shall also revieve $200.

// I'm making the assumption that 0 is the start position

// previous roll needs to be stored before this function is called.
void handlepassthorugh(int sum, Player *p)
{
    if ((p->getPosition() + sum) % 40 < p->getPosition())
    {
        p->setAssets(200 + p->getAssets());            // add $200 to the player's assets
        p->setPreviousPosition(p->getPosition());      // set the previous position to current position)
        p->setPosition((p->getPosition() + sum) % 40); // set the current position to the sum of the current position and the sum of the roll
    }
    else
    {
        p->setPreviousPosition(p->getPosition());      // set the previous position to current position)
        p->setPosition((p->getPosition() + sum) % 40); // set the current position to the sum of the current position and the sum of the roll
    }
}

// this is used to handle the logic for when a player for forced on tims.
void handletims(Player *p, vector<Property *> &Card)
{
    cout << "You have been sent to DC Tims" << endl;
    cout << "You have " << p->getTurnsAtTims() << " turns in DC tims" << endl;

    if (p->getAtTims() >= 3)
    {
        cout << "You can either pay $50 or use roll up the rim card or pass" << endl;
        cout << "Write Pay to Pay $50 or write RURC to use roll up the rim card or pass to pass" << endl;
        string s;

        while (true)
        {
            cout << "Write Pay to Pay $50 or write RURC to use roll up the rim card" << endl;
            getline(cin, s);
            stringstream ss{s};
            ss >> s;

            if (s == "pass")
            {
                break;
            }

            if (s == "RURC")
            {
                if (p->getRUTR())
                {
                    p->setTurnsAtTims(0);
                    p->setAtTims(false);
                    p->setRUTR(p->getRUTR() - 1);
                    // code to roll a dice and move the player and update previous position.
                    // no need to update previous roll as nothing is being rolled.
                    handlepassthorugh(p->getPrevRoll(), p);

                    handlecard(Card[p->getPosition()], p); // hadles the logic of player landing on the card.

                    break;
                }
                else
                {
                    cout << "You don't have roll up the rim card" << endl;
                    continue;
                }
            }

            else if (s == "pay" || s == "Pay")
            {
                if (p->getAssets() < 50)
                {
                    cout << "Not enough money" << endl;
                    continue;
                }
                else
                {
                    p->setTurnsAtTims(0);
                    p->setAtTims(false);
                    p->setAssets(p->getAssets() - 50);

                    handlepassthorugh(p->getPrevRoll(), p);

                    handlecard(Card[p->getPosition()], p); // hadles the logic of player landing on the card.
                }
            }
        }
    }
    else
    {
        p->setTurnsAtTims(p->getTurnsAtTims() + 1);

        cout << "You can either roll doubles pay $50 or use roll up the rim card or pass" << endl;

        string s;

        while (true)
        {
            cout << "Write roll to roll dice, Pay to Pay $50 or write RURC to use roll up the rim card or pass to pass" << endl;
            getline(cin, s);
            stringstream ss{s};

            ss >> s;
            if (s=="pass"){
                p->setTurnsAtTims(p->getTurnsAtTims()-1); 
                break;
            }
            else if(s=="")
        }
    }
}