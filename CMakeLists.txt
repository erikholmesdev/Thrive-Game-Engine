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
	add_subdirectory(${THIRD_PARTY_DIR}/imgui)

add_subdirectory(Engine)

add_subdirectory(Game)
