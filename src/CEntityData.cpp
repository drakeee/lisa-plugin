#include "Main.h"

#include <string>
#include <cstring>

CEntityData::CEntityData()
{
	this->dataType = EntityDataType::DATA_NAN;

	this->dataString = NULL;
}

CEntityData::CEntityData(const char *value)
{
	this->dataType = EntityDataType::DATA_STRING;

	this->dataString = std::unique_ptr<char[]>(new char[strlen(value) + 1]);
	strcpy(this->dataString.get(), value);
}

CEntityData::CEntityData(std::string value)
	: CEntityData(value.c_str())
{
	
}

CEntityData::CEntityData(float value)
{
	this->dataType = EntityDataType::DATA_FLOAT;

	this->dataString = NULL;

	this->dataFloat = value;
}

CEntityData::CEntityData(double value)
{
	this->dataType = EntityDataType::DATA_DOUBLE;

	this->dataString = NULL;

	this->dataDouble = value;
}

CEntityData::CEntityData(int value)
{
	this->dataType = EntityDataType::DATA_INTEGER;

	this->dataString = NULL;

	this->dataInteger = value;
}

CEntityData::CEntityData(bool value)
{
	this->dataType = EntityDataType::DATA_BOOLEAN;

	this->dataString = NULL;

	this->dataBool = value;
}

CEntityData::CEntityData(Vector3 &value)
{
	this->dataType = EntityDataType::DATA_VECTOR3;

	this->dataString = NULL;

	this->dataVector3 = value;
}

CEntityData::CEntityData(Vector4 &value)
{
	this->dataType = EntityDataType::DATA_VECTOR4;

	this->dataString = NULL;

	this->dataVector4 = value;
}

CEntityData::~CEntityData()
{

}