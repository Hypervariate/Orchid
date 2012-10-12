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
	//--------------------------------------------------------------------------
	Initialize();
    //--------------------------------------------------------------------------

    bool doSleep = true;

    // Define the gravity vector.
    b2Vec2 gravity(0.0f, -10.0f);

    // Construct a world object, which will hold and simulate the rigid bodies.
    b2World world(gravity);

    b2BodyDef groundBodyDef;

    groundBodyDef.position.Set(0.0f, -10.0f);

    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    b2PolygonShape groundBox;

    groundBox.SetAsBox(50.0f, 10.0f);

    groundBody->CreateFixture(&groundBox, 0.0f);

    b2BodyDef bodyDef;

    bodyDef.type = b2_dynamicBody;

    bodyDef.position.Set(0.0f, 4.0f);

    b2Body* body = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;

    dynamicBox.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;

    fixtureDef.shape = &dynamicBox;

    fixtureDef.density = 1.0f;

    fixtureDef.friction = 0.3f;

	body->CreateFixture(&fixtureDef);

    //--------------------------------------------------------------------------

    BreakoutGame::Run();
	//BalloonFightGame::Run();
	//AnimalCrossingGame::Run();
    
    //--------------------------------------------------------------------------	
	Deinitialize();
	//--------------------------------------------------------------------------

	return 0;
}
