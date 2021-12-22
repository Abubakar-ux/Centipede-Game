#ifndef MOVEABLEOBJECT_H_
#define MOVEABLEOBJECT_H_

#include "GameObject.h"

class MoveableObject : public GameObject {

public:
	MoveableObject();
	virtual void move() = 0;
	virtual ~MoveableObject();

};




#endif /* MOVEABLEOBJECT_H_ */
