//File		 : EventDispatcher.h
//Programmer : 
//Date		 : Mar 22, 2026
//Description: This file contains the Event Dispatcher class. 

#pragma once
#include <pch.h>
#include "Event.h"

namespace Thrive
{
	//Class		 : EventDispatcher
	//Description: This class is used to dispatch the event 
	class EventDispatcher
	{

	public: 
		EventDispatcher(Event& Event)
			:m_Event(Event) {}
		
		//Method		: Dispatch (const F& func) 
		//Parameters	: const F& func
		//Returns		: bool
		//Description   : This method will dispatch the event call the func that goes with that event
		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			// Ensure type match
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				// Safe cast to concrete event type
				T& castedEvent = static_cast<T&>(m_Event);

				// Execute handler
				bool handled = func(castedEvent);

				// Proper encapsulated API
				if (handled)
					m_Event.Handled = true;

				return true;
			}

			return false;
		}
	private:
		Event& m_Event;
	};
}