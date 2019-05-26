#pragma once

#include "Main.h"

class CEntity;

class CLuaDefs
{
public:
	static const char* GetEntityType(CEntity *entity);
	static int Index(lua_State *L);
	static int NewIndex(lua_State *L);
	static int Call(lua_State *L);
};