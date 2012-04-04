#include "EventCore.h"
#include "GlobalData.h"
#include "UtilityRectangle.h"
#include "UtilityCircle.h"
#include "AudioCore.h"

#include "mappy_A5.h"

int main(void)
{
	EventCore::Initialize();
	GraphicsCore::Initialize();
	AudioCore::Initialize();
	

	UtilityRectangle b = UtilityRectangle(WIDTH/2, HEIGHT/2, 100, 100);	

	EventCore::RegisterGameObjectAsPlayer(&b, 0);	

	UtilityCircle c = UtilityCircle();	

	
	

	EventCore::Update();

	AudioCore::Deinitialize();
	GraphicsCore::Deinitialize();
	EventCore::Deinitialize();
	

	return 0;
}
