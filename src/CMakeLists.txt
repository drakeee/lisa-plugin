include(AMXConfig)
include(AddSAMPPlugin)

set(SAMP_SDK_ROOT "${PROJECT_SOURCE_DIR}/include/sampsdk")
set(SAMPGDK_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/sampgdk462")

find_package(SAMPSDK REQUIRED)

add_samp_plugin(lisa 
	${SAMPSDK_DIR}/amxplugin.cpp
	${SAMPSDK_DIR}/amxplugin2.cpp
	${SAMPSDK_DIR}/amx/getch.c
	${SAMPGDK_INCLUDE_DIR}/sampgdk.c
	CActor.cpp
	CEntity.cpp
	CEntityData.cpp
	CObject.cpp
	CPlayer.cpp
	CVehicle.cpp
	CLuaDefs.cpp
	CLuaFunctionDefs.cpp
	CLuaVehicleFuncDefs.cpp
	CSAMP.cpp
	CModeInit.cpp
	Shared.cpp
	Main.cpp
	Main.def
)

target_link_libraries(lisa ${PROJECT_SOURCE_DIR}/lib/lua535/liblua.a)