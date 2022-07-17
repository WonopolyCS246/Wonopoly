#include grid.h

<Property *> Grid::card{

}

<Players *> Grid::players{

}
<string, int> Grid::piece{

}

void Grid::roll(){

}

void Grid::nextTurn(){

}

void Grid::trade(){

}

Property* Grid::getProperty(string propertyName){

}

void Grid:: Grid::buyProperty(Property* p){

}

void Grid::sellProperty(Property* p){

}

void Grid::mortgage(Property* p){

}

void Grid::unmortgage(Property* p){

}


bool Grid::bankrupt(){

}

int Grid::assets(){

}

int Grid::all{

}
// Explicitly defining the type of auction
void Grid::auctionProperty(Property * p){

}
// auctionPlayer() calls auctionProperty() on all properties owned by player 
void Grid::auctionPlayer(Player * p){

}

void Grid::transfer(Player * p1, Player * p2){

}

    
