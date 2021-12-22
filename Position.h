#ifndef POSITION_H_
#define POSITION_H_

#include <iostream>
using namespace std;

class Position {
protected:
	int x;
	int y;

public:
	Position();
	Position(int X,int Y);
	Position(const Position &p);
	void setX(int X);
	void setY(int Y);
	int getX() const;
	int getY() const;

};




#endif /* POSITION_H_ */
