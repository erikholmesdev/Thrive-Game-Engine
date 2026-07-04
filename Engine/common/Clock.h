/*
*@file Clock.h
*
*@brief This file contains the clock class. 
* 
*/

#pragma once
#include <SFML/Graphics.hpp>

namespace Thrive
{
/*
* @brief The clock class is a wrapper for the sfml clock class
* 
* @note This clock class includes some methods that include
*       - Restarting the clock 
*       - Getting the time in seconds
*	
*
*/
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