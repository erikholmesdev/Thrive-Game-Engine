//File		 :  Input.h
//Programmer : 
//Date		 : May 06, 2026 
//Description: This file contains the input class. 

#pragma once
#include "Key.h"
#include <array>
#include <SFML/Graphics.hpp>

namespace Thrive
{
	//Class		 : Input
	//Description: This is the input class declaration. 
	class Input
	{
	public: 
		static void Init(); 
		static void EndFrame(); 

		static void SetKeyDown(Key key);
		static void SetKeyUp(Key key); 

		static bool IsKeyDown(Key key); 
		static bool IsKeyPressed(Key key); 
		static bool IsKeyReleased(Key key);

		static Key MapSFMLKey(sf::Keyboard::Key key);

	private:
		static std::array<bool, (size_t)Key::COUNT> s_KeyDown;
		static std::array<bool, (size_t)Key::COUNT> s_KeyPressed;
		static std::array<bool, (size_t)Key::COUNT> s_KeyReleased;
	};
}