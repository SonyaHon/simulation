#include "../headers/grass.h"
#include <GLUT/glut.h>

int TGrass::size = 8;

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
	deathTimeOut = _deathTimeOut;
	birthTimeOut = deathTimeOut / 3;
}

TGrass::~TGrass() {}

void TGrass::Draw() {
	int x = position.x * 10 + 1;
	int y = position.y * 10 + 1;

	glColor3f(0.3f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(x, y);
	glVertex2f(x + size, y);
	glVertex2f(x + size, y + size);
	glVertex2f(x, y + size);
	glEnd();
}

void TGrass::Proccess(int gmm[100][100], std::vector<TGrass> &l, int idx) {
	static int timer;
	static int multy = 1;
	bool goodPlace = false;
	Vector2 pos;
	timer++;
	if(timer == multy*birthTimeOut) { // make another Grass
		while(!goodPlace) {
			pos.x = rand()%3 - 1;
			pos.y = rand()%3 - 1;

			if(pos.x == 0 && pos.y == 0) continue;

			if(gmm[position.x - pos.x][position.y - pos.y] == 0) goodPlace = true;
		}

		TGrass newGrass = TGrass(pos, deathTimeOut);
		l.push_back(newGrass);
		multy++;
	}

	if(timer == deathTimeOut) {
		//l[idx].~TGrass();
		l.erase(l.begin() + idx);
	}
}