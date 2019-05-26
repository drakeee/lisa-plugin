#include "CEntity.h"

CEntity::CEntity()
{

}

CEntity::~CEntity()
{
	for (auto const &tempItem : this->entityData)
		delete tempItem.second;
}

/*void CEntity::setData(const char* key, int value)
{

}

void CEntity::setData(const char* key, float value)
{

}

void CEntity::setData(const char* key, bool value)
{

}*/