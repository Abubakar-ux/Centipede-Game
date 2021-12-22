#include "Bomb.h"

Bomb::Bomb() {

	pos.setX(0);
	pos.setY(0);
	action = 0;
	p_action = 0;
}

void Bomb::setAction(int a) {
	action = a;
}

int Bomb::getAction() const {
	return action;
}

void Bomb::setPAction(int p) {
	p_action = p;
}

int Bomb::getPAction() const {
	return p_action;
}

void Bomb::setX(int x) {
	pos.setX(x);
}

void Bomb::setY(int y) {
	pos.setY(y);
}

int Bomb::getX() const {
	return pos.getX();
}

int Bomb::getY() const {
	return pos.getY();
}



void Bomb::draw() {



	if(action == 1 && pos.getY() < 810) {
	DrawLine(pos.getX(),pos.getY(),pos.getX()+10,pos.getY(),5,colors[ORANGE]);

	move();
	}


}

void Bomb::move() {

		pos.setY(pos.getY()+25);

}




