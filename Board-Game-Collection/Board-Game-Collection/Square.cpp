#include "Square.h"
#include "Piece.h"
#include <iostream>
#include <string>
//Author Richard Kavanagh
using namespace std;


//default square, no player owner and unoccupied
Square::Square(){
	p.owner = 0;
	occupied = false;
}



bool Square::isOccupied(){
	return occupied;
}

int Square::getPlayer(){
	return p.owner;
}

string Square::getRepresentation(){
	return p.representation;
}

	// assigns values to an already created square
void Square::setUpSquare(int player){
	if(player==1){
		p.owner=player;
		p.representation="x";
		occupied = true;
	}
	else if(player==2){
		p.owner=player;
		p.representation="o";
		occupied = true;
	}
	else{
		p.owner=0;
		p.representation="-";
		occupied=false;
	}
}
