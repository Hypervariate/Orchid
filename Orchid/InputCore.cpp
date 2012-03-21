#include "InputCore.h"


bool InputCore::initialized = false;
ALLEGRO_EVENT_QUEUE *InputCore::eventQueue = NULL;
ALLEGRO_EVENT InputCore::allegroEvent;
map<int, bool> InputCore::keys;
Vector2D InputCore::mousePosition;
int InputCore::mouseWheelPosition;

InputCore::InputCore(){}
InputCore::~InputCore(){}
void InputCore::Initialize(){
	if(!initialized){
		
		al_install_keyboard();
		al_install_mouse();

		
		eventQueue = al_create_event_queue();
		al_register_event_source(eventQueue, al_get_mouse_event_source());
		al_register_event_source(eventQueue, al_get_keyboard_event_source());
		al_register_event_source(eventQueue, al_get_display_event_source(GraphicsCore::GetDisplay()));
		
		mouseWheelPosition = 0;


		initialized = true;
	}
}
void InputCore::Deinitialize(){
	if(initialized){
		al_destroy_event_queue(eventQueue);
		initialized = false;
	}
}
void InputCore::Update(){
	al_wait_for_event(eventQueue, &allegroEvent);

	if(allegroEvent.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		keys[allegroEvent.keyboard.keycode] = true;
		cout << allegroEvent.keyboard.keycode << endl;
			
	}
	if(allegroEvent.type == ALLEGRO_EVENT_KEY_UP)
	{
		keys[allegroEvent.keyboard.keycode] = false;

		//cout << allegroEvent.keyboard.keycode << endl;
			
		switch(allegroEvent.keyboard.keycode){
			case ALLEGRO_KEY_ESCAPE:
				GlobalData::RequestApplicationTermination("escape button");
				break;
		}
	}
	//requires display event source registered
	if(allegroEvent.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
	{
		GlobalData::RequestApplicationTermination("closed window");
	}
	if(allegroEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		switch(allegroEvent.mouse.button){
			case 1:
				cout << "left mouse button" << endl;
				break;
			case 2:
				cout << "right mouse button" << endl;
				break;
			case 3:
				cout << "middle mouse button" << endl;
				break;
		}
		
	}
	if(allegroEvent.type == ALLEGRO_EVENT_MOUSE_AXES)
	{
		
		mousePosition.Set(allegroEvent.mouse.x, allegroEvent.mouse.y);
		
		
		if(allegroEvent.mouse.z != mouseWheelPosition)
			cout << "wheel: " << allegroEvent.mouse.z << endl;
		else
			cout << mousePosition.GetX() << " " << mousePosition.GetY() << endl;

		mouseWheelPosition = allegroEvent.mouse.z;
	}
}