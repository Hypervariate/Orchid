#include "EventCore.h"
#include "GlobalData.h"
#include "Witch.h"
#include "FileReader.h"
#include "Animation.h"

int main(void)
{
	EventCore::Initialize();
	GraphicsCore::Initialize();
	
	

	Witch w = Witch();
	EventCore::RegisterGameObjectAsPlayer(&w, 0);	

	Witch w2 = Witch();	

	EventCore::Update();

	GraphicsCore::Deinitialize();
	EventCore::Deinitialize();
	

	return 0;
}
