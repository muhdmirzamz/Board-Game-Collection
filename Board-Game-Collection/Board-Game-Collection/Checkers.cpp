#include "Checkers.h"
#include <iostream>
//Author Kevin Reid
using namespace std;

Checkers::Checkers()
:Game()
{
	startPos();
}

//Method to determine if a player has no pieces remaining.
bool Checkers::checkWin(int currentPlayer){
	if(p1Pieces==0){
		//victor = 1;
		return true;
	}
	else if(p2Pieces==0){
		//victor = 2;
		return true;
	}
	else{
		return false;
	}
}
//Check if a player piece has made it to opposite board edge to be kinged.
void Checkers::checkPromotion(){
	if(currentPlayer==1&&rowDest==7){
		b.board[rowDest][colDest].promote(1);
		cout<<"Player 1 piece at "<<rowDest+1<< " "<<colDest+1<<" is now a king!\n";
	}
	else if(currentPlayer==2&&rowDest==0){
		b.board[rowDest][colDest].promote(2);
		cout<<"Player Two's piece at "<<rowDest+1<< " "<<colDest+1<<" is now a king!\n";
	}
}
//Execute functions to perform a player turn.
void Checkers::takeTurn(int currentPlayer){
	rowOrig = 0;
	colOrig = 0;
	rowKill = 0;
	colKill = 0;
	killing=false;
	cout<<"Player 1: "<<p1Pieces<<" Player 2: "<<p2Pieces<<"\n";
	while(!selectPiece()){
		cout<<"Error, invalid piece.\n";
		rowOrig = 0;
		colOrig = 0;
	}
	while(!selectMoveTo()){
		cout<<"Error, invalid move.\n";
		rowKill = 0;
		colKill = 0;
	}
	swapPieces();
	if(killing){
		killPiece();
	}
	checkPromotion();
}
//Print board state to the standard output.
void Checkers::drawScreen(){
	cout<<"\n";
	cout<<"";
	for(int k = 1; k < 9; k++){
		cout<<"  "<<k;
	}

	cout<<"\n";

	for(int i =0;i<8;i++){
		cout<<(i+1)<<" ";
		for(int j=0;j<8;j++){
			cout<<b.board[i][j].getRepresentation()<<"  ";
		}
		cout<<"\n\n";
	}
	cout<<"\n";
}
//Set board to game starting state.
void Checkers::startPos(){
	for(int i =0;i<8;i++){
		for(int j=0;j<8;j++){
			b.board[i][j].setUpSquare(0);
		}
	}

	for(int i = 0; i < 8; i+=2)
		b.board[0][i].setUpSquare(1);

	for(int i = 0; i < 8; i+=2)
		b.board[1][i+1].setUpSquare(1);

	for(int i = 0; i < 8; i+=2)
		b.board[2][i].setUpSquare(1);

	for(int i = 0; i < 8; i+=2)
		b.board[5][i+1].setUpSquare(2);

	for(int i = 0; i < 8; i+=2)
		b.board[6][i].setUpSquare(2);

	for(int i = 0; i < 8; i+=2)
		b.board[7][i+1].setUpSquare(2);
	opposing = 2;
	p1Pieces = 12;
	p2Pieces = 12;
}

//Private
//Remove a killed piece from the board and adjust player piece count.
void Checkers::killPiece(){
	if(b.board[rowKill][colKill].getPlayer()==1){
		p1Pieces--;
	}
	else{
		p2Pieces--;
	}
	b.board[rowKill][colKill].setUpSquare(0);
}
//Swap pieces to move them.
void Checkers::swapPieces(){
	CheckerSquare tmp = b.board[rowOrig][colOrig];
	b.board[rowOrig][colOrig] = b.board[rowDest][colDest];
	b.board[rowDest][colDest] = tmp;
}

//Function will set the x1,y1,x2,y2 vars based on the player. Allows generalisation of checkMove functions.
void Checkers::setStuff(int &x1, int &y1, int &x2, int &y2){
	if(currentPlayer==1){
		x1=rowOrig;
		y1=colOrig;
		x2=rowDest;
		y2=colDest;
		opposing=2;
	}
	else{
		//Mirrored from player 1.
		x1=rowDest;
		y1=colDest;
		x2=rowOrig;
		y2=colOrig;
		opposing=1;
	}
}
//Function sets the rowKill and colKill vars.
void Checkers::setKill(int y1, int x2, int &y2, int &rowKill, int &colKill){
	//This flag is needed to prevent killing the wrong piece.
	bool left = true;
	cout<<"x1 "<<(x1)<<" y1 "<<(y1)<<"\n";
	cout<<"x2 "<<(x2)<<" y2 "<<(y2)<<"\n";
	//If y is increasing for player 1, it is killing towards the right.
	if(y2>y1&&currentPlayer==1){
		left=false;
	}
	//If y is decreasing for player 2, it has the same effect of a p1 right kill
	else if(y1>y2&&currentPlayer==2){
		cout<<y1<<" is greater than "<<y2<<"\n";
		left=false;
	}
	if(currentPlayer==2&&left){
		y2=y1;
	}
	cout<<"y2: "<<y2<<"\n";
	//cout<<"x1 "<<(x1)<<" y1 "<<(y1)<<"\n";
	//cout<<"x2 "<<(x2)<<" y2 "<<(y2)<<"\n";
	//cout<<"Right "<<right<<"\n";
	//Making a left kill.
	cout<<"Left: "<<left<<"\n";
	cout<<"x2-1: "<<(x2-1)<<" y2+1: "<<(y2+1)<<"\n";
	if(b.board[x2-1][y2+1].getPlayer()==opposing&&left){
		rowKill = x2-1;
		if(currentPlayer==1)
			colKill = y2+1;
		else
			colKill = y2+1;
		killing = true;
		cout<<"Left kill\n";
	}
	//Making a right kill.
	else{
		rowKill = x2-1;
		if(currentPlayer==1)
			colKill = y2-1;
		else
			colKill = y2+1;
		killing = true;
		cout<<"Right kill\n";
	}
	cout<<"rowKill: "<<rowKill<<" colKill: "<<colKill<<"\n";
}

void Checkers::setKingKill(int y1, int x2, int &y2, int &rowKill, int &colKill){
	if(b.board[x2+1][y2-1].getPlayer()==opposing&&y2>y1){
		rowKill = x2+1;
		colKill = y2-1;
		killing = true;
	}
	else{
		rowKill = x2+1;
		colKill = y2+1;
		killing=true;
	}
	//cout<<"rowKill: "<<rowKill<<" colKill: "<<colKill<<"\n";
}

bool Checkers::checkNormMove(int rowOrig, int colOrig, int rowDest, int colDest){
	x1=0; y1=0;
	x2=0; y2=0;
	//
	setStuff(x1,y1,x2,y2);
	//Standard move of a one square diagonal.
	if( x2>x1 && x2-x1==1 && (y1-y2==1||y2-y1==1) && b.board[rowDest][colDest].getPlayer()==0){
		return true;
	}
	//Killing move of two square diagonal.
	else if( (x2>x1 && x2-x1==2) && (y1-y2==2||y2-y1==2) && (b.board[x2-1][y2-1].getPlayer()==opposing||b.board[x2-1][y2+1].getPlayer()==opposing) ){
		setKill(y1,x2,y2,rowKill,colKill);		
		return true;
	}
	//Is not a legal move.
	else{
		return false;
	}
}

bool Checkers::checkKingMove(int rowOrig, int colOrig, int rowDest, int colDest){
	//Check if a normal or killing move is being made in the standard direction allowed for the player.
	if(checkNormMove(rowOrig, colOrig, rowDest, colDest)){
		return true;
	} 
	//Check for a normal move in the direction not standard to the player.
	if( x1>x2 && x1-x2==1 && (y1-y2==1||y2-y1==1) && b.board[rowDest][colDest].getPlayer()==0){
		return true;
	}
	//Check for a killing move in the direction not standard to the player.
	else if( (x1>x2 && x1-x2==2) && (y1-y2==2||y2-y1==2) && (b.board[x2+1][y2+1].getPlayer()==opposing||b.board[x2+1][y2-1].getPlayer()==opposing)){
		setKingKill(y1,x2,y2,rowKill,colKill);
		return true;
	}
	//Is not a legal move.
	else{
		return false;
	}
}

//Simulates attempted moves before the origin position is accepted. Cycles through possible positions 
bool Checkers::predictLegality(int &rowDest, int &colDest){
	for(rowDest = rowOrig - 2; rowDest <= rowOrig + 2; rowDest++){
		for(colDest = colOrig - 2; colDest <= colOrig + 3; colDest++){
			if(colDest>-1 && colDest < 8 && rowDest > -1 && rowDest < 8 && rowDest!=rowOrig && colDest!=colOrig){

				if(b.board[rowOrig][colOrig].isKing()){
					if (checkKingMove(rowOrig, colOrig, rowDest, colDest)){
						return true;
					}
				}
				else if(checkNormMove(rowOrig, colOrig, rowDest, colDest)){
					return true;		
				}			
			}
		}
	}
	cout<<"There is no legal move available, please select a different piece.\n";
	return false;
}
//Get input for the origin position and checks if the player owns the piece there and can make a legal move with it.
bool Checkers::selectPiece(){
	cout<<"Player "<<currentPlayer<<" choose a piece to move.";
	rowOrig=0; colOrig=0;
	cout<<"Choose row and column:\n";
	cin>>rowOrig;
	cin>>colOrig;
	//Deal with unexpected inputs.
	if(cin.fail()){	
        	cin.clear();
        	cin.ignore(1000,'\n');
    	}
	//Check inputs are within the board boundaries.
	if(rowOrig>8||rowOrig<1||colOrig>8||colOrig<1){
		cout<<"Error invalid input. Please re-enter.\n";
		return false;
	}
	rowOrig--;
	colOrig--;
	//Check if a legal move can be made.
	if(b.board[rowOrig][colOrig].getPlayer()==currentPlayer){
		return predictLegality(rowDest,colDest);
	}
	//At this stage the player does not own the piece selected.
	else{
		cout<<"Error, you do not own a piece in that position.\n";
		return false;
	}
}
//Get input for the destination position and checks if the player can leaglly move the piece from the origin position to the inputted destination.
bool Checkers::selectMoveTo(){
	rowDest=0;
	colDest=0;
	killing=false;
	cout<<"Player "<<currentPlayer<<" choose a position to move to.";
	cout<<" Choose row and column:\n";
	cin>>rowDest;
	cin>>colDest;
	//Deal with unexpected inputs.
	if(cin.fail()){	
        	cin.clear();
        	cin.ignore(1000,'\n');
    	}
	//Check inputs are within the board boundaries.
	if(rowDest>8||rowDest<1||colDest>8||colDest<1){
		cout<<"Error invalid input. Please re-enter.\n";
		return false;
	}
	rowDest--;
	colDest--;
	//Check if the destination is occupied.
	if(b.board[rowDest][colDest].getPlayer()!=0){
		cout<<"Error: There is a piece in that position.\n";
		return false;
	}
	//If piece is a king, check if it can make a legal move.
	else if(b.board[rowOrig][colOrig].isKing()){
		return checkKingMove(rowOrig,colOrig,rowDest,colDest);	
	}
	//Check if the piece can make a normal move.
	else{
		return checkNormMove(rowOrig,colOrig,rowDest,colDest);
	}	
}
