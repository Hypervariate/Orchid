#include "EventCore.h"
#include "GlobalData.h"
#include "Witch.h"
#include "AudioCore.h"

int main(void)
{
	EventCore::Initialize();
	GraphicsCore::Initialize();
	AudioCore::Initialize();
	

	Witch w = Witch();
	EventCore::RegisterGameObjectAsPlayer(&w, 0);	

	Witch w2 = Witch();	
	AudioCore::PlaySample("chirp");

	EventCore::Update();

	AudioCore::Deinitialize();
	GraphicsCore::Deinitialize();
	EventCore::Deinitialize();
	

	return 0;
}
