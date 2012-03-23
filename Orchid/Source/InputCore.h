#ifndef INPUTCORE_H_
#define INPUTCORE_H_

#include "GlobalData.h"
#include "GraphicsCore.h"
#include "Vector2D.h"

#include <allegro5\allegro.h>

#include <map>
#include <vector>
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
	static ALLEGRO_EVENT ev;
	
	static map<int, bool> keys;
	static Vector2D mousePosition;
	static int mouseWheelPosition;
	

};
#endif