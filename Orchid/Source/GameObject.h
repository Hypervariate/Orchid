#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "GraphicsCore.h"
#include "Shape2DRect.h"

#include "Vector2DF.h"
#include "GlobalData.h"

#include <list>


class GameObject{

public:
	GameObject();
	~GameObject();

	static std::list<GameObject *> objects;
	static std::list<GameObject *>::iterator iter1;
	static std::list<GameObject *>::iterator iter2;

	virtual void Update();
	virtual void Draw();

	static void UpdateAll();

	virtual void StartMovingUp();
	virtual void StartMovingDown();
	virtual void StartMovingLeft();
	virtual void StartMovingRight();

	virtual void StopMovingUp();
	virtual void StopMovingDown();
	virtual void StopMovingLeft();
	virtual void StopMovingRight();

	virtual void ResumeMovement();

	bool DetectCollision(GameObject* target);
	Shape2D* GetShape();
	


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