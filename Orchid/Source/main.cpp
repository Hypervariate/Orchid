//General includes
#include "GlobalData.h"
#include "EventCore.h"
#include "AudioCore.h"

#include "BreakoutGame.h"
#include "BalloonFightGame.h"
#include "AnimalCrossingGame.h"

#include <Box2D\Box2D.h>

//Initialize Orchid
void Initialize(){
	EventCore::Initialize();
	GraphicsCore::Initialize();
	AudioCore::Initialize();
}

//Deinitialize Orchid
void Deinitialize(){
	GameObject::DestroyAll();

	AudioCore::Deinitialize();
	GraphicsCore::Deinitialize();
	EventCore::Deinitialize();
}


int main()
{
	
	Initialize();

    // Define the gravity vector.
    b2Vec2 gravity(0.0f, -10.0f);

    // Construct a world object, which will hold and simulate the rigid bodies.
    b2World world(gravity);

	BreakoutGame::Run();
	//BalloonFightGame::Run();
	//AnimalCrossingGame::Run();
    	
	Deinitialize();
	

	return 0;
}
