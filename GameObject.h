#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Position.h"
#include "util.h"

class GameObject {
protected:
	Position pos;

public:
	GameObject();
	GameObject(Position &p);
	GameObject(const GameObject &obj);
	void setPos(Position &p);
	Position getPos() const;
	virtual void draw() = 0;
	virtual ~GameObject();

};




#endif /* GAMEOBJECT_H_ */
