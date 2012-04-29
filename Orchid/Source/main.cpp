extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

#include <iostream>
using namespace std;


#include <boost/filesystem.hpp>



int main()
{
    int s=0;
 
    lua_State *L = lua_open();
 
    // load the libs
    luaL_openlibs(L);

	string filename = "foo.lua";
	
	boost::filesystem3::path boostPath = boost::filesystem::initial_path();
	string scriptPath = boostPath.string() + "\\Script\\" + filename;
	cout << scriptPath << endl;
	

 
    //run a Lua scrip here
    if (luaL_dofile(L, scriptPath.c_str()))
    {
        printf("%s\n", lua_tostring(L, -1));
    }
 
    printf("\nI am done with Lua in C++.\n");
 
    lua_close(L);
 
    return 0;
}


//#include "EventCore.h"
//#include "GlobalData.h"
//#include "UtilityRectangle.h"
//#include "UtilityCircle.h"
//#include "AudioCore.h"
//#include "Witch.h"
//
//#include "TiledLevel.h"
//#include "Timer.h"
//
//
//int main(void)
//{
//	EventCore::Initialize();
//	GraphicsCore::Initialize();
//	AudioCore::Initialize();
//
//	EventCore::Update();
//
//	TiledLevel level = TiledLevel();
//	level.Load("desert");
//	Timer timer = Timer(800);
//	timer.Start();
//	
//	
//	while(GlobalData::ApplicationRunning()){
//		EventCore::Update();
//		
//		level.Update();
//		level.Draw();
//		GameObject::UpdateAll();
//		//GraphicsCore::PrintToDisplay(b->GetX(), 0, 0, "Arcade", 255);
//		//GraphicsCore::PrintToDisplay(b->GetY(), 0, 12,"Arcade", 255);
//		
//		GraphicsCore::PrintToDisplay(GraphicsCore::GetMapScrollingOffsetX(), 0, 36, "Arcade", 255);
//		GraphicsCore::PrintToDisplay(GraphicsCore::GetMapScrollingOffsetY(), 0, 48,"Arcade", 255);
//		GraphicsCore::PrintToDisplay(timer.GetRemainingTime(), 10, 0,"Arcade", 255, 128);
//		if(timer.Arrived())
//			GraphicsCore::PrintToDisplay("Arrived", 64, 0,"Arcade", 255, 128);
//		else
//			GraphicsCore::PrintToDisplay("Counting...", 64, 0,"Arcade", 255, 128);
//
//		if(timer.GetRemainingTime() < -200)
//			timer.Reset(400);
//	}
//
//	level.Unload();
//	GameObject::DestroyAll();
//
//	AudioCore::Deinitialize();
//	GraphicsCore::Deinitialize();
//	EventCore::Deinitialize();
//	
//
//	return 0;
//}
