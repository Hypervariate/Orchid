#ifndef BREAKOUTPADDLE_H_
#define BREAKOUTPADDLE_H_


#include "GameObject.h"
#include "Animation.h"

class BreakoutPaddle : public GameObject{

public:
	BreakoutPaddle(int x, int y);
	~BreakoutPaddle();

	void Update();
	void HandleCollisionWithTarget(GameObject* target);
	void Draw();

private:
	
	
	

};

#endif