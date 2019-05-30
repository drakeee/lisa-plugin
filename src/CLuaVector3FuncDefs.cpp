#include "Main.h"

void CVector3Defs::init(lua_State *L)
{
	CVector3Defs::initVariables(L);
	CVector3Defs::initClass(L);
}

void CVector3Defs::initClass(lua_State *L)
{
	lua_newclass(L, "Vector3");

	lua_classmetatable(L, "__gc", CVector3Defs::destroy);

	lua_registerfunction(L, "new", CVector3Defs::create, false);

	lua_registerclass(L);
}

void CVector3Defs::initVariables(lua_State *L)
{

}

int CVector3Defs::create(lua_State *L)
{
	Vector3 vector;

	CArgReader argReader(L);
	if(argReader.IsCurrentType(LUA_TTABLE))
	{
		//Syntax: Vector3({x = x, y = y, z = z})
		lua_pushstring(L, "x");
		lua_rawget(L, -2);

		if(lua_isnumber(L, -1))
		{
			vector.x = static_cast<float>(lua_tonumber(L, -1));
			lua_pop(L, 1);
		} else {
			lua_pop(L, 1);
			lua_rawgeti(L, -1, 1);

			if(lua_isnumber(L, -1))
				vector.x = static_cast<float>(lua_tonumber(L, -1));
			
			lua_pop(L, 1);
		}


		lua_pushstring(L, "y");
		lua_rawget(L, -2);

		if(lua_isnumber(L, -1))
		{
			vector.y = static_cast<float>(lua_tonumber(L, -1));
			lua_pop(L, 1);
		} else {
			lua_pop(L, 1);
			lua_rawgeti(L, -1, 2);

			if(lua_isnumber(L, -1))
				vector.y = static_cast<float>(lua_tonumber(L, -1));

			lua_pop(L, 1);
		}


		lua_pushstring(L, "z");
		lua_rawget(L, -2);

		if(lua_isnumber(L, -1))
		{
			vector.z = static_cast<float>(lua_tonumber(L, -1));
			lua_pop(L, 1);
		} else {
			lua_pop(L, 1);
			lua_rawgeti(L, -1, 3);

			if(lua_isnumber(L, -1))
				vector.z = static_cast<float>(lua_tonumber(L, -1));  

			lua_pop(L, 1);
		}

		lua_pop(L, 1);
	}else if(argReader.IsCurrentType(LUA_TNUMBER))
	{
		argReader.ReadVector3D(vector);
	}

	sampgdk::logprintf("Vector3: x = %f, y = %f, z = %f", vector.x, vector.y, vector.z);

	Vector3 *tempVector = new Vector3(vector);
	//auto tempVector = std::make_unique<Vector3>(vector);

	sampgdk::logprintf("Vector3(2): x = %f, y = %f, z = %f", tempVector->x, tempVector->y, tempVector->z);
	lua_userdata(L, "Vector3", tempVector);

	//lua_stacktrace(L, "Vector32");

	return 1;
}

int CVector3Defs::destroy(lua_State *L)
{
	Vector3 *vector = nullptr;

	CArgReader argReader(L);
	argReader.ReadUserData(vector);

	if(!argReader.HasAnyError())
	{
		delete vector;

		lua_pushboolean(L, true);
		return 1;
	}

	lua_pushboolean(L, false);
	return 1;
}