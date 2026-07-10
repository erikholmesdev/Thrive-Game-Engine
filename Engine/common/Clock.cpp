/*
* @file Clock.cpp
* 
* @brief This file will contain all the class definition from the clock class 
* 
*/
#include <pch.h>
#include "Clock.h"

namespace Thrive
{	
	/*
	*@brief This will restarts the clock
	*
	*@return float
	*/
	float Clock::Restart() 
	{
		return m_Clock.restart().asSeconds(); 
	}

	/*
	*@brief This will get the current time
	* 
	*@return float 
	* 
	*/
	float Clock::GetElapsed() const 
	{
		return m_Clock.getElapsedTime().asSeconds(); 
	}
}

