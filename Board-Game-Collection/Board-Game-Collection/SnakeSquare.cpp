#include "SnakeSquare.h"
#include <string>
#include <iostream>
//Author Kevin Reid
SnakeSquare::SnakeSquare()
:Square()
{
	special = false;
}

void SnakeSquare::addPiece(Piece pa, int player){
	
	if(player==1){
		
		h.pieces[0]=pa;
	}
	else{
		h.pieces[1]=pa;
	}
	occupied = true;
}
//This doesn't actually get the right stuff from the holder yet.
Piece SnakeSquare::takePiece(int player){
	//setDefault();
	
	
	Piece tmp;
	
	if(player==1){
		tmp = h.pieces[0];
		//Set to default piece.
		h.pieces[0]=p;
		
		//If other piece is default. No longer occupied.
		
		if(h.pieces[1].owner==0){
			occupied=false;
			//std::cout<<"Square is now empty";
		}
		//std::cout<<"Took from slot 1\n";
		return tmp;
	}
	else{
		tmp = h.pieces[1];
		h.pieces[1]=p;
		
		//If other piece is default. No longer occupied.
	
		if(h.pieces[0].owner==0)
			occupied = false;
		return tmp;
	}
}
//Gives the piece representation from the holder, if the players piece isn't there it should return 0.
int SnakeSquare::getPieceOwner(int player){
	return h.pieces[player-1].owner;
}
//Gives the squares number used for printing when there is no piece or it is not a special square.
std::string SnakeSquare::getSquareRepresentation(){
	return squareRepresentation;
}
//Gives the piece representation from the holder, if the players piece isn't there it should return blank.
std::string SnakeSquare::getPieceRepresentation(int player){
	return h.pieces[player-1].representation;
}
//Sets the square to special and sets the end point coordinate to a given x and y.
void SnakeSquare::setSpecial(std::string s, int x, int y){
	c.x=x; c.y=y;
	squareRepresentation = s;
	special = true;
}
// Gives a square both pieces in its holder.
void SnakeSquare::setStartSquare(){
	h.pieces[0].owner=1;
	h.pieces[0].representation="X";
	h.pieces[1].owner=2;
	h.pieces[1].representation="O";
	occupied=true;
}


Coordinate SnakeSquare::getEndPoint(){
	return c;
}

void SnakeSquare::setSquareRepresentation(std::string rep){
	squareRepresentation = rep;
}

bool SnakeSquare::isSpecial(){
	return special;
}
