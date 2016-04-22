#include "../headers/tile.h"
#include <GLUT/glut.h>
#include <iostream>

int Ttile::size = 10;

Ttile::Ttile(Vector2 pos, int _type) {
	position = pos;
	type = _type;
}

Ttile::Ttile() {

}

void Ttile::print() {
	position.print();
	
}

int Ttile::getType() {
	return type;
}

void Ttile::setType(int t) {
	type = t;
}

void Ttile::Draw() {
	switch(type) {
		case 0: // ground
			glColor3f(0.32f, 0.25f, 0.02f);
			glBegin(GL_QUADS);
			glVertex2f(position.x, position.y);
			glVertex2f(position.x + size, position.y);
			glVertex2f(position.x + size, position.y + size);
			glVertex2f(position.x, position.y + size);
			glEnd();
			
		break;
		case 1: // water
			glColor3f(0.1f, 0.1f, 1.0f);
			glBegin(GL_QUADS);
			glVertex2f(position.x, position.y);
			glVertex2f(position.x + size, position.y);
			glVertex2f(position.x + size, position.y + size);
			glVertex2f(position.x, position.y + size);
			glEnd();
		break;
		case 2: // rock - wall of the map
			glColor3f(0.1f, 0.1f, 0.1f);
			glBegin(GL_QUADS);
			glVertex2f(position.x, position.y);
			glVertex2f(position.x + size, position.y);
			glVertex2f(position.x + size, position.y + size);
			glVertex2f(position.x, position.y + size);
			glEnd();
		break;
	}
}