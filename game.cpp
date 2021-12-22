 //============================================================================
// Name        : .cpp
// Author      : Sibt ul Hussain
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Centipede...
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "Board.h"
#include "util.h"
#include "GameObject.cpp"
#include "MoveableObject.cpp"
#include "Position.cpp"
#include "Mushroom.cpp"
#include "ScoreBoard.cpp"
#include "Player.cpp"
#include "Bomb.cpp"
#include "Segment.cpp"
#include "Centipede.h"
#include <iostream>
#include <vector>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


/*
 * Main Canvas drawing function.
 * */
Board *b = new Board;
vector<GameObject*> objs;

void bullet() {
	int bullet_x = b->p.getX();
	int bullet_y = b->p.getY();

	b->fire.setX(bullet_x);
	b->fire.setY(bullet_y-10);



}

void status() {
	b->s.setLives(b->centipede.c.getLives());
}

void player() {
	int player_x = b->p.getX();
	int player_y = b->p.getY();

	b->centipede.c.setP_X(player_x);
	b->centipede.c.setP_Y(player_y);
}




void GameDisplay()/**/{
	


	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors


	if(b->s.getLives() != 0)
	{
	b->s.draw(); // ScoreBoard Draw()
	b->m.draw(); // Mushroom Draw()
	b->p.draw(); // Player Draw()

	player(); // Call to player() function.

	b->centipede.c.draw(); // Centipede Object c's draw()



	b->m.setCollisionY(b->fire.getY());
    
	status(); // Call to status() for Score and NumberOfLives.

	if(b->fire.getAction() != 1) {
		bullet();
	}
      
	if(b->fire.getY() > 800) {
		bullet();
		b->fire.setAction(0);
	}



	DrawLine(0 , 4 , 1020, 4 , 8, colors[DEEP_PINK]); // Used to draw lower border.
	DrawLine(0,810,1020,810,4,colors[DEEP_PINK]); // Used to draw upper border.




	if(b->fire.getAction() == 1 || b->centipede.c.getAction() == 1 ) {
		b->fire.draw(); // call to Bomb Draw()
		glutPostRedisplay(); // Used to reframe.

	}

	}

	else { // This is used to give status after NumberOfLives == 0
		DrawString(420,400,"GAME OVER!!!!" , colors[MISTY_ROSE]);
		DrawString(420, 350, "Score= ", colors[MISTY_ROSE]);
		int score = b->s.getScore();
		string s = to_string(score);
		DrawString(490, 350, s, colors[MISTY_ROSE]);
	}


	glutSwapBuffers(); // do not modify this line..

}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key  pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key == GLUT_KEY_LEFT) {

		b->p.setAction(-2);
		b->fire.setAction(0);


	} else if (key == GLUT_KEY_RIGHT) {
		b->p.setAction(2);
		b->fire.setAction(0);
	}

	else if (key == GLUT_KEY_UP) {
		b->p.setAction(1);
		b->fire.setAction(0);
	}

	else if (key == GLUT_KEY_DOWN) {
		b->p.setAction(-1);
		b->fire.setAction(0);
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */

void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		b->p.setAction(0);
		b->fire.setAction(1);
	}
	glutPostRedisplay();
}

/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(1000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *

void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
} */

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */ /*
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{

	}
	glutPostRedisplay();
}
 */
 // our gateway main function

int main(int argc, char*argv[]) {

	b = new Board(60, 60); // create a new board object to use in the Display Function ...


	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	b->InitalizeBoard(width, height);
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("OOP Centipede"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	//glutMouseFunc(MouseClicked);
	//glutPassiveMotionFunc(MouseMoved); // Mouse
	//glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* AsteroidS_CPP_ */
