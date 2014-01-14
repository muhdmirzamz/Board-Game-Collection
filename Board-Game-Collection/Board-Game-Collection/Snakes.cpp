//Implementation for SnakesAndLAdders
//Author Shared
#include <stdlib.h>		
#include <iostream>
#include "Snakes.h"
#include "Square.h"
#include "Game.h"
#include <stdio.h>
#include <sstream>


using namespace std;


	//Implemented by Kevin Reid
	Snakes::Snakes():Game() {


		player1Pos.x=9; player1Pos.y=0;
		player2Pos.x=9; player2Pos.y=0;
		s.grid[9][0].setStartSquare();
		int tens = 0;					
		int rep = 0;
		std::string repS;
		
		for(int x = 9; x >= 0; x--){
			for(int y = 0; y < 10; y++){
				rep = tens+(y+1);
				std::ostringstream ostr;
				ostr << rep;
				repS = ostr.str(); 
				if(repS.length()<2)
					repS = "  "+repS;
				else if(repS.length()<3)
					repS = " "+repS;
				s.grid[x][y].setSquareRepresentation(repS);
			}
			tens+=10;
		}
		addEntities();
		player1Stuck = false;
		player2Stuck = false;

	
	}


	//Implemented by Richard Kavanagh
	// Much longer than intended, a player class would have been ideal
	void Snakes::takeTurn(int currentPlayer){
		
		srand(time(NULL));	//seeded for dice roll
		char input;
		do{
			cout << "Player " << currentPlayer << " it is your go\n";
			cout << "Please enter r to roll the dice\n";
			cin >> input;
			if(cin.fail()){			// for invalid input
				cout << "Invalid input";
          		 	cin.clear();
           		 	cin.ignore(1000,'\n');
			}
		}
		while(input != 'r');		

		

		int playerRoll = rand()%6+1;
		cout << "player " << currentPlayer << " you rolled a " << playerRoll <<"\n";
		
		if(currentPlayer == 1 && player1Stuck && playerRoll == 6){
			player1Stuck =  false;
		}


		if(currentPlayer == 2 && player2Stuck && playerRoll == 6){
			player2Stuck = false;
		}


		// players must land exactly on the end square
		if(distanceToEnd() < playerRoll ) {		
			cout << "Sorry you cannot move this turn";
			return;
		}


		// used if player had previously rolled 3 6's
		if(currentPlayer == 1 && player1Stuck == true){
			cout << "Sorry you need to roll a six before you can move";
			return;
		}
		else if(currentPlayer == 2 && player2Stuck){
			cout << "Sorry you need to roll a six before you can move"; 
			return;
		}

		
	
		updateDiceCount(playerRoll);
		
		if(lastThreeRollsSix() == true){
			moveToStart();
		}	

		// movement of pieces
		if(currentPlayer == 1){
			
			if(player1Pos.y + playerRoll > 9){
				
				int temp = (playerRoll + player1Pos.y) % 10;
				Coordinate destination( player1Pos.x -1, temp);
				movePiece(currentPlayer, player1Pos , destination);     
				if(s.grid[destination.x][destination.y].isSpecial())
					player1Pos = s.grid[destination.x][destination.y].getEndPoint();
				else
					player1Pos = destination;
			}
			else {		
				
				Coordinate destination( player1Pos.x,  player1Pos.y + playerRoll);			
				movePiece(currentPlayer,player1Pos ,  destination);

				if(s.grid[destination.x][destination.y].isSpecial())
					player1Pos = s.grid[destination.x][destination.y].getEndPoint();
				else
					player1Pos = destination;
			}


		}
		else if(currentPlayer == 2){	
			
			if(player2Pos.y + playerRoll > 9){
				
				int temp = (playerRoll + player2Pos.y) % 10;
				Coordinate destination( player2Pos.x -1, temp);	
				movePiece(currentPlayer,  player2Pos  , destination);     // minus 1 as we are moving up one row, 
				if(s.grid[destination.x][destination.y].isSpecial())
					player2Pos = s.grid[destination.x][destination.y].getEndPoint();
				else					
					player2Pos = destination;
				
			}
			else {	
					
				Coordinate destination( player2Pos.x,  player2Pos.y + playerRoll);		
				movePiece(currentPlayer, player2Pos ,  destination);
				if(s.grid[destination.x][destination.y].isSpecial())
					player2Pos = s.grid[destination.x][destination.y].getEndPoint();
				else
					player2Pos = destination;
			}
		}

	}



	// helper methods start here

	//Implemented by Kevin Reid
	void Snakes::movePiece(int currentPlayer, Coordinate current, Coordinate destination){
		
		if(s.grid[destination.x][destination.y].isSpecial()){
			Coordinate c = s.grid[destination.x][destination.y].getEndPoint();
			destination = c;
		}

		Piece tmp = s.grid[current.x][current.y].takePiece(currentPlayer);
		s.grid[destination.x][destination.y].addPiece(tmp,currentPlayer);
	}

	//Implemented by Richard Kavanagh
	bool Snakes::lastThreeRollsSix(){

		if(currentPlayer == 1) return player1Six == 3;
		if(currentPlayer == 2) return player2Six == 3;
	}

	//Implemented by Richard Kavanagh
	int Snakes::distanceToEnd(){		// need to take into account reverse display of board
								
		if(currentPlayer == 1 && player1Pos.x != 0)
			return   ((player1Pos.x * 10) + player1Pos.y);
		else if(currentPlayer == 1 && player1Pos.x == 0)
			return (10 + player1Pos.x) - (player1Pos.y + 1);	
			
		if(currentPlayer == 2 && player2Pos.x != 0)
			return   ((player2Pos.x * 10) + player2Pos.y);
		else if(currentPlayer == 2 && player2Pos.x == 0)
			return (10 + player2Pos.x) - (player2Pos.y + 1);
				
	}

	//Implemented by Richard Kavanagh
	bool Snakes::checkWin(int currentPlayer){

		return (s.grid[0][9].isOccupied());
	}


	// displays the board and pieces on the screen
	//Prints the board in the right to left, left to right, right to left etc. format.
	//Implemented by Kevin Reid
	void Snakes::drawScreen(){
		cout<<"\n";
		cout<<"";
		int j;
		for(int i =0;i<10;i++){
			//Right to left increment.
			if(i%2!=0){
				for(j=0;j<10;j++){
					printRow(i, j);			
				}
			}
			//Left to right increment.
			else{
				for(j=9;j>=0;j--){
					printRow(i, j);			
				}
			}
			cout<<"\n";
		}
		cout<<"\n";	
	}

	//Prints the row using representations variables.
	//Implemented by Kevin Reid
	void Snakes::printRow(int row, int col){
		//If occupied, print the piece.
		if(s.grid[row][col].isOccupied()){
			//If the piece in the player 1 slot is 1, print it.
			if(s.grid[row][col].getPieceOwner(1)==1){
				cout<<"   "<<s.grid[row][col].getPieceRepresentation(1);
			}
			//Otherwise print the piece from slot player 2.
			else{
				cout<<"   "<<s.grid[row][col].getPieceRepresentation(2);
			}
		}
		//No pieces on the square.
		else{
			//If the square is standard and has no piece on it.
			if(!s.grid[row][col].isSpecial())
				cout<<" "<<s.grid[row][col].getSquareRepresentation();
			//If the square is special and has no piece on it.
			else
				cout<<" "<<s.grid[row][col].getSquareRepresentation();
		}
	}

		
	//Implemented by Richard Kavanagh
	// moves piece back to the starting square
	void Snakes::moveToStart(){

		Coordinate end(9,0);
		
		if(currentPlayer == 1){
			cout << "Sorry player 1 you have been moved back to the starting position";
			movePiece(currentPlayer, player1Pos ,end );			
			player1Stuck = true;
			player1Pos = end;
			player1Six = 0;			// need to reset it to 0
			return;
		}
		else{
			cout << "Sorry player 2 you have been moved back to the starting position";
			movePiece(currentPlayer,player2Pos  ,end  );			
			player2Stuck = true;
			player2Pos = end;
			player2Six = 0;  // need to reset it to 0
			return;
		}
	}
	
	//Implemented by Richard Kavanagh
	// keeps track of 6's rolled
	void Snakes::updateDiceCount(int playerRoll) {

		if(currentPlayer == 1 && playerRoll == 6)
			player1Six++;
		else player1Six--;

		if(player1Six < 0)
			player1Six = 0;


		if(currentPlayer == 2 && playerRoll == 6)
			player2Six++;
		else player2Six--;

		if(player2Six < 0)
			player2Six = 0;
	}


	//Implemented by Kevin Reid
	// used to add the "Snakes and ladders to the game"
	void Snakes::addEntities(){
			s.grid[9][7].setSpecial(" L1",2,3);
			s.grid[2][3].squareRepresentation =" L1";

			s.grid[6][3].setSpecial(" L2",3,3);
			s.grid[3][3].squareRepresentation =" L2";

			s.grid[3][4].setSpecial(" L3",0,2);
			s.grid[0][2].squareRepresentation =" L3";

			s.grid[5][4].setSpecial(" S1",8,3);
			s.grid[8][3].squareRepresentation =" S1";

			s.grid[3][6].setSpecial(" S2",2,0);
			s.grid[2][0].squareRepresentation =" S2";

			s.grid[0][7].setSpecial(" S3",4,6);
			s.grid[4][6].squareRepresentation =" S3";
		}






















	
