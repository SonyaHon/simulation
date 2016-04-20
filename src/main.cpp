#include <GLUT/glut.h>
#include <iostream>

#include "../headers/vector2.h"
#include "../headers/tile.h"

void Render();

int main(int argc, char **argv) {

	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("The SIM");

	glutDisplayFunc(Render);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1000, 1000, 0, -1, 1);

	glutMainLoop();
	return 0;
}

void Render() {
	glClear(GL_COLOR_BUFFER_BIT);


	glutSwapBuffers();
}