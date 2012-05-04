#ifndef INPUTEVENT_H_
#define INPUTEVENT_H_

#include <string>
using namespace std;

enum INPUT_EVENT_TYPE
{
   INPUT_EVENT_NULL  = 0,
   
	//TODO: put in all joystick buttons/axis events
   
   INPUT_EVENT_JOYSTICK_BUTTON_DOWN,
   INPUT_EVENT_JOYSTICK_BUTTON_UP,
   INPUT_EVENT_JOYSTICK_AXIS_0,
   INPUT_EVENT_JOYSTICK_AXIS_1,
   INPUT_EVENT_JOYSTICK_AXIS_2,
   INPUT_EVENT_JOYSTICK_AXIS_3,

   
   INPUT_EVENT_KEY_DOWN,
   INPUT_EVENT_KEY_CHAR,
   INPUT_EVENT_KEY_UP,

   INPUT_EVENT_MOUSE_AXES_X,
   INPUT_EVENT_MOUSE_AXES_Y,
   INPUT_EVENT_MOUSE_AXES_Z,
   INPUT_EVENT_MOUSE_LEFT_BUTTON_DOWN,
   INPUT_EVENT_MOUSE_RIGHT_BUTTON_DOWN,
   INPUT_EVENT_MOUSE_MIDDLE_BUTTON_DOWN,
   INPUT_EVENT_MOUSE_LEFT_BUTTON_UP,
   INPUT_EVENT_MOUSE_RIGHT_BUTTON_UP,
   INPUT_EVENT_MOUSE_MIDDLE_BUTTON_UP,
   INPUT_EVENT_MOUSE_ENTER_DISPLAY,
   INPUT_EVENT_MOUSE_LEAVE_DISPLAY,
   INPUT_EVENT_MOUSE_WARPED,

   INPUT_EVENT_DISPLAY_EXPOSE,
   INPUT_EVENT_DISPLAY_RESIZE,
   INPUT_EVENT_DISPLAY_CLOSE,
   INPUT_EVENT_DISPLAY_LOST,
   INPUT_EVENT_DISPLAY_FOUND,
   INPUT_EVENT_DISPLAY_SWITCH_IN,
   INPUT_EVENT_DISPLAY_SWITCH_OUT,
   INPUT_EVENT_DISPLAY_ORIENTATION
};

class InputEvent{
public:
	InputEvent(INPUT_EVENT_TYPE type = INPUT_EVENT_NULL, int value = 0);
	~InputEvent();

	//Set the values for this event
	void SetEventData(INPUT_EVENT_TYPE type, int value){this->type = type; this->value = value;};

	//Return the type of the event
	INPUT_EVENT_TYPE GetEventType(){return type;};

	//return the value corresponding to this event type
	int GetEventValue(){return value;};

	//event value has not been set
	bool IsNull();

private:
	INPUT_EVENT_TYPE type;
	int value;

};


#endif