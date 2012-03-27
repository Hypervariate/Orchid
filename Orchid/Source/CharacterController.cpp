#include "CharacterController.h"

CharacterController::CharacterController(){
	target = NULL;
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
	const int threshold = 400;

	if(target == NULL)
		return;

	InputEvent ev;
	while(!inputEvents.empty()){
		ev = PopInputEvent();
		switch(ev.GetEventType()){
			case INPUT_EVENT_KEY_DOWN:
				cout << "key down event " << ev.GetEventValue() << endl;
				switch(ev.GetEventValue()){
					case 84:	//up
						target->Move(0,-1);
						break;
					case 85:	//down
						target->Move(0,1);
						break;
					case 82:	//left
						target->Move(-1,0);
						break;
					case 83:	//right
						target->Move(1,0);
						break;
				}
				break;
			case INPUT_EVENT_KEY_UP:
				cout << "key up event " << ev.GetEventValue() << endl;
				switch(ev.GetEventValue()){
					case 84:	//up
						target->StopMovingY();
						break;
					case 85:	//down
						target->StopMovingY();
						break;
					case 82:	//left
						target->StopMovingX();
						break;
					case 83:	//right
						target->StopMovingX();
						break;
				}
				break;
			case INPUT_EVENT_JOYSTICK_BUTTON_DOWN:
				cout << "joystick button down event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_JOYSTICK_BUTTON_UP:
				cout << "joystick button up event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_JOYSTICK_AXIS_0:
				cout << "joystick axis 0 event " << ev.GetEventValue() << endl;
				if(ev.GetEventValue() < -threshold)
					target->Move(-1,0);
				else if(ev.GetEventValue() > threshold)
					target->Move(1,0);
				else
					target->StopMovingX();
				break;
			case INPUT_EVENT_JOYSTICK_AXIS_1:
				cout << "joystick axis 1 event " << ev.GetEventValue() << endl;
				if(ev.GetEventValue() < -threshold)
					target->Move(0,-1);
				else if(ev.GetEventValue() > threshold)
					target->Move(0,1);
				else
					target->StopMovingY();
				break;
			case INPUT_EVENT_JOYSTICK_AXIS_2:
				cout << "joystick axis 2 event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_JOYSTICK_AXIS_3:
				cout << "joystick axis 3 event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_LEFT_BUTTON_DOWN:
				cout << "left mouse button down event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_RIGHT_BUTTON_DOWN:
				cout << "right mouse button down event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_MIDDLE_BUTTON_DOWN:
				cout << "middle mouse button down event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_LEFT_BUTTON_UP:
				cout << "left mouse button up event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_RIGHT_BUTTON_UP:
				cout << "right mouse button up event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_MIDDLE_BUTTON_UP:
				cout << "middle mouse button up event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_AXES_X:
				cout << "mouse axis x event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_AXES_Y:
				cout << "mouse axis y event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_AXES_Z:
				cout << "mouse axis z event " << ev.GetEventValue() << endl;
				break;
		}
		
	}
	
}