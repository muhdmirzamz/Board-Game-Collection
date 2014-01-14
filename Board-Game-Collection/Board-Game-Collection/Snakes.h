#ifndef SnakesAndLadders_H
#define SnakesAndLadders_H
#include "SnakeSquare.h"
#include "Game.h"
//Author Shared




struct SnakeBoard {
	SnakeSquare grid [10][10];
};


class Snakes : public Game {	

public:
	Snakes();
	void drawScreen();
	bool checkWin(int currentPlayer);
	void takeTurn(int currentPlayer);
	

protected:
	SnakeBoard s;
	


private:

	bool lastThreeRollsSix();
	int distanceToEnd();
	void movePiece(int currentPlayer, Coordinate current, Coordinate destination);
	void printRow(int row, int col);
	void addEntities();
	void moveToStart();
	void updateDiceCount(int playerRoll);


	// used to keep track of 6's rolled
	int player1Six;
	int player2Six;
	

	// used to keep track of players positions
	Coordinate player1Pos;
	Coordinate player2Pos;	

	// if a player rolled 3 6's and is at the starting square
	bool player1Stuck;
	bool player2Stuck;

};
#endif
