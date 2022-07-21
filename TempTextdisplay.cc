#include <iostream>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
class Player;

struct Pixel{
    int Ln;
    int Col;
};

struct Unit{
    std::string Building;
    Pixel Place;

};
std::vector<Unit> Place_Player1{{"AL",{55,74}}, {"ML",{55,58}}, {"ECH",{55,34}}, {"PAS",{55,18}}, {"HH",{55,10}}, {"RCH",{55,2}}, {"DWE",{40,2}}, {"CPH",{35,2}}, {"LHI",{25,2}}, {"BMH",{15,2}}, {"OPT",{10,2}}, {"EV1",{5,10}}, {"EV2",{5,26}}, {"EV3",{5,34}}, {"PHYS",{5,50}}, {"B1",{5,58}}, {"B2",{5,74}}, {"EIT",{10,82}}, {"ESC",{15,82}}, {"C2",{25,82}}, {"MC",{40,82}}, {"DC",{50,82}}};
std::vector<Unit> Place_Player2{{"AL",{55,75}}, {"ML",{55,59}}, {"ECH",{55,35}}, {"PAS",{55,19}}, {"HH",{55,11}}, {"RCH",{55,3}}, {"DWE",{40,3}}, {"CPH",{35,3}}, {"LHI",{25,3}}, {"BMH",{15,3}}, {"OPT",{10,3}}, {"EV1",{5,11}}, {"EV2",{5,27}}, {"EV3",{5,35}}, {"PHYS",{5,51}}, {"B1",{5,59}}, {"B2",{5,75}}, {"EIT",{10,83}}, {"ESC",{15,83}}, {"C2",{25,83}}, {"MC",{40,83}}, {"DC",{50,83}}};
std::vector<Unit> Place_Player3{{"AL",{55,76}}, {"ML",{55,60}}, {"ECH",{55,36}}, {"PAS",{55,20}}, {"HH",{55,12}}, {"RCH",{55,4}}, {"DWE",{40,4}}, {"CPH",{35,4}}, {"LHI",{25,4}}, {"BMH",{15,4}}, {"OPT",{10,4}}, {"EV1",{5,12}}, {"EV2",{5,28}}, {"EV3",{5,36}}, {"PHYS",{5,52}}, {"B1",{5,60}}, {"B2",{5,76}}, {"EIT",{10,84}}, {"ESC",{15,84}}, {"C2",{25,84}}, {"MC",{40,84}}, {"DC",{50,84}}};
std::vector<Unit> Place_Player4{{"AL",{55,77}}, {"ML",{55,61}}, {"ECH",{55,37}}, {"PAS",{55,21}}, {"HH",{55,13}}, {"RCH",{55,5}}, {"DWE",{40,5}}, {"CPH",{35,5}}, {"LHI",{25,5}}, {"BMH",{15,5}}, {"OPT",{10,5}}, {"EV1",{5,13}}, {"EV2",{5,29}}, {"EV3",{5,37}}, {"PHYS",{5,53}}, {"B1",{5,61}}, {"B2",{5,77}}, {"EIT",{10,85}}, {"ESC",{15,85}}, {"C2",{25,85}}, {"MC",{40,85}}, {"DC",{50,85}}};
std::vector<Unit> Place_Player5{{"AL",{55,78}}, {"ML",{55,62}}, {"ECH",{55,38}}, {"PAS",{55,22}}, {"HH",{55,14}}, {"RCH",{55,6}}, {"DWE",{40,6}}, {"CPH",{35,6}}, {"LHI",{25,6}}, {"BMH",{15,6}}, {"OPT",{10,6}}, {"EV1",{5,14}}, {"EV2",{5,30}}, {"EV3",{5,38}}, {"PHYS",{5,54}}, {"B1",{5,62}}, {"B2",{5,78}}, {"EIT",{10,86}}, {"ESC",{15,86}}, {"C2",{25,86}}, {"MC",{40,86}}, {"DC",{50,86}}};
std::vector<Unit> Place_Player6{{"AL",{55,79}}, {"ML",{55,63}}, {"ECH",{55,39}}, {"PAS",{55,23}}, {"HH",{55,15}}, {"RCH",{55,7}}, {"DWE",{40,7}}, {"CPH",{35,7}}, {"LHI",{25,7}}, {"BMH",{15,7}}, {"OPT",{10,7}}, {"EV1",{5,15}}, {"EV2",{5,31}}, {"EV3",{5,39}}, {"PHYS",{5,55}}, {"B1",{5,63}}, {"B2",{5,79}}, {"EIT",{10,87}}, {"ESC",{15,87}}, {"C2",{25,87}}, {"MC",{40,87}}, {"DC",{50,87}}};



int main()
{
  char letter ;
  int i ;
  int Ln = 0;
  string line ;
  int Col = 0;
  ifstream reader( "Stdboard.txt" ) ;

  if( ! reader ) {
    cout << "Error opening input file" << endl ;
    return -1 ;
  }
  for( i = 0; ! reader.eof() ; i++ ) {
    Col++;
    reader.get( letter ) ;
    if(letter =='\n'){
        Ln++;
        Col = 0;
    }
    if ((Col == 10) &&(Ln==4)){
        cout << "X";
    } else {
        cout << letter ;
    }
    
  }

  reader.close() ;
  cout << i << " I value " << endl;
  cout << Ln << " J value " << endl;
  return 0 ;
}