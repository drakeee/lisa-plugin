#include "CLuaFunctionDefs.h"
#include "CEntity.h"

#include <sampgdk.h>

int CLuaDefs::Index(lua_State *L)
{
	//get the classname
	lua_getmetatable(L, -2);
	lua_getfield(L, -1, "__classname");
	const char* className = luaL_checkstring(L, -1);
	lua_pop(L, 2);

	//lua_getclass(L, className);
	//lua_getfield(L, -1, "__function");
	//lua_getfield(L, -1, luaL_checkstring(L, -3));
	lua_getclassfield(L, className, { "__function", luaL_checkstring(L, -1) });

	lua_stacktrace(L, "Indexhahaha");

	if (lua_isfunction(L, -1))
	{
		//lua_pop(L, -1);
		sampgdk::logprintf("Got function!");
		return 1;
	}

	//lua_remove(L, -2);
	//lua_pushstring()

	//sampgdk::logprintf("classname: %s", className);
	return 0;
}

int CLuaDefs::NewIndex(lua_State *L)
{
	lua_stacktrace(L, "CLuaDefs::NewIndex");

	return 1;
}

int CLuaDefs::Call(lua_State *L)
{
	if (!lua_istable(L, 1))
		return 0;

	int stackTop = lua_gettop(L);

	lua_getmetatable(L, 1);
	lua_getfield(L, -1, "__classname");
	const char* className = luaL_checkstring(L, -1);

	lua_pop(L, 1);

	//lua_getclass(L, className);
	//lua_getfield(L, -1, "__function");
	//lua_getfield(L, -1, "new");
	//lua_getclassfield(L, className, { "__function", "new" });
	lua_getclassfield(L, className, { "__function", "new" });

	if (lua_isfunction(L, -1))
	{
		for (int i = 2; i <= stackTop; i++)
		{
			//sampgdk::logprintf("pushvalue");
			lua_pushvalue(L, i);
		}

		//lua_settop(L, -3);

		lua_call(L, stackTop - 1, LUA_MULTRET);

		return lua_gettop(L) - stackTop - 1;
	}

	//if function not found delete the stack
	lua_settop(L, 0);

	//lua_stacktrace(L, "CLuaDefs::Call");

	return 0;
}