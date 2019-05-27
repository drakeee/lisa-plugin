#include "Main.h"

extern void *pAMXFunctions;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return sampgdk::Supports() | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData)
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];

	sampgdk::logprintf("Plugin Loaded:");
	sampgdk::logprintf("\tPlugin name: %s", PLUGIN_NAME);
	sampgdk::logprintf("\tPlugin version: %s", PLUGIN_VERSION);
	sampgdk::logprintf("\tPlugin author: %s", PLUGIN_AUTHOR);

	return sampgdk::Load(ppData);
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	sampgdk::Unload();
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick()
{
	sampgdk::ProcessTick();
}

AMX *a;
PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx)
{
    return AMX_ERR_NONE;
}


PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx)
{
    return AMX_ERR_NONE;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPublicCall(AMX *amx, const char *name, cell *params, cell *retval)
{
	sampgdk::logprintf("Invoke details:");
	sampgdk::logprintf("\tNative name: %s", name);
	sampgdk::logprintf("\tNative param count: %d", params[0]/sizeof(cell));
	sampgdk::logprintf("\tNative return value: %d", nullptr);

	a = amx;

	if(!strcmp(name, "OnPlayerSelectObject"))
	{
		sampgdk::logprintf("Selected");

		sampgdk::logprintf("Param1: %d", params[1]);
		sampgdk::logprintf("Param2: %d", params[2]);
		sampgdk::logprintf("Param3: %d", params[3]);
		sampgdk::logprintf("Param4: %d", params[4]);
		sampgdk::logprintf("Param5: %d", params[5]);
		sampgdk::logprintf("Param6: %d", params[6]);
		sampgdk::logprintf("Param7: %d", params[7]);
	}

	return true;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeInit()
{
	sampgdk::logprintf("OnGameModeInit invoked.");

	sampgdk::logprintf("Testing out callback.");

	int index = 0;
	if(!amx_FindPublic(a, "OnPlayerSelectObject", &index))
	{
		amx_Push(a, 12.0f); //Float:fZ;
		amx_Push(a, 11.0f); //Float:fY,
		amx_Push(a, 10.0f); //Float:fX,
		amx_Push(a, 100); //modelid,
		amx_Push(a, 22); //objectid,
		amx_Push(a, 21); //type,
		amx_Push(a, 20); //playerid,

		amx_Exec(a, NULL, index);
		sampgdk::logprintf("Found OnPlayerSelectObject");
	}

	//Create new Lua virtual machine
	lua_State *L = luaL_newstate();

	//Import default libraries into the vm
	luaL_openlibs(L);
	lua_initclass(L);
	

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