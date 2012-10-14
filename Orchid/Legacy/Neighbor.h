#pragma once


#include "GameObject.h"
#include "Animation.h"

class Neighbor : public GameObject{

public:
	Neighbor(int x, int y);
	~Neighbor();

	void Update();
	void Draw();
	void HandleCollisionWithTarget(GameObject* target);
	char* GetObjectType(){ return "Neighbor";}

private:
	
	int life;
	GameObject* balloon;
	int direction; // right = 0, left = 180, up = 90, down = 270
	Animation walkRight;
	Animation walkUp;
	Animation walkLeft;
	Animation walkDown;
	Animation *currentAnimation;

};