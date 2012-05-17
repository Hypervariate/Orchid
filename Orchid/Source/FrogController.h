#pragma once

#include "CharacterController.h"

class FrogController: public CharacterController{
public:
	FrogController();
	~FrogController();


	void ProcessEventQueue();

};

