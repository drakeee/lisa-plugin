#pragma once

#include "CEntity.h"
#include "Shared.h"

#ifdef SAMPGDK_AMALGAMATION
	#include <sampgdk.h>
#else
	#include <sampgdk/a_players.h>
	#include <sampgdk/a_samp.h>
#endif

#include <string>
#include <functional>
#include <queue>


class CPlayer : public CEntity
{
public:
	typedef std::function<void(DialogInput dialogInput)> PlayerDialog;

	CPlayer(int playerid);
	~CPlayer();

	//Name related functions
	inline int setName(std::string newName) { return SetPlayerName(this->playerid, newName.c_str()); }

	inline bool setSpawnInfo(int team, int skin, float x, float y, float z, float rotation, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo) { return SetSpawnInfo(this->playerid, team, skin, x, y, z, rotation, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo); }
	inline bool spawn(void) { return SpawnPlayer(this->playerid); }
	inline bool setPos(float x, float y, float z) { return SetPlayerPos(this->playerid, x, y, z); }
	inline bool setPosFindZ(float x, float y, float z) { return SetPlayerPosFindZ(this->playerid, x, y, z); }
	inline Vector3 getPos(void) { Vector3 tempVector; GetPlayerPos(this->playerid, &tempVector.x, &tempVector.y, &tempVector.z); return tempVector; }
	inline bool setFacingAngle(float angle) { return SetPlayerFacingAngle(this->playerid, angle); }
	inline float getFacingAngle(void) { float angle; GetPlayerFacingAngle(this->playerid, &angle); return angle; }
	inline bool isInRangeOfPoint(float range, float x, float y, float z) { return IsPlayerInRangeOfPoint(this->playerid, range, x, y, z); }
	inline float getDistanceFromPoint(float x, float y, float z) { return GetPlayerDistanceFromPoint(this->playerid, x, y, z); }
	inline bool isStreamedIn(int forplayerid) { return IsPlayerStreamedIn(this->playerid, forplayerid); }
	inline bool setInterior(int interiorid) { return SetPlayerInterior(this->playerid, interiorid); }
	inline int getInterior(void) { return GetPlayerInterior(this->playerid); } 
	inline bool setHealth(float health) { return SetPlayerHealth(this->playerid, health); }
	inline float getHealth(void) { float health; GetPlayerHealth(this->playerid, &health); return health; }
	inline bool setArmour(float armour) { return SetPlayerArmour(this->playerid, armour); }
	inline float getArmour(void) { float armour; GetPlayerArmour(this->playerid, &armour); return armour; }
	inline bool setAmmo(int weaponid, int ammo) { return SetPlayerAmmo(this->playerid, weaponid, ammo); }
	inline int getAmmo(void) { return GetPlayerAmmo(this->playerid); }
	inline int getWeaponState(void) { return GetPlayerWeaponState(this->playerid); } 
	inline int getTarget(void) { return GetPlayerTargetPlayer(this->playerid); }
	inline int getTargetActor(void) { return GetPlayerTargetActor(this->playerid); }
	inline bool setTeam(int teamid) { return SetPlayerTeam(this->playerid, teamid); }
	inline int getTeam(void) { return GetPlayerTeam(this->playerid); }
	inline bool setScore(int score) { return SetPlayerScore(this->playerid, score); }
	inline int getScore(void) { return GetPlayerScore(this->playerid); }
	inline int getDrunkLevel(void) { return GetPlayerDrunkLevel(this->playerid); }
	inline bool setDrunkLevel(int level) { return SetPlayerDrunkLevel(this->playerid, level); } 
	inline bool setColor(int color) { return SetPlayerColor(this->playerid, color); }
	inline int getColor(void) { return GetPlayerColor(this->playerid); }
	inline bool setSkin(int skinid) { return SetPlayerSkin(this->playerid, skinid); }
	inline int getSkin(void) { return GetPlayerSkin(this->playerid); }
	inline bool giveWeapon(int weaponid, int ammo) { return GivePlayerWeapon(this->playerid, weaponid, ammo); }
	inline bool resetWeapons(void) { return ResetPlayerWeapons(this->playerid); }
	inline bool setArmedWeapon(int weaponid) { return SetPlayerArmedWeapon(this->playerid, weaponid); }
	inline bool getWeaponData(int slot, int *weapon, int *ammo) { return GetPlayerWeaponData(this->playerid, slot, weapon, ammo); }
	inline bool giveMoney(int money) { return GivePlayerMoney(this->playerid, money); }
	inline bool resetMoney(void) { return ResetPlayerMoney(this->playerid); } 
	inline int setName(const char * name) { return SetPlayerName(this->playerid, name); }
	inline int getMoney(void) { return GetPlayerMoney(this->playerid); }
	inline int getState(void) { return GetPlayerState(this->playerid); }
	inline std::string getIp(void) { char playerIP[16 + 1]; GetPlayerIp(this->playerid, playerIP, sizeof(playerIP)); return std::string(playerIP); }
	inline int getPing(void) { return GetPlayerPing(this->playerid); }
	inline int getWeapon(void) { return GetPlayerWeapon(this->playerid); } 
	inline bool getKeys(int * keys, int * updown, int * leftright) { return GetPlayerKeys(this->playerid, keys, updown, leftright); } 
	inline std::string getName(void) { char playerName[32 + 1]; GetPlayerName(this->playerid, playerName, sizeof(playerName)); return std::string(playerName); }
	inline bool setTime(int hour, int minute) { return SetPlayerTime(this->playerid, hour, minute); } 
	inline bool getTime(int * hour, int * minute) { return GetPlayerTime(this->playerid, hour, minute); } 
	inline bool toggleClock(bool toggle) { return TogglePlayerClock(this->playerid, toggle); } 
	inline bool setWeather(int weather) { return SetPlayerWeather(this->playerid, weather); } 
	inline bool forceClassSelection(void) { return ForceClassSelection(this->playerid); } 
	inline bool setWantedLevel(int level) { return SetPlayerWantedLevel(this->playerid, level); } 
	inline int getWantedLevel(void) { return GetPlayerWantedLevel(this->playerid); } 
	inline bool setFightingStyle(int style) { return SetPlayerFightingStyle(this->playerid, style); } 
	inline int getFightingStyle(void) { return GetPlayerFightingStyle(this->playerid); } 
	inline bool setVelocity(float x, float y, float z) { return SetPlayerVelocity(this->playerid, x, y, z); } 
	inline Vector3 getVelocity(void) { Vector3 tempVector; GetPlayerVelocity(this->playerid, &tempVector.x, &tempVector.y, &tempVector.z); return tempVector; }
	inline bool playCrimeReport(int suspectid, int crime) { return PlayCrimeReportForPlayer(this->playerid, suspectid, crime); } 
	inline bool playAudioStream(const char * url, float posX = 0.0, float posY = 0.0, float posZ = 0.0, float distance = 50.0, bool usepos = false) { return PlayAudioStreamForPlayer(this->playerid, url, posX, posY, posZ, distance, usepos); } 
	inline bool stopAudioStream(void) { return StopAudioStreamForPlayer(this->playerid); } 
	inline bool setShopName(const char * shopname) { return SetPlayerShopName(this->playerid, shopname); } 
	inline bool setSkillLevel(int skill, int level) { return SetPlayerSkillLevel(this->playerid, skill, level); } 
	inline int getSurfingVehicleID(void) { return GetPlayerSurfingVehicleID(this->playerid); } 
	inline int getSurfingObjectID(void) { return GetPlayerSurfingObjectID(this->playerid); } 
	inline bool removeBuilding(int modelid, float fX, float fY, float fZ, float fRadius) { return RemoveBuildingForPlayer(this->playerid, modelid, fX, fY, fZ, fRadius); } 
	inline bool getLastShotVectors(float * fOriginX, float * fOriginY, float * fOriginZ, float * fHitPosX, float * fHitPosY, float * fHitPosZ) { return GetPlayerLastShotVectors(this->playerid, fOriginX, fOriginY, fOriginZ, fHitPosX, fHitPosY, fHitPosZ); }
	inline bool setAttachedObject(int index, int modelid, int bone, float fOffsetX = 0.0, float fOffsetY = 0.0, float fOffsetZ = 0.0, float fRotX = 0.0, float fRotY = 0.0, float fRotZ = 0.0, float fScaleX = 1.0, float fScaleY = 1.0, float fScaleZ = 1.0, int materialcolor1 = 0, int materialcolor2 = 0) { return SetPlayerAttachedObject(this->playerid, index, modelid, bone, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ, materialcolor1, materialcolor2); } 
	inline bool removeAttachedObject(int index) { return RemovePlayerAttachedObject(this->playerid, index); } 
	inline bool isAttachedObjectSlotUsed(int index) { return IsPlayerAttachedObjectSlotUsed(this->playerid, index); } 
	inline bool editAttachedObject(int index) { return EditAttachedObject(this->playerid, index); } 
	inline int createTextDraw(float x, float y, const char * text) { return CreatePlayerTextDraw(this->playerid, x, y, text); } 
	inline bool textDrawDestroy(int text) { return PlayerTextDrawDestroy(this->playerid, text); } 
	inline bool textDrawLetterSize(int text, float x, float y) { return PlayerTextDrawLetterSize(this->playerid, text, x, y); } 
	inline bool textDrawTextSize(int text, float x, float y) { return PlayerTextDrawTextSize(this->playerid, text, x, y); } 
	inline bool textDrawAlignment(int text, int alignment) { return PlayerTextDrawAlignment(this->playerid, text, alignment); } 
	inline bool textDrawColor(int text, int color) { return PlayerTextDrawColor(this->playerid, text, color); } 
	inline bool textDrawUseBox(int text, bool use) { return PlayerTextDrawUseBox(this->playerid, text, use); } 
	inline bool textDrawBoxColor(int text, int color) { return PlayerTextDrawBoxColor(this->playerid, text, color); } 
	inline bool textDrawsetShadow(int text, int size) { return PlayerTextDrawSetShadow(this->playerid, text, size); } 
	inline bool textDrawsetOutline(int text, int size) { return PlayerTextDrawSetOutline(this->playerid, text, size); } 
	inline bool textDrawBackgroundColor(int text, int color) { return PlayerTextDrawBackgroundColor(this->playerid, text, color); } 
	inline bool textDrawFont(int text, int font) { return PlayerTextDrawFont(this->playerid, text, font); } 
	inline bool textDrawSetProportional(int text, bool set) { return PlayerTextDrawSetProportional(this->playerid, text, set); } 
	inline bool textDrawSetSelectable(int text, bool set) { return PlayerTextDrawSetSelectable(this->playerid, text, set); } 
	inline bool textDrawShow(int text) { return PlayerTextDrawShow(this->playerid, text); } 
	inline bool textDrawHide(int text) { return PlayerTextDrawHide(this->playerid, text); } 
	inline bool textDrawSetString(int text, const char * string) { return PlayerTextDrawSetString(this->playerid, text, string); } 
	inline bool textDrawSetPreviewModel(int text, int modelindex) { return PlayerTextDrawSetPreviewModel(this->playerid, text, modelindex); } 
	inline bool textDrawSetPreviewRot(int text, float fRotX, float fRotY, float fRotZ, float fZoom = 1.0) { return PlayerTextDrawSetPreviewRot(this->playerid, text, fRotX, fRotY, fRotZ, fZoom); } 
	inline bool textDrawSetPreviewVehCol(int text, int color1, int color2) { return PlayerTextDrawSetPreviewVehCol(this->playerid, text, color1, color2); } 
	inline bool setPVarInt(const char * varname, int value) { return SetPVarInt(this->playerid, varname, value); } 
	inline int getPVarInt(const char * varname) { return GetPVarInt(this->playerid, varname); } 
	inline bool setPVarString(const char * varname, const char * value) { return SetPVarString(this->playerid, varname, value); } 
	inline std::string getPVarString(const char * varname) { char tempString[128]; GetPVarString(this->playerid, varname, tempString, sizeof(tempString)); return std::string(tempString); }
	inline bool setPVarFloat(const char * varname, float value) { return SetPVarFloat(this->playerid, varname, value); } 
	inline float getPVarFloat(const char * varname) { return GetPVarFloat(this->playerid, varname); } 
	inline bool deletePVar(const char * varname) { return DeletePVar(this->playerid, varname); } 
	inline int getPVarsUpperIndex(void) { return GetPVarsUpperIndex(this->playerid); } 
	inline std::string getPVarNameAtIndex(int index, char * varname, int size) { char tempString[128]; GetPVarNameAtIndex(this->playerid, index, tempString, sizeof(tempString)); return std::string(tempString); }
	inline int getPVarType(const char * varname) { return GetPVarType(this->playerid, varname); } 
	inline bool setChatBubble(const char * text, int color, float drawdistance, int expiretime) { return SetPlayerChatBubble(this->playerid, text, color, drawdistance, expiretime); } 
	inline bool putInVehicle(int vehicleid, int seatid) { return PutPlayerInVehicle(this->playerid, vehicleid, seatid); } 
	inline int getVehicleID(void) { return GetPlayerVehicleID(this->playerid); } 
	inline int getVehicleSeat(void) { return GetPlayerVehicleSeat(this->playerid); } 
	inline bool removeFromVehicle(void) { return RemovePlayerFromVehicle(this->playerid); } 
	inline bool toggleControllable(bool toggle) { return TogglePlayerControllable(this->playerid, toggle); } 
	inline bool playSound(int soundid, float x, float y, float z) { return PlayerPlaySound(this->playerid, soundid, x, y, z); } 
	inline bool applyAnimation(const char * animlib, const char * animname, float fDelta, bool loop, bool lockx, bool locky, bool freeze, int time, bool forcesync = false) { return ApplyAnimation(this->playerid, animlib, animname, fDelta, loop, lockx, locky, freeze, time, forcesync); } 
	inline bool clearAnimations(bool forcesync = false) { return ClearAnimations(this->playerid, forcesync); } 
	inline int getAnimationIndex(void) { return GetPlayerAnimationIndex(this->playerid); } 
	inline bool getAnimationName(int index, char * animlib, int animlib_size, char * animname, int animname_size) { return GetAnimationName(index, animlib, animlib_size, animname, animname_size); } 
	inline int getSpecialAction(void) { return GetPlayerSpecialAction(this->playerid); } 
	inline bool setSpecialAction(int actionid) { return SetPlayerSpecialAction(this->playerid, actionid); } 
	inline bool disableRemoteVehicleCollisions(bool disable) { return DisableRemoteVehicleCollisions(this->playerid, disable); } 
	inline bool setCheckpoint(float x, float y, float z, float size) { return SetPlayerCheckpoint(this->playerid, x, y, z, size); } 
	inline bool disableCheckpoint(void) { return DisablePlayerCheckpoint(this->playerid); }
	inline bool setRaceCheckpoint(int type, float x, float y, float z, float nextx, float nexty, float nextz, float size) { return SetPlayerRaceCheckpoint(this->playerid, type, x, y, z, nextx, nexty, nextz, size); } 
	inline bool disableRaceCheckpoint(void) { return DisablePlayerRaceCheckpoint(this->playerid); } 
	inline bool setWorldBounds(float x_max, float x_min, float y_max, float y_min) { return SetPlayerWorldBounds(this->playerid, x_max, x_min, y_max, y_min); } 
	inline bool setMarkerForPlayer(int showplayerid, int color) { return SetPlayerMarkerForPlayer(this->playerid, showplayerid, color); } 
	inline bool showNameTagForPlayer(int showplayerid, bool show) { return ShowPlayerNameTagForPlayer(this->playerid, showplayerid, show); } 
	inline bool setMapIcon(int iconid, float x, float y, float z, int markertype, int color, int style = MAPICON_LOCAL) { return SetPlayerMapIcon(this->playerid, iconid, x, y, z, markertype, color, style); } 
	inline bool removeMapIcon(int iconid) { return RemovePlayerMapIcon(this->playerid, iconid); } 
	inline bool allowTeleport(bool allow) { return AllowPlayerTeleport(this->playerid, allow); } 
	inline bool setCameraPos(float x, float y, float z) { return SetPlayerCameraPos(this->playerid, x, y, z); } 
	inline bool setCameraLookAt(float x, float y, float z, int cut = CAMERA_CUT) { return SetPlayerCameraLookAt(this->playerid, x, y, z, cut); } 
	inline bool setCameraBehind(void) { return SetCameraBehindPlayer(this->playerid); } 
	inline Vector3 getCameraPos(void) { Vector3 tempVector; GetPlayerCameraPos(this->playerid, &tempVector.x, &tempVector.y, &tempVector.z); return tempVector; }
	inline Vector3 getCameraFrontVector(float * x, float * y, float * z) { Vector3 tempVector; GetPlayerCameraFrontVector(this->playerid, &tempVector.x, &tempVector.y, &tempVector.z); return tempVector; }
	inline int getCameraMode(void) { return GetPlayerCameraMode(this->playerid); } 
	inline bool enableCameraTarget(bool enable) { return EnablePlayerCameraTarget(this->playerid, enable); } 
	inline int getCameraTargetObject(void) { return GetPlayerCameraTargetObject(this->playerid); }
	inline int getCameraTargetVehicle(void) { return GetPlayerCameraTargetVehicle(this->playerid); } 
	inline int getCameraTargetPlayer(void) { return GetPlayerCameraTargetPlayer(this->playerid); } 
	inline int getCameraTargetActor(void) { return GetPlayerCameraTargetActor(this->playerid); } 
	inline float getCameraAspectRatio(void) { return GetPlayerCameraAspectRatio(this->playerid); }
	inline float getCameraZoom(void) { return GetPlayerCameraZoom(this->playerid); }
	inline bool attachCameraToObject(int objectid) { return AttachCameraToObject(this->playerid, objectid); }
	inline bool attachCameraToPlayerObject(int playerobjectid) { return AttachCameraToPlayerObject(this->playerid, playerobjectid); }
	inline bool interpolateCameraPos(float FromX, float FromY, float FromZ, float ToX, float ToY, float ToZ, int time, int cut = CAMERA_CUT) { return InterpolateCameraPos(this->playerid, FromX, FromY, FromZ, ToX, ToY, ToZ, time, cut); }
	inline bool interpolateCameraLookAt(float FromX, float FromY, float FromZ, float ToX, float ToY, float ToZ, int time, int cut = CAMERA_CUT) { return InterpolateCameraLookAt(this->playerid, FromX, FromY, FromZ, ToX, ToY, ToZ, time, cut); }
	inline bool isConnected(void) { return IsPlayerConnected(this->playerid); }
	inline bool isInVehicle(int vehicleid) { return IsPlayerInVehicle(this->playerid, vehicleid); }
	inline bool isInAnyVehicle(void) { return IsPlayerInAnyVehicle(this->playerid); } 
	inline bool isInCheckpoint(void) { return IsPlayerInCheckpoint(this->playerid); } 
	inline bool isInRaceCheckpoint(void) { return IsPlayerInRaceCheckpoint(this->playerid); }
	inline bool setVirtualWorld(int worldid) { return SetPlayerVirtualWorld(this->playerid, worldid); }
	inline int getVirtualWorld(void) { return GetPlayerVirtualWorld(this->playerid); }
	inline bool enableStuntBonusFor(bool enable) { return EnableStuntBonusForPlayer(this->playerid, enable); }
	//inline bool EnableStuntBonusForAll(bool enable) { return EnableStuntBonusForAll(enable); }
	inline bool toggleSpectating(bool toggle) { return TogglePlayerSpectating(this->playerid, toggle); }
	inline bool spectatePlayer(int targetplayerid, int mode = SPECTATE_MODE_NORMAL) { return PlayerSpectatePlayer(this->playerid, targetplayerid, mode); }
	inline bool spectateVehicle(int targetvehicleid, int mode = SPECTATE_MODE_NORMAL) { return PlayerSpectateVehicle(this->playerid, targetvehicleid, mode); }
	inline bool startRecordingData(int recordtype, const char * recordname) { return StartRecordingPlayerData(this->playerid, recordtype, recordname); }
	inline bool stopRecordingData(void) { return StopRecordingPlayerData(this->playerid); }
	inline bool createExplosion(float X, float Y, float Z, int type, float Radius) { return CreateExplosionForPlayer(this->playerid, X, Y, Z, type, Radius); }
	bool sendMessage(int color, const char* message, ...);

	inline bool gameText(const char *string, int time, int style) { return GameTextForPlayer(this->playerid, string, time, style); }

	bool showDialog(int style, const char* caption, const char *info, const char* button1, const char *button2, PlayerDialog &&functionTemplate);
	bool reshowDialog(int style, const char* caption, const char* info, const char* button1, const char *button2);
	//inline bool isDialogNullPtr(void) { return this->playerDialog == nullptr; }
	inline std::queue<PlayerDialog> &getDialog(void) { return this->playerDialog; }

	inline int getPlayerID(void) { return this->playerid; }

private:
	int playerid;

	std::queue<PlayerDialog> playerDialog;
};