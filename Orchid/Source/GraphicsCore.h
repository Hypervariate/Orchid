#ifndef GRAPHICSCORE_H_
#define GRAPHICSCORE_H_

#include "GlobalData.h"

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5\allegro_image.h>

#include <map>
#include "FileReader.h"
#include "Vector2D.h"
#include "Vector2DF.h"

using namespace std;

const int WIDTH = 640;
const int HEIGHT = 480;

#define IMAGE_DIRECTORY "Data/Images/"
#define IMAGE_EXTENSION ".png"

#define FONT_DIRECTORY "Data/Fonts/"
#define FONT_EXTENSION ".ttf"

class GraphicsCore{

public:
	GraphicsCore();
	~GraphicsCore();

	//Core Routines
	//------------------
	static void Initialize();		//setup routine
	static void Update();			//per-frame update
	static void Deinitialize();		//shutdown routine
	//------------------

	//Public Routines
	//------------------

	//blit an image to the buffer
	static void BlitImage(string index, int x = WIDTH/2, int y = HEIGHT/2, int flags = 0);
	//blit a section of an image to the buffer (sprite/tile sheets)
	static void BlitImageRegion(int sx, int sy, int w, int h, int dx, int dy, string image_name);

	//Draw Rectangles
	static void DrawRectangle(float x1, float y1, float x2, float y2,  char r,  char g,  char b, float thickness);
	static void DrawRoundedRectangle(float x1, float y1, float x2, float y2, float rx, float ry,  char r,  char g,  char b, float thickness);
	static void DrawFilledRectangle(float x1, float y1, float x2, float y2,  char r,  char g,  char b);
	static void DrawFilledRoundedRectangle(float x1, float y1, float x2, float y2, float rx, float ry,  char r,  char g,  char b);
	
	//Draw Lines
	static void DrawLine(float x1, float y1, float x2, float y2,  char r,  char g,  char b, float thickness);
	
	//Draw Triangles
	static void DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3,  char r,  char g,  char b, float thickness);
    static void DrawFilledTriangle(float x1, float y1, float x2, float y2, float x3, float y3,  char r,  char g,  char b);

	//Draw Circles
	static void DrawCircle(float cx, float cy, float rad,  char r,  char g,  char b, float thickness);
	static void DrawFilledCircle(float cx, float cy, float rad,  char r,  char g,  char b);

	//Draw Ellipses
	static void DrawEllipse(float cx, float cy, float rx, float ry,  char r,  char g,  char b, float thickness);
	static void DrawFilledEllipse(float cx, float cy, float rx, float ry,  char r,  char g,  char b);

	//Draw Splines
	static void DrawSpline(float points[8],  char r,  char g,  char b, float thickness);
	
	//Print text to the buffer
	static void PrintToDisplay(string text, int x, int y, string font = "Acknowledge",  char r = 0,  char g = 0,  char b = 0);
	static void PrintToDisplay(int i, int x, int y, string font = "Acknowledge",  char r = 0,  char g = 0,  char b = 0);
	
	//Level routines
	//These allow the level to appear to be scrolling relative to Player 0
	static float GetMapScrollingOffsetX();
	static float GetMapScrollingOffsetY();
	static void SetMapScrollingOffsetX(int x = 0);
	static void SetMapScrollingOffsetY(int y = 0);
	static void SetMapTileDimensions(int x, int y);
	static void SetMapDimensions(int x, int y);

	//Get the display object reference
	//This is not for common use.
	//Don't mess with this unless you know what you're doing.
	static ALLEGRO_DISPLAY* GetDisplay();
	//------------------

private:
	static void FlipDisplay();

	static bool LoadImage(char* image_name);
	
	static bool LoadFont(string font_name,  int size);

	static FileReader fileReader;

	static ALLEGRO_DISPLAY *display;	//Allegro Display Object (back-buffer)
	static bool initialized;			//graphics have been initialized
	
	//Fonts
	//------------------
	static map<string, ALLEGRO_FONT*> fonts;	//archived fonts loaded at load-time
	static map<string, ALLEGRO_FONT*>::iterator fontIterator;
	//------------------

	//Images
	//------------------
	static map<string, ALLEGRO_BITMAP*> m_images;
	//------------------

	static Vector2DF scrollingOffset;
	static Vector2D mapTileDimensions;
	static Vector2D mapDimensions;
};
#endif