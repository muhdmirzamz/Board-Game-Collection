//Implementation for Connect Four
// Author Richard Kavanagh
#include <stdlib.h>
#include <iostream>
#include "ConnectFour.h"
#include "Square.h"
#include "Game.h"


using namespace std;

	
	ConnectFour::ConnectFour():Game(){

		rows = 6;
		columns = 7;
		// used for bounds checking in takeTurn
		for(int i = 0; i <columns; i ++ )
			columnHeight[i] = 0;
	}

	
	// displays board 
	void ConnectFour::drawScreen(){
		cout<<" 1    2    3    4    5    6    7\n";
		for(int i = 0; i < rows; i++) {
			for (int x = 0; x < columns; x++){
                        	cout<< "[ " << b.grid[i][x].getRepresentation() << " ]";
                        }
                        cout<< endl;
		}	
	}

		
	// checkwin is split into 3 smaller methods 
	bool ConnectFour::checkWin(int player) {
		return (fourRow());
	}



	// each player enters the column they wish to add a piece to
	void ConnectFour::takeTurn(int currentPlayer){
		
		int input = 0;

		if(boardFull()){
			cout << "Looks like it is a draw\n";
			exit(1);
		}

		
		do {
			cout << "Player " << currentPlayer << " it is your go\n";
			cout << "Please enter the column you wish to drop your piece\n";
			cin >> input;
			if(cin.fail()){	// for invalid input
				cout << "Invalid input";
          		 	cin.clear();
           		 	cin.ignore(1000,'\n');
			}
			
		}
		while(input < 1 || input > 7 || columnHeight[input - 1] == 6);
		
		input--;
		columnHeight[input]++;
		b.grid [rows-(columnHeight[input])][input].setUpSquare(currentPlayer);	//adds piece to the square at column selected
		lastMove = input;	// lastMove used for win checking		
		turnCount++;	
	}


	 bool ConnectFour::fourRow() {
		
		int temp = lastMove;
		checkInRow( 6 - (columnHeight[lastMove]), lastMove ); 		//  lastPiece entered x, y coordinates
	}


	// instead of checking every combination, we only check around the last piece placed
	bool ConnectFour::checkInRow(int x, int y) {

   		if (isMatch(x, y, 1,  0) +  isMatch(x, y, -1, 0) >= 3) return true;	// vertical check right + vertical check left
		if (isMatch(x, y, 0,  1) +  isMatch(x, y, 0, -1) >= 3) return true;	// horizontal check right + horizontal check left
	        if (isMatch(x, y, 1,  1) +  isMatch(x, y, -1,-1) >= 3) return true;	// diagonal check
		return (isMatch(x, y, 1, -1) +  isMatch(x, y, -1, 1) >= 3);		// diagonal check
	}


	int ConnectFour::isMatch(int x, int y, int directionX, int directionY) {
    
		int count = 0;
   		Square startSquare = b.grid[x][y];		// the piece we just put down
   		for (int i = 1; i < 4; ++i) {
			if(x + (i * directionX) > 5 || y + (i * directionY) > 6)	// bounds checking
				return count;
        		if (b.grid[x + i * directionX][y + i * directionY].getPlayer() == startSquare.getPlayer())	// checking for same owner
            			count++;	// increments if owner is same
		}
   		 return count;
	}

	// used in case of a draw
	bool ConnectFour::boardFull() {
		return (turnCount == 42);
	}


	
