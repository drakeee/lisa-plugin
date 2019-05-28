#pragma once

#include "Main.h"

class CVehicleFuncDefs
{
public:
	static void init(lua_State *L);
	static void initClass(lua_State *L);
	static void initVariables(lua_State *L);
	static void initFunctions(lua_State *L);
	static int createVehicle(lua_State *L);
	static int setVehiclePosition(lua_State *L);
	static int getVehiclePosition(lua_State *L);
};