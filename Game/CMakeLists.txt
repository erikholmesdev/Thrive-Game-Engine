cmake_minimum_required(VERSION 3.20)
project(Game)

# Collect all Game .cpp files
file(GLOB_RECURSE GAME_SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

# Create the executable
add_executable(Game ${GAME_SRC})

# Include Game-specific headers (optional)
target_include_directories(Game
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
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