#ifndef LEVELCOLLISIONTILE_H_
#define LEVELCOLLISIONTILE_H_


#include "GameObject.h"
#include "Shape2DRect.h"

class LevelCollisionTile : public GameObject{

public:
	LevelCollisionTile(int x = 100, int y = 100, int w = 32, int h = 32);
	~LevelCollisionTile();

	void Update();
	void Draw();

	void HandleCollisionWithTarget(GameObject* target);

private:
	

	

};

#endif