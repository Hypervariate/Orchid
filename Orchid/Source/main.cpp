#include "EventCore.h"
#include "GlobalData.h"
#include "UtilityRectangle.h"
#include "UtilityCircle.h"
#include "AudioCore.h"
#include "Witch.h"

#include "TiledLevel.h"


int main(void)
{
	EventCore::Initialize();
	GraphicsCore::Initialize();
	AudioCore::Initialize();
	
	TiledLevel level = TiledLevel();
	level.Load("grass");
	
	while(GlobalData::ApplicationRunning()){
		EventCore::Update();
		
		level.Update();
		level.Draw();
		GameObject::UpdateAll();
		//GraphicsCore::PrintToDisplay(b->GetX(), 0, 0, "Arcade", 255);
		//GraphicsCore::PrintToDisplay(b->GetY(), 0, 12,"Arcade", 255);
		
		GraphicsCore::PrintToDisplay(GraphicsCore::GetMapScrollingOffsetX(), 0, 36, "Arcade", 255);
		GraphicsCore::PrintToDisplay(GraphicsCore::GetMapScrollingOffsetY(), 0, 48,"Arcade", 255);
		
	}

	level.Unload();
	GameObject::DestroyAll();

	AudioCore::Deinitialize();
	GraphicsCore::Deinitialize();
	EventCore::Deinitialize();
	

	return 0;
}
