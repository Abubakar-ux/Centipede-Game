#include "Position.h"

Position::Position() {
	x = 0;
	y = 0;
}

Position::Position(int X,int Y) {
	x = X;
	y = Y;
}

Position::Position(const Position &p) {
	x = p.x;
	y = p.y;
}

void Position::setX(int X) {
	x = X;
}

void Position::setY(int Y) {
	y = Y;
}

int Position::getX() const {
	return x;
}

int Position::getY() const {
	return y;
}








