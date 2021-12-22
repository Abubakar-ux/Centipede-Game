#ifndef BOMB_H_
#define BOMB_H_

#include "MoveableObject.h"
#include "Player.h"

class Bomb : public MoveableObject {

	int action;
	int p_action;

public:
	Bomb();
	void setAction(int a);
	void setPAction(int p);
	int getPAction() const;
	int getAction() const;
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	void draw();
	void move();
};




#endif /* BOMB_H_ */
