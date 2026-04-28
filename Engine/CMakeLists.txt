# Engine Cmake file 

file(GLOB_RECURSE ENGINE_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp
)

add_library(Engine STATIC ${ENGINE_SOURCES})

# Include 
target_include_directories(Engine
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/common
        ${PROJECT_SOURCE_DIR}/ThirdParty/spdlog/include
)

target_link_libraries(Engine
    PUBLIC
        sfml-graphics
        sfml-window
        sfml-system
        
)

target_precompile_headers(Engine
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/pch.h
)


target_compile_definitions(Engine PRIVATE
    $<$<CONFIG:Debug>:THRIVE_DEBUG>
    $<$<CONFIG:Release>:THRIVE_RELEASE>
)