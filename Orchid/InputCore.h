#ifndef INPUTCORE_H_
#define INPUTCORE_H_

#include "GlobalData.h"

#include <allegro5\allegro.h>
#include <map>
#include <string>
#include <iostream>

using namespace std;


class InputCore{

public:
	InputCore();
	~InputCore();

	//Input Core Routines
	//------------------
	static void Initialize();
	static void Update();
	static void Deinitialize();
	//------------------

private:	
	static bool initialized;			//graphics have been initialized
	static ALLEGRO_EVENT_QUEUE *eventQueue;
	static ALLEGRO_EVENT allegroEvent;
	

};
#endif