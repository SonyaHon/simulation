#ifndef GRASS_H_
#define GRASS_H_

#include "vector2.h"
#include <vector>

class TGrass {
private:

	static int size;

	Vector2 position;
	int birthTimeOut;
	int deathTimeOut;
	int timer;
	int multy;
	int tries;

public:

	TGrass();
	TGrass(Vector2 pos, int _birthTimeOut);
	~TGrass();
	void Draw();
	void Proccess(int gmm[100][100], std::vector<TGrass> &all, int idx);
};

#endif