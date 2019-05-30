#pragma once

#include "CEntity.h"
#include "Shared.h"

#include <sampgdk.h>

#include <vector>
#include <string>

typedef const std::vector<std::string> VehicleNameMap;
VehicleNameMap vehicleNames = {
	{ "Landstalker" },{ "Bravura" },{ "Buffalo" },{ "Linerunner" },{ "Perrenial" },{ "Sentinel" },{ "Dumper" },
	{ "Firetruck" },{ "Trashmaster" },{ "Stretch" },{ "Manana" },{ "Infernus" },{ "Voodoo" },{ "Pony" },{ "Mule" },
	{ "Cheetah" },{ "Ambulance" },{ "Leviathan" },{ "Moonbeam" },{ "Esperanto" },{ "Taxi" },{ "Washington" },
	{ "Bobcat" },{ "Mr Whoopee" },{ "BF Injection" },{ "Hunter" },{ "Premier" },{ "Enforcer" },{ "Securicar" },
	{ "Banshee" },{ "Predator" },{ "Bus" },{ "Rhino" },{ "Barracks" },{ "Hotknife" },{ "Trailer 1" },{ "Previon" },
	{ "Coach" },{ "Cabbie" },{ "Stallion" },{ "Rumpo" },{ "RC Bandit" },{ "Romero" },{ "Packer" },{ "Monster" },
	{ "Admiral" },{ "Squalo" },{ "Seasparrow" },{ "Pizzaboy" },{ "Tram" },{ "Trailer 2" },{ "Turismo" },
	{ "Speeder" },{ "Reefer" },{ "Tropic" },{ "Flatbed" },{ "Yankee" },{ "Caddy" },{ "Solair" },{ "Berkley's RC Van" },
	{ "Skimmer" },{ "PCJ-600" },{ "Faggio" },{ "Freeway" },{ "RC Baron" },{ "RC Raider" },{ "Glendale" },{ "Oceanic" },
	{ "Sanchez" },{ "Sparrow" },{ "Patriot" },{ "Quad" },{ "Coastguard" },{ "Dinghy" },{ "Hermes" },{ "Sabre" },
	{ "Rustler" },{ "ZR-350" },{ "Walton" },{ "Regina" },{ "Comet" },{ "BMX" },{ "Burrito" },{ "Camper" },{ "Marquis" },
	{ "Baggage" },{ "Dozer" },{ "Maverick" },{ "News Chopper" },{ "Rancher" },{ "FBI Rancher" },{ "Virgo" },{ "Greenwood" },
	{ "Jetmax" },{ "Hotring" },{ "Sandking" },{ "Blista Compact" },{ "Police Maverick" },{ "Boxville" },{ "Benson" },
	{ "Mesa" },{ "RC Goblin" },{ "Hotring Racer A" },{ "Hotring Racer B" },{ "Bloodring Banger" },{ "Rancher" },
	{ "Super GT" },{ "Elegant" },{ "Journey" },{ "Bike" },{ "Mountain Bike" },{ "Beagle" },{ "Cropdust" },{ "Stunt" },
	{ "Tanker" },{ "Roadtrain" },{ "Nebula" },{ "Majestic" },{ "Buccaneer" },{ "Shamal" },{ "Hydra" },{ "FCR-900" },
	{ "NRG-500" },{ "HPV1000" },{ "Cement Truck" },{ "Tow Truck" },{ "Fortune" },{ "Cadrona" },{ "FBI Truck" },
	{ "Willard" },{ "Forklift" },{ "Tractor" },{ "Combine" },{ "Feltzer" },{ "Remington" },{ "Slamvan" },
	{ "Blade" },{ "Freight" },{ "Streak" },{ "Vortex" },{ "Vincent" },{ "Bullet" },{ "Clover" },{ "Sadler" },
	{ "Firetruck LA" },{ "Hustler" },{ "Intruder" },{ "Primo" },{ "Cargobob" },{ "Tampa" },{ "Sunrise" },{ "Merit" },
	{ "Utility" },{ "Nevada" },{ "Yosemite" },{ "Windsor" },{ "Monster A" },{ "Monster B" },{ "Uranus" },{ "Jester" },
	{ "Sultan" },{ "Stratum" },{ "Elegy" },{ "Raindance" },{ "RC Tiger" },{ "Flash" },{ "Tahoma" },{ "Savanna" },
	{ "Bandito" },{ "Freight Flat" },{ "Streak Carriage" },{ "Kart" },{ "Mower" },{ "Duneride" },{ "Sweeper" },
	{ "Broadway" },{ "Tornado" },{ "AT-400" },{ "DFT-30" },{ "Huntley" },{ "Stafford" },{ "BF-400" },{ "Newsvan" },
	{ "Tug" },{ "Trailer 3" },{ "Emperor" },{ "Wayfarer" },{ "Euros" },{ "Hotdog" },{ "Club" },{ "Freight Carriage" },
	{ "Trailer 3" },{ "Andromada" },{ "Dodo" },{ "RC Cam" },{ "Launch" },{ "Police Car (LSPD)" },{ "Police Car (SFPD)" },
	{ "Police Car (LVPD)" },{ "Police Ranger" },{ "Picador" },{ "S.W.A.T. Van" },{ "Alpha" },{ "Phoenix" },{ "Glendale" },
	{ "Sadler" },{ "Luggage Trailer A" },{ "Luggage Trailer B" },{ "Stair Trailer" },{ "Boxville" },{ "Farm Plow" },
	{ "Utility Trailer" }
};

class CVehicle : public CEntity
{
public:
	CVehicle(int vehicleid);

	CVehicle(int modelid, float x, float y, float z, float rotation, int color1, int color2, int respawn_delay, bool addsiren = false, bool staticvehicle = false); //createVehicle
	CVehicle(int modelid, Vector3 &position, float rotation, int color1, int color2, int respawn_delay, bool addsiren = false, bool staticvehicle = false); //createVehicle
	CVehicle(int modelid, Vector4 &position, int color1, int color2, int respawn_delay, bool addsiren = false, bool staticvehicle = false); //createVehicle

	CVehicle(int modelid, float x, float y, float z, float rotation, int color1, int color2); //addStaticVehicle
	CVehicle(int modelid, Vector3 &position, float rotation, int color1, int color2); //addStaticVehicle
	CVehicle(int modelid, Vector4 &position, int color1, int color2); //addStaticVehicle
	//CVehicle(int modelid, float x, float y, float z, float rotation, int color1, int color2, int respawn_delay, int addsiren = 0); //addStaticVehicleEx
	~CVehicle();

	inline static std::string getVehicleName(int modelid) { return vehicleNames.at(modelid - 400); }

	inline std::string getName(void) { return getVehicleName(this->modelid); }
	inline bool isValid(int vehicleid) { return IsValidVehicle(this->vehicleid); } 
	inline float getDistanceFromPoint(float x, float y, float z) { return GetVehicleDistanceFromPoint(this->vehicleid, x, y, z); } 
	//inline int create(int vehicletype, float x, float y, float z, float rotation, int color1, int color2, int respawn_delay, bool addsiren = false) { return true; }
	//inline bool destroy(int vehicleid) { return DestroyVehicle(this->vehicleid); } 
	inline bool isStreamedIn(int forplayerid) { return IsVehicleStreamedIn(this->vehicleid, forplayerid); } 
	inline Vector4 getPos(void) { Vector4 tempVector; GetVehiclePos(this->vehicleid, &tempVector.x, &tempVector.y, &tempVector.z); GetVehicleZAngle(this->vehicleid, &tempVector.w); return tempVector; }
	inline bool setPos(float x, float y, float z) { return SetVehiclePos(this->vehicleid, x, y, z); } 
	inline bool setPos(float x, float y, float z, float rotation) { return SetVehiclePos(this->vehicleid, x, y, z); SetVehicleZAngle(this->vehicleid, rotation); }
	inline bool setPos(Vector3 &position) { return SetVehiclePos(this->vehicleid, position.x, position.y, position.z); }
	inline bool setPos(Vector4 &position) { return SetVehiclePos(this->vehicleid, position.x, position.y, position.z); SetVehicleZAngle(this->vehicleid, position.w); }
	inline float getZAngle(int vehicleid) { float z_angle; GetVehicleZAngle(this->vehicleid, &z_angle); return z_angle; }
	inline Vector4 getRotationQuat(int vehicleid) { Vector4 tempVector; GetVehicleRotationQuat(this->vehicleid, &tempVector.w, &tempVector.x, &tempVector.y, &tempVector.z); return tempVector; }
	inline bool setZAngle(float z_angle) { return SetVehicleZAngle(this->vehicleid, z_angle); } 
	inline bool setParamsForPlayer(int playerid, int objective, int doorslocked) { return SetVehicleParamsForPlayer(this->vehicleid, playerid, objective, doorslocked); } 
	//inline bool ManualEngineAndLights() { return true; } 
	inline bool setParamsEx(int engine, int lights, int alarm, int doors, int bonnet, int boot, int objective) { return SetVehicleParamsEx(this->vehicleid, engine, lights, alarm, doors, bonnet, boot, objective); } 
	inline bool getParamsEx(int * engine, int * lights, int * alarm, int * doors, int * bonnet, int * boot, int * objective) { return GetVehicleParamsEx(this->vehicleid, engine, lights, alarm, doors, bonnet, boot, objective); } 
	inline int getParamsSirenState(int vehicleid) { return GetVehicleParamsSirenState(this->vehicleid); } 
	inline bool setParamsCarDoors(int driver, int passenger, int backleft, int backright) { return SetVehicleParamsCarDoors(this->vehicleid, driver, passenger, backleft, backright); } 
	inline bool getParamsCarDoors(int * driver, int * passenger, int * backleft, int * backright) { return GetVehicleParamsCarDoors(this->vehicleid, driver, passenger, backleft, backright); } 
	inline bool setParamsCarWindows(int driver, int passenger, int backleft, int backright) { return SetVehicleParamsCarWindows(this->vehicleid, driver, passenger, backleft, backright); } 
	inline bool getParamsCarWindows(int * driver, int * passenger, int * backleft, int * backright) { return GetVehicleParamsCarWindows(this->vehicleid, driver, passenger, backleft, backright); }
	inline bool setToRespawn(int vehicleid) { return SetVehicleToRespawn(this->vehicleid); } 
	inline bool linkToInterior(int interiorid) { return LinkVehicleToInterior(this->vehicleid, interiorid); } 
	inline bool addComponent(int componentid) { return AddVehicleComponent(this->vehicleid, componentid); } 
	inline bool removeComponent(int componentid) { return RemoveVehicleComponent(this->vehicleid, componentid); } 
	inline bool changeColor(int color1, int color2) { return ChangeVehicleColor(this->vehicleid, color1, color2); } 
	inline bool ChangePaintjob(int paintjobid) { return ChangeVehiclePaintjob(this->vehicleid, paintjobid); } 
	inline bool setHealth(float health) { return SetVehicleHealth(this->vehicleid, health); } 
	inline float getHealth(int vehicleid) { float health; GetVehicleHealth(this->vehicleid, &health); return health; }
	inline bool attachTrailer(int trailerid, int vehicleid) { return AttachTrailerToVehicle(trailerid, this->vehicleid); } 
	inline bool detachTrailer(int vehicleid) { return DetachTrailerFromVehicle(this->vehicleid); } 
	inline bool isTrailerAttached(int vehicleid) { return IsTrailerAttachedToVehicle(this->vehicleid); } 
	inline int getTrailer(int vehicleid) { return GetVehicleTrailer(this->vehicleid); } 
	inline bool setNumberPlate(const char * numberplate) { return SetVehicleNumberPlate(this->vehicleid, numberplate); } 
	inline int getModel(int vehicleid) { return GetVehicleModel(this->vehicleid); } 
	inline int getComponentInSlot(int slot) { return GetVehicleComponentInSlot(this->vehicleid, slot); } 
	inline int getComponentType(int component) { return GetVehicleComponentType(component); } 
	inline bool repair(int vehicleid) { return RepairVehicle(this->vehicleid); } 
	inline Vector3 getVelocity(float * X, float * Y, float * Z) { Vector3 tempVector; GetVehicleVelocity(this->vehicleid, &tempVector.x, &tempVector.y, &tempVector.z); return tempVector; }
	inline bool setVelocity(float X, float Y, float Z) { return SetVehicleVelocity(this->vehicleid, X, Y, Z); } 
	inline bool setAngularVelocity(float X, float Y, float Z) { return SetVehicleAngularVelocity(this->vehicleid, X, Y, Z); } 
	inline bool getDamageStatus(int * panels, int * doors, int * lights, int * tires) { return GetVehicleDamageStatus(this->vehicleid, panels, doors, lights, tires); } 
	inline bool updateDamageStatus(int panels, int doors, int lights, int tires) { return UpdateVehicleDamageStatus(this->vehicleid, panels, doors, lights, tires); } 
	inline bool setVirtualWorld(int worldid) { return SetVehicleVirtualWorld(this->vehicleid, worldid); } 
	inline int getVirtualWorld(int vehicleid) { return GetVehicleVirtualWorld(this->vehicleid); } 
	inline Vector3 getModelInfo(int model, int infotype, float * X, float * Y, float * Z) { Vector3 tempVector; GetVehicleModelInfo(model, infotype, &tempVector.x, &tempVector.y, &tempVector.z); return tempVector; }

	inline int getVehicleID(void) { return this->vehicleid; }
	inline bool isStatic(void) { return this->isVehicleStatic; }

private:
	int vehicleid;
	int modelid;
	bool isVehicleStatic = false;
};