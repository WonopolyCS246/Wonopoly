#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>

class Player;

struct Pixel {
    int Ln;
    int Col;
};

struct Unit{
    std::string Building;
    Pixel Place;
};

struct PrintHeader{
    const char* Icon;
    Pixel Place;
};

/*
    * Procedure
    * A primary function that will be called 
    * Then it would call private methods to make a vector SST
    * Printing will be done accordingly
*/


class display {
    private:
        std::map<std::string, Pixel> m {{"AL",{54,77}}, {"ML",{54,61}}, {"ECH",{54,37}}, {"PAS",{54,21}}, {"HH",{54,13}}, {"RCH",{54,5}}, {"DWE",{39,5}}, {"CPH",{34,5}}, {"LHI",{24,5}}, {"BMH",{14,5}}, {"OPT",{9,5}}, {"EV1",{4,13}}, {"EV2",{4,29}}, {"EV3",{4,37}}, {"PHYS",{4,53}}, {"B1",{4,61}}, {"B2",{4,77}}, {"EIT",{9,85}}, {"ESC",{14,85}}, {"C2",{24,85}}, {"MC",{39,85}}, {"DC",{49,85}}};

        // std::vector<Unit> Pivot_Pixel{{"AL",{55,77}}, {"ML",{55,61}}, {"ECH",{55,37}}, {"PAS",{55,21}}, {"HH",{55,13}}, {"RCH",{55,5}}, {"DWE",{40,5}}, {"CPH",{35,5}}, {"LHI",{25,5}}, {"BMH",{15,5}}, {"OPT",{10,5}}, {"EV1",{5,13}}, {"EV2",{5,29}}, {"EV3",{5,37}}, {"PHYS",{5,53}}, {"B1",{5,61}}, {"B2",{5,77}}, {"EIT",{10,85}}, {"ESC",{15,85}}, {"C2",{25,85}}, {"MC",{40,85}}, {"DC",{50,85}}};
    public:
        void textdisplay(std::vector<Player *> Player_Ptrs, std::vector<char> Player_Dis);
};



