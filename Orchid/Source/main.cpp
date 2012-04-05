#include "EventCore.h"
#include "GlobalData.h"
#include "UtilityRectangle.h"
#include "UtilityCircle.h"
#include "AudioCore.h"

#include "GameLevel.h"

int main(void)
{
	EventCore::Initialize();
	GraphicsCore::Initialize();
	AudioCore::Initialize();
	
	GameLevel level = GameLevel();
	level.Load("Data/Maps/0.fmp");
	level.DrawBackground();
	level.DrawForeground();
	GraphicsCore::FlipDisplay();
	level.Unload();

	UtilityRectangle b = UtilityRectangle(WIDTH/2, HEIGHT/2, 100, 100);	

	EventCore::RegisterGameObjectAsPlayer(&b, 0);	

	UtilityCircle c = UtilityCircle(WIDTH/2, HEIGHT/2, 50);
	EventCore::RegisterGameObjectAsPlayer(&c, 1);

	
	

	EventCore::Update();

	AudioCore::Deinitialize();
	GraphicsCore::Deinitialize();
	EventCore::Deinitialize();
	

	return 0;
}
