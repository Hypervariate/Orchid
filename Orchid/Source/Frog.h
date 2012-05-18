#pragma once


#include "GameObject.h"
#include "Shape2DCircle.h"

class Frog : public GameObject{

public:
	Frog(int x, int y);
	~Frog();

	void Update();
	void Draw();
	void HandleCollisionWithTarget(GameObject* target);

private:
	
	int life;
	GameObject* balloon;
	int direction; // 1 == right, 0 == left
	

};