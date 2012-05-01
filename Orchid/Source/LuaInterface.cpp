#include "LuaInterface.h"

lua_State* LuaInterface::L;

LuaInterface::LuaInterface(){}
LuaInterface::~LuaInterface(){}
bool LuaInterface::Initialize(){
	/* initialize Lua */
	L = lua_open();

	/* load Lua base libraries */
	luaL_openlibs(L);

	/* register our function */
	lua_register(L, "average", average);
	lua_register(L, "PrintToDisplay", PrintToDisplay);

	return true;
}
bool LuaInterface::DoFile(const char* filePath){
	//run a Lua scrip here
    if (luaL_dofile(L, filePath))
    {
        printf("%s\n", lua_tostring(L, -1));
		return false;
    }
	return true;
}
bool LuaInterface::Deinitialize(){
	/* cleanup Lua */
	lua_close(L);

	return true;
}
int LuaInterface::average(lua_State *L)
{
	/* get number of arguments */
	int n = lua_gettop(L);
	double sum = 0;
	int i;

	/* loop through each argument */
	for (i = 1; i <= n; i++)
	{
		/* total the arguments */
		sum += lua_tonumber(L, i);
	}

	/* push the average */
	lua_pushnumber(L, sum / n);

	/* push the sum */
	lua_pushnumber(L, sum);

	/* return the number of results */
	return 2;
}
int LuaInterface::PrintToDisplay(lua_State *L)
{
	/* get number of arguments */
	int n = lua_gettop(L);
	
	const char* text = lua_tostring(L,1);
	int x = lua_tonumber(L,2);
	int y = lua_tonumber(L,3);
	const char* font = lua_tostring(L,4);
	int r = lua_tonumber(L,5);
	int g = lua_tonumber(L,6);
	int b = lua_tonumber(L,7);

	GraphicsCore::PrintToDisplay(text, x, y, font, r, g, b);

	return 0;
}