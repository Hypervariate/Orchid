#include "GraphicsCore.h"
#include "EventCore.h"
#include "GlobalData.h"
#include "Witch.h"


int main(void)
{
	if(!al_init())			//initialize Allegro
		return -1;
	
	GraphicsCore::Initialize();
	EventCore::Initialize();
	
	
	
	EventCore::Update();
		

	
	

	GraphicsCore::Deinitialize();
	EventCore::Deinitialize();
	

	return 0;
}
