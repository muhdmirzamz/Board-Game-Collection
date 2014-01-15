//Implementation for Game
// Author Richard Kavanagh
#include "Game.h"
#include <iostream>
using namespace std;


	Game::Game() {
	
		// sets the number of players to 1 on constructor
		currentPlayer = 1;
		turnCount = 0;
		
	}
	
	void Game::play() {
		drawScreen();
			
		while(true){
		
			takeTurn(currentPlayer);
			
			if(checkWin(currentPlayer) == true){
				drawScreen();	
				cout << "PLayer 1 wins !" << endl;
				break;
			}
			
			drawScreen();
			currentPlayer++;
			takeTurn(currentPlayer);
			
			if(checkWin(currentPlayer) == true){
				drawScreen();	
				cout << "PLayer 2 wins !" << endl;
				break;
			}
			drawScreen();
			currentPlayer--;
		}	
		cout << "Thanks for Playing" << endl;	
	}
