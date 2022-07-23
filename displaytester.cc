#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "display.h"

using namespace std;


int main(){
	Player Rahul{"Rahul", 500, 0};
	Player Medhu{"Medhu", 1200, 11};
	Player Priyanshu{"Priyanshu", 300, 7};
	Player *p1 = &Priyanshu;
	Player *p2 = &Medhu;
	Player *p3 = &Rahul;
	std::vector<Player*> Player {p1, p2, p3};
	std::vector<char> Names{'P','R','M'};
	display d;
	d.textdisplay(Player,Names);


	return 0;
}
