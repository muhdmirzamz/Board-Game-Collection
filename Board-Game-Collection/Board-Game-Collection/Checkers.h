#ifndef CHECKERS_H
#define CHECKERS_H
#include "CheckerSquare.h"
#include "Game.h"
//Author Kevin Reid
struct CheckerBoard{
	CheckerSquare board [8][8]; //use these in loops elsewhere.
} b;

class Checkers:public Game{
protected:
	int p1Pieces;
	int p2Pieces;
	int rowOrig;
	int colOrig;

	int rowDest;
	int colDest;

	int rowKill;
	int colKill;

	int opposing;
	bool killing;

	int x1;
	int x2;
	int y1;
	int y2;

public:
	Checkers();
	bool checkWin(int currentPlayer);
	void takeTurn(int currentPlayer);
	void drawScreen();
	void playGame();
	void startPos();
	void testKillOne();
	void testKillTwo();

private:
	void killPiece();
	void swapPieces();

	bool checkNormMove(int rowOrig, int colOrig, int rowDest, int colDest);
	bool checkKingMove(int rowOrig, int colOrig, int rowDest, int colDest);

	bool predictLegality(int &rowDest, int &colDest);
	bool selectPiece();
	bool selectMoveTo();

	void setStuff(int &x1, int &y1, int &x2, int &y2);
	void setKill(int y1, int x2, int &y2, int &rowKill, int &colKill);
	void setKingKill(int y1, int x2, int &y2, int &rowKill, int &colKill);

	void checkPromotion();
};
#endif
