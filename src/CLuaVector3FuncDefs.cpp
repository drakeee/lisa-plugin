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
	lua_classmetatable(L, "__tostring", CVector3Defs::tostring);

	lua_registerfunction(L, "new", CVector3Defs::create, false);

	lua_registerclass(L);
}

void CVector3Defs::initVariables(lua_State *L)
{

}

int CVector3Defs::create(lua_State *L)
{
	Vector3 vector(0.1, 0.2, 0.3);

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

	sampgdk::logprintf("Vector3(2): x = %f, y = %f, z = %f", tempVector->x, tempVector->y, tempVector->z);
	lua_userdata(L, "Vector3", tempVector);

	//lua_stacktrace(L, "Vector32");

	return 1;
}

int CVector3Defs::destroy(lua_State *L)
{
	Vector3 *vector = nullptr;

	lua_stacktrace(L, "destroy");

	CArgReader argReader(L);
	argReader.ReadUserData(vector);

	if(!argReader.HasAnyError())
	{
		delete vector;

		sampgdk::logprintf("Vector garbage collected!");

		lua_pushboolean(L, true);
		return 1;
	}

	argReader.GetErrorMessages();
	sampgdk::logprintf("Vector failed to destroyed");

	lua_pushboolean(L, false);
	return 1;
}

int CVector3Defs::tostring(lua_State *L)
{
	Vector3 *vector = nullptr;
	//Vector3 vector;

	CArgReader argReader(L);
	argReader.ReadUserData(vector);
	//argReader.ReadVector3D(vector);

	if (argReader.HasAnyError())
	{
		argReader.GetErrorMessages();
		return 0;
	}

	char buffer[128];
	sprintf(buffer, "Vector3(%.3f, %.3f, %.3f)", vector->x, vector->y, vector->z);

	lua_pushstring(L, buffer);

	return 1;
}