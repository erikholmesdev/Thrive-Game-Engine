//File		 : Clock.h
//Programmer : 
//Date		 : 
//Description: This file contains the clock class. 

#pragma once
#include <SFML/Graphics.hpp>

namespace Thrive
{
	//Class		 : Clock
	//Description: This is our clock class. 
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