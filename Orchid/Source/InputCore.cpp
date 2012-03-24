#include "InputCore.h"


bool InputCore::initialized = false;
ALLEGRO_EVENT_QUEUE *InputCore::eventQueue = NULL;
ALLEGRO_EVENT InputCore::ev;
map<int, bool> InputCore::keys;
Vector2D InputCore::mousePosition;
int InputCore::mouseWheelPosition;
vector<CharacterController> InputCore::players;
unsigned int InputCore::playerCount = 0;


InputCore::InputCore(){}
InputCore::~InputCore(){}
void InputCore::Initialize(){
	if(!initialized){
		
		al_install_keyboard();
		al_install_mouse();
		al_install_joystick();

		
		eventQueue = al_create_event_queue();
		al_register_event_source(eventQueue, al_get_mouse_event_source());
		al_register_event_source(eventQueue, al_get_keyboard_event_source());
		al_register_event_source(eventQueue, al_get_joystick_event_source());
		al_register_event_source(eventQueue, al_get_display_event_source(GraphicsCore::GetDisplay()));
		
		mouseWheelPosition = 0;

		if(al_get_num_joysticks())
			cout << al_get_num_joysticks() << " joysticks installed." << endl;

		//player 1
		CharacterController cc;
		players.push_back(cc);

		playerCount = players.size();

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
	while(!al_is_event_queue_empty(eventQueue)){
		al_get_next_event(eventQueue, &ev);

		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			keys[ev.keyboard.keycode] = true;
			cout << ev.keyboard.keycode << endl;
			
			//push events to respective character controllers
			//players.at(0).PushEvent(ev.keyboard.keycode);
			
		}
		if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			keys[ev.keyboard.keycode] = false;

			//cout << ev.keyboard.keycode << endl;
			
			switch(ev.keyboard.keycode){
				case ALLEGRO_KEY_ESCAPE:
					GlobalData::RequestApplicationTermination("escape button");
					break;
			}
		}
		//requires display event source registered
		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
		{
			GlobalData::RequestApplicationTermination("closed window");
		}
		if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			switch(ev.mouse.button){
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
		if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			mousePosition.Set(ev.mouse.x, ev.mouse.y);
			if(ev.mouse.z != mouseWheelPosition)
				cout << "wheel: " << ev.mouse.z << endl;
			else
				cout << mousePosition.GetX() << " " << mousePosition.GetY() << endl;

			mouseWheelPosition = ev.mouse.z;
		}
		if(al_is_joystick_installed()){
			int number_of_joysticks = 0;
			switch(ev.type){
				case ALLEGRO_EVENT_JOYSTICK_AXIS:
					cout << "joy " << ev.joystick.id << " stick: " << ev.joystick.stick << " axis: " << ev.joystick.axis << " value: " << ev.joystick.pos << endl;
					break;
				case ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN:
					cout << "joy " << ev.joystick.id << " button: " << ev.joystick.button << endl;
					break;
				case ALLEGRO_EVENT_JOYSTICK_BUTTON_UP:
					//cout << "joy " << ev.joystick.id << " button: " << ev.joystick.button << endl;
					break;
					
			}
		}
	}
}