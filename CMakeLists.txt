cmake_minimum_required(VERSION 3.0.0)
project(samp-lua-plugin VERSION 0.1.0)

set(PLUGIN_VERSION "0.0.1")

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/vendor/cmake-modules")

include_directories(
	${PROJECT_SOURCE_DIR}/include/lua535
	${PROJECT_SOURCE_DIR}/include/sampsdk
	${PROJECT_SOURCE_DIR}/include/sampgdk462
)

add_compile_definitions(SAMPGDK_AMALGAMATION)
add_compile_definitions(_GNU_SOURCE)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_subdirectory(src)
