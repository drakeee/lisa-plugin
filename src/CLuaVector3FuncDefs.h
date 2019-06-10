#pragma once

#include "Main.h"

class CVector3Defs
{
public:
	static void init(lua_State *L);
	static void initClass(lua_State *L);
	static void initVariables(lua_State *L);
	static int create(lua_State *L);
	static int destroy(lua_State *L);
	static int tostring(lua_State *L);
};