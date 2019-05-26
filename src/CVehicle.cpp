#include "CVehicle.h"
#include "CSAMP.h"

#ifdef SAMPGDK_AMALGAMATION
#include <sampgdk.h>
#else
#include <sampgdk/a_samp.h>
#include <sampgdk/a_vehicles.h>
#endif

CVehicle::CVehicle(int vehicleid)
	: vehicleid(vehicleid)
{
	entityType = ENTITY_VEHICLE;
}

//createVehicle
CVehicle::CVehicle(int modelid, float x, float y, float z, float rotation, int color1, int color2, int respawn_delay, bool addsiren, bool staticvehicle)
	: modelid(modelid),
	isVehicleStatic(staticvehicle)
{
	entityType = ENTITY_VEHICLE;

	this->vehicleid = (!staticvehicle ? CreateVehicle : AddStaticVehicleEx)(modelid, x, y, z, rotation, color1, color2, respawn_delay, addsiren);

	CSAMP::getInstance()->addVehicle(this->vehicleid, std::unique_ptr<CVehicle>(this));
}

//createVehicle with Vector3
CVehicle::CVehicle(int modelid, Vector3 &position, float rotation, int color1, int color2, int respawn_delay, bool addsiren, bool staticvehicle)
	: CVehicle(modelid, position.x, position.y, position.z, rotation, color1, color2, respawn_delay, addsiren, staticvehicle)
{

}

//createVehicle with Vector4
CVehicle::CVehicle(int modelid, Vector4 &position, int color1, int color2, int respawn_delay, bool addsiren, bool staticvehicle)
	: CVehicle(modelid, position.x, position.y, position.z, position.w, color1, color2, respawn_delay, addsiren, staticvehicle)
{

}

//addStaticVehicle
CVehicle::CVehicle(int modelid, float x, float y, float z, float rotation, int color1, int color2)
	: modelid(modelid),
	isVehicleStatic(true)
{
	this->vehicleid = AddStaticVehicle(modelid, x, y, z, rotation, color1, color2);
	this->isVehicleStatic = true;

	entityType = ENTITY_VEHICLE;

	CSAMP::getInstance()->addVehicle(this->vehicleid, std::unique_ptr<CVehicle>(this));
}

//addStaticVehicle with Vector3
CVehicle::CVehicle(int modelid, Vector3 &position, float rotation, int color1, int color2)
	: CVehicle(modelid, position.x, position.y, position.z, rotation, color1, color2)
{

}

//addStaticVehicle with Vector4
CVehicle::CVehicle(int modelid, Vector4 &position, int color1, int color2)
	: CVehicle(modelid, position.x, position.y, position.z, position.w, color1, color2)
{

}

CVehicle::~CVehicle()
{
	if(IsValidVehicle(this->vehicleid))
		DestroyVehicle(this->vehicleid);

	CSAMP::getInstance()->removeVehicle(vehicleid);
}