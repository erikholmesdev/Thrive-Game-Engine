//File		 : Components.h
//Programmer : 
//Date		 :
//Description: This file contains the Entity components. 

#pragma once
#include <SFML/Graphics.hpp>

namespace Thrive
{
	struct TransformComponent
	{
		sf::Vector2f Postion; 
		float Rotation = 0.0f; 
		sf::Vector2f Scale = { 1.0f, 1.0f };
	};

	struct SpriteComponent
	{
		sf::Sprite Sprite; 
	};
}