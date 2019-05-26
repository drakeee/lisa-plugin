#include "Main.h"

PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeInit()
{
	sampgdk::logprintf("OnGameModeInit invoked.");

	//Create new Lua virtual machine
	lua_State *L = luaL_newstate();

	//Import default libraries into the vm
	luaL_openlibs(L);

	//Try to load file for testing purposes
	if(luaL_dofile(L, "./scripts/test.lua"))
	{
		//Sadly far from perfect
		sampgdk::logprintf(" Unable to load \"test.lua\"");

		//Get the error from the top of the stack
		if (lua_isstring(L, -1))
			sampgdk::logprintf(" Error: %s", luaL_checkstring(L, -1));

		//Close virtual machine and point to null pointer
		lua_close(L);
		L = nullptr;
	}

	return true;
}