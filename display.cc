#include "display.h"
#include <player.h>
#include <ncurses.h>

std::vector<PrintHeader> Placement;

void print(){
    initscr();
    char letter[] ="";
    int i ;
    int Ln = 0;
    string line ;
    int Col = 0;
    ifstream reader( "boardstd.txt" ) ;
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
        printw((it->Player).Icon);
    }
    
    refresh();
    getchar();
    endwin();
    return;
}


void display :: textdisplay(std::vector<Player *> Player_Ptrs) {
    Placement.clear();
    std::map<int,std::string> Basic_places;
    for (auto it = Player_Ptrs.begin(); it != Player_Ptrs.end(); it++){
        PrintHeader temp;
        temp->Icon = it->getName();
        temp->Pixel = Basic_places[it->getPosition()];
        Placement.emplace_back(temp);

    }
    /*
        * Logic to generate a map of the player and location
        * ALso for the improvements 
        * 
        * 
        * 
    */

   print()

}

