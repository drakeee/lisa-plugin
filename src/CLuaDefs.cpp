#include "LuaDefs.h"
#include "CLuaFunctionDefs.h"

#include <sampgdk.h>
#include <cassert>

void lua_stacktrace(lua_State* L, const char* stackName)
{
	int stackTop = lua_gettop(L);

	sampgdk::logprintf(" --------- Stack Begins: %s---------", stackName);
	for (size_t i = stackTop; i >= 1; i--)
	{
		int valueType = lua_type(L, i);
		switch (valueType)
		{
		case LUA_TSTRING:
			sampgdk::logprintf("\tAbsolute: %d ~~ Relative: %d ~~\t Value: '%s'", i, (i - stackTop) - 1, luaL_checkstring(L, i));
			break;
		case LUA_TBOOLEAN:
			sampgdk::logprintf("\tAbsolute: %d ~~ Relative: %d ~~\t Value: '%s'", i, (i - stackTop) - 1, lua_toboolean(L, i) ? ("true") : ("false"));
			break;
		case LUA_TNUMBER:
			sampgdk::logprintf("\tAbsolute: %d ~~ Relative: %d ~~\t Value: '%g'", i, (i - stackTop) - 1, luaL_checknumber(L, i));
			break;
		case LUA_TTABLE:
			sampgdk::logprintf("\tAbsolute: %d ~~ Relative: %d ~~\t Value '%s'", i, (i - stackTop) - 1, lua_typename(L, valueType));
			sampgdk::logprintf("\t{");

			lua_dumptable(L, i, 2);

			sampgdk::logprintf("\t}");
			/*lua_pushnil(L);
			while (lua_next(L, i) != 0)
			{
			sampgdk::logprintf("%s => %s", lua_tostring(L, -2), lua_tostring(L, -1));
			lua_pop(L, 1);
			}*/

			break;
		default:
			sampgdk::logprintf("\tAbsolute: %d ~~ Relative: %d ~~\t Value type: %s", i, (i - stackTop) - 1, lua_typename(L, valueType));
			break;
		}
	}
	sampgdk::logprintf(" --------- Stack Ends: %s ---------", stackName);
}

void lua_dumptable(lua_State *L, int idx, int level)
{
	std::string levelTab;
	levelTab.insert(0, level, '\t');

	lua_pushnil(L);  /* first key */
	while (lua_next(L, idx) != 0)
	{
		//we need to copy the key and value so lua_tostring will not convert it to other type
		lua_pushvalue(L, -2);

		//check if value is table
		if (lua_istable(L, -2))
		{
			//make it beautifuly aligned
			sampgdk::logprintf("%s%s => Table\n%s{", levelTab.c_str(), lua_tostring(L, -1), levelTab.c_str());

			//for some reason we need to pass the original table and not the referenced one (recursive call)
			lua_dumptable(L, -3, level + 1);

			//make it beautifuly aligned
			sampgdk::logprintf("%s}", levelTab.c_str());
		}
		else
			sampgdk::logprintf("%s%s => %s,", levelTab.c_str(), lua_tostring(L, -1), lua_tostring(L, -2));

		lua_pop(L, 2);
	}
}

void lua_inserttable(lua_State *L, int idx, const char* key, const char* value)
{
	assert(lua_istable(L, idx));

	lua_pushstring(L, key);
	lua_pushstring(L, value);
	lua_settable(L, idx - 2);

	sampgdk::logprintf("Here lies table");
}

void lua_initclass(lua_State *L)
{
	lua_newtable(L);
	lua_setfield(L, LUA_REGISTRYINDEX, "ge"); //generic elements storage unit in registry

	lua_newtable(L);
	lua_setfield(L, LUA_REGISTRYINDEX, "ge_mt"); //generic elements metatable
}

void lua_newclass(lua_State *L, const char* className)
{
	lua_getfield(L, LUA_REGISTRYINDEX, "ge_mt");
	if (!lua_istable(L, -1))
	{
		sampgdk::logprintf("[C_LUA] ge_mt does not exists!");
		return;
	}

	//create new table for metatable
	lua_pushstring(L, className);
	lua_newtable(L);
	{
		lua_pushstring(L, "__classname");
		//lua_pushboolean(L, 0);
		lua_pushstring(L, className);
		lua_rawset(L, -3);

		//Leave it be normal className
		lua_pushstring(L, "__name");
		//lua_pushboolean(L, 0);
		lua_pushstring(L, className);
		lua_rawset(L, -3);

		lua_pushstring(L, "__call");
		//lua_pushboolean(L, 0);
		lua_pushcfunction(L, CLuaDefs::Call);
		//TODO: create function for __calls
		lua_rawset(L, -3);

		lua_pushstring(L, "__index");
		//lua_pushnil(L);
		lua_pushcfunction(L, CLuaDefs::Index);
		lua_rawset(L, -3);

		lua_pushstring(L, "__newindex");
		//lua_pushnil(L);
		lua_pushcfunction(L, CLuaDefs::NewIndex);
		lua_rawset(L, -3);
	}

	//save the table under className in ge_mt table
	lua_rawset(L, -3);
	lua_pop(L, 1);



	//create the table for functions, variable, etc
	lua_getfield(L, LUA_REGISTRYINDEX, "ge");

	lua_pushstring(L, className);
	lua_newtable(L);
	{
		lua_pushstring(L, "__classname");
		lua_pushstring(L, className);
		lua_rawset(L, -3);

		lua_pushstring(L, "__function");
		//lua_pushboolean(L, 0);
		lua_newtable(L);
		lua_rawset(L, -3);

		lua_pushstring(L, "__set");
		lua_newtable(L);
		//TODO: create function for __calls
		lua_rawset(L, -3);

		lua_pushstring(L, "__get");
		//lua_pushnil(L);
		lua_newtable(L);
		lua_rawset(L, -3);
	}

	lua_rawset(L, -3);
	lua_pop(L, 1);

	lua_pushstring(L, className);
}

//void lua_registerclass(lua_State *L, const char* className)
void lua_registerclass(lua_State *L)
{
	const char* className = luaL_checkstring(L, -1);

	lua_pop(L, 1);

	lua_newtable(L);
	lua_getclassmt(L, className);
	lua_setmetatable(L, -2);
	lua_setglobal(L, className);
}

void lua_registerfunction(lua_State *L, const char* functionName, lua_CFunction func)
{
	const char* className = luaL_checkstring(L, -1);
	
	lua_getclassfield(L, className, {"__function"});
	lua_getfield(L, -1, functionName);

	//check if function does not exists
	if (lua_isnil(L, -1))
	{
		//pop the nil value from the top
		lua_pop(L, 1);

		//push function to the stack, then set the table (ge.class["__function"][functionName] = func)
		lua_pushstring(L, functionName);
		lua_pushcfunction(L, func);
		lua_rawset(L, -3);

		lua_getfield(L, -1, functionName);
		lua_setglobal(L, functionName);

		//stack: ge.class table, ge.class["__function"] table
		lua_pop(L, 1); //after pop: ge.class table

		//sampgdk::logprintf("-lua_registerfunction: %s", functionName);
	}
}

void lua_registeroop(lua_State *L, const char* oopName, const char* functionName)
{
	const char* className = luaL_checkstring(L, -1);
	lua_getclassfield(L, className, { "__function", functionName });

	if (lua_isfunction(L, -1))
	{
		lua_getclassfield(L, className, { "__function" });
		lua_pushstring(L, oopName);
		lua_pushvalue(L, -3);

		lua_rawset(L, -3);

		lua_pop(L, 2);
	}
	else
	{
		sampgdk::logprintf("Unable to register function: %s, Error: %s function not found!", oopName, functionName);
		lua_pop(L, 1);
	}
}

void lua_registervariable(lua_State *L, const char* variableName, const char* setFunction, const char* getFunction)
{
	const char* className = luaL_checkstring(L, -1);

	//Register function for set variable
	lua_getclassfield(L, className, { "__set" });
	lua_getclassfield(L, className, { "__function", setFunction });

	if(lua_isfunction(L, -1))
	{
		lua_pushstring(L, variableName);
		lua_insert(L, -2);
		lua_rawset(L, -3);

		lua_pop(L, 1);
	}

	//Register function for get variable
	lua_getclassfield(L, className, { "__get" });
	lua_getclassfield(L, className, { "__function", getFunction });

	if (lua_isfunction(L, -1))
	{
		lua_pushstring(L, variableName);
		lua_insert(L, -2);
		lua_rawset(L, -3);

		lua_pop(L, 1);
	}
}

void lua_getclass_helper(lua_State *L, bool mt, const char* className)
{
	//get metatables or storage unit (depending on "mt" variable) from lua registry
	lua_getfield(L, LUA_REGISTRYINDEX, (mt ? ("ge_mt") : ("ge"))); //stack: ge_mt (table?)

	//check if we have indeed a table for it
	if (!lua_istable(L, -1))
	{
		sampgdk::logprintf("Unable to retrieve generic elements metatable!");
		return;
	}

	//push which index we want to access then get it from the table
	lua_pushstring(L, className); //stack: ge_mt, className
	lua_rawget(L, -2); //ge_mt table, class (table?)

	//if there is no class metatable then inform about it
	if (!lua_istable(L, -1))
	{
		sampgdk::logprintf("Unable to retrieve \"%s\" class metatable!", className);
		return;
	}

	//remove "ge_mt" metatable from the stack leaving only the requested class metatable
	lua_remove(L, -2); //class table
}

/*void lua_getclass(lua_State *L, const char* className)
{
	lua_getfield(L, LUA_REGISTRYINDEX, "ge");
	if (!lua_istable(L, -1))
	{
		//lua_pop(L, 1);
		sampgdk::logprintf("Unable to retrieve generic elements storage unit!");
		return;
	}

	lua_pushstring(L, className);
	lua_rawget(L, -2);

	if (!lua_istable(L, -1))
	{
		lua_remove(L, -2);
		sampgdk::logprintf("Unable to retrieve \"%s\" class storage unit!", className);
		return;
	}

	lua_remove(L, -2);
}

void lua_getclassmt(lua_State *L, const char* className)
{
	//get metatables from lua registry
	lua_getfield(L, LUA_REGISTRYINDEX, "ge_mt"); //stack: ge_mt (table?)

	//check if we have indeed a table for it
	if (!lua_istable(L, -1))
	{
		sampgdk::logprintf("Unable to retrieve generic elements metatable!");
		return;
	}

	//push which index we want to access then get it from the table
	lua_pushstring(L, className); //stack: ge_mt, className
	lua_rawget(L, -2); //ge_mt table, class (table?)

	//if there is no class metatable then inform about it
	if (!lua_istable(L, -1))
	{
		sampgdk::logprintf("Unable to retrieve \"%s\" class metatable!", className);
		return;
	}

	//remove "ge_mt" metatable from the stack leaving only the requested class metatable
	lua_remove(L, -2); //class table
}*/

void lua_getclassfield_helper(lua_State *L, bool mt, const char* className, std::initializer_list<std::string> values)
{
	//check the stack size because we want to keep them
	int startStack = lua_gettop(L);

	//check if we need metatable or the storage unit
	if (!mt)
		lua_getclass(L, className);
	else
		lua_getclassmt(L, className);

	if (!lua_istable(L, -1))
	{
		//if we dont have matching table then push a nil on top
		lua_pushnil(L);
		return;
	}

	//count how many string we have been processed
	int numString = 0;

	//run through all the strings
	for(auto &value : values)
	{
		//count how many string we have been processed
		numString++;

		//convert string to const char
		const char* a = value.c_str();
		
		//get given key
		lua_getfield(L, -1, a);

		//check if the result is nil or not
		if (lua_isnil(L, -1))
			break;

		//if not and we have a table on top of the stack and we have more string then continue
		if (lua_istable(L, -1) && numString != values.size())
			continue;
	}

	//keep the started stack only + the result on top
	int stackNum = lua_gettop(L) - startStack - 1; //-1 means how many values we want to save
	for (int i = 1; i <= stackNum; i++)
		lua_remove(L, startStack + 1);
}

void lua_getdebuginfo(lua_State *L, lua_Debug &debugInfo)
{
	//lua_Debug debugInfo;
	const char* nameTemp = nullptr;

	for (int level = 0; level <= 4; level++)
	{
		//get info about interpreter stack
		int stackInfo = lua_getstack(L, level, &debugInfo);

		//if there is no information then stop loop
		if (stackInfo == 0)
			break;

		//get info about function
		lua_getinfo(L, "nSl", &debugInfo);

		//if we got a function name then store it
		if (debugInfo.name != nullptr)
		{
			nameTemp = debugInfo.name;
		}

		//if we don't have the currentline then it means we need to go deeper
		if (debugInfo.currentline == -1)
			continue;
		else
		{
			//load the stored function name into the struct
			debugInfo.name = nameTemp;
			break;
		}
	}
}