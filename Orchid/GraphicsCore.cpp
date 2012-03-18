#include "GraphicsCore.h"

bool GraphicsCore::initialized = false;
ALLEGRO_DISPLAY* GraphicsCore::display;

GraphicsCore::GraphicsCore(){}
GraphicsCore::~GraphicsCore(){
	al_destroy_display(display);						//destroy our display object
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