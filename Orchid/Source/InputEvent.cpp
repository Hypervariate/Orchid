#include "InputEvent.h"


InputEvent::~InputEvent(){

}
InputEvent::InputEvent(INPUT_EVENT_TYPE type, int value){
	SetEventData(type, value);
}
bool InputEvent::IsNull(){
	if(type == INPUT_EVENT_NULL)
		return true;
	
	return false;
}