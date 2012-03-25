#include "InputCore.h"


bool InputCore::initialized = false;
ALLEGRO_EVENT_QUEUE *InputCore::eventQueue = NULL;
ALLEGRO_EVENT InputCore::ev;
map<int, bool> InputCore::keys;
Vector2D InputCore::mousePosition;
int InputCore::mouseWheelPosition;

vector<CharacterController> InputCore::players;
unsigned int InputCore::playerCount = 0;

map<ALLEGRO_JOYSTICK*, int> InputCore::joysticks;

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

		//player 0
		for(int i = 0; i < al_get_num_joysticks() + 1; i++)
			players.push_back(CharacterController());
		
		playerCount = players.size();

		initialized = true;
	}
}
int InputCore::GetJoystickNumberFromID(ALLEGRO_JOYSTICK* joystick){
	if(joysticks.find(joystick) == joysticks.end())
		joysticks[joystick] = joysticks.size();

	return joysticks[joystick];
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
			//
			players.at(0).PushInputEvent(INPUT_EVENT_KEY_DOWN, ev.keyboard.keycode);
			
			//push events to respective character controllers
			//players.at(0).PushEvent(ev.keyboard.keycode);
			
		}
		if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			keys[ev.keyboard.keycode] = false;
			players.at(0).PushInputEvent(INPUT_EVENT_KEY_UP, ev.keyboard.keycode);

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
					players.at(0).PushInputEvent(INPUT_EVENT_MOUSE_LEFT_BUTTON_DOWN, ev.mouse.button);
					break;
				case 2:
					players.at(0).PushInputEvent(INPUT_EVENT_MOUSE_RIGHT_BUTTON_DOWN, ev.mouse.button);
					break;
				case 3:
					players.at(0).PushInputEvent(INPUT_EVENT_MOUSE_MIDDLE_BUTTON_DOWN, ev.mouse.button);
					break;
			}
		
		}
		if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			
			switch(ev.mouse.button){
				case 1:
					players.at(0).PushInputEvent(INPUT_EVENT_MOUSE_LEFT_BUTTON_UP, ev.mouse.button);
					break;
				case 2:
					players.at(0).PushInputEvent(INPUT_EVENT_MOUSE_RIGHT_BUTTON_UP, ev.mouse.button);
					break;
				case 3:
					players.at(0).PushInputEvent(INPUT_EVENT_MOUSE_MIDDLE_BUTTON_UP, ev.mouse.button);
					break;
			}
		
		}
		if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			players.at(0).PushInputEvent(INPUT_EVENT_MOUSE_AXES_X, ev.mouse.x);
			players.at(0).PushInputEvent(INPUT_EVENT_MOUSE_AXES_Y, ev.mouse.y);
			players.at(0).PushInputEvent(INPUT_EVENT_MOUSE_AXES_Z, ev.mouse.z);

			mousePosition.Set(ev.mouse.x, ev.mouse.y);
			mouseWheelPosition = ev.mouse.z;
		}
		if(al_is_joystick_installed()){
			int number_of_joysticks = 0;
			int joy_number = GetJoystickNumberFromID(ev.joystick.id);
			switch(ev.type){
				case ALLEGRO_EVENT_JOYSTICK_AXIS:
					cout << "joystick " << joy_number << " ";
					/*cout << "joy " << ev.joystick.id << " stick: " << ev.joystick.stick << " axis: " << ev.joystick.axis << " value: " << ev.joystick.pos << endl;*/
					switch(ev.joystick.axis){
						case 0:
							players.at(joy_number).PushInputEvent(INPUT_EVENT_JOYSTICK_AXIS_0, ev.joystick.pos * 1000);
							break;
						case 1:
							players.at(joy_number).PushInputEvent(INPUT_EVENT_JOYSTICK_AXIS_1, ev.joystick.pos * 1000);
							break;
						case 2:
							players.at(joy_number).PushInputEvent(INPUT_EVENT_JOYSTICK_AXIS_2, ev.joystick.pos * 1000);
							break;
						case 3:
							players.at(joy_number).PushInputEvent(INPUT_EVENT_JOYSTICK_AXIS_3, ev.joystick.pos * 1000);
							break;
					}
					break;
				case ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN:
					cout << "joystick " << joy_number << " ";
					//cout << "joy " << ev.joystick.id << " button: " << ev.joystick.button << endl;
					players.at(joy_number).PushInputEvent(INPUT_EVENT_JOYSTICK_BUTTON_DOWN, ev.joystick.button);
					break;
				case ALLEGRO_EVENT_JOYSTICK_BUTTON_UP:
					cout << "joystick " << joy_number << " ";
					//cout << "joy " << ev.joystick.id << " button: " << ev.joystick.button << endl;
					players.at(joy_number).PushInputEvent(INPUT_EVENT_JOYSTICK_BUTTON_UP, ev.joystick.button);
					break;
					
			}
		}
	}
	//let character controllers process player input
	for(int i = 0; i < players.size(); i++)
		players.at(i).ProcessEventQueue();
}