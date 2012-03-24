#ifndef INPUTEVENT_H_
#define INPUTEVENT_H_

#include <string>
using namespace std;

class InputEvent{
public:
	InputEvent();
	InputEvent(string eventData);
	~InputEvent();

	void SetEventData(string eventData){this->eventData = eventData;};
	string GetEventData(){return eventData;};

private:
	string eventData;

};


#endif