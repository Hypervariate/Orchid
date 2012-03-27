#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "GraphicsCore.h"

class GameObject{

public:
	GameObject();
	~GameObject();

	virtual void Update();
	virtual void Draw();

	virtual void Move(float dirX, float dirY);

	virtual void StopMovingX();
	virtual void StopMovingY();

private:


};

#endif