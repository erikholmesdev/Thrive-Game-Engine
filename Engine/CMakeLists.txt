# Engine Cmake file 

file(GLOB_RECURSE ENGINE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Graphics/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Events/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Events/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Inputs/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Inputs/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Scenes/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Scenes/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Common/*.h


)

add_library(Engine STATIC ${ENGINE_SOURCES})

# Include 
target_include_directories(Engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Core
        ${CMAKE_CURRENT_SOURCE_DIR}/Graphics
        ${CMAKE_CURRENT_SOURCE_DIR}/Events
        ${CMAKE_CURRENT_SOURCE_DIR}/Inputs
        ${CMAKE_CURRENT_SOURCE_DIR}/Common
        
        ${CMAKE_CURRENT_SOURCE_DIR}/Scenes


        ${PROJECT_SOURCE_DIR}/ThirdParty/spdlog/include
)

target_link_libraries(Engine
    PUBLIC
        sfml-graphics
        sfml-window
        sfml-system
        ImGui
        ImGui-SFML
)

target_precompile_headers(Engine
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Common/pch.h
)


target_compile_definitions(Engine PRIVATE
    $<$<CONFIG:Debug>:THRIVE_DEBUG>
    $<$<CONFIG:Release>:THRIVE_RELEASE>
)