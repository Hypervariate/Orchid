#ifndef CHARACTERCONTROLLER_H_
#define CHARACTERCONTROLLER_H_

#include "InputEvent.h"
#include <queue>


class CharacterController{
public:
	CharacterController();
	~CharacterController();

	void PushEvent(InputEvent ev);
	void PopEvent();
	string GetNextEventData();

private:
	queue<InputEvent> inputEvents;

};

#endif