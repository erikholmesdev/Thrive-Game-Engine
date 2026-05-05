@echo off
cd ..

REM --- ALWAYS ensure submodules are correct ---
git submodule sync --recursive
git submodule update --init --recursive

REM --- Clean build directory (IMPORTANT) ---
if exist build (
    rmdir /s /q build
)

Rem Make build dir. This is where the solution will live. 
mkdir build

REM This is for setting up the right version for the project
cd ThirdParty/imgui
git checkout v1.91.1-docking

cd ../SFML
git checkout 3.0.x

REM Back to main project dir: Thrive 
cd ..\.. 

cd build

REM --- Configure fresh ---
cmake .. -G "Visual Studio 17 2022" -A x64

echo Run the solution file from the build directory