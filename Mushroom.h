#ifndef MUSHROOM_H_
#define MUSHROOM_H_

#include "GameObject.h"
#include "util.h"
#include "Board.h"
#include "Bomb.h"
#include <ctime>

class Mushroom : public GameObject {

protected:

	int *fx;
	int *fy;
	int noOfMushrooms;
	int collision_y;

public:
	Mushroom();
	void setCollisionY(int y);
	int getCollisionY() const;
	void draw();




};




#endif /* MUSHROOM_H_ */
