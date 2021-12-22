#ifndef PLAYER_H_
#define PLAYER_H_

#include "MoveableObject.h"
#include "Bomb.h"

class Player : public MoveableObject {

	int action;
public:

	Player();
	void setAction(int a);
	int getAction() const;
	int getX() const;
	int getY() const;
	void move();
	void draw();

};




#endif /* PLAYER_H_ */
