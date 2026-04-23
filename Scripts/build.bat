@echo off

cd ..

if not exist ThirdParty (
     mkdir ThirdParty
    git submodule update --init --recursive
)


if not exist build mkdir build

cd build 

cmake .. -G "Visual Studio 17 2022"

cls

echo "Run solution file from the build directory"