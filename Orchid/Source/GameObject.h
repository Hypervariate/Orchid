#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "GraphicsCore.h"
#include "Shape2DRect.h"

#include "Vector2DF.h"
#include "GlobalData.h"

class GameObject{

public:
	GameObject();
	~GameObject();

	virtual void Update();
	virtual void Draw();

	virtual void StartMovingUp();
	virtual void StartMovingDown();
	virtual void StartMovingLeft();
	virtual void StartMovingRight();

	virtual void StopMovingUp();
	virtual void StopMovingDown();
	virtual void StopMovingLeft();
	virtual void StopMovingRight();
	virtual void ResumeMovement();

	virtual void ResumeMovement();

protected:
	Shape2D* shape;
	unsigned int speed;
	float maxSpeed;
	float minSpeed;

	Vector2DF position;
	Vector2DF velocity;
	Vector2DF drag;
	Vector2DF inertia;
	Vector2DF baseInertia;

	
	bool moveUp;
	bool moveDown;
	bool moveLeft;
	bool moveRight;

private:
	virtual void Move(float dirX, float dirY);


};

#endif