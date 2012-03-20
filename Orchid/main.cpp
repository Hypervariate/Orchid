#include "GraphicsCore.h"

int main(void)
{
	if(!al_init())			//initialize Allegro
		return -1;

	GraphicsCore::Initialize();

	GraphicsCore::DrawRectangle(10, 10, 250, 250, 255, 0, 255, 5);
	GraphicsCore::DrawRoundedRectangle(WIDTH - 200, 10, WIDTH - 10, 50, 5, 5, 0, 0, 255, 15);
	GraphicsCore::DrawFilledRectangle(10, 280, 250, HEIGHT - 10, 255, 255, 255);
	GraphicsCore::DrawFilledRoundedRectangle(WIDTH - 200, 180, WIDTH - 10, HEIGHT - 10, 10, 10, 0, 255, 0);

	GraphicsCore::DrawLine(100, 100, WIDTH - 100, 100, 255, 0, 0, 3);

	GraphicsCore::DrawTriangle(10, 200, 100, 10, 190, 200, 255, 0, 255, 5);
	GraphicsCore::DrawFilledTriangle(300, 400, 400, 200, 500, 400, 0, 0, 255);

	GraphicsCore::DrawCircle(100, 100, 50, 255, 255, 0, 3);
	GraphicsCore::DrawFilledCircle(400, 400, 70, 255, 128, 255);

	GraphicsCore::DrawEllipse(150, 100, 100, 50, 127, 3, 34, 7);
	GraphicsCore::DrawFilledEllipse(400, 250, 100, 200, 0, 255, 255);
	
	float points[] = {0, 0, 400, 100, 50, 200, WIDTH, HEIGHT};
	GraphicsCore::DrawSpline(points, 255, 0, 255, 10);


	GraphicsCore::PrintToDisplay(3436346, 10, 350, "acknowledge", 128, 255);
	GraphicsCore::PrintToDisplay("Hi! Howareya?", 10, 400, "acknowledge", 128, 128);
	
	
	al_install_keyboard();
	al_install_mouse();
	ALLEGRO_EVENT_QUEUE *event_queue = NULL;
	event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_keyboard_event_source());
	//al_register_event_source(event_queue, al_get_display_event_source(display));	//put in graphics core with its own event queue
	
	GraphicsCore::FlipDisplay();
	bool done = false;
	while(!done){
		
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);

		if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch(ev.keyboard.keycode)
			{
				case ALLEGRO_KEY_UP:
					
					break;
				case ALLEGRO_KEY_DOWN:
					
					break;
				case ALLEGRO_KEY_RIGHT:
					
					break;
				case ALLEGRO_KEY_LEFT:
					
					break;
			}
		}
		else if(ev.type == ALLEGRO_EVENT_KEY_UP)
		{
			if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
				done = true;
		}
		//requires display event source registered
		/*if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) 
		{
			done = true;
		}*/
		if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if(ev.mouse.button & 1)
				done = true;
			else if (ev.mouse.button & 2)
				done = true;
		}
		if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			/*pos_x = ev.mouse.x;
			pos_y = ev.mouse.y;*/
		}
	}
	al_destroy_event_queue(event_queue);

	GraphicsCore::Deinitialize();

	return 0;
}
