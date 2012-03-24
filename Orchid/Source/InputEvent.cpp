#include "InputEvent.h"

InputEvent::InputEvent(){
	SetEventData("");
}
InputEvent::~InputEvent(){

}
InputEvent::InputEvent(string eventData){
	SetEventData(eventData);
}
