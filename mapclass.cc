#include "mapclass.h"

using namespace std;

// int getprice(std::string name);
//     int getrent(std::string name, int increments);
//     int getIncrementcost(std::string name);

MapClass::MapClass()
{
    rent_increment["AL0"] = 2;
    rent_increment["AL1"] = 10;
    rent_increment["AL2"] = 30;
    rent_increment["AL3"] = 90;
    rent_increment["AL4"] = 160;
    rent_increment["AL5"] = 250;
    rent_increment["ML0"] = 4;
    rent_increment["ML1"] = 20;
    rent_increment["ML2"] = 60;
    rent_increment["ML3"] = 180;
    rent_increment["ML4"] = 320;
    rent_increment["ML5"] = 450;
    rent_increment["ECH0"] = 6;
    rent_increment["ECH1"] = 30;
    rent_increment["ECH2"] = 90;
    rent_increment["ECH3"] = 270;
    rent_increment["ECH4"] = 400;
    rent_increment["ECH5"] = 550;
    rent_increment["PAS0"] = 6;
    rent_increment["PAS1"] = 30;
    rent_increment["PAS2"] = 90;
    rent_increment["PAS3"] = 270;
    rent_increment["PAS4"] = 400;
    rent_increment["PAS5"] = 550;
    rent_increment["HH0"] = 8;
    rent_increment["HH1"] = 40;
    rent_increment["HH2"] = 100;
    rent_increment["HH3"] = 300;
    rent_increment["HH4"] = 450;
    rent_increment["HH5"] = 600;
    rent_increment["RCH0"] = 10;
    rent_increment["RCH1"] = 50;
    rent_increment["RCH2"] = 150;
    rent_increment["RCH3"] = 450;
    rent_increment["RCH4"] = 625;
    rent_increment["RCH5"] = 750;
    rent_increment["DWE0"] = 10;
    rent_increment["DWE1"] = 50;
    rent_increment["DWE2"] = 150;
    rent_increment["DWE3"] = 450;
    rent_increment["DWE4"] = 625;
    rent_increment["DWE5"] = 750;
    rent_increment["CPH0"] = 12;
    rent_increment["CPH1"] = 60;
    rent_increment["CPH2"] = 180;
    rent_increment["CPH3"] = 500;
    rent_increment["CPH4"] = 700;
    rent_increment["CPH5"] = 900;
    rent_increment["LHI0"] = 14;
    rent_increment["LHI1"] = 70;
    rent_increment["LHI2"] = 200;
    rent_increment["LHI3"] = 550;
    rent_increment["LHI4"] = 750;
    rent_increment["LHI5"] = 950;
    rent_increment["BMH0"] = 16;
    rent_increment["BMH1"] = 80;
    rent_increment["BMH2"] = 220;
    rent_increment["BMH3"] = 600;
    rent_increment["BMH4"] = 800;
    rent_increment["BMH5"] = 1000;
    rent_increment["OPT0"] = 18;
    rent_increment["OPT1"] = 90;
    rent_increment["OPT2"] = 250;
    rent_increment["OPT3"] = 700;
    rent_increment["OPT4"] = 875;
    rent_increment["OPT5"] = 1050;
    rent_increment["EV10"] = 18;
    rent_increment["EV11"] = 90;
    rent_increment["EV12"] = 250;
    rent_increment["EV13"] = 700;
    rent_increment["EV14"] = 875;
    rent_increment["EV15"] = 1050;
    rent_increment["EV20"] = 18;
    rent_increment["EV21"] = 90;
    rent_increment["EV22"] = 250;
    rent_increment["EV23"] = 700;
    rent_increment["EV24"] = 875;
    rent_increment["EV25"] = 1050;
    rent_increment["EV30"] = 20;
    rent_increment["EV31"] = 100;
    rent_increment["EV32"] = 300;
    rent_increment["EV33"] = 750;
    rent_increment["EV34"] = 925;
    rent_increment["EV35"] = 1100;
    rent_increment["PHYS0"] = 22;
    rent_increment["PHYS1"] = 110;
    rent_increment["PHYS2"] = 330;
    rent_increment["PHYS3"] = 800;
    rent_increment["PHYS4"] = 975;
    rent_increment["PHYS5"] = 1150;
    rent_increment["B10"] = 22;
    rent_increment["B11"] = 110;
    rent_increment["B12"] = 330;
    rent_increment["B13"] = 800;
    rent_increment["B14"] = 975;
    rent_increment["B15"] = 1150;
    rent_increment["B20"] = 24;
    rent_increment["B21"] = 120;
    rent_increment["B22"] = 360;
    rent_increment["B23"] = 850;
    rent_increment["B24"] = 1025;
    rent_increment["B25"] = 1200;
    rent_increment["EIT0"] = 26;
    rent_increment["EIT1"] = 130;
    rent_increment["EIT2"] = 390;
    rent_increment["EIT3"] = 900;
    rent_increment["EIT4"] = 1100;
    rent_increment["EIT5"] = 1275;
    rent_increment["ESC0"] = 26;
    rent_increment["ESC1"] = 130;
    rent_increment["ESC2"] = 390;
    rent_increment["ESC3"] = 900;
    rent_increment["ESC4"] = 1100;
    rent_increment["ESC5"] = 1275;
    rent_increment["C20"] = 28;
    rent_increment["C21"] = 150;
    rent_increment["C22"] = 450;
    rent_increment["C23"] = 1000;
    rent_increment["C24"] = 1200;
    rent_increment["C25"] = 1400;
    rent_increment["MC0"] = 35;
    rent_increment["MC1"] = 175;
    rent_increment["MC2"] = 500;
    rent_increment["MC3"] = 1100;
    rent_increment["MC4"] = 1300;
    rent_increment["MC5"] = 1500;
    rent_increment["DC0"] = 50;
    rent_increment["DC1"] = 200;
    rent_increment["DC2"] = 600;
    rent_increment["DC3"] = 1400;
    rent_increment["DC4"] = 1700;
    rent_increment["DC5"] = 2000;
}

int MapClass::getprice(std::string name)
{
    int index = 0;
    for (int i = 0; i < nameOfBuildings.size(); ++i)
    {
        if (nameOfBuildings[i] == name)
        {
            index = i;
            break;
        }
    }
    return purchaseCost[index];
}

int MapClass::getrent(std::string name, int increments)
{
    return rent_increment[name + std::to_string(increments)];
}

int MapClass::getIncrementcost(std::string name)
{
    int index = 0;
    for (int i = 0; i < nameOfBuildings.size(); ++i)
    {
        if (nameOfBuildings[i] == name)
        {
            index = i;
            break;
        }
    }
    return improvementCost[index];
}