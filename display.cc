#include "display.h"
#include "player.h"
#include "property.h"
#include <ncurses.h>

std::vector<PrintHeader> Placement;
std::vector<PrintHeader> Improvements;
void print(){
    std::cout << "Inside Print" << std::endl;
    initscr();
    char letter[] ="";
    int i ;
    int Ln = 0;
    std::string line ;
    int Col = 0;
    std::ifstream reader( "boardstd.txt" ) ;
    std::cout << "Reading Began" << std::endl;
    for( i = 0; ! reader.eof() ; i++ ) {
        Col++;
        reader.get( letter[0] ) ;
        if(letter[0] =='\n'){
            Ln++;
            Col = 0;
        }
        attron(A_REVERSE);
        printw(letter) ;
        attroff(A_REVERSE);
    }

    for (int i = 0 ; i < Placement.size(); ++i){
        move((Placement[i].Place).Ln,(Placement[i].Place).Col);
        //attron(A_REVERSE);
        printw(Placement[i].Icon);
        //attroff(A_REVERSE);
    }
    for (int i = 0 ; i < Improvements.size(); ++i){
        move((Improvements[i].Place).Ln,(Improvements[i].Place).Col);
        printw(Improvements[i].Icon);
    }
    move(0,0);
    refresh();
    getchar();
    endwin();
    return;
}


void display :: textdisplay(std::vector<Player *> Player_Ptrs, std::vector<char> Player_Dis, std::vector<Property *> Cards) {
    // std::cout << "SLC WILL GIVE  " << m["SLC"].Col << std::endl;
    Placement.clear();
    std::map<int,Pixel> Basic_places {{0,{54,82}},{1,{54,74}},{2,{54,66}},{3,{54,58}},{4,{54,50}},{5,{54,42}},{6,{54,34}},{7,{54,26}},{8,{54,18}},{9,{54,10}},{10,{54,2}},{11,{49,2}},{12,{44,2}},{13,{39,2}},{14,{34,2}},{15,{29,2}},{16,{24,2}},{17,{19,2}},{18,{14,2}},{19,{9,2}},{20,{4,2}},{21,{4,10}},{22,{4,18}},{23,{4,26}},{24,{4,34}},{25,{4,42}},{26,{4,50}},{27,{4,58}},{28,{4,66}},{29,{4,74}},{30,{4,82}},{31,{9,82}},{32,{14,82}},{33,{19,82}},{34,{24,82}},{35,{29,82}},{36,{34,82}},{37,{39,82}},{38,{44,82}},{39,{49,82}}};

    for (int i = 0 ; i < Player_Ptrs.size();++i) {
        std::cout << Player_Ptrs[i]->getPosition() << std::endl;
        std::cout << Basic_places[0].Ln << std::endl;
        PrintHeader temp{Player_Dis[i],{Basic_places[Player_Ptrs[i]->getPosition()].Ln,Basic_places[Player_Ptrs[i]->getPosition()].Col+ i - 1}};
        Placement.emplace_back(temp);
    }
    for (int i = 0 ; i < Cards.size();++i) {
        if((m[Cards[i]->getName()].Col !=0)&&(Cards[i]->getOwner() != nullptr)){
            for(int j = 0; j < Cards[i]->getImprovemnet(); ++j){
                PrintHeader temp{'I',{m[Cards[i]->getName()].Ln-4,m[Cards[i]->getName()].Col + j}};
                Placement.emplace_back(temp);
            }
            for (int j = 0 ; j < Player_Ptrs.size();++j) {
                if(Player_Ptrs[j]==Cards[i]->getOwner()){
                    PrintHeader temp{Player_Dis[j],{m[Cards[i]->getName()].Ln-4,m[Cards[i]->getName()].Col + 7}};
                    Placement.emplace_back(temp);
                }
            }
        }
    }
   print();
}

