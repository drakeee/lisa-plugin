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