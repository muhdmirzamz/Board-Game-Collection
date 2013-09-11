#ifndef CHECKERSSQUARE_H
#define CHECKERSSQUARE_H
#include "Square.h"
//Author Kevin Reid

class CheckerSquare: public Square{
	public:
		CheckerSquare();
		bool isKing();
		void promote(int player);
};
#endif
