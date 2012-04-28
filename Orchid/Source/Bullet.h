#ifndef BULLET_H_
#define BULLET_H_


#include "GameObject.h"
#include "Shape2DCircle.h"
#include "Timer.h"

class Bullet : public GameObject{

public:
	Bullet(int x, int y, float vx, float vy);
	~Bullet();

	void Update();
	void Draw();
	

private:
	Timer lifeSpan;	//when lifespan <= 0, destroy self
	int damage;

	

};

#endif