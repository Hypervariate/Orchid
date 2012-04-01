#include "EventCore.h"
#include "GlobalData.h"
#include "Witch.h"


int main(void)
{
	EventCore::Initialize();
	GraphicsCore::Initialize();
	
	Witch w = Witch();
	EventCore::RegisterGameObjectAsPlayer(&w, 0);		

	EventCore::Update();
	

	GraphicsCore::Deinitialize();
	EventCore::Deinitialize();
	

	return 0;
}
