#ifndef TREE_H_
#define TREE_H_

#include <vector>
#include "vector2.h"

/*
	3 стадии - росток -> маленькое дерево -> большое дерево
	разные пикчи
	рандомное время роста
	убивает траву под собой
	размножается в 4 дерева за пол цикла перед смертью 
	семена имеют шанс не прорости
*/

class TTree {
private:
	Vector2 position;
	int deathTimeOut;
	int timer;
	int multy;
	int birthTime;
	int step;

public:
	TTree();
	~TTree();

	TTree(Vector2 pos, int deathTimeOut);
	void Draw();
	void Proccess(int gmm[100][100], std::vector<TTree> &all, int idx);

};

#endif