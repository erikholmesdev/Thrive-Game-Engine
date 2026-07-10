# =======================================================
#  This is the root cmake file where everything will be 
#    added together 
#
#
# =======================================================

cmake_minimum_required(VERSION 3.20)

project(Thrive LANGUAGES CXX)

# -------------------------
# MSVC settings
# -------------------------
if(MSVC)
    add_compile_options("/utf-8")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_definitions(NOMINMAX)
add_compile_definitions(WIN32_LEAN_AND_MEAN)


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
# Header only libs will be called in the Engine 
#    cmakelists.txt. 
#===========================================================


# =========================================================
# Engine
# =========================================================
add_subdirectory(Engine)

# =========================================================
# Game
# =========================================================
add_subdirectory(Game)

# =========================================================
# Tests
# =========================================================
option(THRIVE_BUILD_TESTS "Build Thrive test" ON)

if(THRIVE_BUILD_TESTS)
    enable_testing()
    add_subdirectory(${THIRD_PARTY_DIR}/googletest)
    add_subdirectory(Tests)
endif()


# =========================================================
# Startup project (Visual Studio)
# =========================================================
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    PROPERTY VS_STARTUP_PROJECT Game
)
