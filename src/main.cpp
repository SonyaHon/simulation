#include <GLUT/glut.h>
#include <iostream>

#include "../headers/vector2.h"
#include "../headers/tile.h"
#include "../headers/grass.h"
#include "../headers/tree.h"

#include <time.h>
#include <vector>

void Render();
void Timer(int a);
void generateMap();
int getNeigh(int i, int j);

int GlobalMapMatrix[100][100];

/*
 0 - ground
 1 - water
 2 - super wall 
 3 - ground with grass on it
*/

Ttile arr[100][100];
std::vector<TGrass> grassArr;
std::vector<TTree> treeArr;

int main(int argc, char **argv) {
	srand(time(NULL));
	generateMap();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(10, 10);
	glutCreateWindow("The SIM");

	glutDisplayFunc(Render);
	glutTimerFunc(10, Timer, 0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1000, 1000, 0, -1, 1);

	glutMainLoop();
	return 0;
}

int getNeigh(int i, int j) {
	int groundN = 0;

	if(arr[i - 1][j - 1].getType() == 0) groundN++;
	if(arr[i][j - 1].getType() == 0) groundN++;
	if(arr[i + 1][j - 1].getType() == 0) groundN++;
	if(arr[i - 1][j].getType() == 0) groundN++;
	if(arr[i + 1][j].getType() == 0) groundN++;
	if(arr[i - 1][j + 1].getType() == 0) groundN++;
	if(arr[i][j + 1].getType() == 0) groundN++;
	if(arr[i + 1][j + 1].getType() == 0) groundN++;


	if(groundN > 6) return 0;
	if(groundN > 4) return rand()*rand()*rand()%2;
	else return 1;
}

void generateMap() {

	for(size_t i = 0; i < 100; ++i) {
		for(size_t j = 0; j < 100; ++j) {
			Vector2 v;
			v.x = 10*i;
			v.y = 10*j;
			arr[i][j] = Ttile(v, rand()*rand()%2);
		}
	}

	for(size_t howMany = 0; howMany < 7; ++howMany) {

		for(size_t i = 1; i < 99; ++i) {
			for(size_t j = 1; j < 99; ++j) {
				int a = getNeigh(i, j);
				arr[i][j].setType(a);
			}
		}
	}

	for(size_t i = 0; i < 100; ++i) {
		for(size_t j = 0; j < 100; ++j) {
			if(i == 0 || i == 99 || j == 0 || j == 99)
			arr[i][j].setType(2);
		}
	}		

	for(size_t i = 0; i < 100; ++i) {
		for(size_t j = 0; j < 100; ++j) {
			if(arr[i][j].getType() < 0) arr[i][j].setType(0);
		}
	}

	for(size_t i = 0; i < 100; ++i) {
		for(size_t j = 0; j < 100; ++j) {
			GlobalMapMatrix[i][j] = arr[i][j].getType();
		}
	}

	for(size_t i = 0; i < 300; ++i) {
		Vector2 pos;
		bool goodPlace = false;

		while(!goodPlace) {
		pos.x = rand()%99 + 1;
		pos.y = rand()%99 + 1;

		if(GlobalMapMatrix[pos.x][pos.y] == 0)
			goodPlace = true;
		}

		TGrass grass = TGrass(pos, 90);
		grassArr.push_back(grass);
	}

	for(size_t i = 0; i < 50; ++i) {
		Vector2 pos;
		bool goodPlace = false;
		while(!goodPlace) {
			pos.x = rand()%99 + 1;
			pos.y = rand()%99 + 1;
			if(GlobalMapMatrix[pos.x][pos.y] != 1 && GlobalMapMatrix[pos.x][pos.y] != 2)
				goodPlace = true;
		}

		TTree tree = TTree(pos, 600);
		treeArr.push_back(tree);
	}
}

void Timer(int a) {

	for(int i = 0; i < grassArr.size(); ++i) {
		grassArr[i].Proccess(GlobalMapMatrix, grassArr, i);
	}
	grassArr.shrink_to_fit();

	glutPostRedisplay();
	glutTimerFunc(200, Timer, 0);
}

void Render() {
	glClear(GL_COLOR_BUFFER_BIT);

	for(size_t i = 0; i < 100; ++i) { // Rendering main map 
		for(size_t j = 0; j < 100; ++j) {
			arr[i][j].Draw();
		}
	}

	for(size_t i = 0; i < grassArr.size(); ++i) { // Rendering grass
		grassArr[i].Draw();
	}

	for(size_t i = 0; i < treeArr.size(); ++i) {
		treeArr[i].Draw();
	}

	glutSwapBuffers();
}