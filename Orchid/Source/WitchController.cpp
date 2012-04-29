#include "WitchController.h"
#include "Bullet.h"

WitchController::WitchController(){
	target = NULL;
}
WitchController::~WitchController(){

}
void WitchController::ProcessEventQueue(){
	const int threshold = 400;

	if(target == NULL)
		return;

	InputEvent ev;
	while(!inputEvents.empty()){
		ev = PopInputEvent();
		switch(ev.GetEventType()){
			case INPUT_EVENT_KEY_DOWN:
				//cout << "key down event " << ev.GetEventValue() << endl;
				Bullet* bullet;
				switch(ev.GetEventValue()){
					case 23: //w
						target->StartMovingUp();
						break;
					case 19: //a
						target->StartMovingDown();
						break;
					case 4: //s
						target->StartMovingRight();
						break;
					case 1: //d						
						target->StartMovingLeft();
						break;
					case 84:	//up
						bullet = new Bullet(target->GetX(), target->GetY() - target->GetHalfOfHeight(), 0, -1);
						GameObject::AddToWorld(bullet);
						break;
					case 85:	//down
						bullet = new Bullet(target->GetX(), target->GetY() + target->GetHalfOfHeight(), 0, 1);
						GameObject::AddToWorld(bullet);
						break;
					case 82:	//left
						bullet = new Bullet(target->GetX() - target->GetHalfOfWidth(), target->GetY(), -1, 0);
						GameObject::AddToWorld(bullet);
						break;
					case 83:	//right
						bullet = new Bullet(target->GetX() + target->GetHalfOfWidth(), target->GetY(), 1, 0);
						GameObject::AddToWorld(bullet);
						break;
				}
				break;
			case INPUT_EVENT_KEY_UP:
				//cout << "key up event " << ev.GetEventValue() << endl;
				switch(ev.GetEventValue()){
					case 23: //w
						target->StopMovingUp();
						break;
					case 19: //a
						target->StopMovingDown();
						break;
					case 4: //s
						target->StopMovingRight();
						break;
					case 1: //d
						target->StopMovingLeft();						
						break;
					case 84:	//up
						
						break;
					case 85:	//down
						
						break;
					case 82:	//left
						
						break;
					case 83:	//right
						
						break;
				}
				break;
			case INPUT_EVENT_JOYSTICK_BUTTON_DOWN:
				////cout << "joystick button down event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_JOYSTICK_BUTTON_UP:
				////cout << "joystick button up event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_JOYSTICK_AXIS_0:
				////cout << "joystick axis 0 event " << ev.GetEventValue() << endl;
				if(ev.GetEventValue() < -threshold)
					target->StartMovingLeft();
				else
					target->StopMovingLeft();

				if(ev.GetEventValue() > threshold)
					target->StartMovingRight();
				else
					target->StopMovingRight();

				break;
			case INPUT_EVENT_JOYSTICK_AXIS_1:
				////cout << "joystick axis 1 event " << ev.GetEventValue() << endl;
				if(ev.GetEventValue() < -threshold)
					target->StartMovingUp();
				else
					target->StopMovingUp();

				if(ev.GetEventValue() > threshold)
					target->StartMovingDown();
				else
					target->StopMovingDown();

				break;
			case INPUT_EVENT_JOYSTICK_AXIS_2:
				////cout << "joystick axis 2 event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_JOYSTICK_AXIS_3:
				////cout << "joystick axis 3 event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_LEFT_BUTTON_DOWN:
				//cout << "left mouse button down event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_RIGHT_BUTTON_DOWN:
				//cout << "right mouse button down event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_MIDDLE_BUTTON_DOWN:
				//cout << "middle mouse button down event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_LEFT_BUTTON_UP:
				//cout << "left mouse button up event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_RIGHT_BUTTON_UP:
				//cout << "right mouse button up event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_MIDDLE_BUTTON_UP:
				//cout << "middle mouse button up event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_AXES_X:
				//cout << "mouse axis x event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_AXES_Y:
				//cout << "mouse axis y event " << ev.GetEventValue() << endl;
				break;
			case INPUT_EVENT_MOUSE_AXES_Z:
				//cout << "mouse axis z event " << ev.GetEventValue() << endl;
				break;
		}
		
	}
	
}