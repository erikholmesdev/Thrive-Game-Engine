//File		 : 
//Programmer : 
//Date		 :
//Description: 

#include <pch.h>
#include "Time.h"

namespace Thrive
{

	Clock Time::s_Clock; 

	float Time::s_DeltaTime = 0.0f; 
	float Time::s_UnscaledDeltaTime = 0.0f; 
	float Time::s_TotalTime = 0.0f; 
	float Time::s_TimeScale = 1.0f;

	//Method		: 
	//Parameters	: 
	//Returns		: 
	//Description   : 
	void Time::Update()
	{
		//Raw frame time
		s_UnscaledDeltaTime = s_Clock.Restart();

		//Apply time scaling
		s_DeltaTime = s_UnscaledDeltaTime * s_TimeScale;

		//Accumulate total time (scaled) 
		s_TotalTime += s_DeltaTime;
	}

	float Time::GetDeltaTime() {
		return s_DeltaTime; 
	}

	float Time::GetUnscaledDeltaTime() {
		return s_UnscaledDeltaTime;
	}

	float Time::GetTime(){
		return s_TotalTime; 
	}

	void Time::SetTimeScales(float scale) {
		s_TimeScale = scale;
	}

	float Time::GetTimeScale() {
		return s_TimeScale;
	}
}
