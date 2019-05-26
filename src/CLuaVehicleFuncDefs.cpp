#include "CLuaVehicleFuncDefs.h"
#include "CVehicle.h"

#include "CArgReader.h"

const char* haha = nullptr;

int CVehicleFuncDefs::createVehicle(lua_State *L)
{
	int modelid;
	float x, y, z;
	float rotation;
	int color1, color2;

	CArgReader argReader(L);
	argReader.ReadNumber(modelid);
	argReader.ReadNumber(x);
	argReader.ReadNumber(y);
	argReader.ReadNumber(z);
	argReader.ReadNumber(rotation);
	argReader.ReadNumber(color1);
	argReader.ReadNumber(color2);

	if (argReader.HasAnyError())
	{
		argReader.GetErrorMessages();
		return 0;
	}

	CVehicle *vehicle = new CVehicle(modelid, x, y, z, rotation, color1, color2, -1);
	lua_userdata(L, vehicle->getEntityTypeName(), vehicle);
	//CVehicle **vehicle = reinterpret_cast<CVehicle **>(lua_newuserdata(L, sizeof(CVehicle*)));

	//CVehicle *vehicle = new CVehicle(modelid, x, y, z, rotation, color1, color2);
	sampgdk::logprintf("vehicle data: %d | %f %f %f | %f | %d %d", modelid, x, y, z, rotation, color1, color2);

	return 1;
}

int CVehicleFuncDefs::setVehiclePosition(lua_State *L)
{
	CVehicle *vehicle;
	float x, y, z;

	CArgReader argReader(L);
	argReader.ReadUserData(vehicle);
	argReader.ReadNumber(x);
	argReader.ReadNumber(y);
	argReader.ReadNumber(z);

	if (argReader.HasAnyError())
	{
		argReader.GetErrorMessages();
		return 0;
	}

	lua_pushboolean(L, 1);

	//vehicle->setPos(x, y, z);

	lua_stacktrace(L, "setVehiclePosition");
	return 1;
}

int CVehicleFuncDefs::getVehiclePosition(lua_State *L)
{

	CVehicle *vehicle;

	CArgReader argReader(L);
	argReader.ReadUserData(vehicle);

	if (argReader.HasAnyError())
	{
		argReader.GetErrorMessages();
		return 0;
	}

	Vector4 vehiclePosition = vehicle->getPos();
	//sampgdk::InvokeNativeArray()
	int vehicleid = vehicle->getVehicleID();
	float x, y, z;
	void *haha[4];
	haha[0] = &vehicleid;
	haha[1] = &x;
	haha[2] = &y;
	haha[3] = &z;
	void *somepointer = &haha;
	AMX_NATIVE someNativeFunction = sampgdk::FindNative("getVehiclePos");
	sampgdk::logprintf("someNativeFunction: %d", someNativeFunction);
	sampgdk::InvokeNativeArray(someNativeFunction, "dRRR", haha);

	sampgdk::logprintf("Haha: %f %f %f", x, y, z);

	lua_pushnumber(L, static_cast<lua_Number>(vehiclePosition.x));
	lua_pushnumber(L, static_cast<lua_Number>(vehiclePosition.y));
	lua_pushnumber(L, static_cast<lua_Number>(vehiclePosition.z));
	lua_pushnumber(L, static_cast<lua_Number>(vehiclePosition.w));

	lua_stacktrace(L, "getVehiclePosition");
	return 4;
}