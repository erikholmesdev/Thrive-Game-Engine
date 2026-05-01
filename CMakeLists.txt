cmake_minimum_required(VERSION 3.20)

project(Thrive LANGUAGES CXX) 	

if(MSVC)  # Only for Visual Studio
	add_compile_options("/utf-8")
endif()

set(CMAKE_CXX_STANDARD 23)

# .exe 
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Shared Libs (.dll) 
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Static libs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/ThirdParty)

#External Libs
# SFML
	add_subdirectory(${THIRD_PARTY_DIR}/SFML)
#Imgui
	set(IMGUI_DIR ${THIRD_PARTY_DIR}/imgui)

add_library(ImGui STATIC
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_demo.cpp
    ${IMGUI_DIR}/misc/cpp/imgui_stdlib.cpp
)

target_include_directories(ImGui PUBLIC
    ${IMGUI_DIR}
    IMGUI_USER_CONFIG="ThriveImGuiConfig.h"
)

add_subdirectory(Engine)

add_subdirectory(Game)

set(IMGUI_SFML_FIND_SFML OFF)
add_subdirectory(${THIRD_PARTY_DIR}/imgui-sfml)

# Game must always be the startup project !!!
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Game)