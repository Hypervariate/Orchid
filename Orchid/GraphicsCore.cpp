#include "GraphicsCore.h"

bool GraphicsCore::initialized = false;
ALLEGRO_DISPLAY* GraphicsCore::display;

GraphicsCore::GraphicsCore(){}
GraphicsCore::~GraphicsCore(){
	al_destroy_display(display);							//destroy our display object
	initialized = false;
}
void GraphicsCore::Initialize(){
	if(!initialized){
		ALLEGRO_DISPLAY* display = NULL;
		display = al_create_display(WIDTH, HEIGHT);			//create our display object
		al_init_primitives_addon();
		initialized = true;
	}
}
void GraphicsCore::FlipDisplay(){
	al_flip_display();
}
void GraphicsCore::DrawRectangle(float x1, float y1, float x2, float y2, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_rectangle(x1, y1, x2, y2, al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawRoundedRectangle(float x1, float y1, float x2, float y2, float rx, float ry, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_rounded_rectangle(x1, y1, x2, y2, rx, ry, al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawFilledRectangle(float x1, float y1, float x2, float y2, unsigned char r, unsigned char g, unsigned char b){
	al_draw_filled_rectangle(x1, y1, x2, y2, al_map_rgb(r, g, b));
}
void GraphicsCore::DrawFilledRoundedRectangle(float x1, float y1, float x2, float y2, float rx, float ry, unsigned char r, unsigned char g, unsigned char b){
	al_draw_filled_rounded_rectangle(x1, y1, x2, y2, rx, ry, al_map_rgb(r, g, b));
}
void GraphicsCore::DrawLine(float x1, float y1, float x2, float y2, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_line(x1, y1, x2, y2, al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_triangle(x1, y1, x2, y2, x3, y3, al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawFilledTriangle(float x1, float y1, float x2, float y2, float x3, float y3, unsigned char r, unsigned char g, unsigned char b){
	al_draw_filled_triangle(x1, y1, x2, y2, x3, y3, al_map_rgb(r, g, b));
}
void GraphicsCore::DrawCircle(float cx, float cy, float rad, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_circle(cx, cy, rad, al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawFilledCircle(float cx, float cy, float rad, unsigned char r, unsigned char g, unsigned char b){
	al_draw_filled_circle(cx, cy, rad, al_map_rgb(r, g, b));
}
void GraphicsCore::DrawEllipse(float cx, float cy, float rx, float ry, unsigned char r, unsigned char g, unsigned char b, float thickness){
	al_draw_ellipse(cx, cy, rx, ry, al_map_rgb(r, g, b), thickness);
}
void GraphicsCore::DrawFilledEllipse(float cx, float cy, float rx, float ry, unsigned char r, unsigned char g, unsigned char b){
	al_draw_filled_ellipse(cx, cy, rx, ry, al_map_rgb(r, g, b));
}
