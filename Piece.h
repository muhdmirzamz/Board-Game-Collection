#ifndef PIECE_H
#define PIECE_H
#include <string>
//Author Kevin Reid
class Piece {
protected:

	friend class Square;
	friend class CheckerSquare;
	friend class SnakeSquare;
	std::string representation;
	int owner;
public:
	Piece();
};
#endif
