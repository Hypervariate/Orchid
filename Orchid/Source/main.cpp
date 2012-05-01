#include "EventCore.h"
#include "GlobalData.h"
#include "UtilityRectangle.h"
#include "UtilityCircle.h"
#include "AudioCore.h"
#include "Witch.h"

#include "TiledLevel.h"
#include "Timer.h"

#include "LuaInterface.h"
#include <boost/filesystem.hpp>

using namespace std;



int main()
{
	EventCore::Initialize();
	GraphicsCore::Initialize();
	AudioCore::Initialize();

	
	LuaInterface::Initialize();
	string filename = "test.lua";
	
	boost::filesystem3::path boostPath = boost::filesystem::initial_path();
	string scriptPath = boostPath.string() + "\\Script\\" + filename;
	cout << scriptPath << endl;

	EventCore::Update();

	TiledLevel level = TiledLevel();
	level.Load("desert");
	Timer timer = Timer(800);
	timer.Start();
	
	
	while(GlobalData::ApplicationRunning()){
		EventCore::Update();
		
		level.Update();
		level.Draw();
		GameObject::UpdateAll();

		LuaInterface::DoFile(scriptPath.c_str());

		//GraphicsCore::PrintToDisplay(b->GetX(), 0, 0, "Arcade", 255);
		//GraphicsCore::PrintToDisplay(b->GetY(), 0, 12,"Arcade", 255);
		
		/*GraphicsCore::PrintToDisplay(GraphicsCore::GetMapScrollingOffsetX(), 0, 36, "Arcade", 255);
		GraphicsCore::PrintToDisplay(GraphicsCore::GetMapScrollingOffsetY(), 0, 48,"Arcade", 255);
		GraphicsCore::PrintToDisplay(timer.GetRemainingTime(), 10, 0,"Arcade", 255, 128);*/
		/*if(timer.Arrived())
			GraphicsCore::PrintToDisplay("Arrived", 64, 0,"Arcade", 255, 128);
		else
			GraphicsCore::PrintToDisplay("Counting...", 64, 0,"Arcade", 255, 128);*/

		/*if(timer.GetRemainingTime() < -200)
			timer.Reset(400);*/
	}

	LuaInterface::Deinitialize();

	level.Unload();
	GameObject::DestroyAll();

	AudioCore::Deinitialize();
	GraphicsCore::Deinitialize();
	EventCore::Deinitialize();
	

	return 0;
}
