#include "EventCore.h"
#include "GlobalData.h"
#include "UtilityRectangle.h"
#include "UtilityCircle.h"
#include "AudioCore.h"
#include "Witch.h"

#include "GameLevel.h"

int main(void)
{
	EventCore::Initialize();
	GraphicsCore::Initialize();
	AudioCore::Initialize();
	
	
	

	UtilityRectangle b = UtilityRectangle(WIDTH/2, HEIGHT/2, 100, 100);	
	//Witch b = Witch();
	EventCore::RegisterGameObjectAsPlayer(&b, 0);	

	UtilityCircle c = UtilityCircle(WIDTH/2, HEIGHT/2, 50);
	EventCore::RegisterGameObjectAsPlayer(&c, 1);

	GameLevel level = GameLevel();
	level.Load("0", &b);
	
	while(GlobalData::ApplicationRunning()){
		EventCore::Update();
		level.Update();
		level.DrawBackground();
		GameObject::UpdateAll();
		level.DrawForeground();
		
	}

	level.Unload();

	AudioCore::Deinitialize();
	GraphicsCore::Deinitialize();
	EventCore::Deinitialize();
	

	return 0;
}
