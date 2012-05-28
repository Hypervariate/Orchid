//General includes
#include "GlobalData.h"
#include "EventCore.h"
#include "AudioCore.h"

//#include "BreakoutGame.h"
//#include "BalloonFightGame.h"
#include "AnimalCrossingGame.h"

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

	//BreakoutGame::Run();
	//BalloonFightGame::Run();
	AnimalCrossingGame::Run();
	
	
	Deinitialize();
	

	return 0;
}
