#pragma once

#include <string>
#include <memory>

#define COL_MKEK		"{1E90FF}"
#define COL_SZURKE 		"{757167}"
#define COL_FEHER 		"{FFFFFF}"
#define COL_LRED		"{FF6347}"

#define COLOR_MKEK 		0x1E90FFFF
#define COLOR_SZURKE	0x757167FF
#define COLOR_LIGHTKEK 	0x1E90FFFF

class CPlayer;
class CParamsParser;

struct CommandParameter
{
	CPlayer *player;
	std::unique_ptr<CParamsParser> params;
};

struct DialogInput
{
	CPlayer* player;
	int response;
	int listitem;
	std::unique_ptr<char[]> inputtext;
};

struct Vector4;

struct Vector3
{
	float x;
	float y;
	float z;

	Vector3(const Vector4 &rhs);
	Vector3(void) : x(0.0f), y(0.0f), z(0.0f) {};
	Vector3(float x, float y, float z) : x(x), y(y), z(z) {};

	Vector3& operator=(const Vector4 & other);
};

struct Vector4
{
	float x;
	float y;
	float z;
	float w;

	Vector4(const Vector3 &rhs);
	Vector4(void) : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {};
	Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {};

	Vector4& operator=(const Vector3 & other);
};

namespace Utility
{
	std::string vector3_string(Vector3 &tempVector);
	std::string vector4_string(Vector4 &tempVector);
}