#ifndef _LUA_DEFINITIONS_H
#define _LUA_DEFINITIONS_H

#include <string>
#include <utility>

#define lua_clearstack(L) lua_pop(L, lua_gettop(L))
#define lua_getclass(L,classname) \
	lua_getclass_helper(L, false, classname)

#define lua_getclassmt(L,classname) \
	lua_getclass_helper(L, true, classname)

#define lua_getclassfield(L,classname,...) \
	lua_getclassfield_helper(L, false, classname, __VA_ARGS__)

#define lua_getclassfieldmt(L,classname,...) \
	lua_getclassfield_helper(L, true, classname, __VA_ARGS__)

void lua_stacktrace(lua_State* L, const char* stackName = "Unknown");
void lua_dumptable(lua_State *L, int idx, int level = 0);
void lua_inserttable(lua_State *L, int idx, const char* key, const char* value);

void lua_initclass(lua_State *L);
void lua_newclass(lua_State *L, const char* className = "");
void lua_classmetatable(lua_State *L, const char* metaName, lua_CFunction func);
//void lua_registerclass(lua_State *L, const char* className);
void lua_registerclass(lua_State *L);
void lua_registerfunction(lua_State *L, const char* functionName, lua_CFunction func, bool isGlobal = true);
void lua_registeroop(lua_State *L, const char* oopName, const char* functionName);
void lua_registervariable(lua_State *L, const char* variableName, const char* setFunction, const char* getFunction);
void lua_getclass_helper(lua_State *L, bool mt, const char* className);
//void lua_getclass(lua_State *L, const char* className);
//void lua_getclassmt(lua_State *L, const char* className);

template <typename T>
T* lua_userdata(lua_State *L, const char* className, T* userdata)
{
	T **tempUserdata = reinterpret_cast<T **>(lua_newuserdata(L, sizeof(T*)));
	*tempUserdata = userdata;

	//Experimental stuff
	//void *tempUserdata = lua_newuserdata(L, sizeof(T*));
	//new(tempUserdata) std::unique_ptr<T>(userdata);

	lua_getclassmt(L, className);
	lua_setmetatable(L, -2);

	return userdata;
}

void lua_getclassfield_helper(lua_State *L, bool mt, const char* className, std::initializer_list<std::string> values);
void lua_getdebuginfo(lua_State *L, lua_Debug &debugInfo);

#endif