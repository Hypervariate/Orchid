#include "GlobalData.h"

bool GlobalData::applicationRunning = true;
b2World* GlobalData::world = NULL;

GlobalData::GlobalData(){

}
GlobalData::~GlobalData(){

}
void GlobalData::RequestApplicationTermination(string reason){
	applicationRunning = false;
}
bool GlobalData::ApplicationRunning(){
	return applicationRunning;
}
b2World *GlobalData::GetWorldPointer()
{
    if(world == NULL)
    {
        // Define the gravity vector.
        b2Vec2 gravity(0.0f, -10.0f);
        
        // Do we want to let bodies sleep?
        bool doSleep = true;
        
        world = new b2World(gravity, doSleep);
    }
    return world;
}