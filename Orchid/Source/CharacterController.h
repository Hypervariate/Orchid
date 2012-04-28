#ifndef CHARACTERCONTROLLER_H_
#define CHARACTERCONTROLLER_H_

#include "InputEvent.h"
#include <queue>
#include <iostream>
#include "GameObject.h"
#include "Bullet.h"
class CharacterController{
public:
	CharacterController();
	~CharacterController();

	virtual void PushInputEvent(INPUT_EVENT_TYPE type, int value = 0);
	virtual InputEvent PopInputEvent();
	virtual InputEvent GetFrontInputEvent();

	virtual void ProcessEventQueue();

	virtual void SetTarget(GameObject* target){this->target = target;};

protected:
	queue<InputEvent> inputEvents;
	
	GameObject* target;
};

#endif