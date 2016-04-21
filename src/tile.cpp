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

void Ttile::Draw() {
	switch(type) {
		case 0: // grass // TODO Other types of blocks.
			glColor3f(0.2f, 1.0f, 0.0f);
			glBegin(GL_QUADS);
			glVertex2f(position.x, position.y);
			glVertex2f(position.x + size, position.y);
			glVertex2f(position.x + size, position.y + size);
			glVertex2f(position.x, position.y + size);
			glEnd();
		break;
	}
}