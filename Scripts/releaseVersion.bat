REM *---------------------------------------------------------------------*
REM * This file contains all the tags and branches currently used for     *
REM *  the Thrive game engine.                                            *
REM *---------------------------------------------------------------------*

cd ..

cd ThirdParty

REM Add the relase versions here

cd imgui
git checkout v1.91.1-docking

cd ../imgui-filebrowser
git checkout dockable

cd ../SFML
git checkout 3.0.x

cd ../imgui-sfml
git checkout master

cd ../entt
git checkout v3.15.0

cd ../spdlog
git checkout v1.15.3


REM --------------------------------------------------------------



cd ../..
