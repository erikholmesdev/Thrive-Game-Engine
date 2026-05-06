cmake_minimum_required(VERSION 3.20)
project(Game)

# Collect all Game .cpp files
file(GLOB_RECURSE GAME_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Layers/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Layers/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Assets/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Assets/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Scenes/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Scenes/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Entities/*.cpp
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${GAME_SRC})

# Create the executable
add_executable(Game ${GAME_SRC})

# Include Game-specific headers (optional)
target_include_directories(Game
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Core
        ${CMAKE_CURRENT_SOURCE_DIR}/Layers
        ${CMAKE_CURRENT_SOURCE_DIR}/Assets
        ${CMAKE_CURRENT_SOURCE_DIR}/Scenes
        ${CMAKE_CURRENT_SOURCE_DIR}/Entities
)

# Link the Engine library
target_link_libraries(Game
    PRIVATE
        Engine
       
)

# Reuse Engine's precompiled header
target_precompile_headers(Game
    REUSE_FROM Engine
)



target_compile_definitions(Game PRIVATE
    $<$<CONFIG:Debug>:THRIVE_DEBUG>
    $<$<CONFIG:Release>:THRIVE_RELEASE>
)