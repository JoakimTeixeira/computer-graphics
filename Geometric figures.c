/* This program displays the design of a letter with 2 colors and a stamp with a 3rd color, in the middle of the screen */

#include <GL/glut.h>

void render()
{
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 0.0, 1.0);
	glPointSize(5.0);

	glBegin(GL_POINTS);
	glVertex2f(2, 2);
	glVertex2f(-2, 2);
	glVertex2f(2, -2);
	glVertex2f(-2, -2);
	glEnd();

	glBegin(GL_LINES);
	glVertex2f(2, 2);
	glVertex2f(-2, 2);
	glVertex2f(2, 2);
	glVertex2f(-2, -2);
	glEnd();

	glBegin(GL_LINE_STRIP);
	glVertex2f(2, 2);
	glVertex2f(2, -2);
	glVertex2f(-2, 2);
	glVertex2f(-2, -2);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(2, -2);
	glVertex2f(0, 0);
	glVertex2f(-2, -2);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-2, 2);
	glVertex2f(0, 0);
	glVertex2f(2, 2);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(2, -2);
	glVertex2f(2, 2);
	glVertex2f(-2, -2);
	glVertex2f(-2, 2);
	glEnd();

	glBegin(GL_QUAD_STRIP);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(0.5, -1);
	glVertex2f(0.5, 0);
	glVertex2f(-0.5, -1);
	glVertex2f(-0.5, 0);
	glEnd();

	glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(450, 450);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Geometric figures");
	gluOrtho2D(-5, 5, -5, 5);
	glutDisplayFunc(render);
	glutMainLoop();
}