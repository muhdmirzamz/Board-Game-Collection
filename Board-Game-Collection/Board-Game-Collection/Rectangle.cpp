#include "Rectangle.h"
#include <iostream>
using namespace std;

	Rectangle::Rectangle(){}

	void Rectangle::getArea(){
		
		int length,width;

		cout << "Please enter length and width\n";
		cin >> length;
		cin >> width;	
		area = (width * length);

	}


	void Rectangle::getPerimeter(){


		int length1,width1;

		cout << "Please enter length and width\n";
		cin >> length1;
		cin >> width1;	
		
		perimeter = (length1 + length1 + width1 + width1);

	}




