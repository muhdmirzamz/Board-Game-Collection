//
//  Rectangle.h
//  Board-Game-Collection
//	Rectangle header class
//
//  Created by Muhd Mirza on 15/1/14.
//  Copyright (c) 2014 Muhd Mirza. All rights reserved.
//

#ifndef Board_Game_Collection_Rectangle_h
#define Board_Game_Collection_Rectangle_h

class Rectangle {
public:
	Rectangle();
	
	void getArea();
	void getPerimeter();
				
private:
	int area;
	int perimeter;
};

#endif
