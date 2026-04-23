//File		 : Event.h
//Programmer : 
//Date		 : Mar 22, 2026
//Description: This file will contain the base Event class. 

#pragma once
#include <pch.h>
#include "SFML/Graphics.hpp"

namespace Thrive
{
	// These are all the current types of event the game engine supports/ 
	enum class EventType
	{
		None = 0,
		WindowClose,
		KeyPressed,
		KeyReleased, 
		WindowResized,
		MouseButtonPressed,
		MouseButtonReleased,
		MouseMove
	};

	//Class		 : Event 
	//Description: This class will be base event system class. All events will inherit from this class.
	class Event
	{
	public:
		virtual ~Event() = default;
		bool Handled = false;

		virtual EventType GetEventType() const = 0;
	};
}