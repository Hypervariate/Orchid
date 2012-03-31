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
	
	
	

	Witch w0 = Witch();
	
	EventCore::RegisterGameObjectAsPlayer(&w0, 0);
	

	
	while(GlobalData::ApplicationRunning()){

		w0.Update();		
		w0.Draw();		
		EventCore::Update();
		

	}
	

	GraphicsCore::Deinitialize();
	EventCore::Deinitialize();
	

	return 0;
}
