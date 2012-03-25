#ifndef WITCH_H_
#define WITCH_H_

#include "Shape2DRect.h"
#include "GameObject.h"

class Witch : public GameObject{

public:
	Witch();
	~Witch();

	void Draw();
	
	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

private:
	Shape2DRect shape;
	unsigned int speed;

};

#endif