#include "CharacterController.h"

CharacterController::CharacterController(){

}
CharacterController::~CharacterController(){

}
void CharacterController::PushInputEvent(INPUT_EVENT_TYPE type, int value){
	InputEvent ev = InputEvent(type, value);
	inputEvents.push(ev);

}

InputEvent CharacterController::PopInputEvent(){
	InputEvent ev = InputEvent();
	if(!inputEvents.empty()){
		ev = GetFrontInputEvent();
		inputEvents.pop();
	}
	return ev;
}

InputEvent CharacterController::GetFrontInputEvent(){
	if(inputEvents.empty())
		return InputEvent(INPUT_EVENT_NULL,0);
	
	return inputEvents.front();
}
void CharacterController::ProcessEventQueue(){
	InputEvent ev;
	while(!inputEvents.empty()){
		ev = PopInputEvent();
		switch(ev.GetEventType()){
			case INPUT_EVENT_KEY_DOWN:
				cout << "key down event ";
				break;
			case INPUT_EVENT_KEY_UP:
				cout << "key up event ";
				break;
			case INPUT_EVENT_MOUSE_LEFT_BUTTON_DOWN:
				cout << "left mouse button down event ";
				break;
			case INPUT_EVENT_MOUSE_RIGHT_BUTTON_DOWN:
				cout << "right mouse button down event ";
				break;
			case INPUT_EVENT_MOUSE_MIDDLE_BUTTON_DOWN:
				cout << "middle mouse button down event ";
				break;
			case INPUT_EVENT_MOUSE_LEFT_BUTTON_UP:
				cout << "left mouse button up event ";
				break;
			case INPUT_EVENT_MOUSE_RIGHT_BUTTON_UP:
				cout << "right mouse button up event ";
				break;
			case INPUT_EVENT_MOUSE_MIDDLE_BUTTON_UP:
				cout << "middle mouse button up event ";
				break;
			case INPUT_EVENT_MOUSE_AXES_X:
				cout << "mouse axis x event ";
				break;
			case INPUT_EVENT_MOUSE_AXES_Y:
				cout << "mouse axis y event ";
				break;
			case INPUT_EVENT_MOUSE_AXES_Z:
				cout << "mouse axis z event ";
				break;
			case INPUT_EVENT_JOYSTICK_BUTTON_DOWN:
				cout << "joystick button down event ";
				break;
			case INPUT_EVENT_JOYSTICK_BUTTON_UP:
				cout << "joystick button up event ";
				break;
		}
		cout << ev.GetEventValue() << endl;
	}
}