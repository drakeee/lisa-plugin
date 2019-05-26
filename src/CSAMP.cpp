#include "CSAMP.h"
#include "CObject.h"
#include "CVehicle.h"

//#include "CParamsParser.h"

#ifdef SAMPGDK_AMALGAMATION
	#include <sampgdk.h>
#else
	#include <sampgdk/a_samp.h>
	#include <sampgdk/a_vehicles.h>
#endif

CSAMP *g_Core = CSAMP::getInstance();
CSAMP* CSAMP::m_pInstance = NULL;
CSAMP* CSAMP::getInstance()
{
	if (!m_pInstance)
		m_pInstance = new CSAMP();

	return m_pInstance;
}

CSAMP::CSAMP()
{
	//if (!this->m_pMySQL)
	//	this->m_pMySQL = CMySQL::getInstance();
}

CSAMP::~CSAMP()
{
	//if (this->m_pMySQL)
	//	delete this->m_pMySQL;
}

/*void CSAMP::addCommand(std::string commandName, std::function<bool(CommandParameter params)> commandFunction)
{
	this->commandPool.insert(std::pair<std::string, std::function<bool(CommandParameter)>>("/" + commandName, commandFunction));
}*/

/*void CSAMP::addCommand(std::vector<std::string> commandsName, std::function<bool(CommandParameter commandParameter)> commandFunction)
{
	int index = 0;
	for (auto const& commandName : commandsName)
	{
		if (!index)
		{
			this->commandPool.insert(std::pair<std::string, std::function<bool(CommandParameter)>>("/" + commandName, commandFunction));
		}
		else
			this->commandAlias.insert(std::pair<std::string, std::string>("/" + commandName, "/" + commandsName.at(0)));

		index++;
	}
}*/