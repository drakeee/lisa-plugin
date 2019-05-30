#pragma once

#include "Shared.h"
#include "CPlayer.h"

#include <sampgdk.h>

class CObject : public CEntity
{
public:
	CObject(int modelid, float X, float Y, float Z, float rX, float rY, float rZ, float DrawDistance = 0.0);
	~CObject();

	//inline int CreateObject(int modelid, float x, float y, float z, float rX, float rY, float rZ, float DrawDistance = 0.0); - Constructor
	inline bool attachToVehicle(int vehicleid, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ) { return AttachObjectToVehicle(this->objectid, vehicleid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ); }
	inline bool attachToObject(int attachtoid, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ, bool SyncRotation = false) { return AttachObjectToObject(this->objectid, attachtoid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, SyncRotation); }
	inline bool attachTo(int playerid, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ) { return AttachObjectToPlayer(this->objectid, playerid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ); }
	inline bool attachTo(CPlayer *player, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ) { return AttachObjectToPlayer(this->objectid, player->getPlayerID(), fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ); }
	inline bool setPos(float x, float y, float z) { return SetObjectPos(this->objectid, x, y, z); }
	inline bool setPos(Vector3 &posVector) { return SetObjectPos(this->objectid, posVector.x, posVector.y, posVector.z); }
	inline Vector3 getPos(void) { Vector3 tempVector; GetObjectPos(this->objectid, &tempVector.x, &tempVector.y, &tempVector.z); return tempVector; }
	inline bool setRot(float rotX, float rotY, float rotZ) { return SetObjectRot(this->objectid, rotX, rotY, rotZ); }
	inline bool setRot(Vector3 &rotVector) { return SetObjectRot(this->objectid, rotVector.x, rotVector.y, rotVector.z); }
	inline Vector3 getRot(float * rotX, float * rotY, float * rotZ) { Vector3 tempVector; GetObjectRot(this->objectid, &tempVector.x, &tempVector.y, &tempVector.z); return tempVector; }
	inline int getModel(void) { return GetObjectModel(this->objectid); }
	inline bool setNoCameraCol(void) { return SetObjectNoCameraCol(this->objectid); }
	inline bool isValid(void) { return IsValidObject(this->objectid); }
	//inline bool destroy(void); - Deconstructor
	inline int move(float X, float Y, float Z, float Speed, float RotX = -1000.0, float RotY = -1000.0, float RotZ = -1000.0) { return MoveObject(this->objectid, X, Y, Z, Speed, RotX, RotY, RotZ); }
	inline bool stop(void) { return StopObject(this->objectid); }
	inline bool isMoving(void) { return IsObjectMoving(this->objectid); }
	inline bool setMaterial(int materialindex, int modelid, const char * txdname, const char * texturename, int materialcolor = 0) { return SetObjectMaterial(this->objectid, materialindex, modelid, txdname, texturename, materialcolor); }
	inline bool setMaterialText(const char * text, int materialindex = 0, int materialsize = OBJECT_MATERIAL_SIZE_256x128, const char * fontface = "Arial", int fontsize = 24, bool bold = true, int fontcolor = 0xFFFFFFFFL, int backcolor = 0, int textalignment = 0) { return SetObjectMaterialText(this->objectid, text, materialindex, materialsize, fontface, fontsize, bold, fontcolor, backcolor, textalignment); }
	inline bool edit(int playerid) { return EditObject(playerid, this->objectid); }
	inline bool edit(CPlayer *player) { return EditObject(player->getPlayerID(), this->objectid); }
	inline bool select(int playerid) { return SelectObject(playerid); }
	inline bool select(CPlayer *player) { return SelectObject(player->getPlayerID()); }
	inline bool cancelEdit(int playerid) { return CancelEdit(playerid); }
	inline bool cancelEdit(CPlayer *player) { return CancelEdit(player->getPlayerID()); }
	inline bool setsDefaultCameraCol(bool disable) { return SetObjectsDefaultCameraCol(disable); }

private:
	int objectid;
};

class CPObject
{
public:
	CPObject(int playerid, int modelid, float x, float y, float z, float rX, float rY, float rZ, float DrawDistance = 0.0);
	CPObject(CPlayer *player, int modelid, float x, float y, float z, float rX, float rY, float rZ, float DrawDistance = 0.0);
	~CPObject();

	//inline int create(int playerid, int modelid, float x, float y, float z, float rX, float rY, float rZ, float DrawDistance = 0.0) { return CreateObject(playerid, modelid, x, y, z, rX, rY, rZ, DrawDistance); }
	inline bool attachToPlayer(int attachplayer, float OffsetX, float OffsetY, float OffsetZ, float rX, float rY, float rZ) { return AttachPlayerObjectToPlayer(this->player->getPlayerID(), this->objectid, attachplayer, OffsetX, OffsetY, OffsetZ, rX, rY, rZ); }
	inline bool attachToPlayer(int attachplayer, Vector3 &offsetVector, Vector3 &rotVector) { return AttachPlayerObjectToPlayer(this->player->getPlayerID(), this->objectid, attachplayer, offsetVector.x, offsetVector.y, offsetVector.z, rotVector.x, rotVector.y, rotVector.z); }
	inline bool attachToVehicle(int vehicleid, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ) { return AttachPlayerObjectToVehicle(this->player->getPlayerID(), this->objectid, vehicleid, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ); }
	inline bool attachToVehicle(int vehicleid, Vector3 &offsetVector, Vector3 &rotVector) { return AttachPlayerObjectToVehicle(this->player->getPlayerID(), this->objectid, vehicleid, offsetVector.x, offsetVector.y, offsetVector.z, rotVector.x, rotVector.y, rotVector.z); }
	inline bool setPos(float x, float y, float z) { return SetPlayerObjectPos(this->player->getPlayerID(), this->objectid, x, y, z); }
	inline bool setPos(Vector3 &posVector) { return SetPlayerObjectPos(this->player->getPlayerID(), this->objectid, posVector.x, posVector.y, posVector.z); }
	inline Vector3 getPos(void) { Vector3 tempVector; GetPlayerObjectPos(this->player->getPlayerID(), this->objectid, &tempVector.x, &tempVector.y, &tempVector.z); return tempVector; }
	inline bool setRot(float rotX, float rotY, float rotZ) { return SetPlayerObjectRot(this->player->getPlayerID(), this->objectid, rotX, rotY, rotZ); }
	inline bool setRot(Vector3 &rotVector) { return SetPlayerObjectRot(this->player->getPlayerID(), this->objectid, rotVector.x, rotVector.y, rotVector.z); }
	inline Vector3 getRot(void) { Vector3 tempVector; GetPlayerObjectRot(this->player->getPlayerID(), this->objectid, &tempVector.x, &tempVector.y, &tempVector.z); return tempVector; }
	inline int getModel(void) { return GetPlayerObjectModel(this->player->getPlayerID(), this->objectid); }
	inline bool setNoCameraCol(void) { return SetPlayerObjectNoCameraCol(this->player->getPlayerID(), this->objectid); }
	inline bool isValid(void) { return IsValidPlayerObject(this->player->getPlayerID(), this->objectid); }
	//inline bool destroy(void) { return DestroyPlayerObject(t) }
	inline int move(float x, float y, float z, float Speed, float RotX = -1000.0, float RotY = -1000.0, float RotZ = -1000.0) { return MovePlayerObject(this->player->getPlayerID(), this->objectid, x, y, z, Speed, RotX, RotY, RotZ); }
	inline bool stop(void) { return StopPlayerObject(this->player->getPlayerID(), this->objectid); }
	inline bool isMoving(void) { return IsPlayerObjectMoving(this->player->getPlayerID(), this->objectid); }
	inline bool setMaterial(int materialindex, int modelid, const char * txdname, const char * texturename, int materialcolor = 0) { return SetPlayerObjectMaterial(this->player->getPlayerID(), this->objectid, materialindex, modelid, txdname, texturename, materialcolor); }
	inline bool setMaterialText(const char * text, int materialindex = 0, int materialsize = OBJECT_MATERIAL_SIZE_256x128, const char * fontface = "Arial", int fontsize = 24, bool bold = true, int fontcolor = 0xFFFFFFFFL, int backcolor = 0, int textalignment = 0) { return SetPlayerObjectMaterialText(this->player->getPlayerID(), this->objectid, text, materialindex, materialsize, fontface, fontsize, bold, fontcolor, backcolor, textalignment); }
	inline bool edit(void) { return EditObject(this->player->getPlayerID(), this->objectid); }
	inline bool select(void) { return SelectObject(this->player->getPlayerID()); }
	inline bool cancelEdit(void) { return CancelEdit(this->player->getPlayerID()); }
	inline bool setsDefaultCameraCol(bool disable) { return SetObjectsDefaultCameraCol(disable); }

private:
	CPlayer *player;
	int objectid;
};