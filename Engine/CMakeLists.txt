# Engine Cmake file 
file(GLOB_RECURSE ENGINE_SOURCES

    ${CMAKE_CURRENT_SOURCE_DIR}/Core/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/*.h

    ${CMAKE_CURRENT_SOURCE_DIR}/Platform/*.cpp
     ${CMAKE_CURRENT_SOURCE_DIR}/Platform/*.h
    
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics/*.h

    ${CMAKE_CURRENT_SOURCE_DIR}/Events/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Events/*.h

    ${CMAKE_CURRENT_SOURCE_DIR}/Inputs/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Inputs/*.h

    ${CMAKE_CURRENT_SOURCE_DIR}/Scenes/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Scenes/*.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Common/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/*.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Tools/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/Tools/*.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/Config/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Config/*.cpp

)

# Used for IDE's to make solution explores 
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${ENGINE_SOURCES})

# Engine Lib
add_library(Engine STATIC ${ENGINE_SOURCES})

# FORCE C++20 ON THIS TARGET (IMPORTANT)
target_compile_features(Engine PUBLIC cxx_std_20)

# Folders included. 
target_include_directories(Engine
    PUBLIC

        ${CMAKE_CURRENT_SOURCE_DIR}/Core
        ${CMAKE_CURRENT_SOURCE_DIR}/Graphics
        ${CMAKE_CURRENT_SOURCE_DIR}/Events
        ${CMAKE_CURRENT_SOURCE_DIR}/Inputs
        ${CMAKE_CURRENT_SOURCE_DIR}/Common
        ${CMAKE_CURRENT_SOURCE_DIR}/Common/Tools
        ${CMAKE_CURRENT_SOURCE_DIR}/Platform
        
        ${CMAKE_CURRENT_SOURCE_DIR}/Scenes
        ${CMAKE_CURRENT_SOURCE_DIR}/Config

        # Header file lib.
        ${PROJECT_SOURCE_DIR}/ThirdParty/spdlog/include
        ${PROJECT_SOURCE_DIR}/ThirdParty/imgui-filebrowser
)

target_include_directories(EnginePrivate PRIVATE
     ${PROJECT_SOURCE_DIR}ThirdParty/entt/src
)


# Link libs 
target_link_libraries(Engine
    PUBLIC
        sfml-graphics
        sfml-window
        sfml-system
        ImGui
        ImGui-SFML::ImGui-SFML
)

# target_compile_definitions(Engine
#     PUBLIC
#         IMGUI_USER_CONFIG="imconfig-SFML.h"
# )

# Precompiled header containing the c++ standard lib
target_precompile_headers(Engine
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Common/pch.h
)

# Different build modes 
target_compile_definitions(Engine PRIVATE
    $<$<CONFIG:Debug>:THRIVE_DEBUG>
    $<$<CONFIG:Release>:THRIVE_RELEASE>
)