#include <pch.h>
#include "Application.h"

class GameApplication : public Thrive::Application
{
public: 
	GameApplication()
	{

	}
};


Thrive::Application* Thrive::CreateApplication()
{
	return new GameApplication();
}