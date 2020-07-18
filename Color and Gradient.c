// This program displays a 4-color gradient square in the middle of the screen

#include <GL/glut.h>

void render()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.0, 1.0);
	glPointSize(4.0);

	glBegin(GL_QUAD_STRIP);
	glColor3f(1, 0, 0);
	glVertex2f(2, 2);

	glColor3f(0, 1, 0);
	glVertex2f(-2, 2);

	glColor3f(0, 0, 1);
	glVertex2f(2, -2);

	glColor3f(1, 0, 1);
	glVertex2f(-2, -2);
	glEnd();

	glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(450, 450);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Color and Gradient");
	gluOrtho2D(-5, 5, -5, 5);
	glutDisplayFunc(render);
	glutMainLoop();
}