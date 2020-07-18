// This program displays a cartesian coordinate system, which shows different functions depending on user input

/*
	Basic commands

	Keyboard:
		- "1" key: draws a linear function 
		- "2" key: draws a exponential function
		- "3" key: draws a sine function
		- C key: clear function drawing
		- R key: toggle cartesian system
*/

#include <GL/glut.h>
#include <math.h>

int aux = 1;
int aux2 = 0;

void axis()
{
	glColor3f(0, 0, 0);
	glBegin(GL_LINES);

	// x axis
	glVertex2f(-10, 0);
	glVertex2f(10, 0);

	// y axis
	glVertex2f(0, -10);
	glVertex2f(0, 10);
	glEnd();
}

void function01()
{
	float x, y;
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	for (x = -10; x <= 10; x += 0.01)
	{
		y = x;
		// y = sin(x); sine function
		// y = pow(0.5f, x); // exponential function
		glVertex2f(x, y);
	}
	glEnd();
}

void function02()
{
	float x, y;
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	for (x = -10; x <= 10; x += 0.01)
	{
		y = pow(x, 2);
		glVertex2f(x, y);
	}
	glEnd();
}

void function03()
{
	float x, y;
	glColor3f(1, 0, 0);
	glBegin(GL_POINTS);
	for (x = -10; x <= 10; x += 0.01)
	{
		y = sin(x);
		glVertex2f(x, y);
	}
	glEnd();
}

void redraw()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	if (aux == 1)
	{
		axis();
	}
	else if (aux == 2)
	{
		axis();
		function01();
		aux = 1;
	}
	else if (aux == 3)
	{
		axis();
		function02();
		aux = 1;
	}
	else if (aux == 4)
	{
		axis();
		function03();
		aux = 1;
	}

	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1':
		aux = aux + 1;
		break;
	case '2':
		aux = aux + 2;
		break;
	case '3':
		aux = aux + 3;
		break;
	case 'E':
	case 'e':
		aux = aux * (-1);
		break;
	}
	redraw();
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(450, 450);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Keyboard and math functions");
	// allows use of the keyboard
	glutKeyboardFunc(keyboard);
	gluOrtho2D(-10, 10, -10, 10);
	glutDisplayFunc(redraw);
	glutMainLoop();
}