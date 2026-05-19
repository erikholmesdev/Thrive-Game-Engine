//File		 : Time.cpp
//Programmer : 
//Date		 : May 12, 2026
//Description: This file will contain all the Time class method defintions. 

#include <pch.h>
#include "Time.h"

namespace Thrive
{

	Clock Time::s_Clock; 

	float Time::s_DeltaTime = 0.0f; 
	float Time::s_UnscaledDeltaTime = 0.0f; 
	float Time::s_TotalTime = 0.0f; 
	float Time::s_TimeScale = 1.0f;

	//Method		: Update
	//Parameters	: ()
	//Returns		: void
	//Description   : This method will update our static Time class members. 
	void Time::Update()
	{
		//Raw frame time
		s_UnscaledDeltaTime = s_Clock.Restart();

		//Apply time scaling
		s_DeltaTime = s_UnscaledDeltaTime * s_TimeScale;

		//Accumulate total time (scaled) 
		s_TotalTime += s_DeltaTime;
	}

	//Method		: GetDeltaTime
	//Parameters	: ()
	//Returns		: float
	//Description   : This method returns the delta time
	float Time::GetDeltaTime() {
		return s_DeltaTime; 
	}

	//Method		: GetUnscaledDeltaTime
	//Parameters	: ()
	//Returns		: float
	//Description   : This method will return the unscaled delta time 
	float Time::GetUnscaledDeltaTime() {
		return s_UnscaledDeltaTime;
	}

	//Method		: GetTime
	//Parameters	: ()
	//Returns		: float
	//Description   : This method will return the total time
	float Time::GetTime(){
		return s_TotalTime; 
	}

	//Method		: SetTimeScales (float scales)
	//Parameters	: (float scales)
	//Returns		: void
	//Description   : This method will set our time scale. 
	void Time::SetTimeScales(float scale) {
		s_TimeScale = scale;
	}

	//Method		: GetTimeScale()
	//Parameters	: ()
	//Returns		: float
	//Description   : This method will return the time scale. 
	float Time::GetTimeScale() {
		return s_TimeScale;
	}
}
