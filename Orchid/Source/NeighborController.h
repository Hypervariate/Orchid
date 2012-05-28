#pragma once

#include "CharacterController.h"

class NeighborController: public CharacterController{
public:
	NeighborController();
	~NeighborController();


	void ProcessEventQueue();

};

