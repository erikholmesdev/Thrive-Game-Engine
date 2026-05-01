//File		 : WindowEvents.h
//Programmer : 
//Date		 : Apr 10, 2026
//Description: This file will contain all the declarations for Window Events. 

#pragma once
#include <pch.h>
#include "Event.h"

namespace Thrive
{
    //Class		 : WindowResizeEvent
    //Description: This is our Window resize Event. It inherits from the Event class.
    class WindowResizeEvent : public Event
    {
    public:

        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width), m_Height(height) {
        }

        unsigned int GetWidth() const { return m_Width; }
        unsigned int GetHeight() const { return m_Height; }

        EventType GetEventType() const override { return GetStaticType(); }
        static EventType GetStaticType() { return EventType::WindowResized; }

    private:
        unsigned int m_Width;
        unsigned int m_Height;
    };

    //Class		 : WindowCloseEvent
	//Description: This is our Window Close Event. It inherits from the Event class.
    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() = default;

        EventType GetEventType() const override { return GetStaticType(); }
        static EventType GetStaticType() { return EventType::WindowClose; }
    };
}