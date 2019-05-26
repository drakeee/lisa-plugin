#pragma once

#include "LuaDefs.h"

#include <vector>

class CArgReader
{
public:
	CArgReader(lua_State *L)
	{
		m_luaVM = L;
		m_stackIndex = 1;
		m_errorOccured = false;
	}

	~CArgReader()
	{

	}

	template <typename T>
	void ReadNumber(T &number, T defaultValue = 0)
	{
		//check if argument is number
		int argType = lua_type(m_luaVM, m_stackIndex);
		if (argType == LUA_TNUMBER || argType == LUA_TSTRING)
		{
			if (!lua_isnumber(m_luaVM, m_stackIndex))
				return;

			//read if it is
			lua_Number readNumber = lua_tonumber(m_luaVM, m_stackIndex);

			//fill the variable and increase argindex
			number = static_cast<T>(readNumber);
			m_stackIndex++;

			return;
		}

		AddErrorMessage("number");

		number = defaultValue;
		m_stackIndex++;
	}

	void ReadString(std::string &stringValue, const char* defaultValue = NULL)
	{
		//check if argument is string
		int argType = lua_type(m_luaVM, m_stackIndex);
		if (argType == LUA_TSTRING)
		{
			//check if it is indeed a string
			if (!lua_isstring(m_luaVM, m_stackIndex))
				return;

			//read if it is
			stringValue.append(luaL_checkstring(m_luaVM, m_stackIndex));

			//fill the variable and increase argindex
			m_stackIndex++;
			return;
		}

		AddErrorMessage("string");

		stringValue.append(defaultValue);
		m_stackIndex++;
	}

	template <typename T>
	void ReadUserData(T* &userdata)
	{
		//check if argument is number or string
		int argType = lua_type(m_luaVM, m_stackIndex);

		if (argType == LUA_TUSERDATA)
		{
			if (!lua_isuserdata(m_luaVM, m_stackIndex))
				return;

			//T *tempUserData = reinterpret_cast<T*>(lua_touserdata(m_luaVM, m_stackIndex));

			userdata = reinterpret_cast<T*>(*((void**)lua_touserdata(m_luaVM, m_stackIndex)));
			m_stackIndex++;

			return;
		}

		AddErrorMessage("userdata");

		userdata = nullptr;
		m_stackIndex++;

		return;
	}

	void AddMessage(const std::string &errorMessage)
	{
		m_errorMessages.push_back(errorMessage);
	}

	void AddErrorMessage(const char* expectedType)
	{
		char buffer[128];

		lua_Debug debugInfo;
		lua_getdebuginfo(m_luaVM, debugInfo);

		int argType = lua_type(m_luaVM, m_stackIndex);
		//sprintf_s(buffer, "Bad Argument (%s) Expected argument at index %d: '%s', got '%s' instead.", lua_tostring(m_luaVM, lua_upvalueindex(1)), m_stackIndex, expectedType, lua_typename(m_luaVM, argType));
		sprintf_s(buffer, "Bad Argument (%s:%d) Expected argument at index %d: '%s', got '%s' instead.", debugInfo.name, debugInfo.currentline, m_stackIndex, expectedType, lua_typename(m_luaVM, argType));
		//sampgdk::logprintf("Bad Argument (%s:%d) Expected argument at index %d: '%s', got '%s' instead.", debugInfo.name, debugInfo.currentline, m_stackIndex, expectedType, lua_typename(m_luaVM, argType));

		AddMessage(buffer);

		m_errorOccured = true;
	}

	bool HasAnyError(void)
	{
		return m_errorOccured;
	}

	void GetErrorMessages(void)
	{
		for (auto &message : m_errorMessages)
		{
			sampgdk::logprintf(message.c_str());
		}
	}

private:
	lua_State *m_luaVM;

	int m_stackIndex;
	bool m_errorOccured;

	std::vector<std::string> m_errorMessages;
};