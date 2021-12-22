#include "Player.h"

Player::Player() {
	action = 0;
	pos.setX(550);
	pos.setY(20);
}

void Player::setAction(int a) {
	action = a;
}

int Player::getAction() const {
	return action;
}

int Player::getX() const {
	return pos.getX();
}

int Player::getY() const {
	return pos.getY();
}

void Player::draw() {

	move();

	DrawTriangle(pos.getX(), pos.getY()+20 , pos.getX()+20, pos.getY()+20 , pos.getX()+10 , pos.getY()+40, colors[MISTY_ROSE] );

}

void Player::move() {
	int x = pos.getX();
	int y = pos.getY();

	if(action == 1) {
		if(pos.getY() < 60)
		pos.setY(y+10);
	}

	if(action == -1) {
		if(pos.getY() > -10)
		pos.setY(y-10);
	}

	if(action == 2) {
		if(pos.getX() < 1000)
		pos.setX(x+10);
	}

	if(action == -2) {
		if(pos.getX() > 0)
		pos.setX(x-10);
	}
}




