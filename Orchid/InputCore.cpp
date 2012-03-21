#include "InputCore.h"

bool InputCore::initialized = false;
ALLEGRO_EVENT_QUEUE *InputCore::eventQueue = NULL;
ALLEGRO_EVENT InputCore::allegroEvent;

InputCore::InputCore(){}
InputCore::~InputCore(){}
void InputCore::Initialize(){
	if(!initialized){
		
		al_install_keyboard();
		al_install_mouse();

		
		eventQueue = al_create_event_queue();
		al_register_event_source(eventQueue, al_get_mouse_event_source());
		al_register_event_source(eventQueue, al_get_keyboard_event_source());
	
		

		initialized = true;
	}
}
void InputCore::Deinitialize(){
	if(initialized){
	//destroy all fonts
	/*for(fontIterator=fonts.begin() ; fontIterator != fonts.end(); fontIterator++)
		al_destroy_font((*fontIterator).second);*/

	al_destroy_event_queue(eventQueue);


	initialized = false;
	}
}
void InputCore::Update(){
	al_wait_for_event(eventQueue, &allegroEvent);
	if(allegroEvent.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(allegroEvent.keyboard.keycode)
			{
				case ALLEGRO_KEY_UP:
					cout << "up" << endl;
					break;
				case ALLEGRO_KEY_DOWN:
					cout << "down" << endl;
					break;
				case ALLEGRO_KEY_RIGHT:
					cout << "right" << endl;
					break;
				case ALLEGRO_KEY_LEFT:
					cout << "left" << endl;
					break;
			}
		}
		if(allegroEvent.type == ALLEGRO_EVENT_KEY_UP)
		{
			if(allegroEvent.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				GlobalData::RequestApplicationTermination("escape button");
		}
	//	//requires display event source registered
	//	if(allegroEvent.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
	//	{
	//		done = true;
	//	}
		if(allegroEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if(allegroEvent.mouse.button & 1)
				cout << "left mouse button" << endl;
			else if (allegroEvent.mouse.button & 2)
				cout << "right mouse button" << endl;
		}
		if(allegroEvent.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			cout << allegroEvent.mouse.x << " " << allegroEvent.mouse.y << endl;
			/*pos_x = allegroEvent.mouse.x;
			pos_y = allegroEvent.mouse.y;*/
		}
}