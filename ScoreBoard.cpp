#include "ScoreBoard.h"

ScoreBoard::ScoreBoard() {
	NumberOfLives = 2;
	Score = 0;
}

void ScoreBoard::setLives(int n) {
	NumberOfLives = n;
}

int ScoreBoard::getLives() const {
	return NumberOfLives;
}

void ScoreBoard::setScore(int n) {
	Score = n;
}

int ScoreBoard::getScore() const {
	return Score;
}

void ScoreBoard::draw() {
	DrawString(0, 820, "Score= ", colors[MISTY_ROSE]);
	string score = to_string(Score);
	DrawString(70,820,score,colors[MISTY_ROSE]);
	DrawString(810,820, "NumberOfLives= ", colors[MISTY_ROSE]);
	string lives = to_string(NumberOfLives);
	DrawString(990,820,lives,colors[MISTY_ROSE]);

}



