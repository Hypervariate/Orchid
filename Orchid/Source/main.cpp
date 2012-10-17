
#include "GlobalData.h"

using std::ostream;
using std::ofstream;
using std::cout;

namespace bio = boost::iostreams;
using bio::tee_device;
using bio::stream;


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

#include "BoxCrate.h"

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
    GlobalData gd = GlobalData();
    
    B2_NOT_USED(argc);
    B2_NOT_USED(argv);
    
    
    Initialize();
    
    //Box2D----------------------------------------------------------------------------------
    // Define the gravity vector.
    b2Vec2 gravity(0.0f, -10.0f);
    
    // Do we want to let bodies sleep?
    bool doSleep = true;
    
    // Construct a world object, which will hold and simulate the rigid bodies.

    world = GlobalData::GetWorldPointer();
    
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

    BoxCrate bc = BoxCrate(SCREEN_WIDTH/2/PTM_RATIO, -1.0f, 60);
    
    
       
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
        

        
        //printf("%4.2f %4.2f %4.2f\n", position.x, position.y, angle);

        
        al_clear_to_color(al_map_rgb(0,0,0));
        

        
        ALLEGRO_COLOR color_purple;
        color_purple.r = 128;
        color_purple.b = 128;
        
        
       

    
        bc.Draw();
        
        
        
        
        
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

