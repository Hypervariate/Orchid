#include "GraphicsCore.h"
#include "InputCore.h"
#include "GlobalData.h"
#include "Witch.h"


int main(void)
{
	if(!al_init())			//initialize Allegro
		return -1;
	
	GraphicsCore::Initialize();
	InputCore::Initialize();
	
	
	

	Witch w0 = Witch();
	Witch w1 = Witch();
	InputCore::RegisterGameObjectAsPlayer(&w0, 0);
	InputCore::RegisterGameObjectAsPlayer(&w1, 1);

	
	while(GlobalData::ApplicationRunning()){

		w0.Update();
		w1.Update();
		w0.Draw();
		w1.Draw();

		
		
		GraphicsCore::Update();
		InputCore::Update();
		

	}
	

	GraphicsCore::Deinitialize();
	InputCore::Deinitialize();
	

	return 0;
}
