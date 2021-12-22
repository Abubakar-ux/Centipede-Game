#include "Segment.h"
#include "ScoreBoard.h"

Segment::Segment() {
	size = 5;
	fx = new int[size];
	fy = new int[size];
	action = 1;
	p_x = 0;
	p_y = 0;

	x = 920;
	y = 790;
	reset_x = 920;
	reset_y = 790;
	condition = 1;
	lives = 2;

	for(int i = 0; i<size; i++) {
		fx[i] = x;
		fy[i] = y;
		x = x+20;
	}



}

int Segment::getAction() const {
	return action;
}

int Segment::getLives() const {
	return lives;
}

void Segment::setP_X(int x) {
	p_x = x;
}

void Segment::setP_Y(int y) {
	p_y = y;
}

void Segment::draw() {
	for(int i = 0; i<size; i++) {
		DrawCircle(fx[i],fy[i],10,colors[ORANGE]);
	}
	move();
}

void Segment::move() {


	for(int i = 0; i<size; i++) {

		if(condition%2 != 0 && fy[i] > 10) {
			fx[i] = fx[i] - 10;
			if(fx[i] < 5) {
				for(int j = 0; j<size; j++)
				fy[j] = y-30;
				fx[i] = 10;
				condition++;
				y = y - 30;
			}
		}

		if(fy[i] <= 10 || (fx[i] == p_x && fy[i] == p_y ) || (fx[i] == p_x+1 && fy[i] == p_y+1) || (fx[i] == p_x+2 && fy[i] == p_y+2) || (fx[i] == p_x+3 && fy[i] == p_y+3) || (fx[i] == p_x+4 && fy[i] == p_y+4) || (fx[i] == p_x+5 && fy[i] == p_y+5) || (fx[i] == p_x+6 && fy[i] == p_y+6) || (fx[i] == p_x+7 && fy[i] == p_y+7) || (fx[i] == p_x+8 && fy[i] == p_y+8) || (fx[i] == p_x+9 && fy[i] == p_y+9) || (fx[i] == p_x+10 && fy[i] == p_y+10)
			|| (fx[i] == p_x-1 && fy[i] == p_y) || (fx[i] == p_x-1 && fy[i] == p_y+1) || (fx[i] == p_x-2 && fy[i] == p_y+2) || (fx[i] == p_x-3 && fy[i] == p_y+3) || (fx[i] == p_x-4 && fy[i] == p_y+4) || (fx[i] == p_x-5 && fy[i] == p_y+5) || (fx[i] == p_x-6 && fy[i] == p_y+6) || (fx[i] == p_x-7 && fy[i] == p_y+7) || (fx[i] == p_x-8 && fy[i] == p_y+8) || (fx[i] == p_x-9 && fy[i] == p_y+9) || (fx[i] == p_x-10 && fy[i] == p_y+10)) {
			x = reset_x;
			y = reset_y;

			for(int j = 0; j<size; j++){
					fy[j] = y;
					fx[j] = x;
					x = x + 20;
			}

			lives -= 1;

		}

		if(condition%2 == 0 && fy[i] > 10) {
			fx[i] = fx[i] + 10;
			if(fx[i] >= x) {
				for(int j = 0; j<size; j++)
				fy[j] = y-30;
				fx[i] = x;
				condition++;
				y = y - 30;
			}
		}
	}
}




