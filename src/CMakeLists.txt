include(AMXConfig)
include(AddSAMPPlugin)

set(SAMP_SDK_ROOT "${PROJECT_SOURCE_DIR}/include/sampsdk")
set(SAMPGDK_INCLUDE_DIR "${PROJECT_SOURCE_DIR}/include/sampgdk462")

find_package(SAMPSDK REQUIRED)

add_samp_plugin(samp-lua-plugin 
	${SAMPSDK_DIR}/amxplugin.cpp
	${SAMPSDK_DIR}/amxplugin2.cpp
	${SAMPSDK_DIR}/amx/getch.c
	${SAMPGDK_INCLUDE_DIR}/sampgdk.c
	Main.cpp
)