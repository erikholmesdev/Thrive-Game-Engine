@echo off
cd ..

REM --- ALWAYS ensure submodules are correct ---
git submodule sync --recursive
git submodule update --init --recursive

REM --- Clean build directory (IMPORTANT) ---
if exist build (
    rmdir /s /q build
)

mkdir build
cd build

REM --- Configure fresh ---
cmake .. -G "Visual Studio 17 2022" -A x64

echo Run the solution file from the build directory