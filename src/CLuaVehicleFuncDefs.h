#pragma once

#include "Main.h"

class CVehicleFuncDefs
{
public:
	static int createVehicle(lua_State *L);
	static int setVehiclePosition(lua_State *L);
	static int getVehiclePosition(lua_State *L);
};