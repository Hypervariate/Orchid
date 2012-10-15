#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_color.h>


#include <Box2D/Box2D.h>
#include <cstdio>

#include <boost/iostreams/tee.hpp>
#include <boost/iostreams/stream.hpp>
#include <fstream>
#include <iostream>

#include "GlobalData.h"

using std::ostream;
using std::ofstream;
using std::cout;

namespace bio = boost::iostreams;
using bio::tee_device;
using bio::stream;

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


static ALLEGRO_TIMER *frame_timer = NULL;
static int frames;
static int fps;
static int seconds;

static ALLEGRO_EVENT_QUEUE *eventQueue;
static ALLEGRO_EVENT ev;
static ALLEGRO_DISPLAY *display = NULL;	//Allegro Display Object (back-buffer)
static b2World* world;
static double deltaTime;			//current time - lastTick
static double milliseconds = 0;
static double lastFrameTimeStamp = 0;



bool Initialize()
{
    //Allegro----------------------------------------------------------------------------------
    al_init();
    
    al_install_keyboard();
    al_install_mouse();
    al_install_joystick();
    
    frame_timer = al_create_timer(1.0 / 60);
    display = al_create_display(SCREEN_WIDTH, SCREEN_HEIGHT);
    
    eventQueue = al_create_event_queue();
    al_register_event_source(eventQueue, al_get_mouse_event_source());
    al_register_event_source(eventQueue, al_get_keyboard_event_source());
    al_register_event_source(eventQueue, al_get_display_event_source(display));
    al_register_event_source(eventQueue, al_get_timer_event_source(frame_timer));
    
    al_start_timer(frame_timer);
    frames = 0;

    
    
    
    al_init_primitives_addon();
    
    
    
    return true;
    
}
bool Deinitialize()
{
    al_shutdown_primitives_addon();
    al_destroy_event_queue(eventQueue);
    al_destroy_timer(frame_timer);
    al_destroy_display(display);
    
    delete world;
	world = NULL;
    
    return true;

}
bool Update()
{
    al_wait_for_event(eventQueue, &ev);

	if(ev.type == ALLEGRO_EVENT_TIMER && al_is_event_queue_empty(eventQueue)) {
        
		
		milliseconds = al_get_timer_count(frame_timer);
		deltaTime = milliseconds - lastFrameTimeStamp;
		seconds = (milliseconds)/100.0f;
		lastFrameTimeStamp = al_get_timer_count(frame_timer);
//		GraphicsCore::PrintToDisplay(Timer::GetDeltaTime() , 0, 24, "Arcade", 0, 255, 0);
		
		frames++;
		fps = frames/(seconds + 1);	//frames / second
        
//		GraphicsCore::PrintToDisplay(fps , WIDTH - 48, 0, "Arcade", 0, 255, 0);
		
		//cout << Timer::GetDeltaTime() << endl;
		//GraphicsCore::Update();
        
        
        
        al_flip_display();

	}
    //requires display event source registered
	if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
	{
        return false;   //denit and quit
	}
    else if(ev.type == ALLEGRO_EVENT_KEY_UP)
	{
        if(ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE){
				return false;
		}
	}
    return true;

}
int main(int argc, char **argv)
{
    
    B2_NOT_USED(argc);
    B2_NOT_USED(argv);
    
    
    Initialize();
    
    //Box2D----------------------------------------------------------------------------------
    // Define the gravity vector.
    b2Vec2 gravity(0.0f, -10.0f);
    
    // Do we want to let bodies sleep?
    bool doSleep = true;
    
    // Construct a world object, which will hold and simulate the rigid bodies.

    world = new b2World(gravity, doSleep);
    
    
    // Define the ground body.
    b2BodyDef groundBodyDef;

    float gw = SCREEN_WIDTH/4/PTM_RATIO - 0.7f ;
    float gh = 0.5f;
    
    groundBodyDef.position.Set(gw + 1.0f , -SCREEN_HEIGHT / PTM_RATIO - gh + 3);
    
    
    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    b2Body* groundBody = world->CreateBody(&groundBodyDef);
    
    // Define the ground box shape.
    b2PolygonShape groundBox;
    
    
    
    // The extents are the half-widths of the box.
    groundBox.SetAsBox(gw, gh);
    
    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);
    
    float gx = groundBody->GetPosition().x;
    float gy = groundBody->GetPosition().y;

    
    
    // Define the dynamic body. We set its position and call the body factory.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(SCREEN_WIDTH/2/PTM_RATIO, 1.0f);
    b2Body* body = world->CreateBody(&bodyDef);
    
    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    float boxSize = 1.0f;
    dynamicBox.SetAsBox(boxSize, boxSize);
    
    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    
    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;
    
    // Override the default friction.
    fixtureDef.friction = 0.3f;
    
    // Add the shape to the body.
    body->CreateFixture(&fixtureDef);
    
    // Prepare for simulation. Typically we use a time step of 1/60 of a
    // second (60Hz) and 10 iterations. This provides a high quality simulation
    // in most game scenarios.
    int32 velocityIterations = 6;
    int32 positionIterations = 2;
    float32 timeStep = 1.0f / 60.0f;
    // When the world destructor is called, all bodies and joints are freed. This can
    // create orphaned pointers, so be careful about your world management.

    //ALLEGRO----------------------------------------------------------------------------------
    
    while(Update())
    {

        // Instruct the world to perform a single step of simulation.
        // It is generally best to keep the time step and iterations fixed.
        world->Step(timeStep, velocityIterations, positionIterations);
        
        // Clear applied body forces. We didn't apply any forces, but you
        // should know about this function.
        world->ClearForces();
        
        // Now print the position and angle of the body.
        b2Vec2 position = body->GetPosition();

        
        //printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);

        
        al_clear_to_color(al_map_rgb(0,0,0));
        
        ALLEGRO_COLOR color_blue;
        color_blue.b = 256;
        
        ALLEGRO_COLOR color_red;
        color_red.r = 256;
        
        ALLEGRO_COLOR color_green;
        color_green.g = 256;
        
        ALLEGRO_COLOR color_purple;
        color_purple.r = 128;
        color_purple.b = 128;
        
        
        
        for (b2Fixture* f = body->GetFixtureList(); f; f = f->GetNext())
        {
            b2Shape::Type shapeType = f->GetType();
            if ( shapeType == b2Shape::e_circle )
            {
                b2CircleShape* circleShape = (b2CircleShape*)f->GetShape();
                ;
            }
            else if ( shapeType == b2Shape::e_polygon )
            {
                b2PolygonShape* polygonShape = (b2PolygonShape*)f->GetShape();

                
                
                float *polygon = new float[8];
                
                


                
                
                // hWidth, hHeight = half the rectangle's width & height
                // position.x, position.y = center position of the rectangle
                const b2Transform transform = body->GetTransform();
                float rad = transform.GetAngle();
                
                //top left
                polygon[0] = -(boxSize * cosf(rad) + boxSize * sinf(rad) ) + position.x;
                polygon[1] = -(boxSize * sinf(rad) - boxSize * cosf(rad) ) + position.y;
                
                //bottom left
                polygon[2] = -(boxSize * cosf(rad) - boxSize * sinf(rad) ) + position.x;
                polygon[3] = -(boxSize * sinf(rad) + boxSize * cosf(rad) ) + position.y;
            
                //bottom right
                polygon[4] = (boxSize * cosf(rad) + boxSize * sinf(rad) ) + position.x;
                polygon[5] = (boxSize * sinf(rad) - boxSize * cosf(rad) ) + position.y;
                
                //top right
                polygon[6] = (boxSize * cosf(rad) - boxSize * sinf(rad) ) + position.x;
                polygon[7] = (boxSize * sinf(rad) + boxSize * cosf(rad) ) + position.y;
                
                
                
                for(int i = 0; i < 7; i+=2)
                {
                    
                    
                    polygon[i]   *= PTM_RATIO;  //x
                    polygon[i+1] *= PTM_RATIO;  //y
                    
                    polygon[i]   = ABS(polygon[i]);  //x
                    polygon[i+1] = ABS(polygon[i+1]);  //y
                }
                
                for(int i = 0; i < 7; i+=2)
                    printf("(%4.f, %4.f) ", polygon[i], polygon[i+1]);
                printf("\n");
                
                //al_draw_polygon(polygon,4,ALLEGRO_LINE_JOIN_NONE,color_purple,1.5,1);	//not in allegro 5.0.7
				al_draw_line(polygon[0], polygon[1], polygon[2], polygon[3], color_purple, 1);
                al_draw_line(polygon[2], polygon[3], polygon[4], polygon[5], color_purple, 1);
				al_draw_line(polygon[4], polygon[5], polygon[6], polygon[7], color_purple, 1);
				al_draw_line(polygon[6], polygon[7], polygon[0], polygon[1], color_purple, 1);

                delete[] polygon;
            }
        }
        
        
        
        
        
        
        
        //al_draw_line(polygon[0], polygon[1], polygon[2], polygon[3], color_purple, 2);



        
        al_draw_rectangle(PTM_RATIO*(gx - gw), -PTM_RATIO*(gy - gh), PTM_RATIO*(gx + gw), -PTM_RATIO*(gy + gh), color_purple, 1);
        
    };
    
    
    

    
    
    
    
    
    
    
    
   

    //BOOST----------------------------------------------------------------------------------
    
    
    typedef tee_device<ostream, ofstream> TeeDevice;
    typedef stream<TeeDevice> TeeStream;
    ofstream ofs("sample.txt");
    TeeDevice my_tee(cout, ofs);
    TeeStream my_split(my_tee);
    my_split << "Hello, World!\n";
    my_split.flush();
    my_split.close();
    
    
    Deinitialize();
    
    
    
    
    return 0;
}

