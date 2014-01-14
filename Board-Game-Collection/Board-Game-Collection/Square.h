#ifndef SQUARE_H
#define SQUARE_H
#include <string>
#include "Piece.h"
//Author Richard Kavanagh
class Square {

	protected:	
		Piece p;
		bool occupied;		
		
	public:		
		Square();			
		bool isOccupied();
		int getPlayer();
		std::string getRepresentation();	
		void setUpSquare(int player);
};
#endif
