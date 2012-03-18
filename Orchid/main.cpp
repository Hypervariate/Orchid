#include "GraphicsCore.h"

int main(void)
{
	if(!al_init())										//initialize Allegro
		return -1;

	GraphicsCore::Initialize();

	al_rest(1.0);

	al_draw_rectangle(10, 10, 250, 250, al_map_rgb(255, 0, 255), 5);
	al_draw_rounded_rectangle(WIDTH - 200, 10, WIDTH - 10, 50, 5, 5, al_map_rgb(0, 0, 255), 15);
	al_draw_filled_rectangle(10, 280, 250, HEIGHT - 10, al_map_rgb(255, 255, 255));
	al_draw_filled_rounded_rectangle(WIDTH - 200, 180, WIDTH - 10, HEIGHT - 10, 10, 10,  al_map_rgb(0, 255, 0));

	GraphicsCore::FlipDisplay();
	
	
	al_rest(4.0);

	

	return 0;
}
