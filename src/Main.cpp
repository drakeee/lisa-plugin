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
		sampgdk::logprintf("OnPlayerSelectObject");

		for(int i = 0; i < params[0]/sizeof(cell); i++)
		{
			
			//Check if we need to allocate memory for storing value
			//NOTE: If addr is greater than 0 it means that its probably a string, otherwise it's float or number or bool
			cell *addr;
			amx_GetAddr(amx, params[i + 1], &addr);

			if(addr > 0)
			{
				int stringLength = 0;
				amx_StrLen(addr, &stringLength);

				sampgdk::logprintf("Size: %d", stringLength);
			}

			sampgdk::logprintf("Param(%d): %d | addr: %d", i + 1, params[i + 1], addr);
		}
	}

	if(!strcmp(name, "TestShit"))
	{
		sampgdk::logprintf("TestShit");

		for(int i = 0; i < params[0]/sizeof(cell); i++)
		{
			cell *addr;
			amx_GetAddr(amx, params[i + 1], &addr);

			if(addr > 0)
			{
				int stringLength = 0;
				amx_StrLen(addr, &stringLength);

				if(stringLength > 1)
				{
					stringLength++;

					sampgdk::logprintf("Size: %d", stringLength);

					char *temp_string = new char[stringLength];
					amx_GetString(temp_string, addr, 0, stringLength);
					sampgdk::logprintf("String: %s", temp_string);

					delete[] temp_string;
				}
			}

			sampgdk::logprintf("Param(%d): %d | addr: %d", i + 1, params[i + 1], addr);
		}
	}

	return true;
}

lua_State *L = nullptr;
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

	index = 0;
	if(!amx_FindPublic(a, "TestShit", &index))
	{
		cell addr;
		amx_PushString(a, &addr, NULL, "", 0, 0);

		//int teszt[6] = {0, 1, 2, 3, 4, 5};
		//amx_PushArray(a, &addr, NULL, teszt, 6);

		amx_Exec(a, NULL, index);
	}

	//Create new Lua virtual machine
	if(L == nullptr)
		L = luaL_newstate();

	//Import default libraries into the vm
	luaL_openlibs(L);
	lua_initclass(L);
	
	CVector3Defs::init(L);
	CVehicleFuncDefs::init(L);

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

	lua_gc(L, LUA_GCCOLLECT, 0);
	//lua_close(L);

	return true;
}