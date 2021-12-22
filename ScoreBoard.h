#ifndef SCOREBOARD_H_
#define SCOREBOARD_H_

#include "GameObject.h"
#include "util.h"

class ScoreBoard : public GameObject {

protected:
	int NumberOfLives;
	int Score;

public:
	ScoreBoard();
	void setLives(int n);
	int getLives() const;
	void setScore(int n);
	int getScore() const;
	void draw();

};




#endif /* SCOREBOARD_H_ */
