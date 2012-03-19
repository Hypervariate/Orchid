#ifndef GRAPHICSCORE_H_
#define GRAPHICSCORE_H_

#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>				//Our primitive header file

const int WIDTH = 640;
const int HEIGHT = 480;

class GraphicsCore{

public:
	GraphicsCore();
	~GraphicsCore();

	static void Initialize();
	static void FlipDisplay();

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
	//unsupported for now
	//------------------


private:
	static ALLEGRO_DISPLAY *display;	//screen
	static bool initialized;
};
#endif