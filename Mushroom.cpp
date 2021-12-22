#include "Mushroom.h"

Mushroom::Mushroom() {
	srand(time(NULL));

	noOfMushrooms = 20;
	fx = new int[noOfMushrooms];
	fy = new int[noOfMushrooms];
	collision_y = 0;

	int x , y;

	for(int i = 0; i<noOfMushrooms; i++) {
		x = 100 + rand() % 800;
		y = 150 + rand() % 500;
		if(x < 1000 && y < 800 &&  y > 100) {
			fx[i] = x;
			fy[i] = y;
		}
	}
}

void Mushroom::setCollisionY(int y) {
	collision_y = y;
}


int Mushroom::getCollisionY() const {
	return collision_y;
}



void Mushroom::draw() {


	for(int i = 0; i<noOfMushrooms; i++) {

		if((collision_y == fy[i])|| (collision_y == fy[i]+1) || (collision_y == fy[i]+2) || (collision_y == fy[i]+3) || (collision_y == fy[i]+4) || (collision_y == fy[i]+5)) {
			DrawSquare( fx[i] , fy[i] ,10,colors[BLACK]);
		}
		if(collision_y != fy[i])
		DrawSquare( fx[i] , fy[i] ,10,colors[RED]);
	}

}




