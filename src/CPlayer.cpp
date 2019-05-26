#include "Main.h"

CPlayer::CPlayer(int playerid)
	: playerid(playerid)
{
	CSAMP::getInstance()->addPlayer(playerid, std::unique_ptr<CPlayer>(this));
}

CPlayer::~CPlayer()
{
	CSAMP::getInstance()->removePlayer(this->playerid);
}

bool CPlayer::showDialog(int style, const char* caption, const char *info, const char* button1, const char *button2, PlayerDialog &&functionTemplate)
{
	ShowPlayerDialog(this->playerid, 1, style, caption, info, button1, button2);
	this->playerDialog.push(functionTemplate);
	//CSAMP::getInstance()->getDialogManager()->registerDialog(1, functionTemplate);

	return true;
}

bool CPlayer::reshowDialog(int style, const char* caption, const char *info, const char* button1, const char *button2)
{
	ShowPlayerDialog(this->playerid, 1, style, caption, info, button1, button2);
	this->playerDialog.push(this->playerDialog.front());

	return true;
}

bool CPlayer::sendMessage(int color, const char* message, ...)
{
	char szMessage[144 + 1];
	va_list testList;
	va_start(testList, message);
	vsprintf(szMessage, message, testList);
	va_end(testList);

	return SendClientMessage(this->playerid, color, szMessage);
}