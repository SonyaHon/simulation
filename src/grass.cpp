#include "../headers/grass.h"
#include <GLUT/glut.h>

int TGrass::size = 10;

TGrass::TGrass(){
	Vector2 v;
	v.x = 0;
	v.y = 0;
	position = v;
	deathTimeOut = 0;
	birthTimeOut = 0;
}

TGrass::TGrass(Vector2 v, int _deathTimeOut) {
	position = v;
	deathTimeOut = rand()%50 + _deathTimeOut;
	birthTimeOut = deathTimeOut / 3;
	tries = 0;
	multy = 1;
	timer = 0;
}

TGrass::~TGrass() {}

void TGrass::Draw() {
	int x = position.x * 10;
	int y = position.y * 10;

	glColor3f(0.3f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex2f(x, y);
	glVertex2f(x + size, y);

	glVertex2f(x + size, y);
	glVertex2f(x + size, y + size);

	glVertex2f(x + size, y + size);
	glVertex2f(x, y + size);

	glVertex2f(x, y + size);
	glVertex2f(x, y);

	for(size_t i = 0; i < 10; i +=4 ) {
		glVertex2f(x + i, y);
		glVertex2f(x, y + i);

		glVertex2f(x + size - i, y + size);
		glVertex2f(x + size, y + size - i);
	}

	glEnd();
}

void TGrass::Proccess(int gmm[100][100], std::vector<TGrass> &l, int idx) {
	bool goodPlace = false;
	Vector2 pos;
	timer++;
	if(timer == multy*birthTimeOut) { // make another Grass
		while(!goodPlace || tries >= 8) {
			pos.x = rand()%3 - 1;
			pos.y = rand()%3 - 1;
			tries++;
			if(pos.x == 0 && pos.y == 0) continue;

			if(gmm[position.x - pos.x][position.y - pos.y] == 0) {
				pos.x = position.x - pos.x;
				pos.y = position.y - pos.y;
				tries = 0;
				goodPlace = true;
			}

		}

		TGrass newGrass = TGrass(pos, deathTimeOut);
		l.push_back(newGrass);
		multy++;
	}

	else if(timer >= deathTimeOut) {
		l.erase(l.begin() + idx);
	}

}