#include "card.h"
#include <vector>
#include <string>
class Property;


class Player {
    string name;
    <Property*> owned;
    int assets;
    bool bankruptcy;
    // TutionPaid was not present in the UML
    bool tutionPaid;
    int position;
    int RUTR;
    bool atTims;
    public:
        Player(string name. int assets, int position);
        <Property*> getProp();
        void addProp(Property* p);
        int addAssets();
        // Get Assets was not present in UML
        int getAssets();
        void setAssets(int assests);
        void setBankruptcy(bool B);
        int getRUTR();
        void setRUTR();
        bool getAtTims();
        void setAtTims();
        void transfer(Player* p)
};


/*
class Player {
    string name;
    std::vector<Property*> owned;
    bool tutionPaid;
    bool bankrupt;
    int Assets;
    int position;
    int timCount;
    int prevRoll;
    bool statusTim;
    public:
        int getAssets();
        void addIncrement(Card& Property);
        std::vector<Card> getProperty();
        int getIncrement(Card& Property);
        void removeProperty(Card& Property);
        void roll();
        int getPrev() const;
        int getTimCount();
        void setTimCount(int count);
};
*/
