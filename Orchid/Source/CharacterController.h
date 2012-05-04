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
	
	//Input events are pushed to controller queues from the Event Core
	virtual void PushInputEvent(INPUT_EVENT_TYPE type, int value = 0);
	
	//Input queue is processed once for every game object every frame
	virtual void ProcessEventQueue();

	//set the target game object for this controller
	virtual void SetTarget(GameObject* target){this->target = target;};

protected:
	queue<InputEvent> inputEvents;
	
	GameObject* target;

	//pop an input event from the front of the queue
	//also return it
	virtual InputEvent PopInputEvent();

	//return the input event at the front of the queue
	//without removing it
	virtual InputEvent GetFrontInputEvent();
};

#endif