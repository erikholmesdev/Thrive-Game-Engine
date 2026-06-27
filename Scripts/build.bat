@echo off


REM --- ALWAYS ensure submodules are correct ---

cd ..

git submodule sync --recursive
git submodule update --init --recursive

REM This is the git release version file

call releaseVersion.bat 

REM --- Clean build directory (IMPORTANT) ---

if exist build (
    rmdir /s /q build
)

Rem Make build dir. This is where the solution will live. 

mkdir build

cd build

REM --- Configure fresh ---
cmake .. -G "Visual Studio 17 2022" -A x64

echo Run the solution file from the build directory