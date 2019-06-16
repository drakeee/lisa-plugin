#include "Main.h"

Vector3::Vector3(const Vector4 &rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;

	/* sampgdk::logprintf("Vector3(c1): %f | %f | %f", x, y, z); */
}

Vector3& Vector3::operator=(const Vector4 & other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	return *this;
}

Vector4::Vector4(const Vector3 &rhs)
{
	x = rhs.x;
	y = rhs.y;
	z = rhs.z;
	w = 0.0f;
}

Vector4& Vector4::operator=(const Vector3 & other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = 0.0f;
	return *this;
}

namespace Utility
{
	std::string vector3_string(Vector3 &tempVector)
	{
		char formatChar[128];
		sprintf(formatChar, "(%f, %f, %f)", tempVector.x, tempVector.y, tempVector.z);
		return std::string(formatChar);
	}

	std::string vector4_string(Vector4 &tempVector)
	{
		char formatChar[128];
		sprintf(formatChar, "(%f, %f, %f, %f)", tempVector.x, tempVector.y, tempVector.z, tempVector.w);
		return std::string(formatChar);
	}
}