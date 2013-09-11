#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H
#include "Square.h"
#include "Game.h"
// Author Richard Kavanagh

struct ConnectFourBoard {
	Square grid [6][7];
};


class ConnectFour : public Game {	

public:
	ConnectFour();
	void drawScreen();
	bool checkWin(int currentPlayer);
	void takeTurn(int currentPlayer);
	

protected:
	ConnectFourBoard b;
	int columnHeight[7];
	int lastMove;	


private:
	//helper methods
	bool fourRow();
	bool checkInRow(int x, int y);
	int isMatch(int x, int y, int directionX, int directionY);
	bool boardFull();

};
#endif
