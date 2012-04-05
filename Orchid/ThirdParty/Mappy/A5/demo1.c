/* (C)2001 Robin Burrows! Playback demo 1 */

#include <stdio.h>
#include <allegro5/allegro.h>
#include "allegro5/allegro_native_dialog.h"
#include <allegro5/allegro_image.h>
#include "allegro5/allegro_font.h"

#include "mappy_A5.h"

#define SWIDTH 640		
#define SHEIGHT 480
#define FPS 30
#define MAPINCREMENT 5
#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

float mapxoff = 0;		/* X and Y offset from the map in pixels for the start position */
float mapyoff = 0;		/* used for scrolling the map */

ALLEGRO_DISPLAY *display=NULL;
ALLEGRO_TIMER *timer=NULL;
ALLEGRO_EVENT_QUEUE *queue=NULL;
ALLEGRO_FONT *f=NULL;
ALLEGRO_BITMAP *parallax=NULL;
ALLEGRO_BITMAP *mapparallax=NULL;
int parallaxmode=FALSE;
int isomode=FALSE;

int redraw = TRUE;
enum mapkeys {KLEFT,KRIGHT,KUP,KDOWN};
int keypresses[4]={0,0,0,0};

void abort_example(char const *str);
int InitAllegro();
int InitMap();
void Example();
int SetMap(char*, char*,int,int);


int main (void)
{
	if(InitAllegro() && SetMap("test8bpp.fmp","mappy demo 1 8bpp map animated",FALSE,FALSE))
		Example();

	return 0;
}

int InitAllegro()
{
	int success=TRUE;
    if (!al_init()) 
	{
       abort_example("Error creating display\n");
	   success=FALSE;
	}
	else
	{
	    display = al_create_display(SWIDTH, SHEIGHT);
		if (!display) 
		{
			abort_example("Error creating display");
			success=FALSE;
		}
		else
		{
			//al_install_mouse();
			al_install_keyboard();
			al_init_image_addon();
			al_init_font_addon();

			parallax=al_load_bitmap("parallax.bmp");
			if(!parallax)
			{
				abort_example("Failed to load parallax.bmp Demo 1 will not work properly!");
			}

			f = al_load_font("font.tga", 0, 0);
			if (!f) 
			{
				abort_example("Failed to load font.tga. Use cursors and ESCape!");
			}

			al_set_window_title(display, "mappy demo 1 8bpp map animated");
			timer = al_create_timer(1.0 / FPS);
			queue = al_create_event_queue();
			al_register_event_source(queue, al_get_keyboard_event_source());
			al_register_event_source(queue, al_get_display_event_source(display));
			al_register_event_source(queue, al_get_timer_event_source(timer));
		}
	}
	return success;
}

int InitMap(char* filename)
{
	mapxoff=mapyoff=0;
	if (MapLoad (filename,TRUE)) 
	{			/* Load the FMP file, exit if error */
		abort_example ("Can't find map file for file, please run exe from same folder as fmp file");
		return FALSE;
	}

	if(parallax && !mapparallax)	//called every reload
		mapparallax=MapMakeParallaxBitmap(parallax);

	return TRUE;
}

int SetMap(char* file, char* title, int usingparallax, int usingiso)
{
	if(!InitMap(file))
		return FALSE;
	else
		al_set_window_title(display, title);

	if(mapparallax)
		parallaxmode=usingparallax;
	else parallaxmode=FALSE;

	isomode=usingiso;

	return TRUE;
}

void Example()
{
	int i;
    ALLEGRO_EVENT event;
	int mapwidthpixels=mapwidth*mapblockwidth;
	int mapheightpixels=mapheight*mapblockheight;

	al_start_timer(timer);

    while (1) 
	{
        al_wait_for_event(queue, &event);
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
		if(event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
            if (event.keyboard.keycode==ALLEGRO_KEY_LEFT)
				keypresses[KLEFT]=1;
            if (event.keyboard.keycode==ALLEGRO_KEY_RIGHT)
				keypresses[KRIGHT]=1;
            if (event.keyboard.keycode==ALLEGRO_KEY_UP)
				keypresses[KUP]=1;
            if (event.keyboard.keycode==ALLEGRO_KEY_DOWN)
				keypresses[KDOWN]=1;
		}
		if(event.type == ALLEGRO_EVENT_KEY_UP)
		{
            if (event.keyboard.keycode==ALLEGRO_KEY_LEFT)
				keypresses[KLEFT]=0;
            if (event.keyboard.keycode==ALLEGRO_KEY_RIGHT)
				keypresses[KRIGHT]=0;
            if (event.keyboard.keycode==ALLEGRO_KEY_UP)
				keypresses[KUP]=0;
            if (event.keyboard.keycode==ALLEGRO_KEY_DOWN)
				keypresses[KDOWN]=0;

            if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
                break;

            if (event.keyboard.keycode==ALLEGRO_KEY_1)
			{
				if(!SetMap("test8bpp.fmp","mappy demo 1 8bpp map animated",FALSE,FALSE))
					break;
			}
            if (event.keyboard.keycode==ALLEGRO_KEY_2)
			{
				if(!SetMap("test32bpp.fmp","mappy demo 2 32bpp map animated PARALLAX",TRUE,FALSE))
					break;
			}
            if (event.keyboard.keycode==ALLEGRO_KEY_3)
			{
				if(!SetMap("testhex.fmp","mappy demo 3 hex tile map",FALSE,FALSE))
					break;
			}
            if (event.keyboard.keycode==ALLEGRO_KEY_4)
			{
				if(!SetMap("testiso.fmp","mappy demo 4 isometrix tile map",FALSE,TRUE))
					break;
			}

		}
        else if (event.type == ALLEGRO_EVENT_TIMER)
		{
			MapUpdateAnims ();	//update animations
            redraw = TRUE;
		}
            
		//move ensure we don't go off the edge
		if(keypresses[KLEFT])
			mapxoff-=MAPINCREMENT;
		if(keypresses[KRIGHT])
			mapxoff+=MAPINCREMENT;
		if(keypresses[KUP])
			mapyoff-=MAPINCREMENT;
		if(keypresses[KDOWN])
			mapyoff+=MAPINCREMENT;

		if (mapxoff > (mapwidthpixels-SWIDTH)) 	mapxoff = (mapwidthpixels-SWIDTH);
		if (mapxoff < 0) 			mapxoff = 0;
		if (mapyoff < 0) 			mapyoff = 0;
		if (mapyoff > (mapheightpixels-SHEIGHT-mapblockheight)) 
		{
			if(isomode) mapyoff = (mapheightpixels-SHEIGHT-(mapblockheight/2)-1);
			else mapyoff = (mapheightpixels-SHEIGHT);
		}

        if (redraw && al_is_event_queue_empty(queue)) 
		{
            redraw = FALSE;
            al_clear_to_color(al_map_rgb_f(0, 0, 0));

			/* draw parallax layer if set */
			if(parallaxmode)
				MapDrawParallax(mapparallax,mapxoff,mapyoff,0,0,SWIDTH,SHEIGHT);
			
			/* Here the Map Background layer is drawn... */
			MapDrawBG(mapxoff,mapyoff,0,0,SWIDTH,SHEIGHT);
			/* Anything you want BETWEEN back and foreground goes in here... */
			/* draw rows for iso */
			if(isomode)
			{
				for (i=0;i<((SHEIGHT/(mapblockgapy/2))+14);i++) 
				{
					MapDrawRow (mapxoff, mapyoff, 0,0, SWIDTH, SHEIGHT, i, NULL);
				}
			}

			if(f)
				al_draw_text(f,al_map_rgb(255,0,0),0,0,0,"Cursors move. Press 1,2,3,4 for demos. ESCape quit");

			/* Lastly, the foreground is drawn, you can call this 0 to 3 times, depending
			 * on how many foreground layers you are using, or which you want displayed.
			 * The last paramater is the foreground layer number, and can be 0, 1, or 2 
			 * ISO example doesn't use foreground
			 */
			if(!isomode)
			{
				MapDrawFG(mapxoff,mapyoff,0,0,SWIDTH,SHEIGHT,0);
				MapDrawFG(mapxoff,mapyoff,0,0,SWIDTH,SHEIGHT,1);
				MapDrawFG(mapxoff,mapyoff,0,0,SWIDTH,SHEIGHT,2);
			}

            al_flip_display();
        }
    }

	//unload the map and free up the memory
	MapFreeMem ();
	if(parallax)
		al_destroy_bitmap(parallax);
	if(mapparallax)
		al_destroy_bitmap(mapparallax);
	al_destroy_font(f);

}

void abort_example(char const *str)
{
   ALLEGRO_DISPLAY* disp;

   disp = al_is_system_installed() ? al_get_current_display() : NULL;
   al_show_native_message_box(disp, "Error", "Cannot run example", str, NULL, 0);
   return;
}
