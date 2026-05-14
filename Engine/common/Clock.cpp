#include <pch.h>
#include "Clock.h"

namespace Thrive
{	
	//Method		: Restart()
	//Parameters	: ()
	//Returns		: float
	//Description   : This method will restart the clock. 
	float Clock::Restart()
	{
		return m_Clock.restart().asSeconds(); 
	}

	//Method		: GetElapsed()
	//Parameters	: ()
	//Returns		: float
	//Description   : This method will restart the clock. 
	float Clock::GetElapsed() const 
	{
		return m_Clock.getElapsedTime().asSeconds(); 
	}
}

