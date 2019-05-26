#pragma once

#include "Shared.h"

#include <memory>

#include <sampgdk.h>

enum class EntityDataType
{
	DATA_NAN = 0,
	DATA_STRING = 1,
	DATA_STD_STRING,
	DATA_FLOAT,
	DATA_DOUBLE,
	DATA_INTEGER,
	DATA_BOOLEAN,
	DATA_VECTOR3,
	DATA_VECTOR4,
};

class CEntityData
{
public:
	CEntityData();
	CEntityData(const char *value);
	CEntityData(std::string value);
	CEntityData(float value);
	CEntityData(double value);
	CEntityData(int value);
	CEntityData(bool value);
	CEntityData(Vector3 &value);
	CEntityData(Vector4 &value);
	~CEntityData();

	inline EntityDataType getDataType(void) { return this->dataType; }
	inline const char* getDataString(void) { return this->dataString.get(); }
	inline std::string getDataStdString(void) { return std::string(this->dataString.get()); }
	inline float getDataFloat(void) { return this->dataFloat; }
	inline double getDataDouble(void) { return this->dataDouble; }
	inline int getDataInteger(void) { return this->dataInteger; }
	inline bool getDataBool(void) { return this->dataBool; }
	inline Vector3 getDataVector3(void) { return this->dataVector3; }
	inline Vector4 getDataVector4(void) { return this->dataVector4; }

private:
	EntityDataType dataType;

	std::unique_ptr<char[]> dataString;
	float dataFloat;
	double dataDouble;
	int dataInteger;
	bool dataBool;
	Vector3 dataVector3;
	Vector4 dataVector4;
};