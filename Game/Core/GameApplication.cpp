//File		 : GameApplication.cpp 
//Programmer : 
//Date		 : 04/29/2026
//Description: This file contains our GameApplication class that is derived from the Thrive::Application and it also contains the 
//				Thrive::Application* Thrive::CreateApplication()
#include <pch.h>
#include "Application.h"
#include "GameLayer.h"

//Class		 : GameApplication
//Description: The GameApplication class is a derived class of Thrive::Application. Thrive::Application is the Game Engine. 
class GameApplication : public Thrive::Application
{
public: 
	GameApplication()
	{
		PushLayer(std::make_unique<GameLayer>()); 
	}

};

//Function	  : Thrive::Application* Thrive::CreateApplication
//Parameters  : ()
//Returns	  : new GameApplication();
//Description : This function job is to create our application. It returns a new GameApplication. 
Thrive::Application* Thrive::CreateApplication()
{
	return new GameApplication();
}