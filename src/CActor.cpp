#include "Main.h"

CActor::CActor(int modelid, float x, float y, float z, float rotation)
{
	this->actorid = CreateActor(modelid, x, y, z, rotation);

	CSAMP::getInstance()->addActor(this->actorid, std::unique_ptr<CActor>(this));
}

CActor::~CActor()
{
	if (IsValidActor(this->actorid))
		DestroyActor(this->actorid);

	CSAMP::getInstance()->removeActor(this->actorid);
}