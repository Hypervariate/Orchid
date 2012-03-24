#include "CharacterController.h"

CharacterController::CharacterController(){

}
CharacterController::~CharacterController(){

}
void CharacterController::PushEvent(InputEvent ev){
	if(ev.GetEventData() != "")
		inputEvents.push(ev);
}

void CharacterController::PopEvent(){
	if(!inputEvents.empty())
		inputEvents.pop();
}

string CharacterController::GetNextEventData(){
	if(inputEvents.empty())
		return "";
	
	return inputEvents.front().GetEventData();
}
