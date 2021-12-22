#ifndef SEGMENT_H_
#define SEGMENT_H_

#include "GameObject.h"
#include "MoveableObject.h"

class Segment : public MoveableObject {

protected:
	int *fx;
	int *fy;
	int x;
	int y;
	int condition;
	int reset_y;
	int reset_x;
	int size;
	int action;
	int lives;
	int p_x;
	int p_y;

public:
	Segment();
	int getAction() const;
	int getLives() const;
	void setP_X(int x);
	void setP_Y(int y);
	void draw();
	void move();

};




#endif /* SEGMENT_H_ */
