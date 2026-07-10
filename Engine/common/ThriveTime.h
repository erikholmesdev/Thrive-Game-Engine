/*
* @file ThriveTime.h
* 
* @brief This file will contain the time class
*/

#pragma once
#include "Clock.h"

namespace Thrive
{
	/*
	*@brief This class will keep time. Some of the method are 
	*		- Update() called once per frame 
	*       - GetDeltaTime() seconds
	*       - GetUnscaledDeltaTime()
	*       - GetTime()
	*       - SetTimeScales(float)
	*       - GetTimeScale()
	* 
	* @note This class relies on the clock class 
	*/
	class Time
	{
	public: 
		static void Update(); // Called once per frame. 

		static float GetDeltaTime(); 

		static float GetUnscaledDeltaTime(); 

		static float GetTime(); 

		static void SetTimeScales(float scale);
		static float GetTimeScale(); 

	private:
		static Clock s_Clock; 

		static float s_DeltaTime; 
		static float s_UnscaledDeltaTime;
		static float s_TotalTime; 
		static float s_TimeScale; 
	};
}