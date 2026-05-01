#pragma once
#include "Key.h"
#include <array>
#include <SFML/Graphics.hpp>

namespace Thrive
{
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