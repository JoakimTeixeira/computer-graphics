// This program displays a canvas that can show different objects and / or changes color according to user interaction

/*
	Basic commands

	1) Mouse:
		- left click: change object to red
		- right click: change object to green 
	
	2) Keyboard:
		- "1" key: draws a blue triangle object
		- "2" key: draws a blue square object
		- C key: clear screen
*/

#include <stdio.h>
#include <GL/glut.h>

// screen size
float DIM = 450;
// screen dimension
float size = 50;
int aux = 0;
// changes color
int aux2 = 0;

void objectTriangle()
{
	if (aux2 == 1)
	{
		// green color
		glColor3f(0, 1, 0);
	}
	else if (aux2 == 2)
	{
		// red color
		glColor3f(1, 0, 0);
	}
	else
	{
		// blue color
		glColor3f(0, 0, 1);
	}

	// triangle coordinates
	glBegin(GL_TRIANGLES);
	glVertex2f(-30, -30);
	glVertex2f(30, -30);
	glVertex2f(0, 30);
	glEnd();
}

void objectSquare()
{
	if (aux2 == 1)
	{
		// green color
		glColor3f(0, 1, 0);
	}
	else if (aux2 == 2)
	{
		// red color
		glColor3f(1, 0, 0);
	}
	else
	{
		// blue color
		glColor3f(0, 0, 1);
	}

	// square coordinates
	glBegin(GL_QUADS);
	glVertex2f(-30, 30);
	glVertex2f(-30, -30);
	glVertex2f(30, -30);
	glVertex2f(30, 30);
	glEnd();
}

void redraw()
{
	// clean screen and change its color to white
	glClearColor(1, 1, 1, 1);

	glClear(GL_COLOR_BUFFER_BIT);
	if (aux == 1)
		objectTriangle();
	if (aux == 2)
		objectSquare();
	glFlush();
}

void mouse(int button, int state, int x, int y)
{

	switch (button)
	{
	case GLUT_LEFT_BUTTON:

		// if (state == GLUT_UP){	// keep pressed click
		aux2 = 1;
		redraw();
		break;
		//}

	case GLUT_RIGHT_BUTTON:

		aux2 = 2;
		redraw();
		break;
	}
}

void keyboard(unsigned char key, int x, int y)
{

	switch (key)
	{
	case '1':
		aux = 1;
		aux2 = 3;
		break;
	case '2':
		aux = 2;
		aux2 = 3;
		break;

	// returns to initial state (without objects) -> function "redraw"
	case 'C':
	case 'c':
		aux = 0;
		break;
	}
	redraw();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(DIM, DIM);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Keyboard and mouse");
	gluOrtho2D(-size, size, -size, size);
	glutDisplayFunc(redraw);
	// recognizes mouse
	glutMouseFunc(mouse);
	// recognizes keyboard
	glutKeyboardFunc(keyboard);
	glutMainLoop();
}