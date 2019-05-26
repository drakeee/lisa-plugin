#pragma once

#include "CEntityData.h"

#include <map>

class CEntity
{
public:
	enum ENTITY_TYPE
	{
		ENTITY_NONE,
		ENTITY_VEHICLE,
		ENTITY_OBJECT,
		ENTITY_ACTOR,
		ENTITY_PLAYER
	};

	CEntity();
	~CEntity();

	inline bool isKeyExists(const char *key)
	{
		return (this->entityData.find(key) != this->entityData.end());
	}

	inline bool removeData(const char *key)
	{
		//Search for the given key in the map
		auto iterator = this->entityData.find(key);

		//Check if key is exists in the map
		if (iterator != this->entityData.end())
		{
			//Safely remove any remaining array from the memory
			delete this->entityData[key];

			//Erase the data from the map
			this->entityData.erase(key);

			//Return true if the key successfully deleted
			return true;
		}

		//Return false if the key not existed in the map
		return false;
	}

	template <typename dataType>
	void setData(const char *key, dataType value)
	{
		//Check if key exists
		if (this->isKeyExists(key))
		{
			//If exists call the destructor first
			delete this->entityData[key];
		}

		//Then create a new data
		CEntityData *tempData = new CEntityData(value);
		this->entityData[key] = tempData;
	}

	template <typename T, typename std::enable_if <std::is_same<T, const char *>::value>::type* = nullptr>
	T getData(const char *key)
	{
		if (this->isKeyExists(key))
			return this->entityData[key]->getDataString();

		return NULL;
	}

	template <typename T, typename std::enable_if <std::is_same<T, std::string>::value>::type* = nullptr>
	T getData(const char *key)
	{
		if (this->isKeyExists(key))
			return this->entityData[key]->getDataStdString();

		return NULL;
	}

	template <typename T, typename std::enable_if <std::is_same<T, float>::value>::type* = nullptr>
	T getData(const char *key)
	{
		if (this->isKeyExists(key))
			return this->entityData[key]->getDataFloat();

		return NULL;
	}

	template <typename T, typename std::enable_if <std::is_same<T, double>::value>::type* = nullptr>
	T getData(const char *key)
	{
		if (this->isKeyExists(key))
			return this->entityData[key]->getDataDouble();

		return NULL;
	}

	template <typename T, typename std::enable_if <std::is_same<T, int>::value>::type* = nullptr>
	T getData(const char *key)
	{
		if (this->isKeyExists(key))
			return this->entityData[key]->getDataInteger();

		return NULL;
	}

	template <typename T, typename std::enable_if <std::is_same<T, bool>::value>::type* = nullptr>
	T getData(const char *key)
	{
		if (this->isKeyExists(key))
			return this->entityData[key]->getDataBool();

		return NULL;
	}

	template <typename T, typename std::enable_if <std::is_same<T, Vector3>::value>::type* = nullptr>
	T getData(const char *key)
	{
		if (this->isKeyExists(key))
			return this->entityData[key]->getDataVector3();

		return Vector3();
	}

	template <typename T, typename std::enable_if <std::is_same<T, Vector4>::value>::type* = nullptr>
	T getData(const char *key)
	{
		if (this->isKeyExists(key))
			return this->entityData[key]->getDataVector4();

		return Vector4();
	}

	inline int getEntityType(void)
	{
		return this->entityType;
	}

	inline const char* getEntityTypeName(void)
	{
		switch (this->getEntityType())
		{
		case CEntity::ENTITY_NONE:
			return "None";
		case CEntity::ENTITY_VEHICLE:
			return "Vehicle";
		case CEntity::ENTITY_OBJECT:
			return "Object";
		case CEntity::ENTITY_ACTOR:
			return "Actor";
		case CEntity::ENTITY_PLAYER:
			return "Player";
		}

		return "Element";
		/*enum ENTITY_TYPE
		{
		ENTITY_NONE,
		ENTITY_VEHICLE,
		ENTITY_OBJECT,
		ENTITY_ACTOR,
		ENTITY_PLAYER
		};*/
	}

private:
	std::map<std::string, CEntityData *> entityData;

protected:
	int entityType;
};