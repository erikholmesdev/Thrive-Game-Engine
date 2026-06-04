cmake_minimum_required(VERSION 3.20)

project(Thrive LANGUAGES CXX)

# -------------------------
# MSVC settings
# -------------------------
if(MSVC)
    add_compile_options("/utf-8")
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# -------------------------
# Output directories
# -------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# -------------------------
# Used to fix some build setup errors with ImGui-SFML
# -------------------------
set(IMGUI_SFML_FIND_SFML OFF CACHE BOOL "" FORCE)

#==========================================================
# Third party root
#==========================================================
set(THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/ThirdParty)

# =========================================================
# SFML
# =========================================================
add_subdirectory(${THIRD_PARTY_DIR}/SFML)

# =========================================================
# ImGui (core)
# =========================================================
set(IMGUI_DIR ${THIRD_PARTY_DIR}/imgui) # This is used in the Scripts/imgui. 
add_subdirectory (${CMAKE_SOURCE_DIR}/Scripts/ImGui)

# =========================================================
# ImGui-SFML configuration
# =========================================================
set(SFML_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_DOC OFF CACHE BOOL "" FORCE)
add_subdirectory(${THIRD_PARTY_DIR}/imgui-sfml)

# =========================================================
# Engine + Game
# =========================================================
add_subdirectory(Engine)
add_subdirectory(Game)

# =========================================================
# Startup project (Visual Studio)
# =========================================================
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    PROPERTY VS_STARTUP_PROJECT Game
)
