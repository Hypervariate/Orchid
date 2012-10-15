#ifndef GLOBALDATA_H_
#define GLOBALDATA_H_

#define max(a,b)	(((a) > (b)) ? (a) : (b))
#define min(a,b)	(((a) < (b)) ? (a) : (b))
#define ABS(N)      (((N) >= 0 ? (N) : -(N)))

#define PTM_RATIO 32
#define DEGTORAD 0.0174532925199432957f
#define RADTODEG 57.295779513082320876f


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480






#include <iostream>
#include <boost/shared_ptr.hpp>
#include <boost/regex.hpp>

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>


#include <Box2D/Box2D.h>
#include <cstdio>

#include <boost/iostreams/tee.hpp>
#include <boost/iostreams/stream.hpp>
#include <fstream>
#include <string>


#include <string>
using namespace std;



class GlobalData{
public:
	GlobalData();
	~GlobalData();

	//Public Routines
	//---------------
	static void RequestApplicationTermination(string reason);
	static bool ApplicationRunning();
    static b2World* GetWorldPointer();
	//---------------

private:
	static bool applicationRunning;
    static b2World *world;

};

#endif