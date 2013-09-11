#ifndef SNAKESQUARE_H
#define SNAKESQUARE_H

#include "Square.h"
#include <string>
//Author Kevin Reid

struct Coordinate{
	int x;
	int y;

	Coordinate(int x0, int y0){
		x = x0;
		y = y0;
	}

	Coordinate(){
		x=0;
		y=0;
	}
	
};


struct Holder{
	Piece pieces [2];
};

class SnakeSquare: public Square{
protected:
	
	//Stores piece, if a piece is moved out it is replace with the default piece.
	Holder h;
	bool special;

	//std::string getSquareRepresentation();
	Coordinate c;
	

public:
	SnakeSquare();
	void addPiece(Piece p, int player);
	Piece takePiece(int player);
	std::string getSquareRepresentation();
	std::string getPieceRepresentation(int player);
	Coordinate getEndPoint();
	void setSquareRepresentation(std::string rep);
	void setStartSquare();
	int getPieceOwner(int player);
	void setSpecial(std::string s, int x, int y);
	bool isSpecial();
	std::string squareRepresentation;
};
#endif
