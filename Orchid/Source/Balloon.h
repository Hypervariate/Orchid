#pragma once


#include "GameObject.h"
#include "Shape2DCircle.h"

class Balloon : public GameObject{

public:
	Balloon(int x, int y);
	~Balloon();

	void Update();
	void Draw();

private:
	
	int life;
	

};