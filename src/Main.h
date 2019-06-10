//Define plugin details
#define PLUGIN_NAME "Lisa"
#define PLUGIN_AUTHOR "drake"
#define PLUGIN_VERSION "0.0.2"

//Standard includes
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <memory>
#include <cassert>

//SAMPSDK
#include <amx/amx.h>
#include <plugincommon.h>

//SAMPGDK
#include <sampgdk.h>

//Lua
#include <lua.hpp>

#include "Shared.h"
#include "CArgReader.h"
#include "CLuaFunctionDefs.h"
#include "CLuaDefs.h"
#include "CLuaVector3FuncDefs.h"
#include "CLuaVehicleFuncDefs.h"
#include "CEntityData.h"
#include "CActor.h"
#include "CObject.h"
#include "CPlayer.h"
#include "CVehicle.h"
#include "CSAMP.h"