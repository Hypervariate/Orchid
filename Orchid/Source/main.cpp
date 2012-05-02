#include "EventCore.h"
#include "GlobalData.h"
#include "UtilityRectangle.h"
#include "UtilityCircle.h"
#include "AudioCore.h"
#include "Witch.h"

#include "TiledLevel.h"
#include "Timer.h"
#include "BreakoutBlock.h"
#include "BreakoutPaddle.h"
#include "BreakoutPaddleController.h"
#include "LuaInterface.h"
#include <boost/filesystem.hpp>

using namespace std;



int main()
{
	EventCore::Initialize();
	GraphicsCore::Initialize();
	AudioCore::Initialize();

	int bx = 48;
	int by = 24;
	for(int i = 1; i < 13; i++){
		for(int j = 1; j < 5; j++){
			BreakoutBlock* b = new BreakoutBlock(i * bx, j * by);
			GameObject::AddToWorld(b);
		}
	}

	
	BreakoutPaddle* p = new BreakoutPaddle(WIDTH/2, HEIGHT - 100);
	EventCore::RegisterGameObjectAsPlayer(p, 0, new BreakoutPaddleController());
	GameObject::AddToWorld(p);
	
	
	Timer timer = Timer(250);
	timer.Start();
	

	AudioCore::PlayMusic("BreakoutBGM");
	while(GlobalData::ApplicationRunning()){
		EventCore::Update();
		GameObject::UpdateAll();

		if(!timer.Arrived())
			GraphicsCore::PrintToDisplay("Press space to start.", WIDTH/3, HEIGHT/2,"Arcade", 255);
		

	}

	
	
	GameObject::DestroyAll();
	AudioCore::Deinitialize();
	GraphicsCore::Deinitialize();
	EventCore::Deinitialize();
	

	return 0;
}
