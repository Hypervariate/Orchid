#ifndef GRAPHICSCORE_H_
#define GRAPHICSCORE_H_

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>

#include <map>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

const int WIDTH = 640;
const int HEIGHT = 480;

class GraphicsCore{

public:
	GraphicsCore();
	~GraphicsCore();

	//Graphics Core Routines
	//------------------
	static void Initialize();
	static void Deinitialize();
	static void FlipDisplay();
	static bool LoadFont(string font_name, unsigned int size);
	//------------------

	//Primatives Drawing
	//------------------
	//Rectangles
	static void DrawRectangle(float x1, float y1, float x2, float y2, unsigned char r, unsigned char g, unsigned char b, float thickness);
	static void DrawRoundedRectangle(float x1, float y1, float x2, float y2, float rx, float ry, unsigned char r, unsigned char g, unsigned char b, float thickness);
	static void DrawFilledRectangle(float x1, float y1, float x2, float y2, unsigned char r, unsigned char g, unsigned char b);
	static void DrawFilledRoundedRectangle(float x1, float y1, float x2, float y2, float rx, float ry, unsigned char r, unsigned char g, unsigned char b);
	
	//Lines
	static void DrawLine(float x1, float y1, float x2, float y2, unsigned char r, unsigned char g, unsigned char b, float thickness);
	
	//triangles
	static void DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, unsigned char r, unsigned char g, unsigned char b, float thickness);
    static void DrawFilledTriangle(float x1, float y1, float x2, float y2, float x3, float y3, unsigned char r, unsigned char g, unsigned char b);

	//circles
	static void DrawCircle(float cx, float cy, float rad, unsigned char r, unsigned char g, unsigned char b, float thickness);
	static void DrawFilledCircle(float cx, float cy, float rad, unsigned char r, unsigned char g, unsigned char b);

	//ellipses
	static void DrawEllipse(float cx, float cy, float rx, float ry, unsigned char r, unsigned char g, unsigned char b, float thickness);
	static void DrawFilledEllipse(float cx, float cy, float rx, float ry, unsigned char r, unsigned char g, unsigned char b);

	//splines
	static void DrawSpline(float points[8], unsigned char r, unsigned char g, unsigned char b, float thickness);
	//------------------

	static void PrintToDisplay(string text, int x, int y, string font, unsigned char r = 0, unsigned char g = 0, unsigned char b = 0);
	static void PrintToDisplay(int i, int x, int y, string font, unsigned char r = 0, unsigned char g = 0, unsigned char b = 0);
	

private:
	
	static ALLEGRO_DISPLAY *display;	//Allegro Display Object (back-buffer)
	static bool initialized;			//graphics have been initialized
	
	//Fonts
	//------------------
	static map<string, ALLEGRO_FONT*> fonts;	//archived fonts loaded at load-time
	static map<string, ALLEGRO_FONT*>::iterator fontIterator;
	//------------------

};
#endif