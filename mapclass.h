#ifndef MAPCLASS_H
#define MAPCLASS_H
#include <iostream>
#include <vector>
#include <string>
class MapClass
{
    std::vector<std::string> nameOfBuildings{"AL", "ML", "ECH", "PAS", "HH", "RCH", "DWE", "CPH", "LHI", "BMH", "OPT", "EV1", "EV2", "EV3", "PHYS", "B1", "B2", "EIT", "ESC", "C2", "MC", "DC"};
    std::vector<std::string> monopolyBlock{"Arts1", "Arts1", "Arts2", "Arts2", "Arts2", "Eng", "Eng", "Eng", "Health", "Health", "Health", "Env", "Env", "Env", "Sci1", "Sci1", "Sci1", "Sci2", "Sci2", "Sci2", "Math", "Math"};
    std::vector<int> purchaseCost{40, 60, 100, 100, 120, 140, 140, 160, 180, 180, 200, 220, 220, 240, 260, 260, 280, 300, 300, 320, 350, 400};
    std::vector<int> improvementCost{50, 50, 50, 50, 50, 100, 100, 100, 100, 100, 100, 150, 150, 150, 150, 150, 150, 200, 200, 200, 200, 200};
};

#endif // MAPCLASS_H