#ifndef BREAKOUTPADDLECONTROLLER_H_
#define BREAKOUTPADDLECONTROLLER_H_

#include "CharacterController.h"

class BreakoutPaddleController: public CharacterController{
public:
	BreakoutPaddleController();
	~BreakoutPaddleController();


	void ProcessEventQueue();

};

#endif