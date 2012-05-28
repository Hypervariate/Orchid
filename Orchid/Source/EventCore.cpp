#include "EventCore.h"
#include "GraphicsCore.h"

bool EventCore::initialized = false;
ALLEGRO_EVENT_QUEUE *EventCore::eventQueue = NULL;
ALLEGRO_EVENT EventCore::ev;

Vector2D EventCore::mousePosition;
int EventCore::mouseWheelPosition;

vector<CharacterController*> EventCore::players;
 int EventCore::playerCount = 0;

bool EventCore::redraw = false;

map<ALLEGRO_JOYSTICK*, int> EventCore::joysticks;

ALLEGRO_TIMER *EventCore::timer = NULL;
int EventCore::frames = 1;
int EventCore::fps = 0;
int EventCore::seconds = 1;
int EventCore::milliseconds = 0;
double EventCore::lastFrameTimeStamp = 0;

EventCore::EventCore(){}
EventCore::~EventCore(){}
void EventCore::Initialize(){
	if(!initialized){

		if(!al_init())			//initialize Allegro
			GlobalData::RequestApplicationTermination("Allegro failed to init.");
		
		al_install_keyboard();
		al_install_mouse();
		al_install_joystick();

		timer = al_create_timer(1.0 / 60);


		eventQueue = al_create_event_queue();
		al_register_event_source(eventQueue, al_get_mouse_event_source());
		al_register_event_source(eventQueue, al_get_keyboard_event_source());
		al_register_event_source(eventQueue, al_get_joystick_event_source());
		al_register_event_source(eventQueue, al_get_display_event_source(GraphicsCore::GetDisplay()));
		al_register_event_source(eventQueue, al_get_timer_event_source(timer));

		mouseWheelPosition = 0;

		if(al_get_num_joysticks())
			cout << al_get_num_joysticks() << " joysticks installed." << endl;

		//player 0
		for(int i = 0; i < al_get_num_joysticks() + 1; i++)
			players.push_back(new CharacterController());

		for(int i = 0; i < al_get_num_joysticks(); i++)
			joysticks[al_get_joystick(i)] = i;
		
		
		

		al_start_timer(timer);
		frames = 0;

		initialized = true;
		
		
	}
}
void EventCore::RegisterGameObjectAsPlayer(GameObject* character,  int player_number, CharacterController* cc){
	if(player_number >= players.size() && player_number >= 0) return;
	CharacterController* oldCC = players.at(player_number);
	delete oldCC;
	players.at(player_number) = cc;
	players.at(player_number)->SetTarget(character);
}
int EventCore::GetJoystickNumberFromID(ALLEGRO_JOYSTICK* joystick){
	if(joysticks.find(joystick) == joysticks.end())
		return joysticks.size() + 1;	//no such joystick

	return joysticks[joystick];
}
void EventCore::Deinitialize(){
	if(initialized){
		al_destroy_event_queue(eventQueue);
		al_destroy_timer(timer);
		initialized = false;
		vector<CharacterController*>::iterator it = players.begin();
		for(; it != players.end(); it++){
			delete (*it);
		}
		players.clear();
		
	}
	
}
void EventCore::Update(){
	
	al_wait_for_event(eventQueue, &ev);
		

	if(ev.type == ALLEGRO_EVENT_TIMER) {
		redraw = true;
		
	}
	if(redraw && al_is_event_queue_empty(eventQueue)) {
		redraw = false;
		milliseconds = al_get_timer_count(timer);
		seconds = (milliseconds)/100.0f;	
		
		Timer::SetDeltaTime(milliseconds - lastFrameTimeStamp);
		lastFrameTimeStamp = milliseconds - lastFrameTimeStamp;
		GraphicsCore::PrintToDisplay(Timer::GetDeltaTime() , 0, 24, "Arcade", 0, 255, 0);
		
		frames++;
		fps = frames/(seconds + 1);	//frames / second		

		GraphicsCore::PrintToDisplay(fps , WIDTH - 48, 0, "Arcade", 0, 255, 0);
		
		//cout << Timer::GetDeltaTime() << endl;
		GraphicsCore::Update();
	}
	if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		cout << ev.keyboard.keycode << endl;
			
		players.at(0)->PushInputEvent(INPUT_EVENT_KEY_DOWN, ev.keyboard.keycode);
			
		//push events to respective character controllers
		//players.at(0)->PushEvent(ev.keyboard.keycode);
			
	}
	if(ev.type == ALLEGRO_EVENT_KEY_UP)
	{
			
		players.at(0)->PushInputEvent(INPUT_EVENT_KEY_UP, ev.keyboard.keycode);

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
				players.at(0)->PushInputEvent(INPUT_EVENT_MOUSE_LEFT_BUTTON_DOWN, ev.mouse.button);
				break;
			case 2:
				players.at(0)->PushInputEvent(INPUT_EVENT_MOUSE_RIGHT_BUTTON_DOWN, ev.mouse.button);
				break;
			case 3:
				players.at(0)->PushInputEvent(INPUT_EVENT_MOUSE_MIDDLE_BUTTON_DOWN, ev.mouse.button);
				break;
		}
		
	}
	if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
	{
			
		switch(ev.mouse.button){
			case 1:
				players.at(0)->PushInputEvent(INPUT_EVENT_MOUSE_LEFT_BUTTON_UP, ev.mouse.button);
				break;
			case 2:
				players.at(0)->PushInputEvent(INPUT_EVENT_MOUSE_RIGHT_BUTTON_UP, ev.mouse.button);
				break;
			case 3:
				players.at(0)->PushInputEvent(INPUT_EVENT_MOUSE_MIDDLE_BUTTON_UP, ev.mouse.button);
				break;
		}
		
	}
	if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
	{
		players.at(0)->PushInputEvent(INPUT_EVENT_MOUSE_AXES_X, ev.mouse.x);
		players.at(0)->PushInputEvent(INPUT_EVENT_MOUSE_AXES_Y, ev.mouse.y);
		players.at(0)->PushInputEvent(INPUT_EVENT_MOUSE_AXES_Z, ev.mouse.z);

		mousePosition.Set(ev.mouse.x, ev.mouse.y);
		mouseWheelPosition = ev.mouse.z;
	}
	if(al_is_joystick_installed() && GetJoystickNumberFromID(ev.joystick.id) < players.size()){
			
		int player_number = GetJoystickNumberFromID(ev.joystick.id);
		//cout << "joystick " << player_number << endl;
		
		switch(ev.type){
			case ALLEGRO_EVENT_JOYSTICK_AXIS:
					
					
				/*cout << "joy " << ev.joystick.id << " stick: " << ev.joystick.stick << " axis: " << ev.joystick.axis << " value: " << ev.joystick.pos << endl;*/
				switch(ev.joystick.axis){
					case 0:
						players.at(player_number)->PushInputEvent(INPUT_EVENT_JOYSTICK_AXIS_0, ev.joystick.pos * 1000);
						break;
					case 1:
						players.at(player_number)->PushInputEvent(INPUT_EVENT_JOYSTICK_AXIS_1, ev.joystick.pos * 1000);
						break;
					case 2:
						players.at(player_number)->PushInputEvent(INPUT_EVENT_JOYSTICK_AXIS_2, ev.joystick.pos * 1000);
						break;
					case 3:
						players.at(player_number)->PushInputEvent(INPUT_EVENT_JOYSTICK_AXIS_3, ev.joystick.pos * 1000);
						break;
				}
				break;
			case ALLEGRO_EVENT_JOYSTICK_BUTTON_DOWN:
				//cout << "joy " << ev.joystick.id << " button: " << ev.joystick.button << endl;
				players.at(player_number)->PushInputEvent(INPUT_EVENT_JOYSTICK_BUTTON_DOWN, ev.joystick.button);
				break;
			case ALLEGRO_EVENT_JOYSTICK_BUTTON_UP:
				//cout << "joystick " << player_number << " ";
				//cout << "joy " << ev.joystick.id << " button: " << ev.joystick.button << endl;
				players.at(player_number)->PushInputEvent(INPUT_EVENT_JOYSTICK_BUTTON_UP, ev.joystick.button);
				break;
					
		}
	}


	//let character controllers process player input
	for( int i = 0; i < players.size(); i++)
		players.at(i)->ProcessEventQueue();
	
	
	
}