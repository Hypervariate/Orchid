#ifndef CHARACTERCONTROLLER_H_
#define CHARACTERCONTROLLER_H_

#include "InputEvent.h"
#include <queue>
#include <iostream>

class CharacterController{
public:
	CharacterController();
	~CharacterController();

	void PushInputEvent(INPUT_EVENT_TYPE type, int value = 0);
	InputEvent PopInputEvent();
	InputEvent GetFrontInputEvent();

	void ProcessEventQueue();

private:
	queue<InputEvent> inputEvents;

};

#endif