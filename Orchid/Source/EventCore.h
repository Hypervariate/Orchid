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

#include "Witch.h"

using namespace std;



class EventCore{

public:
	EventCore();
	~EventCore();

	//Input Core Routines
	//------------------
	static void Initialize();
	static void Update();
	static void Deinitialize();
	//------------------

	static void RegisterGameObjectAsPlayer(GameObject* character, unsigned int player_number);

private:	
	static bool initialized;			//graphics have been initialized
	static ALLEGRO_EVENT_QUEUE *eventQueue;
	static ALLEGRO_EVENT ev;
	
	static Vector2D mousePosition;
	static int mouseWheelPosition;
	
	static vector<CharacterController> players;
	static unsigned int playerCount;
	
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