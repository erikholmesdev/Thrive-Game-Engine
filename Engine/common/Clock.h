#pragma once
#include <SFML/Graphics.hpp>

namespace Thrive
{

	class Clock
	{
	public:

		Clock() = default;
		~Clock() = default; 

		float Restart();
		float GetElapsed() const; 

	private:
		sf::Clock m_Clock; 
	};
}