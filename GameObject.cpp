#include "GameObject.h"

GameObject::GameObject() {
	pos.setX(0);
	pos.setY(0);
}

GameObject::GameObject(Position &p) {
	pos.setX(p.getX());
	pos.setY(p.getY());
}

GameObject::GameObject(const GameObject &obj) {
	pos = obj.pos;
}

void GameObject::setPos(Position &p) {
	pos = p;
}

Position GameObject::getPos() const {
	return pos;
}

GameObject::~GameObject() {
	pos.setX(0);
	pos.setY(0);
}




