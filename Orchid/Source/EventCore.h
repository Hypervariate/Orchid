#ifndef EVENTCORE_H_
#define EVENTCORE_H_

#include "GlobalData.h"
#include "GraphicsCore.h"
#include "Vector2D.h"
#include "CharacterController.h"

#include <allegro5\allegro.h>

#include <map>
#include <vector>
#include <string>
#include <iostream>
#include "Timer.h"


using namespace std;



class EventCore{

public:
	EventCore();
	~EventCore();

	//Core Routines
	//------------------
	static void Initialize();		//setup routine
	static void Update();			//per-frame update
	static void Deinitialize();		//shutdown routine
	//------------------

	//Public Routines
	//------------------
	static void RegisterGameObjectAsPlayer(GameObject* character,  int player_number, CharacterController* cc);
	//------------------

private:	
	static bool initialized;				//graphics have been initialized
	static ALLEGRO_EVENT_QUEUE *eventQueue;
	static ALLEGRO_EVENT ev;
	
	static Vector2D mousePosition;
	static int mouseWheelPosition;
	
	static vector<CharacterController*> players;
	static  int playerCount;
	
	static map<ALLEGRO_JOYSTICK*, int> joysticks;
	static int GetJoystickNumberFromID(ALLEGRO_JOYSTICK * joystick);

	static ALLEGRO_TIMER *timer;
	static int frames;
	static int fps;
	static int seconds;
	static int milliseconds;
	static bool redraw;

	
	
	
};
#endif