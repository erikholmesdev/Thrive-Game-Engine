//File		 : 
//Programmer : 
//Date		 :
//Description: 
#pragma once

#include "Layer.h"
#include "Renderer.h"
#include "Camera.h"


#include <SFML/Graphics.hpp>

//Class		 : GameLayer
//Description: This class is derived from our engines layer class found in the Layer.h 
class GameLayer : public Thrive::Layer
{
public: 

	GameLayer()
	{
		
	}

	//Method		: OnUpdate (float dt)
	//Parameters	: float dt
	//Returns		: void
	//Description   : This method will be used when the game layer updates
	void OnUpdate(float dt) override
	{
		
	}

	//Method		: OnRender ()
	//Parameters	: ()
	//Returns		: void
	//Description   : 
	void OnRender() override
	{

	}

	//Method		: OnEvent (Thrive::Event& e)
	//Parameters	: Thrive::Event& e 
	//Returns		: void
	//Description   : This method will be our OnEvent when event happenes with in the game 
	void OnEvent(Thrive::Event& e) override
	{

	}
};