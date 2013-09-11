#include <iostream>
#include "ConnectFour.h"
#include "Checkers.h"
#include "Snakes.h"
using namespace std;
//Author Richard Kavanagh

int main() {


	int choice;
	cout << "Welcome to the games compendium" << endl;
	cout << "Please select which game you would like to play" << endl;
	cout << "(1) Connect Four\n";
	cout << "(2) Draughts\n";
	cout << "(3) Snakes and ladders\n";
	cin >> choice;
	

	switch (choice)
	{
		case 1:{
			ConnectFour c;		
			c.play();				
			break;
		}
         	case 2:{
           		Checkers d;
			d.play();
            		break;
		}
         	case 3:{
            		Snakes s;
			s.play();
			break;
		}
     	}
	return 0;
}



