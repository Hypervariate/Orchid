#ifndef WITCHCONTROLLER_H_
#define WITCHCONTROLLER_H_

#include "CharacterController.h"

class WitchController: public CharacterController{
public:
	WitchController();
	~WitchController();


	void ProcessEventQueue();

};

#endif