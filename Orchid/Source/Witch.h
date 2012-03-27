#ifndef WITCH_H_
#define WITCH_H_

#include "Shape2DRect.h"
#include "GameObject.h"
#include "Vector2DF.h"
#include "GlobalData.h"

class Witch : public GameObject{

public:
	Witch();
	~Witch();

	void Update();
	void Draw();

	void Move(float dirX, float dirY);
	
	void StopMovingX();
	void StopMovingY();

private:
	Shape2DRect shape;
	unsigned int speed;
	float maxSpeed;
	float minSpeed;

	Vector2DF position;
	Vector2DF velocity;
	Vector2DF drag;
	Vector2DF inertia;
	Vector2DF baseInertia;
};

#endif