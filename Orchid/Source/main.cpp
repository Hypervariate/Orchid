#include "GraphicsCore.h"
#include "InputCore.h"
#include "GlobalData.h"
#include "GameObject.h"

int main(void)
{
	if(!al_init())			//initialize Allegro
		return -1;
	
	GraphicsCore::Initialize();
	InputCore::Initialize();

	
	GameObject go = GameObject();
	
	while(GlobalData::ApplicationRunning()){

		
		
		
		GraphicsCore::Update();
		InputCore::Update();
		
		
	}
	

	GraphicsCore::Deinitialize();
	InputCore::Deinitialize();

	return 0;
}
