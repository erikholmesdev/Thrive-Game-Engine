#pragma once
#include "Clock.h"

namespace Thrive
{
	//Class		 : Time
	//Description: This class will keep time. Some of the key functionality are:
	//				- Getting the delta time
	//				- Getting the time
	//				- Updating time per frame
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