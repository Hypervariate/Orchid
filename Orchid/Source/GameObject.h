#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "GraphicsCore.h"

class GameObject{

public:
	GameObject();
	~GameObject();

	virtual void Draw();

	virtual void MoveUp();
	virtual void MoveDown();
	virtual void MoveLeft();
	virtual void MoveRight();

private:


};

#endif