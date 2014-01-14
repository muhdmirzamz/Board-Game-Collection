#ifndef GAME_H
#define GAME_H
// Author Richard Kavanagh
class Game {	

protected:

	Game();
	int columns;
	int rows;	


	int turnCount;
	int currentPlayer;	

	// each game will implement its own version of the following methods
	virtual bool checkWin(int currentPlayer) = 0;
	virtual void takeTurn(int currentPlayer) = 0;
	virtual void drawScreen() = 0;


public:
	void play();

	

};
#endif
