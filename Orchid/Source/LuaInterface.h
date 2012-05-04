#ifndef LUAINTERFACE_H_
#define LUAINTERFACE_H_

//This class is unfinished
//and is a post 1.0 feature
#include <stdio.h>

extern "C" {
	#include "lua.h"
	#include "lualib.h"
	#include "lauxlib.h"
}

#include "GraphicsCore.h"

class LuaInterface{
public:
	LuaInterface();
	~LuaInterface();
	
	static bool Initialize();
	static bool DoFile(const char* filePath);
	static bool Deinitialize();

	static int average(lua_State *L);
	
	//Graphics Core
	static int PrintToDisplay(lua_State *L);

private:
	/* the Lua interpreter */
	static lua_State* L;


};


#endif