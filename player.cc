#include "player.h"
#include "property.h"


// std::string name;
//     std::vector<Property *> owned;
//     int assets;
//     bool bankruptcy;
//     // TutionPaid was not present in the UML
//     bool tutionPaid;
//     int position;
//     int previousPosition; // this has been added keeping in mind that previousPosition must be know for graphic purposes
//     int RUTR;             // number of roll up the rim cards used.
//     bool atTims;
//     int turnsAtTims; // number of turns at DC tims when atTims is true.
//     int prevRoll;    // indicates the last roll of the dice.



Player::Player(std::string name, int assets, int position) : name(name), assets(assets), bankruptcy{false}, position(position), previousPosition{0}, RUTR(0), atTims(false), tutionPaid(false) {}

std::vector<Property *> Player::getProp()
{
    return owned;
}

void Player::addProp(Property *p)
{
    owned.push_back(p);
}
void Player::addAssets(int amount)
{
    assets += amount;
}

// Get Assets was not present in UML
int Player::getAssets()
{
    return assets;
}
void Player::setAssets(int assests)
{
    this->assets = assests;
}
void Player::setBankruptcy(bool B)
{
    bankruptcy = B;
}

int Player::getRUTR()
{
    return RUTR;
}
void Player::setRUTR(int num)
{
    RUTR = num;
}

bool Player::getAtTims()
{
    return atTims;
}

void Player::setAtTims(bool value)
{
    atTims = value;
}

void Player::transfer(Player *p)
{
    bankruptcy = true;

    for (int i = 0; i < owned.size(); i++)
    {
        p->addProp(owned[i]);
        // owned[i]->setOwner(p);
    }

    owned.clear();
}

void Player::setPosition(int position)
{
    this->position = position;
}

int Player::getPosition()
{
    return position;
}

void Player::setPreviousPosition(int position)
{
    previousPosition = position;
}

std::string Player::getName()
{
    return name;
}

bool Player::getBankruptcy()
{
    return bankruptcy;
}

bool Player::getTutionPaid()
{
    return tutionPaid;
}

void Player::setTutionPaid(bool tutionPaid)
{
    this->tutionPaid = tutionPaid;
}

void Player::setTurnsAtTims(int turns)
{
    turnsAtTims = turns;
}

int Player::getTurnsAtTims()
{
    return turnsAtTims;
}

// int getPrevRoll();
//     void setPrevRoll(int roll);

int Player::getPrevRoll()
{
    return prevRoll;
}

void Player::setPrevRoll(int roll)
{
    prevRoll = roll;
}

void Player::removeProp(Property *p)
{
    for (int i = 0; i < owned.size(); ++i)
    {
        if (owned[i] == p)
        {
            owned.erase(owned.begin() + i);
            break;
        }
    }
}

// Player(std::string name, int assets, int position);
//     std::vector<Property *> getProp();
//     void addProp(Property *p);
//     void addAssets(int amount); // note intially int amount was not given but to my best understanding it should accept a parameter of type int.
//     // Get Assets was not present in UML
//     int getAssets();
//     void setAssets(int assests);
//     void setBankruptcy(bool B);
//     int getRUTR();
//     void setRUTR(int num);
//     bool getAtTims();
//     void setAtTims(bool value);
//     void transfer(Player *p);
//     void setPosition(int position);
//     int getPosition();
//     int getPreviousPosition();
//     void setPreviousPosition(int position);
//     std::string getName();
//     bool getBankruptcy();
//     bool getTutionPaid();
//     void setTutionPaid(bool tutionPaid);
