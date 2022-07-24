#include "grid.h"
#include "sstream"
#include "property.h"
#include "ownable.h"
#include "player.h"
#include "roll2die.h"

#include "errorclass.h"
using namespace std;

// std::vector<Property *> cards;
// std::vector<Player *> players;
// std::vector<char> disp;
// std::unordered_map<std::string, int> piece;
// std::unordered_map<std::string, Player*> names;

// istringstream Grid::info(ifstream &file, int *impr)
// {
//     string line;
//     getline(file, line);
//     istringstream ss{line};
//     string s;
//     ss >> s; // building name
//     ss >> s; // name of property
//     int n;
//     ss >> n;
//     *impr = n;       // stores the number of improvements
//     return names[s]; // returns the appropriate player* using the unordered list
// }

// Grid::Grid(std::ifstream infile)
// {
//     string s;
//     getline(infile, s);
//     istringstream line{s};
//     line >> numPlayers; // first line of the file is the number of players
//     for (int a = 0; a < numPlayers; a++)
//     { // reading in the details of the players
//         getline(infile, s);
//         istringstream data{s};
//         string name;
//         data >> name; // Player name
//         char ch;
//         data >> ch; // Player character
//         int tc;
//         data >> tc; // Tim Cards
//         int assets;
//         data >> assets; // Assets/Money
//         int pos;
//         data >> pos; // Position on the board
//         Player *p = new Player{name, assets, pos};
//         p->setRUTR(tc);
//         if (pos == 10)
//         { // means that the player is at Dc Tims
//             int n;
//             data >> n;
//             if (n == 0)
//             {
//                 // player is at Dc Tims but has not been sent there so nothing happens
//             }
//             else if (n == 1)
//             {
//                 int num; // between 0 and 2, indicates the number of turns the player has been at DC Tims
//                 data >> num;
//                 p->setTurnsAtTims(num);
//             }
//         }
//         players.emplace_back(p);
//         disp.emplace_back(ch);
//     }
//     // now, time to create the names map that maps player names to player ptrs
//     for (int a = 0; a < numPlayers; a++)
//     {
//         string name = players[a]->getName();
//         names[name] = players[a];
//     }
//     cards.emplace_back(new Start{});
//     int *impr = new int{0};
//     Player *p = info(infile, impr);
//     cards.emplace_back(new Ownable{});
// }

Grid::~Grid()
{
}


// Explicitly defining the type of auction

// auctionPlayer() calls auctionProperty() on all properties owned by player

void Grid::play()
{

    int count = 0;
    while (true)
    {

        for (int i = 0; i < players.size(); i++)
        {
            if (!players[i]->getBankruptcy())
            {
                count++;
            }
        }

        if (count == 1)
        {
            for (int i = 0; i < players.size(); i++)
            {
                if (!players[i]->getBankruptcy())
                {
                    cout << "Player " << players[i]->getName() << " wins!" << endl;
                    break;
                }
            }
        }

        count = 0;

        for (int i = 0; i < players.size(); ++i)
        {
            if (!players[i]->getBankruptcy())
            {
                int a = handlePre(players[i]);
                if (a == 2)
                {
                    // code to save
                }
                else if (a == 0)
                {
                    break;
                }

                else
                {
                    handleRoll(players[i]);

                    if (handlePost(players[i]) == 2)
                    {
                        // code to save
                    }
                }
            }
        }
    }
}

void Grid::auctionPlayer(Player *p)
{
    p->setBankruptcy(true);

    for (int i = 0; i = p->getProp().size(); ++i)
    {
        auctionProperty(p->getProp()[i], p);
    }
}

int Grid::handlePre(Player *p)
{
    string s;

    cout << "What would you like to do?" << endl;

    getline(cin, s);
    stringstream ss{s};

    string g;

    ss >> g;

    if (s == "trade")
    {
        HandleTrade(p, ss);
    }
    else if (s == "bankrupt")
    {
        cout << "No you're not bankrupt" << endl;
    }
    else if (s == "all")
    {
        for (int i = 0; i < players.size(); ++i)
        {
            cout << "Player " << players[i]->getName() << " has $" << players[i]->getAssets() << endl;

            for (int j = 0; j < players[i]->getProp().size(); ++j)
            {
                cout << "Player " << players[i]->getName() << " has " << players[i]->getProp()[j]->getName() << endl;
            }
        }
    }

    else if (s == "assets")
    {
        cout << "You have $" << p->getAssets() << endl;

        for (int j = 0; j < p->getProp().size(); ++j)
        {
            cout << "You have " << p->getProp()[j]->getName() << endl;
        }
    }
    else if (s == "mortgage")
    {
        ss >> g;
        Property *pt = getProperty(g);

        try
        {
            pt->setMortgaged(p);
        }
        catch (...)
        {
            cout << "Illegal Move" << endl;
        }
    }

    else if (s == "improve")
    {
        ss >> g;
        Property *pt = getProperty(g);

        ss >> g;

        if (g == "buy")
        {
            try
            {
                pt->addincrement(p);
            }
            catch (...)
            {
                cout << "Illegal Move" << endl;
            }
        }

        else if (g == "sell")
        {
            try
            {
                pt->removeincrement(p);
            }
            catch (...)
            {
                cout << "Illegal Move" << endl;
            }
        }
    }

    else if (s == "unmortgage")
    {
        ss >> g;
    }

    else if (s == "roll")
    {
        return 1;
    }
    else if (s == "pass")
    {
        return 0;
    }

    else if (s == "save")
    {
        return 2;
    }
}



void Grid::handleRoll(Player *p)
{
    if (p->getAtTims())
    {
        handletims(p);
    }
    else
    {
        vector<int> a = roll2die();
        int sum = a[0] + a[1];
        p->setPrevRoll(sum);
        handlepassthorugh(sum, p); // handles the passing through of the player
        handlecard(cards[p->getPosition()], p);
    }
}

int Grid::handlePost(Player *p)
{
    string s;

    cout << "What would you like to do?" << endl;

    getline(cin, s);
    stringstream ss{s};

    string g;

    ss >> g;

    if (s == "trade")
    {
        HandleTrade(p, ss);
    }
    else if (s == "bankrupt")
    {
        cout << "No you're not bankrupt" << endl;
    }
    else if (s == "all")
    {
        for (int i = 0; i < players.size(); ++i)
        {
            cout << "Player " << players[i]->getName() << " has $" << players[i]->getAssets() << endl;

            for (int j = 0; j < players[i]->getProp().size(); ++j)
            {
                cout << "Player " << players[i]->getName() << " has " << players[i]->getProp()[j]->getName() << endl;
            }
        }
    }

    else if (s == "assets")
    {
        cout << "You have $" << p->getAssets() << endl;

        for (int j = 0; j < p->getProp().size(); ++j)
        {
            cout << "You have " << p->getProp()[j]->getName() << endl;
        }
    }
    else if (s == "mortgage")
    {
        ss >> g;
        Property *pt = getProperty(g);

        try
        {
            pt->setMortgaged(p);
        }
        catch (...)
        {
            cout << "Illegal Move" << endl;
        }
    }

    else if (s == "improve")
    {
        ss >> g;
        Property *pt = getProperty(g);

        ss >> g;

        if (g == "buy")
        {
            try
            {
                pt->addincrement(p);
            }
            catch (...)
            {
                cout << "Illegal Move" << endl;
            }
        }

        else if (g == "sell")
        {
            try
            {
                pt->removeincrement(p);
            }
            catch (...)
            {
                cout << "Illegal Move" << endl;
            }
        }
    }

    else if (s == "unmortgage")
    {
        ss >> g;
    }

    else if (s == "pass")
    {
        return 1;
    }

    else if (s == "save")
    {
        return 2;
    }
}

Property *getProperty(string name)
{

    return nullptr;
}

void Grid::auctionProperty(Property *p, Player *p1)
{
    int amount = p->getPrice(); // amount of money to bid on the property.
    Player *winner = nullptr;
    std::vector<Player *> participants;

    for (int i = 0; i < players.size(); ++i)
    {
        if (players[i] != p1 && players[i]->getBankruptcy() == false)
        {
            participants.push_back(players[i]);
        }
    }

    while (participants.size() != 1)
    {
        for (int i = 0; i < participants.size(); ++i)
        {
            if (participants[i] != winner)
            {
                cout << "Player " << participants[i]->getName() << " please enter your bid: or say no to opt out of the auction" << endl;
                cout << "Current highest bid is: " << amount << "By player " << winner->getName() << endl;

                string res;
                cin >> res;

                if (isdigit(res[0]))
                {
                    int bid = stoi(res);
                    if (bid < amount)
                    {
                        cout << "Your bid is lower than current max, you are out of the auction" << endl;
                        participants.erase(participants.begin() + i);
                    }
                    else
                    {
                        amount = bid;
                        winner = participants[i];
                    }
                }
                else if (res == "no")
                {
                    participants.erase(participants.begin() + i);
                }
                else
                {
                    cout << "Invalid input" << endl;
                }
            }
        }
    }

    if (p->isMortgaged())
    {
        amount = amount + p->getPrice() * (0.10);

        cout << "This is a mortgaged property. Do you wish to unmortgage this by paying half price: " << p->getPrice() * (0.5) << endl;
        cout << "write yes or no" << endl;
        string res;
        cin >> res;

        if (res == "yes")
        {
            amount = amount + p->getPrice() * (0.5);

            if (winner->getAssets() >= amount)
            {
                winner->setAssets(winner->getAssets() - amount);
                winner->addProp(p);
                p->addOwner(winner);
                p->setMortgaged(false);
                cout << "Property transferred and unmortgaged "
                     << "to player " << winner->getName() << endl;
            }
            else
            {
                if (raise(winner, amount))
                {
                    winner->setAssets(winner->getAssets() - amount);
                    winner->addProp(p);
                    p->addOwner(winner);
                    p->setMortgaged(false);
                    cout << "Property transferred and unmortgaged "
                         << "to player " << winner->getName() << endl;
                }
                else
                {
                    cout << "You can't pay the full amount, hence you're bankrupt" << endl;
                    winner->setBankruptcy(true);
                    p->addOwner(nullptr);
                    p->setMortgaged(false);

                    auctionPlayer(winner);
                }
            }

            return;
        }
    }

    if (winner->getAssets() >= amount)
    {
        winner->setAssets(winner->getAssets() - amount);
        winner->addProp(p);
        p->addOwner(winner);
        cout << "Property transferred "
             << "to player " << winner->getName() << endl;
    }
    else
    {
        if (raise(winner, amount))
        {
            winner->setAssets(winner->getAssets() - amount);
            winner->addProp(p);
            p->addOwner(winner);

            cout << "Property transferred "
                 << "to player " << winner->getName() << endl;
        }
        else
        {
            cout << "You can't pay the full amount, hence you're bankrupt" << endl;
            winner->setBankruptcy(true);
            p->addOwner(nullptr);
            p->setMortgaged(false);

            auctionPlayer(winner);
        }
    }
}

// handles logic for a single trade.
// need to make trade later.
void trade(Player *p, Player *p2, int amount, Property *pt)
{
    if (p->getAssets() < amount)
    {
        cout << "Trade is rejected as you do not have enough money" << endl;
        return;
    }
    else if (pt->getOwner() != p2)
    {
        cout << "Trade is rejected as " << p2->getName() << " doesn't own this property" << endl;
        return;
    }
    else
    {
        string s;
        cout << p2->getName() << "Do you want to sell this property for $" << amount << "?" << endl;
        cout << "Type yes or no" << endl;
        cin >> s;

        while (true)
        {
            if (s == "yes")
            {
                p->setAssets(p->getAssets() - amount);
                p->addProp(pt); // add property to player's list of properties
                p2->setAssets(p2->getAssets() + amount);
                p2->removeProp(pt); // remove property from player's list of properties
                pt->addOwner(p);

                cout << "Trade successful" << endl;

                break;
            }
            else if (s == "no")
            {
                cout << "Trade is rejected because " << p2->getName() << " does not want to sell this property" << endl;
                break;
            }
        }
    }
}

string getnameproperty(Property *p1)
{
    return "";
}

void trade(Player *p, Player *p2, Property *pt1, Property *pt2)
{
    if (pt1->getOwner() != p || pt2->getOwner() != p2)
    {
        cout << "Trade is rejected as one of the properties is not owned by you" << endl;
        return;
    }
    else
    {
        string s;
        cout << p2->getName() << "Do you want to trade" << pt2->getName() << " for " << pt1->getName() << "?" << endl;
        cout << "Type yes or no" << endl;
        cin >> s;

        while (true)
        {
            if (s == "yes")
            {
                p->removeProp(pt1);
                p->addProp(pt2);
                p2->removeProp(pt2);
                p2->addProp(pt1);

                pt1->addOwner(p2);
                pt2->addOwner(p);

                cout << "Trade successful" << endl;
                break;
            }
            else if (s == "no")
            {
                cout << "Trade is rejected because " << p2->getName() << " does not want to trade this property" << endl;
                break;
            }
        }
    }
}

void trade(Player *p, Player *p2, Property *pt1, int amount)
{
    if (pt1->getOwner() != p || p2->getAssets() < amount)
    {
        cout << "Trade is rejected as the property is not owned by you or the other player does not have enough money" << endl;
        return;
    }
    else
    {
        cout << p2->getName() << "Do you want to buy" << pt1->getName() << " for $" << amount << "?" << endl;
        cout << "Type yes or no" << endl;

        string s;
        cin >> s;
        while (true)
        {
            if (s == "yes")
            {
                // not sure if increments are allowed in tradable properties
                p->removeProp(pt1);
                p->setAssets(p->getAssets() + amount);
                p2->setAssets(p2->getAssets() - amount);
                p2->addProp(pt1);
                pt1->addOwner(p2);
            }
            else if (s == "no")
            {
                cout << "Trade is rejected because " << p2->getName() << " does not want to buy this property" << endl;
                break;
            }
        }
    }
}

void Grid::HandleTrade(Player *p, stringstream &ss)
{
    string s;
    ss >> s;
    Player *p2 = getPlayer(s);

    ss >> s;

    if (isdigit(s[0]))
    {
        int amount = stoi(s);
        ss >> s;
        Property *pr = getProperty(s);

        if (pr)
        {
            trade(p, p2, pr, amount);
        }
        else
        {
            cout << "Invalid Building" << endl;
        }
    }
    else
    {
        Property *pr1 = getProperty(s);
        if (!pr1)
        {
            cout << "Invalid Building" << endl;
            return;
        }

        ss >> s;

        if (isdigit(s[0]))
        {
            int amount = stoi(s);
            ss >> s;

            trade(p, p2, pr1, amount);
        }
        else
        {
            Property *pr2 = getProperty(s);
            if (!pr2)
            {
                cout << "Invalid Building" << endl;
                return;
            }
            trade(p, p2, pr1, pr2);
        }
    }
    // handle trade with player
}

// give the player the option to raise amount
int Grid::raise(Player *p, int amount)
{
    cout << "You can raise an amount of " << amount << "or declare bankcrupcy" << endl;
    string s;
    while (true)
    {

        if (p->getAssets() >= amount)
        {
            cout << "You now have enough money" << endl;
            return 1;
        }
        cout << "Enter valid command to raise money or type bankrupt to declare bankrupt" << endl;
        getline(cin, s);
        istringstream ss{s};

        ss >> s;
        if (s == "improvement")
        {
            ss >> s;
            Property *pr = getProperty(s);
            ss >> s;
            if (s == "buy")
            {
                cout << "We asked you to raise money !" << endl;
                continue;
            }

            else if (s == "sell")
            {

                try
                {
                    pr->removeincrement(p);
                }
                catch (...)
                {
                    cout << "Illegal move" << endl;
                }
            }
        }

        else if (s == "all")
        {
            for (int i = 0; i < players.size(); ++i)
            {
                cout << "Player " << players[i]->getName() << " has $" << players[i]->getAssets() << endl;

                for (int j = 0; j < players[i]->getProp().size(); ++j)
                {
                    cout << "Player " << players[i]->getName() << " has " << players[i]->getProp()[j]->getName() << endl;
                }
            }
        }

        else if (s == "assets")
        {
            cout << "You have $" << p->getAssets() << endl;

            for (int j = 0; j < p->getProp().size(); ++j)
            {
                cout << "You have " << p->getProp()[j]->getName() << endl;
            }
        }

        else if (s == "mortgage")
        {
            ss >> s;
            // note it must be a valid proerty
            Property *pr = getProperty(s);

            if (!pr)
            {
                cout << "Not a valid ownable property" << endl;
                continue;
            }

            try
            {
                pr->setMortgaged(p);
                p->setAssets(p->getAssets() + pr->getPrice() / 2);
            }
            catch (...)
            {
                cout << "Illegal move" << endl;
            }
        }

        else if (s == "trade")
        {
            ss >> s;
            Player *p2 = getPlayer(s);

            ss >> s;

            if (isdigit(s[0]))
            {
                int amount = stoi(s);
                ss >> s;
                Property *pr = getProperty(s);

                if (pr)
                {
                    trade(p, p2, pr, amount);
                }
                else
                {
                    cout << "Invalid Building" << endl;
                }
            }
            else
            {
                Property *pr1 = getProperty(s);
                if (!pr1)
                {
                    cout << "Invalid Building" << endl;
                    continue;
                }

                ss >> s;

                if (isdigit(s[0]))
                {
                    int amount = stoi(s);
                    ss >> s;

                    trade(p, p2, pr1, amount);
                }
                else
                {
                    Property *pr2 = getProperty(s);
                    if (!pr2)
                    {
                        cout << "Invalid Building" << endl;
                        continue;
                    }
                    trade(p, p2, pr1, pr2);
                }
            }
            // handle trade with player
        }

        else if (s == "bankrupt")
        {
            return 0;
            break;
        }
    }
}

// we need to do heavy typecasting.
void Grid::newownable(Player *pl, Property *p)
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
            auctionProperty(p, pl);
            // function to conduct auction
        }
        else if (g == "buy")
        {
            if (pl->getAssets() >= p->getPrice())
            {
                pl->addProp(p);
                pl->setAssets(pl->getAssets() - p->getPrice());
                p->addOwner(pl);
                cout << "You have bought " << p->getName() << endl;
            }
            else
            {
                cout << "You do not have enough money" << endl;
                if (raise(pl, p->getPrice()))
                {
                    pl->addProp(p);
                    pl->setAssets(pl->getAssets() - p->getPrice());
                    p->addOwner(pl);
                    cout << "You have bought " << p->getName() << endl;
                }
                else
                {
                    cout << "You tried to raise money but you couldn't so we will auction this property and you are bankrupt!" << endl;
                    pl->setBankruptcy(true);
                    auctionProperty(p, pl);
                    auctionPlayer(pl); // function to conduct auction
                }
            }
        }
    }
}

// void NoRent(int amount, Player *ownee, Player *owned)
// {
//     cout << "You are short of money to pay rent!" << endl;
//     cout << "You have to pay " << amount << " to " << owned->getName() << endl;
//     cout << "Raise money or declare bankruptcy" << endl;

//     while (true)
//     {
//         cout << "Type in a valid command" << endl;
//         if (ownee->getAssets() >= amount)
//         {
//             ownee->setAssets(ownee->getAssets() - amount);
//             owned->setAssets(owned->getAssets() + amount);
//             break;
//         }

//         string s;
//         getline(cin, s);
//         stringstream ss{s};
//         string g;
//         ss >> g;
//         if (g == "bankrupt")
//         {
//             // toogling backrupty in transfer method
//             ownee->transfer(owned);
//         }

//         else if (g == "trade")
//         {
//             // handle logic for trading
//         }

//         else if (g == "improve")
//         {
//             // handle for selling improvements

//             cin >> g;

//             // note that using typecasting here to covert to ownable where I can use the methods but need to
//             // implement checks here

//             Ownable *p = (Ownable *)getProperty(g);

//             cin >> g;

//             if (g == "sell")
//             {
//                 try
//                 {
//                     p->removeincrement(ownee);
//                 }
//                 catch (...)
//                 {
//                     cout << "Either you don't own this property or or this is an illegal move" << endl;
//                 }
//             }
//         }

//         else if (g == "mortgage")
//         {
//             // logic for handling mortage

//             ss >> g;
//             Property *p = getProperty(g);

//             try
//             {
//                 (Ownable *)p->mortgage();
//             }
//             catch (...)
//             {
//                 cout << "You don't own this" << endl;
//             }
//         }
//     }
// }

// this is a function that takes in sum and updates the player's postion and if the player crosses start,
// he shall also revieve $200.

// I'm making the assumption that 0 is the start position

// previous roll needs to be stored before this function is called.
void Grid::handlepassthorugh(int sum, Player *p)
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
void Grid::handletims(Player *p)
{
    cout << "You have been sent to DC Tims" << endl;
    cout << "You have " << p->getTurnsAtTims() << " turns in DC tims" << endl;

    if (p->getTurnsAtTims() >= 3)
    {
        string s;

        while (true)
        {
            cout << "You can either pay $50 or use a roll up the rim card or pass" << endl;
            cout << "Write Pay to Pay $50 or write RURC to use roll up the rim card or pass to pass" << endl;
            cin >> s;
            if (s == "pass")
            {
                break; // potentiall use a throw here to return back and skip turn
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

                    handlecard(cards[p->getPosition()], p); // handles the logic of player landing on the card.

                    break;
                }
                else
                {
                    cout << "You don't have a roll up the rim card" << endl;
                    break;
                }
            }

            else if (s == "pay" || s == "Pay")
            {
                if (p->getAssets() < 50)
                {
                    cout << "Not enough money" << endl;
                    break;
                }
                else
                {
                    p->setTurnsAtTims(0);
                    p->setAtTims(false);
                    p->setAssets(p->getAssets() - 50);

                    handlepassthorugh(p->getPrevRoll(), p);

                    handlecard(cards[p->getPosition()], p); // hadles the logic of player landing on the card.
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
            cout << "Write roll to roll dice, Pay to Pay $50 or write RURC to use roll up the rim card" << endl;
            getline(cin, s);
            stringstream ss{s};

            ss >> s;

            if (s == "roll")
            {
                vector<int> a = roll2die(); // roll the dice
                int sum = a[0] + a[1];
                if (a[0] != a[1])
                {
                    cout << "Sorry you didn't roll doubles" << endl;
                    break;
                }
                p->setPrevRoll(sum);
                handlepassthorugh(sum, p);
                handlecard(cards[p->getPosition()], p); // hadles the logic of player landing on the card.
            }

            else if (s == "RURC")
            {
                if (p->getRUTR())
                {
                    p->setTurnsAtTims(0);
                    p->setAtTims(false);
                    p->setRUTR(p->getRUTR() - 1);
                    // code to roll a dice and move the player and update previous position.
                    // no need to update previous roll as nothing is being rolled.
                    handlepassthorugh(p->getPrevRoll(), p);

                    handlecard(cards[p->getPosition()], p); // hadles the logic of player landing on the card.

                    break;
                }
                else
                {
                    cout << "You don't have roll up the rim card" << endl;
                    break;
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

                    handlecard(cards[p->getPosition()], p); // hadles the logic of player landing on the card.
                }
            }
        }
    }
}

void Grid::handleCoop(Player *p1)
{
    if (p1->getAssets() >= 150)
    {
        cout << "Co-op tution detected" << endl;
        p1->setAssets(p1->getAssets() - 150);
    }
    else
    {
        if (raise(p1, 150))
        {
            cout << "Co-op tution detected" << endl;
            p1->setAssets(p1->getAssets() - 150);
        }
        else
        {
            p1->setBankruptcy(true);
            auctionPlayer(p1);
        }
    }
}

int calculateten(Player *p)
{
    int sum = 0;

    for (int i = 0; i < p->getProp().size(); ++i)
    {
        sum = sum + p->getProp()[i]->getPrice();
        sum = sum + p->getProp()[i]->getIncrementcost(); 
    }

    sum = sum+p->getAssets(); 

    return sum*(0.1);
}

void Grid::handletution(Player *p1)
{
    cout << "You have landed on the tution " << endl;
    cout << " You can either pay $300 or 10"
         << "%"
         << "of your savings" << endl;

    while (true)
    {
        cout << "Write Pay to pay $300 or write 10"
             << "%"
             << " to use 10%" << endl;
        string s;
        getline(cin, s);
        stringstream ss{s};

        ss >> s;
        if (s == "pay")
        {
            if (raisetution(p1, 300))
            {
                cout << "You have paid $300" << endl;
                p1->setAssets(p1->getAssets() - 300);
            }
            else
            {
                p1->setBankruptcy(true);
                auctionPlayer(p1);
            }
        }
        else if (s == "10%")
        {
            int x = calculateten(p1);

            if(p1->getAssets()>=x){
                cout << "10" <<"%" << " amount paid" << x << endl; 
                p1->setAssets(p1->getAssets()-x); 
            }
            else{
                if(raisetution(p1, x)){
                    p1->setAssets(p1->getAssets()-x); 
                }
                else{
                    p1->setBankruptcy(true);
                    auctionPlayer(p1);
                }
            }

        }
    }
}

// void Grid::handlecard(Property *p, Player *p1)
// {
//     if (p->isNewOwnable())
//     {
//         newownable(p1, p);
//         return;
//     }
//     else
//     {
//         try
//         {
//             p->applyRule(p1);
//         }
//         catch (NotMortgage m)
//         {
//             if (p1->getAssets() > m.getAmount())
//             {
//                 cout << "You did not unmortage this property" << endl;
//                 cout << "But since you landed here again amount of $" << m.getAmount() << " has been removed from your assets" << endl;
//                 p1->setAssets(p1->getAssets() - m.getAmount());
//                 p->setMortgaged(false);
//                 return;
//             }
//             else
//             {
//                 cout << "You don't currently have enough money to unmortgage this property" << endl;
//                 cout << "But since you landed here again amount of $" << m.getAmount() << " has been removed from your assets" << endl;
//                 if (raise(p1, m.getAmount()))
//                 {
//                     p1->setAssets(p1->getAssets() - m.getAmount());
//                     p->setMortgaged(false);
//                     return;
//                 }
//                 else
//                 {
//                     cout << "You have failed to unmortgage this property" << endl;
//                     p1->setBankruptcy(true);
//                     auctionPlayer(p1);
//                 }
//             }
//         }
//         catch (NoRent n)
//         {
//             cout << "You landed on a property for which you don't have the balance to pay rent" << endl;
//             cout << "But since you landed here you need to pay $" << n.getRent() << " " << endl;

//             if (raise(p1, n.getRent()))
//             {
//                 p1->setAssets(p1->getAssets() - n.getRent());
//                 p->getOwner()->setAssets(n.getRent());
//                 return;
//             }
//             else
//             {
//                 cout << "You have failed to pay rent" << endl;
//                 p1->setBankruptcy(true);
//                 p1->transfer(p->getOwner());
//             }
//         }
//         catch (NoTution t)
//         {
//             cout << "You have landed on tution which you didn't have the balance to pay" << endl;
//             cout << "But since you landed here you need to pay $" << t.getAmount() << " " << endl;

//             if (raisetution(p1, t.getAmount()))
//             {
//                 p1->setAssets(p1->getAssets() - t.getAmount());
//                 return;
//             }
//             else
//             {
//                 p1->setBankruptcy(true);
//                 auctionPlayer(p1);
//             }
//         }
//         catch (...)
//         {
//             cout << "Illegal move " << endl;
//         }
//     }
// }

void Grid::handlecard(Property *p, Player *p1)
{
    if (p->isNewOwnable())
    {
        newownable(p1, p);
        return;
    }
    else
    {
        try
        {
            p->applyRule(p1);
        }
        catch (NotMortgage m)
        {
            if (p1->getAssets() > m.getAmount())
            {
                cout << "You did not unmortage this property" << endl;
                cout << "But since you landed here again amount of $" << m.getAmount() << " has been removed from your assets" << endl;
                p1->setAssets(p1->getAssets() - m.getAmount());
                p->setMortgaged(false);
                return;
            }
            else
            {
                cout << "You don't currently have enough money to unmortgage this property" << endl;
                cout << "But since you landed here again amount of $" << m.getAmount() << " has been removed from your assets" << endl;
                if (raise(p1, m.getAmount()))
                {
                    p1->setAssets(p1->getAssets() - m.getAmount());
                    p->setMortgaged(false);
                    return;
                }
                else
                {
                    cout << "You have failed to unmortgage this property" << endl;
                    p1->setBankruptcy(true);
                    auctionPlayer(p1);
                }
            }
        }
        catch (NoRent n)
        {
            cout << "You landed on a property for which you don't have the balance to pay rent" << endl;
            cout << "But since you landed here you need to pay $" << n.getRent() << " " << endl;

            if (raise(p1, n.getRent()))
            {
                p1->setAssets(p1->getAssets() - n.getRent());
                p->getOwner()->setAssets(n.getRent());
                return;
            }
            else
            {
                cout << "You have failed to pay rent" << endl;
                p1->setBankruptcy(true);
                p1->transfer(p->getOwner());
            }
        }
        catch (Tuition t)
        {
            handletution(p1);
        }
        catch (CoOp t)
        {
            handleCoop(p1);
        }
        catch (...)
        {
            cout << "Illegal move " << endl;
        }
    }
}


int Grid::raisetution(Player *p, int amount)
{
    cout << "You can raise an amount of " << amount << "or declare bankcrupcy" << endl;
    string s;
    while (true)
    {

        if (p->getAssets() >= amount)
        {
            cout << "You now have enough money" << endl;
            return 1;
        }
        cout << "Enter valid command to raise money or type bankrupt to declare bankrupt" << endl;
        getline(cin, s);
        istringstream ss{s};

        ss >> s;
        if (s == "improvement")
        {
            ss >> s;
            Property *pr = getProperty(s);
            ss >> s;
            if (s == "buy")
            {
                cout << "We asked you to raise money !" << endl;
                continue;
            }

            else if (s == "sell")
            {

                try
                {
                    pr->removeincrement(p);
                }
                catch (...)
                {
                    cout << "Illegal move" << endl;
                }
            }
        }

        else if (s == "all")
        {
            cout << "Since you are paying tution you can't do that" << endl;
            continue;
        }

        else if (s == "assets")
        {
            cout << "Since you are paying tution you can't do that" << endl;
            continue;
        }

        else if (s == "mortgage")
        {
            ss >> s;
            // note it must be a valid proerty
            Property *pr = getProperty(s);

            if (!pr)
            {
                cout << "Not a valid ownable property" << endl;
                continue;
            }

            try
            {
                pr->setMortgaged(p);
                p->setAssets(p->getAssets() + pr->getPrice() / 2);
            }
            catch (...)
            {
                cout << "Illegal move" << endl;
            }
        }

        else if (s == "trade")
        {
            ss >> s;
            Player *p2 = getPlayer(s);

            ss >> s;

            if (isdigit(s[0]))
            {
                int amount = stoi(s);
                ss >> s;
                Property *pr = getProperty(s);

                if (pr)
                {
                    trade(p, p2, pr, amount);
                }
                else
                {
                    cout << "Invalid Building" << endl;
                }
            }
            else
            {
                Property *pr1 = getProperty(s);
                if (!pr1)
                {
                    cout << "Invalid Building" << endl;
                    continue;
                }

                ss >> s;

                if (isdigit(s[0]))
                {
                    int amount = stoi(s);
                    ss >> s;

                    trade(p, p2, pr1, amount);
                }
                else
                {
                    Property *pr2 = getProperty(s);
                    if (!pr2)
                    {
                        cout << "Invalid Building" << endl;
                        continue;
                    }
                    trade(p, p2, pr1, pr2);
                }
            }
            // handle trade with player
        }

        else if (s == "bankrupt")
        {
            return 0;
            break;
        }
    }
}

Player* Grid::getPlayer(std::string s) {
    return nullptr;
}

Property* Grid::getProperty(std::string s) {
    return nullptr;
}
