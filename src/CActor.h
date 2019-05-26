#pragma once

#include "CPlayer.h"
//#include "Shared.h"

#include <sampgdk.h>

class CActor : public CEntity
{
public:
	CActor(int modelid, float x, float y, float z, float rotation);
	~CActor();

	//inline int CreateActor(int modelid, float x, float y, float z, float rotation); - Constructor
	//inline bool DestroyActor(void); - Deconstructor

	inline bool isStreamedIn(int forplayerid) { return IsActorStreamedIn(this->actorid, forplayerid); }
	inline bool isStreamedIn(CPlayer *player) { return IsActorStreamedIn(this->actorid, player->getPlayerID()); }
	inline bool setVirtualWorld(int vworld) { return SetActorVirtualWorld(this->actorid, vworld); }
	inline int getVirtualWorld(void) { return GetActorVirtualWorld(this->actorid); }
	inline bool applyAnimation(const char * animlib, const char * animname, float fDelta, bool loop, bool lockx, bool locky, bool freeze, int time) { return ApplyActorAnimation(this->actorid, animlib, animname, fDelta, loop, lockx, locky, freeze, time); }
	inline bool clearAnimations(void) { return ClearActorAnimations(this->actorid); }
	inline bool setPos(float x, float y, float z) { return SetActorPos(this->actorid, x, y, z); }
	inline bool setPos(Vector3 &posVector) { return SetActorPos(this->actorid, posVector.x, posVector.y, posVector.z); }
	inline Vector3 getPos(float * x, float * y, float * z) { Vector3 tempVector; GetActorPos(this->actorid, &tempVector.x, &tempVector.y, &tempVector.z); return tempVector; }
	inline bool setFacingAngle(float angle) { return SetActorFacingAngle(this->actorid, angle); }
	inline float getFacingAngle(void) { float angle; GetActorFacingAngle(this->actorid, &angle); return angle; }
	inline bool setHealth(float health) { return SetActorHealth(this->actorid, health); }
	inline float getHealth(void) { float health; GetActorHealth(this->actorid, &health); return health; }
	inline bool setInvulnerable(bool invulnerable = true) { return SetActorInvulnerable(this->actorid, invulnerable); }
	inline bool isInvulnerable(void) { return IsActorInvulnerable(this->actorid); }
	inline bool isValid(void) { return IsValidActor(this->actorid); }

private:
	int actorid;
};