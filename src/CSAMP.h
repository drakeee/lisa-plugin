#pragma once

#include "Main.h"

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <memory>

//#include "Shared.h"

//#include "BaseController.h"
//#include "CMySQL.h"

//#include "CParamsParser.h"

class CSAMP
{

public:
	static CSAMP* getInstance();

	//Player pool functions
	inline void addPlayer(int playerid, std::unique_ptr<CPlayer> newPlayer) { this->playerPool.insert(std::pair<int, std::unique_ptr<CPlayer>>(playerid, std::move(newPlayer))); }
	inline CPlayer *getPlayerByID(int playerid) { return ((this->playerPool.find(playerid) != this->playerPool.end()) ? this->playerPool[playerid].get() : nullptr); }
	inline void removePlayer(int playerid) { this->playerPool.erase(playerid); }

	//Vehicle pool functions
	inline void addVehicle(int vehicleid, std::unique_ptr<CVehicle> newVehicle) { this->vehiclePool.insert(std::pair<int, std::unique_ptr<CVehicle>>(vehicleid, std::move(newVehicle))); }
	inline CVehicle *getVehicleByID(int vehicleid) { return ((this->vehiclePool.find(vehicleid) != this->vehiclePool.end()) ? this->vehiclePool[vehicleid].get() : nullptr); }
	inline void removeVehicle(int vehicleid) { this->vehiclePool.erase(vehicleid); }

	//Object pool functions
	inline void addObject(int objectid, std::unique_ptr<CObject> newObject) { this->objectPool.insert(std::pair<int, std::unique_ptr<CObject>>(objectid, std::move(newObject))); }
	inline CObject *getObjectByID(int objectid) { return ((this->objectPool.find(objectid) != this->objectPool.end()) ? this->objectPool[objectid].get() : nullptr); }
	inline void removeObject(int objectid) { this->objectPool.erase(objectid); }

	//PlayerObject pool functions
	inline void addPObject(int objectid, std::unique_ptr<CPObject> newObject) { this->playerObjectPool.insert(std::pair<int, std::unique_ptr<CPObject>>(objectid, std::move(newObject))); }
	inline CPObject *getPObjectByID(int objectid) { return ((this->playerObjectPool.find(objectid) != this->playerObjectPool.end()) ? this->playerObjectPool[objectid].get() : nullptr); }
	inline void removePObject(int objectid) { this->playerObjectPool.erase(objectid); }

	//Actor pool functions
	inline void addActor(int actorid, std::unique_ptr<CActor> newActor) { this->actorPool.insert(std::pair<int, std::unique_ptr<CActor>>(actorid, std::move(newActor))); }
	inline CActor *getActorByID(int actorid) { return ((this->actorPool.find(actorid) != this->actorPool.end()) ? this->actorPool[actorid].get() : nullptr); }
	inline void removeActor(int actorid) { this->objectPool.erase(actorid); }

	//void addCommand(std::string commandName, std::function<bool(CommandParameter commandParameter)> commandFunction);
	//void addCommand(std::vector<std::string> commandsName, std::function<bool(CommandParameter commandParameter)> commandFunction);

	//inline const std::map<std::string, std::function<bool(CommandParameter commandParameter)>> &getCommandMap2(void) { return this->commandPool; }
	//inline const std::map<std::string, std::string> &getCommandAliasMap(void) { return this->commandAlias; }

	//inline void addManager(BaseController* manager) { this->managerPool.push_back(manager); }
	//inline std::vector<BaseController*> getManagerPool(void) { return this->managerPool; }
	//inline void removeManager(BaseController* manager) { this->managerPool.erase(std::remove(this->managerPool.begin(), this->managerPool.end(), manager), this->managerPool.end()); }

	//inline CMySQL* getMySQL(void) { return this->m_pMySQL; }

private:
	CSAMP();
	~CSAMP();
	CSAMP(CSAMP const&) {};
	//CSAMP& operator=(CSAMP const&) { return &this; };
	static CSAMP* m_pInstance;

	//CMySQL* m_pMySQL = nullptr;

	//std::vector<BaseController*> managerPool;

	std::map<int, std::unique_ptr<CActor>> actorPool;
	std::map<int, std::unique_ptr<CPlayer>> playerPool;
	std::map<int, std::unique_ptr<CVehicle>> vehiclePool;
	std::map<int, std::unique_ptr<CObject>> objectPool;
	std::map<int, std::unique_ptr<CPObject>> playerObjectPool;

	//std::map<std::string, std::function<bool(CommandParameter commandParameter)>> commandPool;
	//std::map<std::string, std::string> commandAlias;
};

#define get_player_pointer(playerid) CSAMP::getInstance()->getPlayerByID(playerid)
#define get_vehicle_pointer(vehicleid) CSAMP::getInstance()->getVehicleByID(vehicleid)
#define get_actor_pointer(actorid) CSAMP::getInstance()->getActorByID(actorid)
#define get_object_pointer(objectid) CSAMP::getInstance()->getObjectByID(objectid)
#define get_player_object_pointer(objectid) CSAMP::getInstance()->getPObjectByID(objectid)

extern CSAMP* g_Core;