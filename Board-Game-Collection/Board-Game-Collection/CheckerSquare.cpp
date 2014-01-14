#include "CheckerSquare.h"
#include "Square.h"
#include "Piece.h"
//Author Kevin Reid

CheckerSquare::CheckerSquare()
:Square(){

}

bool CheckerSquare::isKing(){
	return (p.representation=="X" || p.representation=="O");
}

void CheckerSquare::promote(int player){
	if(player==1){
		p.representation="X";
	}
	else if(player==2){
		p.representation="O";
	}
}
