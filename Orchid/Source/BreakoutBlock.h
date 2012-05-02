#ifndef BREAKOUTBLOCK_H_
#define BREAKOUTBLOCK_H_


#include "GameObject.h"
#include "Animation.h"

class BreakoutBlock : public GameObject{

public:
	BreakoutBlock(int x, int y);
	~BreakoutBlock();

	void Update();
	void HandleCollisionWithTarget(GameObject* target);
	void Draw();

private:
	
	int life;
	

};

#endif