#ifndef WITCH_H_
#define WITCH_H_


#include "GameObject.h"
#include "Shape2DCircle.h"
#include "Animation.h"

class Witch : public GameObject{

public:
	Witch();
	~Witch();

	void Update();
	void Draw();

private:
	Animation animation;

	

};

#endif