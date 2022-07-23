#include "display.h"
#include "player.h"
#include <ncurses.h>

std::vector<PrintHeader> Placement;

void print(){
    initscr();
    char letter[] ="";
    int i ;
    int Ln = 0;
    std::string line ;
    int Col = 0;
    std::ifstream reader( "boardstd.txt" ) ;
    for( i = 0; ! reader.eof() ; i++ ) {
        Col++;
        reader.get( letter[0] ) ;
        if(letter[0] =='\n'){
            Ln++;
            Col = 0;
        }
        printw(letter) ;
    }

    for(auto it = Placement.begin(); it != Placement.end(); it++){
        move((it->Place).Ln,(it->Place).Col);
        printw(it->Icon);
    }
    
    refresh();
    getchar();
    endwin();
    return;
}


void display :: textdisplay(std::vector<Player *> Player_Ptrs, std::vector<char> Player_Dis) {
    Placement.clear();
    std::map<int,Pixel> Basic_places {{0,{55,82}},{1,{55,74}},{2,{55,66}},{3,{55,58}},{4,{55,50}},{5,{55,42}},{6,{55,34}},{7,{55,26}},{8,{55,18}},{9,{55,10}},{10,{55,2}},{11,{50,2}},{12,{45,2}},{13,{40,2}},{14,{35,2}},{15,{30,2}},{16,{25,2}},{17,{20,2}},{18,{15,2}},{19,{10,2}},{20,{5,2}},{21,{5,10}},{22,{5,18}},{23,{5,26}},{24,{5,34}},{25,{5,42}},{26,{5,50}},{27,{5,58}},{28,{5,66}},{29,{5,74}},{30,{5,82}},{31,{10,82}},{32,{15,82}},{33,{20,82}},{34,{25,82}},{35,{30,82}},{36,{35,82}},{37,{40,82}},{38,{45,82}},{39,{50,82}}};
    for (int i = 0 ; i < Player_Ptrs.size();++i){
        PrintHeader temp;
        temp.Icon = (const char *)Player_Dis[i];
        temp.Place = {Basic_places[i].Ln,Basic_places[i].Col +i};
        Placement.emplace_back(temp);
    }
    
    /*
        * Logic to generate a map of the player and location
        * ALso for the improvements 
        * 
        * 
        * 
    */

   print();
}

