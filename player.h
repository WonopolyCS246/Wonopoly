#include "card.h"
#include <vector>
#include <string>
class Property;


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
