#include "CObject.h"
#include "CPlayer.h"
#include "CSAMP.h"

#ifdef SAMPGDK_AMALGAMATION
	#include <sampgdk.h>
#else
	#include <sampgdk/a_objects.h>
#endif

CObject::CObject(int modelid, float X, float Y, float Z, float rX, float rY, float rZ, float DrawDistance)
{
	this->objectid = CreateObject(modelid, X, Y, Z, rX, rY, rZ, DrawDistance);

	CSAMP::getInstance()->addObject(this->objectid, std::unique_ptr<CObject>(this));
}

CPObject::CPObject(CPlayer *player, int modelid, float X, float Y, float Z, float rX, float rY, float rZ, float DrawDistance)
	: player(player)
{
	this->objectid = CreatePlayerObject(player->getPlayerID(), modelid, X, Y, Z, rX, rY, rZ, DrawDistance);

	CSAMP::getInstance()->addPObject(this->objectid, std::unique_ptr<CPObject>(this));
}

CPObject::CPObject(int playerid, int modelid, float x, float y, float z, float rX, float rY, float rZ, float DrawDistance)
	: CPObject(get_player_pointer(playerid), modelid, x, y, z, rX, rY, rZ, DrawDistance)
{
	
}

CObject::~CObject()
{
	if (IsValidObject(this->objectid))
		DestroyObject(this->objectid);

	CSAMP::getInstance()->removeObject(this->objectid);
}

CPObject::~CPObject()
{
	if (IsValidPlayerObject(this->player->getPlayerID(), this->objectid))
		DestroyPlayerObject(this->player->getPlayerID(), this->objectid);

	CSAMP::getInstance()->removePObject(this->objectid);
}