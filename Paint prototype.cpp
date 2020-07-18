// This program displays a white canvas that can be painted over
/*
	Basic commands

	1) Mouse
		- Left click: insert point to draw a polygon object
		- Right click: erases canvas

	2) Keyboard
		- D key: reset object to defaut color
		- R key: change object color to red
		- G key: change object color to green
		- B key: change object color to blue
		- P key: User inserts polygon coordinates for new object
*/

// C++ library: this library has to come before all C libraries, because C++ embraces C, and not the other way around
#include <c++/9/vector>

// C libraries
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

using namespace std;

vector<float> px;
vector<float> py;

int counter = 0;
// screen dimension
float DIM = 500;
// screen proportion (scale)
float SIZE = 10;

float R = 0.7;
float G = 0.5;
float B = 0.2;

void object()
{
	glColor3f(R, G, B);
	glBegin(GL_POLYGON);
	for (int i = 0; i < px.size(); i++)
	{
		glVertex2f(px[i], py[i]);
	}
	glEnd();
}

void redraw()
{
	// white window
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	//if (counter == 1)
	object();

	// it always have to be the last
	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
	// vertices number
	int N;
	// screen coordinates that user will insert
	float X, Y;

	switch (key)
	{
	// user chooses the color
	case 'C':
	case 'c':
		printf("\nInsert a color:\n");

		printf("R = ");
		scanf("%f", &R);

		printf("G = ");
		scanf("%f", &G);

		printf("B = ");
		scanf("%f", &B);

		printf("\n");

		redraw();

		break;

	// resets to default color
	case 'd':
	case 'D':
		R = 0.7;
		G = 0.5;
		B = 0.2;
		redraw();
		counter = 0;
		break;

	// defines red color
	case 'r':
	case 'R':
		R = 1;
		G = 0;
		B = 0;
		redraw();
		break;

	// defines green color
	case 'G':
	case 'g':
		R = 0;
		G = 1;
		B = 0;
		redraw();
		break;

	// defines blue color
	case 'B':
	case 'b':
		R = 0;
		G = 0;
		B = 1;
		redraw();
		break;

	// Erases previous object with new object created by the user
	case 'P':
	case 'p':
		counter = 1;
		px.clear();
		py.clear();

		printf("Enter desired polygon points quantity \n");
		printf("N = ");
		scanf("%d", &N);

		printf("Enter X and Y coordinates: \n");
		for (int i = 0; i < N; i++)
		{
			printf("x[%d] = ", i);
			scanf("%f", &X);
			px.push_back(X);

			printf("y[%d] = ", i);
			scanf("%f", &Y);
			py.push_back(Y);
		}
		printf("\n");

		redraw();
		break;
	}
}

void mouse(int button, int state, int x, int y)
{
	// user's mouse coordinates
	float X, Y;

	if ((button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN))
	{
		counter = 1;
		X = x;
		Y = y;

		// conversion of screen and vector coordinates
		if (X >= DIM / 2)
			X = (X - DIM / 2) / (DIM / 2) * SIZE;
		else
			X = -SIZE + (X / (DIM / 2) * SIZE);

		if (Y >= DIM / 2)
			Y = -(Y - DIM / 2) / (DIM / 2) * SIZE;
		else
			Y = SIZE - (Y / (DIM / 2) * SIZE);

		printf("x = %d y = %d\n", x, y);

		px.push_back(X);
		py.push_back(Y);
	}

	else if ((button == GLUT_LEFT_BUTTON && state == GLUT_DOWN))
	{
		// cleans screen
		counter = 0;
		R = 0.7;
		G = 0.5;
		B = 0.2;

		px.clear();
		py.clear();
	}

	redraw();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(DIM, DIM);
	glutInitWindowPosition(400, 30);
	glutCreateWindow("Paint prototype");
	// recognizes keyboard
	glutKeyboardFunc(keyboard);
	// recognizes mouse
	glutMouseFunc(mouse);
	gluOrtho2D(-SIZE, SIZE, -SIZE, SIZE);
	glutDisplayFunc(redraw);
	glutMainLoop();
}