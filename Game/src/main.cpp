//File		 : Main.cpp
//Programmer : 
//Date		 : Mar 19, 2025
//Description:  This file contains the main file and the entry point


#include <pch.h>
#include "Application.h"

int main()
{
	Thrive::Application* app = Thrive::CreateApplication(); 

	app->Run(); 
	delete app;

	return 0; 
}