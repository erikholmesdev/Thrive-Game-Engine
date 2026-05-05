#ImGui cmake setup


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
    ${CMAKE_SOURCE_DIR}/Engine/Config
)

target_compile_definitions(ImGui PUBLIC
    IMGUI_USER_CONFIG="ThriveImGuiConfig.h"
)