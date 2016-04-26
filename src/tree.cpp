#include "../headers/tree.h"
#include <GLUT/glut.h>

TTree::TTree() {}
TTree::~TTree() {}

TTree::TTree(Vector2 pos, int _deathTimeOut) {
	position = pos;
	deathTimeOut = _deathTimeOut;
	multy = 1;
	timer = 0;	
	step = 2;
	birthTime = deathTimeOut - deathTimeOut/3 + deathTimeOut/6;
}

void TTree::Draw() {
	int x = position.x*10;
	int y = position.y*10;
	int size = 10;

	switch(step) {
		case 0: // spline
		glColor3f(0.79f, 0.5f, 0.27f);
		glBegin(GL_LINES);

		glVertex2f(x + 2, y + size);
		glVertex2f(x + size - 2, y + size);

		glVertex2f(x + 2, y + size - 1);
		glVertex2f(x + size - 2, y + size - 1);

		glVertex2f(x + 5, y + size);
		glVertex2f(x + 5, y + 2);

		glVertex2f(x + 5, y + 7);
		glVertex2f(x + 8, y + 5);
		glVertex2f(x + 5, y + 5);
		glVertex2f(x + 2, y + 3);
		glVertex2f(x + 5, y + 3);
		glVertex2f(x + 7, y + 2);

		glEnd();
		break;
		case 1: // small tree
		glColor3f(0.79f, 0.5f, 0.27f);
		glBegin(GL_LINES);

		glVertex2f(x + 2, y + size);
		glVertex2f(x + size - 2, y + size);

		glVertex2f(x + 2, y + size - 1);
		glVertex2f(x + size - 2, y + size - 1);

		glVertex2f(x + 5, y + size);
		glVertex2f(x + 5, y + 2);

		glVertex2f(x + 5, y + 7);
		glVertex2f(x + 8, y + 5);
		glVertex2f(x + 5, y + 5);
		glVertex2f(x + 2, y + 3);
		glVertex2f(x + 5, y + 3);
		glVertex2f(x + 7, y + 2);
		glEnd();

		glColor3f(0.04f, 0.79f, 0.04f);
		glBegin(GL_QUADS);

		glVertex2f(x + 2, y + 2);
		glVertex2f(x + 4, y + 2);
		glVertex2f(x + 4, y + 4);
		glVertex2f(x + 2, y + 4);

		glVertex2f(x + 6, y + 3);
		glVertex2f(x + 8, y + 3);
		glVertex2f(x + 8, y + 5);
		glVertex2f(x + 6, y + 5);

		glEnd();
		break;
		case 2: // BIG tree =D

		glColor3f(0.26f, 0.2f, 0.13f);
		glBegin(GL_LINES);

		glVertex2f(x + 2, y + size);
		glVertex2f(x + size - 2, y + size);

		glVertex2f(x + 2, y + size - 1);
		glVertex2f(x + size - 2, y + size - 1);

		glVertex2f(x + 5, y + size);
		glVertex2f(x + 5, y + 6);

		glVertex2f(x + 4, y + size);
		glVertex2f(x + 4, y + 2);

		glVertex2f(x + 6, y + size);
		glVertex2f(x + 6, y + 2);

		glEnd();

		glColor3f(0.09f, 0.28f, 0.0f);
		glBegin(GL_QUADS);	

		glVertex2f(x + 3, y + 3);
		glVertex2f(x + 7, y + 3);
		glVertex2f(x + 7, y + 6);
		glVertex2f(x + 3, y + 6);

		glEnd();
		break;
	}
}

