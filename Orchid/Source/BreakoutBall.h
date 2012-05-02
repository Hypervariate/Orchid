#ifndef BREAKOUTBALL_H_
#define BREAKOUTBALL_H_


#include "GameObject.h"
#include "Shape2DCircle.h"

class BreakoutBall : public GameObject{

public:
	BreakoutBall(int x, int y, float vx, float vy);
	~BreakoutBall();

	void Update();
	void Draw();

private:
	
	int life;
	

};

#endif