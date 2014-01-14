#ifndef PIECE_H
#define PIECE_H
#include <string>
//Author Kevin Reid

using namespace std;

class Piece {
protected:

	friend class Square;
	friend class CheckerSquare;
	friend class SnakeSquare;
	
	string representation;
	int owner;
	
public:
	Piece();
	
};
#endif
